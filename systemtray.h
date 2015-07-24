#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QString>
#include <QFile>
#include <QTimer>
#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>

class cSystemTray: public QWidget
{
    Q_OBJECT
public:
    cSystemTray();
    void openFile();
public slots:
    void showIcon();
    void showMessage();
    void open();
private:
    QVBoxLayout m_layout;
    QPushButton m_buttonOpen,m_buttonShowMessage,m_buttonShowIcon;
    QTextEdit m_textEdit;
    QSystemTrayIcon *m_notifyIconShow;
};

#endif // SYSTEMTRAY_H
