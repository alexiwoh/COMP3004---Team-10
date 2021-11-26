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

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete view;
}


void MainWindow::updateFrequency()
{
    qInfo("test 2");
    ui->frequencyLabel->setText(QString::number(model->getFrequency()));
}

void MainWindow::updateScreen(bool x)
{
    qInfo("Screenupdating");
    ui->label_10->setVisible(x);
    ui->label_11->setVisible(x);
    ui->label_12->setVisible(x);
    ui->label_6->setVisible(x);
    ui->label_7->setVisible(x);
    ui->label_8->setVisible(x);
    ui->label_9->setVisible(x);
    ui->powerLevelProgressBar->setVisible(x);
    ui->label_8->setVisible(x);
    ui->label_8->setVisible(x);
    ui->timer20Label->setVisible(x);
    ui->timer40Label->setVisible(x);
    ui->timer60Label->setVisible(x);
    ui->timerLCDNumber->setVisible(x);
    ui->waveformLabel->setVisible(x);
    ui->frequencyLabel->setVisible(x);
    ui->frequencyLabel_2->setVisible(x);
    ui->batteryLabel->setVisible(x);


    ui->recordPushButton->setEnabled(x);
    ui->waveformPushButton->setEnabled(x);
    ui->timerPushButton->setEnabled(x);
    ui->upPushButton->setEnabled(x);
    ui->downPushButton->setEnabled(x);
    ui->frequencyPushButton->setEnabled(x);
}

