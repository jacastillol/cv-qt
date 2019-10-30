#include <QApplication>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    fileMenu(nullptr),
    viewMenu(nullptr)
{
  initUI();
}

void MainWindow::initUI()
{
  this->resize(800, 600);
  // setup menubar
  fileMenu = menuBar()->addMenu("&File");
  viewMenu = menuBar()->addMenu("&View");
 
  // setup toolbar
  fileToolBar = addToolBar("File");
  viewToolBar = addToolBar("View");
 
  // main area for image display
  imageScene = new QGraphicsScene(this);
  imageView = new QGraphicsView(imageScene);
  setCentralWidget(imageView);
 
  // setup status bar
  mainStatusBar = statusBar();
  mainStatusLabel = new QLabel(mainStatusBar);
  mainStatusBar->addPermanentWidget(mainStatusLabel);
  mainStatusLabel->setText("Image Information will be here!");

  createActions();
  
}

MainWindow::~MainWindow()
{
  
}

void MainWindow::createActions()
{

    // create actions, add them to menus
    openAction = new QAction("&Open", this);
    fileMenu->addAction(openAction);
    saveAsAction = new QAction("&Save as", this);
    fileMenu->addAction(saveAsAction);
    exitAction = new QAction("E&xit", this);
    fileMenu->addAction(exitAction);

    zoomInAction = new QAction("Zoom in", this);
    viewMenu->addAction(zoomInAction);
    zoomOutAction = new QAction("Zoom Out", this);
    viewMenu->addAction(zoomOutAction);
    prevAction = new QAction("&Previous Image", this);
    viewMenu->addAction(prevAction);
    nextAction = new QAction("&Next Image", this);
    viewMenu->addAction(nextAction);

    // add actions to toolbars
    fileToolBar->addAction(openAction);
    viewToolBar->addAction(zoomInAction);
    viewToolBar->addAction(zoomOutAction);
    viewToolBar->addAction(prevAction);
    viewToolBar->addAction(nextAction);

    connect(exitAction, SIGNAL(triggered(bool)),
	    QApplication::instance(), SLOT(quit()));

}
