#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QWebSocket>

class websocketclient : public QObject
{
    Q_OBJECT
public:
    explicit websocketclient(const QUrl &url, bool debug=false, QObject *parent= Q_NULLPTR);

signals:
    void closed();
    void textMessageReceived(QString message);

public slots:
    void onConnected();
    void onTextMessageReceived(QString message);
    void onSendButton(QString message);

private:
    QWebSocket m_websocket;
    QUrl m_url;
    bool m_debug;
};

#endif // WEBSOCKETCLIENT_H
