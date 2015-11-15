#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mystream.h"
#include "websocketclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    bool eventFilter(QObject *, QEvent *);

signals:
    void newImage(const QImage img);

public slots:
    void onTextMessageReceived(QString message);

private:
    Ui::MainWindow *ui;
    mystream *thread;

    websocketclient *m_websocketclient;
};

#endif // MAINWINDOW_H
