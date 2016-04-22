#include "mainwindow.h"
#include "ui_mainwindow.h"
#include “sensor.h”

#define I2CBus      "/dev/i2c-1"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&this->dataTimer, SIGNAL(timeout()), this, SLOT(newSensorDataSlot()));
    this->dataTimer.start(2000);
}
void MainWindow::newSensorDataSlot()
{
   int fd = htu->i2c_Open(I2CBus);
   float myTemp, myHum;
   htu->htu21df_getValue(fd, &myTemp, READ_TEMPERATURE);
   htu->htu21df_getValue(fd, &myHum, READ_HUMIDITY);
   ui->pitchNumber->display(myTemp);
   ui->rollNumber->display(myHum);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionExit_triggered()
{
    close();
}

