#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "tripserver.h"
#include "credirectostream.h"
#include <memory>

int main(int argc, char *argv[])
{
    std::unique_ptr<CRedirectOStream> ptrCRedirectOStream(new CRedirectOStream(stderr));
    QApplication a(argc, argv);
    TripServer server;
    std::cerr << "hello" << std::endl;
    if(!server.listen(QHostAddress::Any, 6178)){
       std::cerr << "Failed to bind port" << std::endl;
       return 1;
    }
    QPushButton quitButton(QObject::tr("&Quit"));
    quitButton.setWindowTitle(QObject::tr("Trip Server"));
    QObject::connect(&quitButton, SIGNAL(clicked()), &a, SLOT(quit()));
    quitButton.show();
    return a.exec();
}
