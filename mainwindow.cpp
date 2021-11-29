#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new Device(this);
    view = new View(this, model);

    //connecting buttons
    connect(ui->powerPushButton, SIGNAL(released()), model, SLOT(toggle()));
    connect(ui->frequencyPushButton, SIGNAL(released()), model, SLOT(changeFrequency()));
    connect(ui->waveformPushButton, SIGNAL(released()), model, SLOT(changeWaveform()));
    connect(ui->waveformPushButton, SIGNAL(released()), model, SLOT(changeWaveform()));


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
    ui->label_8->setVisible(isOn);
    ui->label_8->setVisible(isOn);
    ui->timer20Label->setVisible(isOn);
    ui->timer40Label->setVisible(isOn);
    ui->timer60Label->setVisible(isOn);
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
}


void MainWindow::on_applyToSkin_stateChanged()
{
    model->toggleTouchingSkin();
}

