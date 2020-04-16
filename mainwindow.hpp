#pragma once

#include <QMainWindow>
#include <QKeyEvent>
#include <QSettings>

#define kIFACE_SETTING "iface"
#define kPORT_SETTING "port"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class UDPHandler;
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    UDPHandler *_udpHandler;
    QString _settingsFile;
    QSettings *_settings;
    int _bindPort;
    QString _ifaceName;
};
