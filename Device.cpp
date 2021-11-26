#include "Device.h"
//testing if my uploading works  --sadiq

Device::Device(MainWindow* mainWindow)
{
    display = mainWindow;
    frequency = 0.5;
    numRecords = 0;
    on = true;
}

Device::~Device(){
  for(int i = 0; i<numRecords; i++){
    delete records[i];
  }
}

//Setters
void Device::setBatteryPercentage(double per){

}

void Device::setFrequency(double freq){
    frequency = freq;
}

void Device::setCurrent(double cur){

}

void Device::setWaveform(QString const wave){

}



//Getters
double Device::getBattery(){

}

double Device::getFrequency(){
    return frequency;
}

double Device::getCurrent(){

}

QString Device::getWaveform(){

}

//functions

void Device::toggleTouchingSkin(){

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
    qInfo("TEST");
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

void Device::resetTimeIdle(){

}
