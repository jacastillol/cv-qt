#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStatusBar>
#include <QLabel>
#include <QListView>
#include <QCheckBox>
#include <QPushButton>

#include "opencv2/opencv.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow();

private:
    void initUI();
    void createActions();
 
private slots:
  void showCameraInfo();
  void openCamera();
  
private:
    QMenu *fileMenu;
 
    QAction *cameraInfoAction;
    QAction *openCameraAction;
    QAction *exitAction;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;

    QCheckBox *monitorCheckBox;
    QPushButton *recordButton;
 
    QListView *saved_list;
 
    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

};

#endif // MAINWINDOW_H
