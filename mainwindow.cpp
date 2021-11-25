#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new Device();
    view = new View(this, model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete view;
}

