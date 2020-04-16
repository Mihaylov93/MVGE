#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "udphandler.hpp"

#include <QtDebug>
#include <QMetaEnum>
#include <QMessageBox>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 320, 240);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    _settingsFile = QDir::currentPath() + "/config.ini";
    _settings = new QSettings(_settingsFile, QSettings::IniFormat);
    const QString mIface = _settings->value(kIFACE_SETTING, "").toString();
    const QString mPort = _settings->value(kPORT_SETTING, "").toString();
    _ifaceName = "usb0";
    _bindPort = 3000;
    if (mIface != "") _ifaceName = mIface;
    if (mPort != "") _bindPort = mPort.toInt();
    _udpHandler = new UDPHandler(_ifaceName, _bindPort, this);

    this->setFocus();
}

MainWindow::~MainWindow()
{
    _settings->setValue(kIFACE_SETTING, _ifaceName);
    _settings->setValue(kPORT_SETTING, QString::number(_bindPort));
    _settings->sync();
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *iKeyEvent)
{
    const QString mKey(QMetaEnum::fromType<Qt::Key>().valueToKey(iKeyEvent->key()));
    qDebug() << "Key: " << mKey << "Pressed!";
    switch (iKeyEvent->key()) {
        case Qt::Key_Up:
            ui->pbUp->setChecked(true);
            break;
        case Qt::Key_Down:
            ui->pbDown->setChecked(true);
            break;
        case Qt::Key_Right:
            ui->pbRight->setChecked(true);
            break;
        case Qt::Key_Left:
            ui->pbLeft->setChecked(true);
            break;
        case Qt::Key_U:
            ui->pbX->setChecked(true);
            break;
        case Qt::Key_I:
            ui->pbY->setChecked(true);
            break;
        case Qt::Key_J:
            ui->pbA->setChecked(true);
            break;
        case Qt::Key_K:
            ui->pbB->setChecked(true);
            break;
        case Qt::Key_Escape:
            ui->pbMenu->setChecked(true);
            break;
        case Qt::Key_Space:
            ui->pbSelect->setChecked(true);
            break;
        case Qt::Key_Return:
            ui->pbStart->setChecked(true);
            break;
        case Qt::Key_Y:
            ui->pbX->setChecked(true);
            break;
        case Qt::Key_O:
            ui->pbY->setChecked(true);
            break;
        case Qt::Key_H:
            ui->pbA->setChecked(true);
            break;
        case Qt::Key_L:
            ui->pbB->setChecked(true);
            break;
        case Qt::Key_Minus:
            ui->pbSelect->setChecked(true);
            break;
        case Qt::Key_Plus:
            ui->pbStart->setChecked(true);
            break;
    }
    _udpHandler->broadcastData(mKey + ":1");
}

void MainWindow::keyReleaseEvent(QKeyEvent *iKeyEvent)
{
    const QString mKey(QMetaEnum::fromType<Qt::Key>().valueToKey(iKeyEvent->key()));
    qDebug() << "Key: " << mKey << "Released!";
    switch (iKeyEvent->key()) {
        case Qt::Key_Up:
            ui->pbUp->setChecked(false);
            break;
        case Qt::Key_Down:
            ui->pbDown->setChecked(false);
            break;
        case Qt::Key_Right:
            ui->pbRight->setChecked(false);
            break;
        case Qt::Key_Left:
            ui->pbLeft->setChecked(false);
            break;
        case Qt::Key_U:
            ui->pbX->setChecked(false);
            break;
        case Qt::Key_I:
            ui->pbY->setChecked(false);
            break;
        case Qt::Key_J:
            ui->pbA->setChecked(false);
            break;
        case Qt::Key_K:
            ui->pbB->setChecked(false);
            break;
        case Qt::Key_Escape:
            ui->pbMenu->setChecked(false);
            break;
        case Qt::Key_Space:
            ui->pbSelect->setChecked(false);
            break;
        case Qt::Key_Return:
            ui->pbStart->setChecked(false);
            break;
        case Qt::Key_Y:
            ui->pbX->setChecked(false);
            break;
        case Qt::Key_O:
            ui->pbY->setChecked(false);
            break;
        case Qt::Key_H:
            ui->pbA->setChecked(false);
            break;
        case Qt::Key_L:
            ui->pbB->setChecked(false);
            break;
        case Qt::Key_Minus:
            ui->pbSelect->setChecked(false);
            break;
        case Qt::Key_Plus:
            ui->pbStart->setChecked(false);
            break;
        case Qt::Key_Backspace:
            ui->pbStart->setChecked(false);
            // Shift+menu to exit
            const QMessageBox::StandardButton mConfirm
                = QMessageBox::question(this, "Exit MVGE?", "Press [Start] to confirm, or [Menu] to cancel.",
                                        QMessageBox::Yes | QMessageBox::No);
            if (mConfirm == QMessageBox::Yes) QApplication::quit();

            break;
    }
    _udpHandler->broadcastData(mKey + ":0");
}
