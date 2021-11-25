#ifndef VIEW_H
#define VIEW_H
class MainWindow;
#include "Device.h"
#include "Record.h"

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
