#ifndef TRIPSERVER_H
#define TRIPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TripServer : public QTcpServer
{
    Q_OBJECT
public:
    TripServer(QObject * parent = 0);
private:
    void incomingConnection(qintptr handle);
};

class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket(QObject *parent = 0);

private slots:
    void readClient();
private:
    void generateRandomTrip(const QString & from, const QString & to,
                            const QDate & date, const QTime & time);
    quint16 nextBlockSize;
};

#endif // TRIPSERVER_H
