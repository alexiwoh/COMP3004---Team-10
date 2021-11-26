#include "Record.h"

Record::Record(QString waveform, double frequency, int duration, int powerLevel) :
    waveform(waveform), frequency(frequency), duration(duration), powerLevel(powerLevel)    {}

double Record::getFrequency(){
  return frequency;
}

int Record::getDuration(){
  return duration;
}

int Record::getPower(){
  return powerLevel;
}

QString Record::getWaveform(){
  return waveform;
}

void Record::setPower(int p){
  powerLevel = p;
}

void Record::setDuration(int d){
  duration = d;
}

void Record::setFrequency(double f){
  frequency = f;
}

void Record::setWaveform(QString w){
  waveform = w;
}
