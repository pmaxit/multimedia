#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_websocketclient = new websocketclient(QUrl(QStringLiteral("ws://localhost:8081")), true, this);
    connect(m_websocketclient, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));

    setFixedSize(662, 536);

    //ui->openGLWidget->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event){
    switch(event->type()){

    case QEvent::Wheel :
            wheelEvent((QWheelEvent *)event);
            break;

    case QEvent::MouseButtonPress:
            mousePressEvent((QMouseEvent *)event);
            break;

    case QEvent::MouseMove:
            mouseMoveEvent((QMouseEvent *)event);
            break;
    }

    return QObject::eventFilter(object, event);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape)
        close();
}

void MainWindow::mousePressEvent(QMouseEvent *event){

}

void MainWindow::mouseMoveEvent(QMouseEvent *event){

}

void MainWindow::onTextMessageReceived(QString message){



    QStringList list = message.split(" ");
    if(list[0] == "1"){

        qDebug()<<" 1 category"<<list[1]<<"  "<<list[2]<<endl;
        int x = list[1].toInt();
        int y = list[2].toInt();
        QMouseEvent *event = new QMouseEvent(QEvent::MouseButtonPress, QPoint(x,y), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

        ui->openGLWidget->mousePressEvent(event);
    }
    else if(list[0] == "2"){
        qDebug()<<" 2 category"<<list[1]<<"   "<<list[2]<<endl;

        int x = list[1].toInt();
        int y = list[2].toInt();
        QMouseEvent *event = new QMouseEvent(QEvent::MouseMove, QPoint(x,y), Qt::NoButton, Qt::LeftButton, Qt::NoModifier);

        ui->openGLWidget->mouseMoveEvent(event);
    }
    else if(list[0] == "3"){
        qDebug()<<" 3 category"<<endl;
        int x = list[1].toInt();
        QWheelEvent *event = new QWheelEvent(QPoint(0, 0), x, Qt::LeftButton,
                                             Qt::NoModifier, Qt::Vertical );
        ui->openGLWidget->wheelEvent(event);
    }

}

void MainWindow::wheelEvent(QWheelEvent *event){
    //qDebug()<<" mouse wheel event "<<endl;
    m_websocketclient->onSendButton("wheel");
}
