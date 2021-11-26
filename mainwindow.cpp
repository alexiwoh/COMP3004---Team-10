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
