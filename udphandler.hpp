#pragma once

#include <QObject>
#include <QUdpSocket>
class UDPHandler : public QObject {
    Q_OBJECT
public:
    explicit UDPHandler(const QString &iface = "usb0", int port = 3000, QObject *parent = nullptr);

    qint64 broadcastData(const QString &iData);

private:
    QUdpSocket *_udpSocket;
    QHostAddress _bcAddress;
    quint16 _port;
    QHostAddress getIfBroadcastAddress(const QString &iInterface);
};
