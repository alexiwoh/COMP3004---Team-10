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

    //model->toggle(); // turn device off at the start
    updateRecordingLED(true);

    time.setHMS(0,model->getTime(), 0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

    timerUpdate();

    //connecting buttons
    //connect(ui->powerPushButton, SIGNAL(released()), model, SLOT(toggle()));
    connect(ui->powerPushButton, SIGNAL(released()), this, SLOT(on_power_off()));
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

void MainWindow::updateCurrent()
{
    ui->powerLevelProgressBar->setValue(model->getCurrent());
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

    ui->recordPushButton->setEnabled(isOn);
    ui->waveformPushButton->setEnabled(isOn);
    ui->timerPushButton->setEnabled(isOn);
    ui->upPushButton->setEnabled(isOn);
    ui->downPushButton->setEnabled(isOn);
    ui->frequencyPushButton->setEnabled(isOn);
    ui->applyToSkin->setEnabled(isOn);

    updateCurrent();
    updateFrequency();
    updateWaveform();
    updateTime();



}

void MainWindow::updateRecordingLED(bool recording)
{
    //ui->recordingLED->setStyleSheet("background-color: red");
    ui->recordingLED->setVisible(recording);
}

void MainWindow::on_applyToSkin_stateChanged()
{
    model->toggleTouchingSkin();
    model->updateRecords();
    ui->recordsTextEdit->setPlainText(model->getRecordsAsText());
    qInfo("TEST2");
}

void MainWindow::timerUpdate(){
    //model->updateRecords();
    model->updateTimes();
  if(model->getSkin()){

    if(model->getBattery() == 0){
        updateScreen(false);
    }
      else{batteryDrain();}

    time = time.addSecs(-1);
    QString timeDisplay = time.toString("m:ss");
    ui->timerLCDNumber->display(timeDisplay);

  }

}

void MainWindow::on_batterySpinBox_valueChanged(int battery)
{
    model->setBatteryPercentage(battery);
    ui->batteryLabel->setText(QString::number(model->getBattery()) + "%");
}

void MainWindow::batteryDrain(){

    int batteryLevel = (model->getBattery() -1);
    on_batterySpinBox_valueChanged(batteryLevel);
}



void MainWindow::on_faultButton_clicked()
{
    model->shutDown();
}

void MainWindow::on_power_off() {
    model->toggle();
    ui->applyToSkin->setChecked(false);
}

