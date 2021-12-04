/*
 * Record class keeps track of the Device variables (states) so they can later be printed.
*/

#ifndef RECORD_H
#define RECORD_H
#include <QString>
#include <QList>

class Record
{
    public:
        Record(QString timeElapsed, QString waveform = "alpha", double frequency = 0.5, int duration = 0, int powerLevel = 0);
        Record();
        ~Record();

        // Getters/Setters.
        double getFrequency();
        int getDuration();
        int getPower();
        QString getWaveform();
        int getNumStates();
        QString getRecordData();
        void setFrequency(double);
        void setDuration(int);
        void setPower(int);
        void setWaveform(QString);

        // Saves the Device's variables into the list.
        void addState(QString waveform, double frequency, int duration, int powerLevel, QString timeElapsed);
        class State {
            // Represents a state of the Record: all the device variables.
            public:
                State(QString waveform, double frequency, int duration, int powerLevel, QString timeElapsed) :
                    waveform(waveform), frequency(frequency), duration(duration), powerLevel(powerLevel), timeElapsed(timeElapsed) {}

                QString waveform;
                double frequency;
                int duration, powerLevel;
                QString timeElapsed;
        };

    private:
        // Initial Record variables.
        QString waveform;
        double frequency;
        int duration, powerLevel;
        QString timeElapsed;

        QList<State*> recordStates; // List of Record states.

};

#endif // RECORD_H
