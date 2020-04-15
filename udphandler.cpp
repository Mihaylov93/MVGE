#include "udphandler.hpp"

#include <QNetworkInterface>
UDPHandler::UDPHandler(const QString& iface, int port, QObject* parent) :
    QObject(parent), _port(static_cast<quint16>(port))
{
    _udpSocket = new QUdpSocket(this);

    _bcAddress = getIfBroadcastAddress(iface);

    qDebug() << "Bind: " << _udpSocket->bind(_bcAddress, _port);
}

qint64 UDPHandler::broadcastData(const QString& iData)
{
    QByteArray mData;
    mData.append(iData);

    return _udpSocket->writeDatagram(mData, _bcAddress, _port);
}

QHostAddress UDPHandler::getIfBroadcastAddress(const QString& iInterface)
{
    foreach (const QNetworkInterface& networkInterface, QNetworkInterface::allInterfaces()) {
        if (networkInterface.name() == iInterface) {
            return networkInterface.addressEntries().at(0).broadcast();
        }
    }
    return QHostAddress::Null;
}
