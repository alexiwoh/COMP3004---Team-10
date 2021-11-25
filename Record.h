#ifndef RECORD_H
#define RECORD_H
#include <QString>

class Record
{
    public:
        Record(QString waveform = "alpha", double frequency = 0.5, int duration = 0, int powerLevel = 0);
    private:
        QString waveform;
        double frequency;
        int duration, powerLevel;
};

#endif // RECORD_H
