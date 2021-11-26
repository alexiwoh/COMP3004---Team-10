#ifndef DEVICE_H
#define DEVICE_H
#include "Record.h"
#include <QString>

const int MAX_RECORDS = 256;

class Device
{
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
    Device() {}

    void toggle(); //on off toggle
    void toggleTouchingSkin();
    bool checkBattery(double);
    void shutDown();

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

public slots:
    void resetTimeIdle(); //slot of the buttons

};




#endif // DEVICE_H
