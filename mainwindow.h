#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include “sensor.h”
// TARGET = Test
// target.files = Test
// target.path = /home/root
// INSTALLS += target
// QWS_MOUSE_PROTO = Linuxinput:/dev/input/event0
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void newSensorDataSlot();
    void on_actionExit_triggered();
private:
    Ui::MainWindow *ui;
    Sensor *htu;
    QTimer dataTimer;
};
#endif // MAINWINDOW_H

