#include "Record.h"

Record::Record( QString timeElapsed, QString waveform, double frequency, int duration, int powerLevel) : waveform(waveform), frequency(frequency), duration(duration), powerLevel(powerLevel), timeElapsed(timeElapsed)   {
    addState(waveform, frequency, duration, powerLevel,timeElapsed);
}
Record::Record() {}
Record::~Record()   {
    for(int i=0; i< recordStates.size(); ++i)   {
        delete recordStates.at(i);
    }
}

void Record::addState(QString waveform, double frequency, int duration, int powerLevel, QString timeElapsed) {
    recordStates.append(new State(waveform, frequency, duration, powerLevel,timeElapsed));
}


int Record::getNumStates()  {return recordStates.size();}
QString Record::getRecordData() {
    if(getNumStates()<1)    return "";
    QString s = "";
    State* state = recordStates.at(0);
    s += state->timeElapsed + "\n";
    s += "Waveform: " + state->waveform + "\t";
    s += "Frequency: " + QString::number(state->frequency) + "\n";
    s += "Duration: " + QString::number(state->duration) + "\t\t";
    s += "Current: " +  QString::number(recordStates.at(recordStates.size()-1)->powerLevel) + "\n";
    return s;
}

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
