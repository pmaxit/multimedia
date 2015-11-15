#include "websocketclient.h"

websocketclient::websocketclient(const QUrl &url, bool debug, QObject *parent):
    QObject(parent), m_url(url), m_debug(debug)
{
    if(m_debug)
        qDebug()<<" Web socket server: "<<url;

    connect(&m_websocket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(&m_websocket, SIGNAL(disconnected()), this, SIGNAL(closed()));

    m_websocket.open(QUrl(url));
}

void websocketclient::onConnected(){
    if(m_debug)
        qDebug()<<"Web socket connected"<<endl;

    connect(&m_websocket, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
    connect(&m_websocket, SIGNAL(textMessageReceived(QString)), this, SIGNAL(textMessageReceived(QString)));

    m_websocket.sendTextMessage(QStringLiteral("Hello world !"));
}

void websocketclient::onSendButton(QString message){
    if(m_debug)
        qDebug()<<"Sending message"<<message<<endl;

    m_websocket.sendTextMessage(message);
}

void websocketclient::onTextMessageReceived(QString message){
    if(m_debug)
        qDebug()<<" Message received"<<message<<endl;


}
