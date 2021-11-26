#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "View.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //connecting buttons
    //connect(ui->powerPushButton, &QPushButton::released, this, &Device::toggle);

private:
    Ui::MainWindow *ui;
    View *view;
    Device *model;
};
#endif // MAINWINDOW_H
