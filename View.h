#ifndef VIEW_H
#define VIEW_H

#include "Device.h"
#include "Record.h"

class MainWindow;
class Device;

class View {
    public:
        View(MainWindow* mainWindow, Device* model);
        ~View();
        MainWindow* getMainWindow();
        Device* getModel();
        void setMainWindow(MainWindow* mainWindow);
        void setModel(Device* model);

    private:
        MainWindow *mainWindow;
        Device *model;

};

#endif // VIEW_H
