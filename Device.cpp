#include "Device.h"

Device::Device(MainWindow* mainWindow)
{
    on = true;
    recording = false;
    isTouchingSkin = false;
    batteryPercentage = 100;
    current = 100;
    frequency = 0.5;
    waveform = "Alpha";
    time = 20;
    timeIdle = 0;
    numRecords = 0;
    display = mainWindow;
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

bool Device::getSkin(){
  return isTouchingSkin;
}

bool Device::getRecording(){
  return recording;
}

//functions

void Device::toggleTouchingSkin(){
    isTouchingSkin = !isTouchingSkin;
    if(isTouchingSkin == true){
      qInfo("touching skin");
    }
    else{qInfo("NOT touching skin");}

}


bool Device::checkBattery(double per){


}


void Device::addRecord(Record* r){
  records[numRecords] = r;
  numRecords++;
  qInfo("added to records");
}

void Device::shutDown(){

    if(on == true){
        toggle();
        qInfo("SHUTODNW");
    }
}


//slots
void Device::toggle(){
    on = !on;
    setBatteryPercentage(100);
    setFrequency(0.5);
    setCurrent(100);
    setWaveform("Alpha");
    setTime(20);
    if(isTouchingSkin == true) {toggleTouchingSkin();}
    display->updateScreen(on);
}


void Device::toggleRecording(){
    recording = !recording;
    display->updateRecordingLED(recording);


}


void Device::changeFrequency(){
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
    if(current < 500){
        setCurrent(current += 50);
        display->updateCurrent();
    }
}


void Device::changeCurrentDown(){
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

}
