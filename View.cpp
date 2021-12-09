#include "View.h"

View::View(MainWindow *mainWindow, Device *model)   {
    this->mainWindow = mainWindow;
    this->model = model;
}

View::~View()   {}

MainWindow* View::getMainWindow()   {return mainWindow;}
Device* View::getModel()    {return model;}
void View::setMainWindow(MainWindow* mainWindow)    {this->mainWindow = mainWindow;}
void View::setModel(Device* model)  {this->model = model;}
