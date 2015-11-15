#ifndef STREAM_H
#define STREAM_H

#include <QThread>
#include <QWaitCondition>
#include <QImage>

class mystream : public QThread
{
    Q_OBJECT
public:
    mystream(QObject *parent=0);
    void run();
    void execute();
     void execute2();

signals:

public slots:
    void newImage(const QImage img);

private:
    QMutex mutex;
    QWaitCondition cond;
    bool quit;

    FILE *m_ffmpeg;

    // data object
    QImage m_image;
};

#endif // STREAM_H
