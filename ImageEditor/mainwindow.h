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
#include <QMap>

#include "editor_plugin_interface.h"


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
  void prevImage();
  void nextImage();
  
  void blurImage();

  void pluginPerform();

private:
  void initUI();
  void createActions();
  void showImage(QString);
  void setupShortcuts();
  void loadPlugins();
 
private:
  QMenu *fileMenu;
  QMenu *viewMenu;
  QMenu *editMenu;
 
  QToolBar *fileToolBar;
  QToolBar *viewToolBar;
  QToolBar *editToolBar;
 
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
  QAction *blurAction;

  QString currentImagePath;

  QMap<QString, EditorPluginInterface*>editPlugins;
};

#endif // MAINWINDOW_H
