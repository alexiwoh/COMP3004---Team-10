#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "View.h"
#include <QTimer>
#include <QTime>

class Device;
class View;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateFrequency();
    void updateWaveform();
    void updateTime();
    void updateCurrent();
    void updateScreen(bool);
    void updateRecordingLED(bool);


private slots:
    void on_applyToSkin_stateChanged();
    void timerUpdate();

private:
    Ui::MainWindow *ui;
    View *view;
    Device *model;
    QTimer* timer;
    QTime time;
};
#endif // MAINWINDOW_H
