#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStatusBar>
#include <QLabel>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 
private:
  void initUI();
 
private:
  QMenu *fileMenu;
  QMenu *viewMenu;
 
  QToolBar *fileToolBar;
  QToolBar *viewToolBar;
 
  QGraphicsScene *imageScene;
  QGraphicsView *imageView;
 
  QStatusBar *mainStatusBar;
  QLabel *mainStatusLabel;
};

#endif // MAINWINDOW_H
