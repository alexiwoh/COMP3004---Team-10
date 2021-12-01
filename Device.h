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
    bool recording;
    bool isTouchingSkin;
    double batteryPercentage;
    double current; //in milliamps
    double frequency; //0.5, 77, 100 hz
    QString waveform; //Alpha, Betta, Gamma
    int time; //20, 40, 60
    int timeIdle; //QTimer will increment this
    Record* records[MAX_RECORDS];
    int numRecords;
    MainWindow* display;

public:
    Device(MainWindow*);
    ~Device();

    //Setters
    void setBatteryPercentage(double);
    void setFrequency(double);
    void setCurrent(double);
    void setWaveform(QString const);
    void setTime(int);

    //Getters
    double getBattery();
    double getFrequency();
    double getCurrent();
    QString getWaveform();
    int getTime();
    bool getSkin();
    bool getRecording();

    //Functions
    void toggleTouchingSkin();
    bool checkBattery(double);
    void shutDown();
    void addRecord(Record* r);


public slots:
    void toggle(); //on off toggle
    void toggleRecording();
    void changeFrequency();
    void changeWaveform();
    void changeTime();
    void changeCurrentUp(); //59 incrementing
    void changeCurrentDown(); // 100 decrementing
    void resetTimeIdle(); //for idle timer

};




#endif // DEVICE_H
