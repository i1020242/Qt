#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H
#include <QPushButton>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QString>
#include <QFile>
#include <QTimer>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QApplication>

#include <QSpinBox>

class cSystemTray: public QWidget
{
    Q_OBJECT
public:
    cSystemTray(QWidget* parent = 0);
    void openFile();
public slots:
    void showIcon();
    void showMessage();
    void open();
private:
    QVBoxLayout *m_layout;
    QPushButton *m_buttonOpen, *m_buttonShowMessage, *m_buttonShowIcon;
    QTextEdit *m_textEdit;
    QSystemTrayIcon *m_notifyIconShow;
    QSpinBox* m_spinBoxDuration;
};

#endif // SYSTEMTRAY_H
