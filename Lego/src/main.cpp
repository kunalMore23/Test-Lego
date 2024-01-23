#include "stdafx.h"
#include "Lego.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication legoApp(argc, argv);
    Lego legoObject;
    legoObject.show();
    return legoApp.exec();
}