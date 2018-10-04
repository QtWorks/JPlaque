#include "mainwindow.h"
#include <QApplication>

QString loadStylesheet( QString filename ){
    QFile file(filename);
    if (!file.open(QFile::ReadOnly)){
        std::cout << file.errorString().toStdString() << std::endl;
    }
    QString stylesheet = QLatin1String(file.readAll());
    return stylesheet;
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWindow   window;

    window.setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    app.setStyleSheet(loadStylesheet(":/styles/global.css"));
    window.show();    

    return app.exec();
}
