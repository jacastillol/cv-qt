#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStatusBar>
#include <QLabel>
#include <QGraphicsPixmapItem>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void openImage();
  void zoomIn();
  void zoomOut();
  void saveAs();
 
private:
  void initUI();
  void createActions();
  void showImage(QString);
 
private:
  QMenu *fileMenu;
  QMenu *viewMenu;
 
  QToolBar *fileToolBar;
  QToolBar *viewToolBar;
 
  QGraphicsScene *imageScene;
  QGraphicsView *imageView;
  QGraphicsPixmapItem *currentImage;
 
  QStatusBar *mainStatusBar;
  QLabel *mainStatusLabel;

  QAction *openAction;
  QAction *saveAsAction;
  QAction *exitAction;
  QAction *zoomInAction;
  QAction *zoomOutAction;
  QAction *prevAction;
  QAction *nextAction;
  
};

#endif // MAINWINDOW_H
