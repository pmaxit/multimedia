#include "mystream.h"
#include <QDebug>
#include <stdio.h>
mystream::mystream(QObject *parent):QThread(parent)
{
    quit = false;

    //const char* cmd = "ffmpeg -r 60 -f rawvideo -pix_fmt rgba -s 1280x720 -i - "
                        "-threads 0 -preset fast -y -pix_fmt yuv420p -crf 21 -vf vflip output.mp4";

    const char *cmd = "sort";
    m_ffmpeg = popen(cmd,"w");
}

void mystream::newImage(const QImage img){
    qDebug()<<"Got the new Image" << img.width()<<img.height()<<endl;
    m_image = img;
    cond.wakeAll();
}

void mystream::execute2(){
    uchar *ptr = m_image.bits();
    int width = m_image.width();
    int height = m_image.height();


    m_image.save("/Users/puneet/Projects/test.png");

    uchar *data = m_image.bits();
    fwrite(data, width * height * 4, 1, stdout);
    /*
    for(int i=0; i< height; i++){
        for(int j=0; j< width*4; j++){
            printf("%u ", ptr[width*i + j]);
        }
        printf("\n");
    }
    */

    //char *data = "echo";
    //fwrite(ptr, width*height*4,1, m_ffmpeg);
    //fwrite(data, strlen(data), 1, m_ffmpeg);
    pclose(m_ffmpeg);
}

void mystream::execute(){
    char *line;
    int read;
    size_t len;
    qDebug()<<"executing "<<endl;
    while((read = getline(&line, &len, m_ffmpeg)) != -1)
        qDebug()<<line<<endl;

    return;
}

void mystream::run(){

    qDebug()<<"starting thread"<<endl;


    while(!quit){
        mutex.lock();
        // get some critical data here.
        qDebug()<<"wait for signal"<<endl;
        cond.wait(&mutex);
        mutex.unlock();

        execute2();
    }
}
