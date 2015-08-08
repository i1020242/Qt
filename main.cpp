#include"systemtray.h"


int main(int argv, char** argc)
{
    QApplication a(argv, argc);
    cSystemTray window;
    window.setWindowTitle("SystemTray Application");
    window.setWindowIcon(QIcon(":/icon.jpeg"));
    window.show();

    return a.exec();
}
