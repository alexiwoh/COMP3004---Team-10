/*
 * This class handles the display elements of the application window.
*/

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

    // Setters to uodate display elements.
    void updateFrequency();
    void updateWaveform();
    void updateTime();
    void updateCurrent();
    void updateScreen(bool);
    void updateRecordingLED(bool);
    void batteryDrain();


public slots:
    void on_applyToSkin_stateChanged(); // Handles checkbox value changes.
    void timerUpdate(); // Periodically changes to display elements.
    void on_batterySpinBox_valueChanged(int);
    void on_faultButton_clicked(); // Handles fault button checkbox.
    void on_power_off(); // Handles power off.

private:
    Ui::MainWindow *ui;
    View *view;
    Device *model;
    QTimer* timer;
    QTime time;
};
#endif // MAINWINDOW_H
