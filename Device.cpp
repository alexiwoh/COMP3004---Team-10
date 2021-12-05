#include "Device.h"
#include <QTimer>

Device::Device(MainWindow* mainWindow)
{
    on = true;
    recording = true;
    isTouchingSkin = false;
    batteryPercentage = 100;
    current = 100;
    frequency = 0.5;
    waveform = "Alpha";
    timer = new QTimer(this);
    time = 20;
    countDown = -1;
    timeIdle = 0;
    numRecords = 0;
    display = mainWindow;

    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
}

Device::~Device(){
  for(int i = 0; i<numRecords; i++){
    delete records[i];
  }
  qInfo("deconstructer");
}

//Setters
void Device::setBatteryPercentage(int per){
    batteryPercentage = per;
}

void Device::setFrequency(double freq){
    frequency = freq;
}

void Device::setCurrent(double cur){
    current = cur;
}

void Device::setWaveform(QString const wave){
    waveform = wave;
}

void Device::setTime(int timer){
    time = timer;
}

//Getters
double Device::getBattery(){
    return batteryPercentage;
}

double Device::getFrequency(){
    return frequency;
}

double Device::getCurrent(){
    return current;
}

QString Device::getWaveform(){
    return waveform;
}

int Device::getTime(){
    return time;
}

int Device::getCountDown(){
    return countDown;
}

bool Device::getSkin(){
  return isTouchingSkin;
}

bool Device::getRecording(){
  return recording;
}

QString Device::getTimeElapsed()    {
    return QDateTime::fromTime_t(timeElapsed).toString("hh:mm:ss");
}

QString Device::getRecordsAsText()  {
    QString s = "";
    QString line = "-------------------------\n";
    for(int i=numRecords-1; i>=0; --i) {
        s += line;
        s += "RECORD " + QString::number(i) + "\n";
        s += line;
        s += records[i]->getRecordData();
    }
    return s;
}

//functions

void Device::updateRecords()    {
    if(numRecords < 1 || !recording)  return;
    records[numRecords-1]->addState(waveform,frequency,time,current,getTimeElapsed());
}

void Device::updateTimes()  {
    if(!isTouchingSkin) {
        if (timeIdle >= 10) {
            toggle();
            timer->stop();
            return;
        }
        timeIdle++;
    }
    timeElapsed++;
    timer->start(1000);
}

void Device::toggleTouchingSkin(){
    resetTimeIdle();

    if(!isTouchingSkin && on && recording) {
        addRecord(new Record());
    }
    isTouchingSkin = !isTouchingSkin;
    if(isTouchingSkin == true){ //touching skin
        qInfo("touching skin");
        display->updateCircuitLED(isTouchingSkin);
        countDown = time;
    }
    else{
        qInfo("NOT touching skin"); //not touching skin
        display->updateCircuitLED(isTouchingSkin);
    }
    resetTimeIdle();
}


void Device::checkSession(){
    if (countDown <= 0) {
        isTouchingSkin = false;
        display->updateApplyToSkin(false);
        display->updateCircuitLED(false);
    }
}


void Device::checkBattery(){
    if (batteryPercentage <= 5) {
        display->updateBatteryLED(true);
    }
    else {
        display->updateBatteryLED(false);
    }
}


void Device::addRecord(Record* r){
  records[numRecords++] = r;
  qInfo("added to records");
}

void Device::timerUpdate() {
    if(isTouchingSkin){
        display->updateTimer();

        if(batteryPercentage == 0){
            display->updateScreen(false);
        }
        else{
            countDown -= 1;
            checkSession();
            display->updateTimer();
            batteryPercentage -= 1;
            checkBattery();
            display->updateBattery();
        }
        timer->start(1000);
    }
    else { //idle timer
        updateTimes();
    }
}

//slots
void Device::toggle(){
    if(on == false)  { //off to on
        timeElapsed = 0;
        resetTimeIdle();
        recording = true;
        timer->start(1000);
        recording = true;
        setFrequency(0.5);
        setCurrent(100);
        setWaveform("Alpha");
        setTime(20);
        checkBattery();
    }
    else if (on == true){ //on to off
        isTouchingSkin = false;
        timer->stop();
        display->updateBatteryLED(false);
    }
    on = !on;
    display->updateScreen(on);
}


void Device::toggleRecording(){
    resetTimeIdle();

    recording = !recording;
    display->updateRecordingLED(recording);
}


void Device::changeFrequency(){
    resetTimeIdle();

    if (frequency == 0.5) {
        setFrequency(77);
        display->updateFrequency();
    }
    else if (frequency == 77) {
        setFrequency(100);
        display->updateFrequency();
    }
    else if (frequency == 100) {
        setFrequency(0.5);
        display->updateFrequency();
    }
}


void Device::changeWaveform(){
    resetTimeIdle();

    if (waveform == "Alpha") {
        setWaveform("Betta");
        display->updateWaveform();
    }
    else if (waveform == "Betta") {
        setWaveform("Gamma");
        display->updateWaveform();
    }
    else if (waveform == "Gamma") {
        setWaveform("Alpha");
        display->updateWaveform();
    }
}


void Device::changeTime(){
    resetTimeIdle();

    if (time == 20) {
        setTime(40);
        display->updateTime();
    }
    else if (time == 40) {
        setTime(60);
        display->updateTime();
    }
    else if (time == 60) {
        setTime(20);
        display->updateTime();
    }
}


void Device::changeCurrentUp(){
    resetTimeIdle();

    if(current < 500){
        setCurrent(current += 50);
        display->updateCurrent();
    }
}


void Device::changeCurrentDown(){
    resetTimeIdle();

    if(current > 100){
        setCurrent(current -= 100);
        display->updateCurrent();
    }
    else{
        setCurrent(50);
        display->updateCurrent();
    }
}

void Device::resetTimeIdle(){
    timeIdle = 0;
    qInfo("reset idle time");
}
