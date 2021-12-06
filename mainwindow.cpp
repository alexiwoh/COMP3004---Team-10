#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "Record.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    model = new Device(this);
    view = new View(this, model);

    //setup inital LEDs
    updateRecordingLED(true);
    updateCircuitLED(false);
    updateBatteryLED(false);

    //connecting buttons
    connect(ui->powerPushButton, SIGNAL(released()), model, SLOT(toggle()));
    connect(ui->recordPushButton, SIGNAL(released()), model, SLOT(toggleRecording()));
    connect(ui->frequencyPushButton, SIGNAL(released()), model, SLOT(changeFrequency()));
    connect(ui->waveformPushButton, SIGNAL(released()), model, SLOT(changeWaveform()));
    connect(ui->timerPushButton, SIGNAL(released()), model, SLOT(changeTime()));
    connect(ui->upPushButton, SIGNAL(released()), model, SLOT(changeCurrentUp()));
    connect(ui->downPushButton, SIGNAL(released()), model, SLOT(changeCurrentDown()));
    connect(ui->batterySpinBox, SIGNAL(valueChanged(int)), model, SLOT(on_batterySpinBox_valueChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete view;
}

void MainWindow::updateRecordText()
{
    ui->recordsTextEdit->setPlainText(model->getRecordsAsText());
}

void MainWindow::updateFrequency()
{
    ui->frequencyLabel->setText(QString::number(model->getFrequency()));
}

void MainWindow::updateWaveform()
{
    ui->waveformLabel->setText(model->getWaveform());
}

void MainWindow::updateTime()
{
    ui->timeLabel->setText(QString::number(model->getTime()));
}

void MainWindow::updateTimer(){
    QTime timeLED(0, 0, 0);
    timeLED = timeLED.addSecs(int(model->getCountDown()));

    //timeLED = QTime::currentTime();
    QString timeDisplay = timeLED.toString("s");
    ui->timerLCDNumber->display(timeDisplay);
}

void MainWindow::updateCurrent()
{
    ui->powerLevelProgressBar->setValue(model->getCurrent());
}

void MainWindow::updateBattery()
{
    ui->batteryLabel->setText(QString::number(model->getBattery()) + "%");
    on_batterySpinBox_valueChanged(model->getBattery());
}

void MainWindow::updateScreen(bool isOn)
{
    qInfo("Screenupdating");
    ui->label_10->setVisible(isOn);
    ui->label_11->setVisible(isOn);
    ui->label_12->setVisible(isOn);
    ui->label_6->setVisible(isOn);
    ui->label_7->setVisible(isOn);
    ui->label_8->setVisible(isOn);
    ui->label_9->setVisible(isOn);
    ui->powerLevelProgressBar->setVisible(isOn);
    ui->timeLabel->setVisible(isOn);
    ui->timerLCDNumber->setVisible(isOn);
    ui->waveformLabel->setVisible(isOn);
    ui->frequencyLabel->setVisible(isOn);
    ui->frequencyLabel_2->setVisible(isOn);
    ui->batteryLabel->setVisible(isOn);
    ui->recordingLED->setVisible(isOn);
    ui->circuitCheckLED_2->setVisible(false);

    ui->recordPushButton->setEnabled(isOn);
    ui->waveformPushButton->setEnabled(isOn);
    ui->timerPushButton->setEnabled(isOn);
    ui->upPushButton->setEnabled(isOn);
    ui->downPushButton->setEnabled(isOn);
    ui->frequencyPushButton->setEnabled(isOn);
    ui->applyToSkin->setEnabled(isOn);

    ui->applyToSkin->setChecked(false);

    updateCurrent();
    updateFrequency();
    updateWaveform();
    updateTime();
}

void MainWindow::updateRecordingLED(bool recording)
{
    ui->recordingLED->setVisible(recording);
}

void MainWindow::updateCircuitLED(bool isTouchingSkin)
{
    ui->circuitCheckLED_2->setVisible(isTouchingSkin);
}

void MainWindow::updateBatteryLED(bool lowBattery)
{
    ui->batteryLED_2->setVisible(lowBattery);
}

void MainWindow::updateApplyToSkin(bool apply)
{
    ui->applyToSkin->setChecked(apply);
}

void MainWindow::on_applyToSkin_stateChanged()
{
    if (ui->applyToSkin->isChecked() == true) {
        model->toggleTouchingSkin();
        if(model->getRecording())    model->updateRecords();
        ui->recordsTextEdit->setPlainText(model->getRecordsAsText());
    }
}

void MainWindow::on_batterySpinBox_valueChanged(int battery)
{
    model->setBatteryPercentage(battery);
    ui->batteryLabel->setText(QString::number(model->getBattery()) + "%");
}

void MainWindow::on_faultButton_clicked()
{
    model->toggle();
}


