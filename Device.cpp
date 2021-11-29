#include "Device.h"

Device::Device(MainWindow* mainWindow)
{
    on = true;
    isTouchingSkin = false;
    batteryPercentage = 100;
    current = 100;
    frequency = 0.5;
    waveform = "Alpha";
    time = 0;
    timeIdle = 0;
    numRecords = 0;
    display = mainWindow;
}

Device::~Device(){
  for(int i = 0; i<numRecords; i++){
    delete records[i];
  }
}

//Setters
void Device::setBatteryPercentage(double per){
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
}

void Device::shutDown(){

}


//slots
void Device::toggle(){
    on = !on;
    qInfo("power button pressed");
    if(on == true){
      qInfo("true");
    }
    else{qInfo("false");}

    display->updateScreen(on);
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


void Device::resetTimeIdle(){

}
