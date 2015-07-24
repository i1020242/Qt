#include<QApplication>
#include"systemtray.h"


int main(int argv, char** argc)
{
    QApplication a(argv, argc);
    cSystemTray *window = new cSystemTray;
    window->resize(300,400);
    window->setWindowIcon(QIcon(":/icon"));
    window->setWindowTitle("Message SystemTray");
    window->show();
    return a.exec();
}
