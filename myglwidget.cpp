#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent):QOpenGLWidget(parent),texture(0)
{

    vertices << QVector3D(-0.5, -0.5, 0.5) << QVector3D( 0.5, -0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) // Front
    << QVector3D( 0.5, 0.5, 0.5) << QVector3D(-0.5, 0.5, 0.5) << QVector3D(-0.5, -0.5, 0.5)
    << QVector3D( 0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, 0.5, -0.5) // Back
    << QVector3D(-0.5, 0.5, -0.5) << QVector3D( 0.5, 0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5)
    << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, 0.5) << QVector3D(-0.5, 0.5, 0.5) // Left
    << QVector3D(-0.5, 0.5, 0.5) << QVector3D(-0.5, 0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5)
    << QVector3D( 0.5, -0.5, 0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, 0.5, -0.5) // Right
    << QVector3D( 0.5, 0.5, -0.5) << QVector3D( 0.5, 0.5, 0.5) << QVector3D( 0.5, -0.5, 0.5)
    << QVector3D(-0.5, 0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) << QVector3D( 0.5, 0.5, -0.5) // Top
    << QVector3D( 0.5, 0.5, -0.5) << QVector3D(-0.5, 0.5, -0.5) << QVector3D(-0.5, 0.5, 0.5)
    << QVector3D(-0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, 0.5) // Bottom
    << QVector3D( 0.5, -0.5, 0.5) << QVector3D(-0.5, -0.5, 0.5) << QVector3D(-0.5, -0.5, -0.5);


    colors << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Front
    << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
    << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Back
    << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
    << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Left
    << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
    << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Right
    << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
    << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Top
    << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
    << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Bottom
    << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1);

    textureCoordinates << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Front
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Back
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Left
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Right
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Top
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Bottom
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0);

    alpha = 25;
    beta = -25;
    distance = 2.5;

}

void MyGLWidget::initializeGL(){

    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
   // glPixelStorei(GL_PACK_ALIGNMENT, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(1.0, 0.0, 0.0, 1.0);

    texture = new QOpenGLTexture(QImage(":/sources/opengl_rt0.png").mirrored());

    // set the nearest filtering mode for texture minification
    texture->setMinificationFilter(QOpenGLTexture::Nearest);

    // set bilinear filtering mode for texture magnification
    texture->setMagnificationFilter(QOpenGLTexture::Linear);

    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/sources/simple_vertex_shader.vsh");
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment,":/sources/simple_fragment_shader.fsh");
    shaderProgram.link();


}

void MyGLWidget::resizeGL(int width, int height){
    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width/ (float)height, 0.001, 1000);
    glViewport(0, 0, width, height);
}


void MyGLWidget::paintGL(){
    //m_fbo->bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);   // make current texture unit active
    texture->bind();                // glBindTexture(GL_TEXTURE_2D, textureID)

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 0 , 1, 0);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpPosition = cameraTransformation * QVector3D(0, 1, 0);

    vMatrix.lookAt( cameraPosition, QVector3D(0, 0, 0), cameraUpPosition);

    shaderProgram.bind();

    shaderProgram.setUniformValue("u_mvpMatrix", pMatrix* vMatrix * mMatrix);
    shaderProgram.setUniformValue("u_color", QColor(Qt::white));

    shaderProgram.setAttributeArray("a_vertex", vertices.constData());
    shaderProgram.enableAttributeArray("a_vertex");

    shaderProgram.setAttributeArray("a_color", colors.constData());
    shaderProgram.enableAttributeArray("a_color");

    shaderProgram.setAttributeArray("a_texcoord", textureCoordinates.constData());
    shaderProgram.enableAttributeArray("a_texcoord");

    shaderProgram.setUniformValue("u_texture", 0);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    shaderProgram.disableAttributeArray("a_vertex");
    shaderProgram.disableAttributeArray("a_color");
    shaderProgram.release();


    glFinish();

    glGetIntegerv(GL_VIEWPORT, viewport);
    int width = viewport[2]*3;
    width = (width + 3) & ~3;
    int bitsize = width * viewport[3];

    static uchar *framedata = new uchar[bitsize];

    glPixelStorei(GL_PACK_ALIGNMENT, 4); /* Force 4-byte alignment */

    glReadPixels(0, 0, viewport[2], viewport[3], GL_RGB, GL_UNSIGNED_BYTE,
                    framedata);

    fwrite(framedata, 1, bitsize, stdout);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event){
    lastMousePosition = event->pos();

    event->accept();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event){

    int deltax = event->x() - lastMousePosition.x();
    int deltay = event->y() - lastMousePosition.y();

    if(1 || event->buttons() & Qt::LeftButton){
        alpha -= deltax;
        if(alpha<0)
            alpha+= 360;

        if(alpha >=360)
            alpha -= 360;

        beta -= deltay;

        if(beta < -90)
            beta = -90;

        if(beta > 90)
            beta = 90;

        update();
    }
    lastMousePosition = event->pos();

    event->accept();

}

void MyGLWidget::wheelEvent(QWheelEvent *event){

    int delta = event->delta();
    if(event->orientation() == Qt::Vertical){
        if(delta < 0)
            distance *= 1.1;
        else if (delta > 0 )
            distance *= 0.9;

        update();
    }

    event->accept();
}

