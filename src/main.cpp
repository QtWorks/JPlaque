#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWindow   window;

    window.setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    window.show();

    return app.exec();
}
