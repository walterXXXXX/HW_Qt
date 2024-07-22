#include <QCoreApplication>
#include <QHostInfo>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHostInfo hostInfo;

    QSqlDatabase sqlDatabase;

    return a.exec();
}
