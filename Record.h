#ifndef RECORD_H
#define RECORD_H
#include <QString>

class Record
{
    public:
        Record(QString waveform = "alpha", double frequency = 0.5, int duration = 0, int powerLevel = 0);
        double getFrequency();
        int getDuration();
        int getPower();
        QString getWaveform();
        void setFrequency(double);
        void setDuration(int);
        void setPower(int);
        void setWaveform(QString);
    private:
        QString waveform;
        double frequency;
        int duration, powerLevel;
};

#endif // RECORD_H
