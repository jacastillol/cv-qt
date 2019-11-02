#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QCameraInfo>
#include <QMessageBox>
#include <QMutex>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    fileMenu(nullptr),
    capturer(nullptr)
{
    initUI();
    data_lock = new QMutex();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
  this->resize(1000, 800);

  // setup menubar
  fileMenu = menuBar()->addMenu("&File");

  QGridLayout *main_layout = new QGridLayout();
  imageScene = new QGraphicsScene(this);
  imageView = new QGraphicsView(imageScene);

  main_layout->addWidget(imageView, 0, 0, 12, 1);

  QGridLayout *tools_layout = new QGridLayout();
  main_layout->addLayout(tools_layout, 12, 0, 1, 1);
 
  monitorCheckBox = new QCheckBox(this);
  monitorCheckBox->setText("Monitor On/Off");
  tools_layout->addWidget(monitorCheckBox, 0, 0);
 
  recordButton = new QPushButton(this);
  recordButton->setText("Record");
  tools_layout->addWidget(recordButton, 0, 1, Qt::AlignHCenter);
  tools_layout->addWidget(new QLabel(this), 0, 2);

  // list of saved videos
  saved_list = new QListView(this);
  main_layout->addWidget(saved_list, 13, 0, 4, 1);

  QWidget *widget = new QWidget();
  widget->setLayout(main_layout);
  setCentralWidget(widget);

  // setup status bar
  mainStatusBar = statusBar();
  mainStatusLabel = new QLabel(mainStatusBar);
  mainStatusBar->addPermanentWidget(mainStatusLabel);
  mainStatusLabel->setText("Gazer is Ready");
 
  createActions();
}
  
void MainWindow::createActions()
{
  // create actions, add them to menus
  cameraInfoAction = new QAction("Camera &Information", this);
  fileMenu->addAction(cameraInfoAction);
  openCameraAction = new QAction("&Open Camera", this);
  fileMenu->addAction(openCameraAction);
  exitAction = new QAction("E&xit", this);
  fileMenu->addAction(exitAction);

  // connect the signals and slots
  connect(exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
  connect(cameraInfoAction, SIGNAL(triggered(bool)), this, SLOT(showCameraInfo()));
  connect(openCameraAction, SIGNAL(triggered(bool)), this, SLOT(openCamera()));
}

void MainWindow::showCameraInfo()
{
  QList<QCameraInfo>cameras = QCameraInfo::availableCameras();
  QString info = QString("Available Cameras: \n");
 
  foreach (const QCameraInfo &cameraInfo, cameras) {
    info += " - " + cameraInfo.deviceName() + ": ";
    info += cameraInfo.description() + "\n";
  }
  
  QMessageBox::information(this, "Cameras", info);
}

void MainWindow::openCamera()
{
  if(capturer != nullptr) {
    // if a thread is already running, stop it
    capturer->setRunning(false);
    disconnect(capturer, &CaptureThread::frameCaptured, this, &MainWindow::updateFrame);
    connect(capturer, &CaptureThread::finished, capturer, &CaptureThread::deleteLater);
  }

  int camID = 0;
  
  capturer = new CaptureThread(camID, data_lock);
  connect(capturer, &CaptureThread::frameCaptured,
	  this, &MainWindow::updateFrame);

  capturer->start();

  mainStatusLabel->setText(QString("Capturing Camera %1").arg(camID));
}

void MainWindow::updateFrame(cv::Mat *mat)
{
  data_lock->lock();
  currentFrame = *mat;
  data_lock->unlock();

  QImage frame(
	       currentFrame.data,
	       currentFrame.cols,
	       currentFrame.rows,
	       currentFrame.step,
	       QImage::Format_RGB888);
  QPixmap image = QPixmap::fromImage(frame);

  imageScene->clear();
  imageView->resetMatrix();
  imageScene->addPixmap(image);
  imageScene->update();
  imageView->setSceneRect(image.rect());
}
