#ifndef DEVICE_H
#define DEVICE_H
#include "Record.h"
#include <QObject>
#include <QString>

const int MAX_RECORDS = 256;

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

public:
    Device();

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
    void toggle(); //on off toggle
    void toggleTouchingSkin();
    bool checkBattery(double);
    void shutDown();


public slots:
    void resetTimeIdle(); //slot of the buttons

};




#endif // DEVICE_H
