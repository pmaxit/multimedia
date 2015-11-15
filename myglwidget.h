#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QGLShaderProgram>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLTexture>
#include <QOpenGLFramebufferObject>

class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    MyGLWidget(QWidget *parent);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

signals:

public slots:


private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;
    QVector<QVector3D> colors;
    QVector<QVector3D> textureCoordinates;

    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;
    QOpenGLTexture * texture;


    /* Extra variables needed */
    GLint viewport[4];
};

#endif // MYGLWIDGET_H
