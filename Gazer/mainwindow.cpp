#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    fileMenu(nullptr)
{
    initUI();
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

}

void MainWindow::openCamera()
{
  
}
