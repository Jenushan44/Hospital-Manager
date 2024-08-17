#include "mainwindow.h"
#include "dbManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DbManager dbManager("hospital.db");
    MainWindow w;
    w.show();
    return a.exec();
}
