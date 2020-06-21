#include "myqmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myQMainWindow w;

    w.show();
    return a.exec();
}
