/*
 * Author: mrnix_Tri_rom
 * Date : 22 - 7 - 2015
 * pop up frequently a message which contains 5-6 spoken English sentences.
 * so that you can easily learn by heart that sentences.
 * (ex: you open com 8h per day so you have 8*60/5 sentences per
 * "day 5 minutes popup once").
 * You'll wonder where I can find source? Don't concern about this, you can seek
 * from film, music, ... enven from the ebook that you learned.
 * My source are found almost from film.
 * Let save and pop up up up :)
 * Ps: Improving writing skill so hard. :(
*/
#include "systemtray.h"

cSystemTray::cSystemTray(QWidget* parent):QWidget(parent)
{
    //layout
    m_layout = new QVBoxLayout(this);
    m_textEdit = new QTextEdit(this);
    m_buttonOpen = new QPushButton(this);
    m_buttonShowIcon = new QPushButton(this);
    m_buttonShowMessage = new QPushButton(this);
    m_spinBoxDuration = new QSpinBox(this);

    m_layout->addWidget(m_buttonOpen);
    m_layout->addWidget(m_spinBoxDuration);
    m_layout->addWidget(m_textEdit);
    m_layout->addWidget(m_buttonShowIcon);
    m_layout->addWidget(m_buttonShowMessage);


    m_buttonOpen->setText("Open file");
    m_buttonShowIcon->setText("Show Icon");
    m_buttonShowMessage->setText("Show Message");
    m_spinBoxDuration->setSuffix("s");
    m_spinBoxDuration->setValue(30);
    m_spinBoxDuration->setRange(1,120);

    //setSize
    m_buttonOpen->setFixedSize(300,50);
    m_buttonShowIcon->setFixedSize(300,50);
    m_buttonShowMessage->setFixedSize(300,50);
    //connect
    QObject::connect(m_buttonShowIcon,SIGNAL(clicked()),this,SLOT(showIcon()));
    QObject::connect(m_buttonShowMessage,SIGNAL(clicked()),this,SLOT(showMessage()));
    QObject::connect(m_buttonOpen,SIGNAL(clicked()),this,SLOT(open()));
    //slot open(); được khai báo ở class nào thì this là con trỏ
    //tới object đc tạo ra từ class
    m_notifyIconShow = new QSystemTrayIcon(this);
    m_notifyIconShow->setIcon(QIcon(":/icon.jpeg"));

}

void cSystemTray::showIcon()
{

    m_notifyIconShow->show();
}

void cSystemTray::showMessage()
{
    QString title("Vocabulary");
    qint8 getDuration = m_spinBoxDuration->value();
    qint32 duration = getDuration*1000;
    QString message = m_textEdit->toPlainText();
    m_notifyIconShow->showMessage(title,message, QSystemTrayIcon::Information, duration);
    QTimer::singleShot(5*60*1000,this,SLOT(showMessage()));
}

void cSystemTray::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                            tr("Open File"), "/home/mrnix/ENG/englishEveryDay.txt",
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
        m_textEdit->setPlainText(content);
        file.close();
    }
}



