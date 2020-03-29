#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include <QtDebug>
#include <QMetaEnum>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 320, 240);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *iKeyEvent)
{
    const QString mkey(QMetaEnum::fromType<Qt::Key>().valueToKey(iKeyEvent->key()));
    qDebug() << "Key: " << mkey << "Pressed!";
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
        case Qt::Key_Enter:
            ui->pbStart->setChecked(true);
            break;
        default:
            Q_ASSERT_X(false, "MainWindow::keyPressEvent - default case: No implementation for ",
                       mkey.toStdString().c_str());
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *iKeyEvent)
{
    const QString mkey(QMetaEnum::fromType<Qt::Key>().valueToKey(iKeyEvent->key()));
    qDebug() << "Key: " << mkey << "Released!";
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
        case Qt::Key_Enter:
            ui->pbStart->setChecked(false);
            break;
        default:
            Q_ASSERT_X(false, "MainWindow::keyReleaseEvent - default case: No implementation for ",
                       mkey.toStdString().c_str());
    }
}
