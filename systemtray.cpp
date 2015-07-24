/*
 * Author: mrnix(mrLinux)_Tri_rom
 * Date : 22 - 7 - 2015
 * pop up a message which contains 5-6 spoken English sentences.
 * With a number of frequencies, you can easily learn by heart that sentences.
 * You'll wonder where I can find it? Don't concern, you can seek
 * from film, music, ... enven from the book that you learned.
 * Let save and pop up up up :)
 * Ps: viết chắc có sai. Luyện viết khó vãi.
*/
#include "systemtray.h"

cSystemTray::cSystemTray():m_layout(this)
{
    //layout
    m_layout.addWidget(&m_buttonOpen);
    m_layout.addWidget(&m_textEdit);
    m_layout.addWidget(&m_buttonShowIcon);
    m_layout.addWidget(&m_buttonShowMessage);

    m_buttonOpen.setText("Open file");
    m_buttonShowIcon.setText("Show Icon");
    m_buttonShowMessage.setText("Show Message");
    //setSize
    m_buttonOpen.setFixedSize(300,50);
    m_buttonShowIcon.setFixedSize(300,50);
    m_buttonShowMessage.setFixedSize(300,50);
    //connect
    QObject::connect(&m_buttonShowIcon,SIGNAL(clicked()),this,SLOT(showIcon()));
    QObject::connect(&m_buttonShowMessage,SIGNAL(clicked()),this,SLOT(showMessage()));
    QObject::connect(&m_buttonOpen,SIGNAL(clicked()),this,SLOT(open()));

    m_notifyIconShow = new QSystemTrayIcon();
    m_notifyIconShow->setIcon(QIcon(":/icon.jpeg"));

}

void cSystemTray::showIcon()
{

    m_notifyIconShow->show();
}

void cSystemTray::showMessage()
{
    QString title("Vocabulary");
    QString message = m_textEdit.toPlainText();
    m_notifyIconShow->showMessage(title,message, QSystemTrayIcon::Information, 20000);
    QTimer *timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(showMessage()));
    timer->start(60*1000);
}

void cSystemTray::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                            tr("Open File"), "",
                            tr("Text Files (*.txt);;All files (*.*)"));
    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"),
            tr("Could not open file"));
            return;
        }
        QString content = file.readAll();
        m_textEdit.setPlainText(content);
        file.close();
    }
}



