#ifndef DEVICE_H
#define DEVICE_H
#include "mainwindow.h"
#include "Record.h"
#include <QObject>
#include <QString>

const int MAX_RECORDS = 256;

class Records;
class MainWindow;


class Device : public QObject
{
Q_OBJECT

private:
    bool on;
    bool isTouchingSkin;
    double batteryPercentage;
    double current; //in milliamps
    double frequency; //0.5, 77, 100 hz
    QString waveform;
    int time;
    int timeIdle; //QTimer will increment this
    Record records[MAX_RECORDS];
    MainWindow* display;

public:
    Device(MainWindow*);

    //Setters
    void setBatteryPercentage(double);
    void setFrequency(double);
    void setCurrent(double);
    void setWaveform(QString const);

    //Getters
    double getBattery();
    double getFrequency();
    double getCurrent();
    QString getWaveform();

    //Functions
    void toggleTouchingSkin();
    bool checkBattery(double);
    void shutDown();


public slots:
    void toggle(); //on off toggle
    void changeFrequency();
    void resetTimeIdle(); //slot of the buttons

};




#endif // DEVICE_H
