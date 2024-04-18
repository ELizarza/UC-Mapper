#include "myglwidget.h"
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>
#include<QOpenGLShaderProgram>
#include<QOpenGLTexture>

MyGLWidget::MyGLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{

}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL()
{
    // Set up the rendering context, load shaders and other resources, etc.:
    initializeOpenGLFunctions();

    makeObject();

#define PROGRAM_VERTEX_ATTRIBUTE 0
#define PROGRAM_TEXCOORD_ATTRIBUTE 1

    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char *vsrc =
        "attribute highp vec4 vertex;\n"
        "attribute mediump vec4 texCoord;\n"
        "varying mediump vec4 texc;\n"
        "uniform mediump mat4 matrix;\n"
        "void main(void)\n"
        "{\n"
        "    gl_Position = matrix * vertex;\n"
        "    texc = texCoord;\n"
        "}\n";
    vshader->compileSourceCode(vsrc);

    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char *fsrc =
        "uniform sampler2D texture;\n"
        "varying mediump vec4 texc;\n"
        "void main(void)\n"
        "{\n"
        "    gl_FragColor = texture2D(texture, texc.st);\n"
        "}\n";
    fshader->compileSourceCode(fsrc);

    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->bindAttributeLocation("vertex", PROGRAM_VERTEX_ATTRIBUTE);
    program->bindAttributeLocation("texCoord", PROGRAM_TEXCOORD_ATTRIBUTE);
    program->link();

    program->bind();
    program->setUniformValue("texture", 0);

}


void MyGLWidget::resizeGL(int w, int h)
{


    //clear to cyan
    glClearColor(0.5, 1, 1, 1);
}

void MyGLWidget::paintGL()
{
    // Draw the scene:
    /*
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT);
    */
    //set every pixel to current clear color
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw triangle
    /*
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(0.0f, 0.707f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
    */

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    vbo.bind();
    program->bind();
    program->enableAttributeArray(PROGRAM_VERTEX_ATTRIBUTE);
    program->enableAttributeArray(PROGRAM_TEXCOORD_ATTRIBUTE);
    program->setAttributeBuffer(PROGRAM_VERTEX_ATTRIBUTE, GL_FLOAT, 0, 3, 5 * sizeof(GLfloat));
    program->setAttributeBuffer(PROGRAM_TEXCOORD_ATTRIBUTE, GL_FLOAT, 3 * sizeof(GLfloat), 2, 5 * sizeof(GLfloat));


    texture->bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, 6);


}

void MyGLWidget::makeObject()
{
    float vertices[] = {
        // positions          // texture coords
        0.5f,  0.5f, 0.0f,     1.0f, 1.0f,       // top right
        0.5f, -0.5f, 0.0f,     1.0f, 0.0f,       // bottom right
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f,      // bottom left
        -0.5f,  0.5f, 0.0f,    0.0f, 1.0f       // top left
    };


    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    texture = new QOpenGLTexture(QImage(QString(":/imgs/imgs/black ops 4.png")).mirrored());

    QList<GLfloat> vertData;
    for (int i = 0; i < 6; i++){
        // vertex pos
        vertData.append(0.2 * vertices[0 + (indices[i] * 5)]);
        vertData.append(0.2 * vertices[1 + (indices[i] * 5)]);
        vertData.append(0.2 * vertices[2 + (indices[i] * 5)]);
        //vertex tex coord
        vertData.append(0.2 * vertices[3 + (indices[i] * 5)]);
        vertData.append(0.2 * vertices[4 + (indices[i] * 5)]);
    }

    vbo.create();
    vbo.bind();
    vbo.allocate(vertData.constData(), vertData.count() * sizeof(GLfloat));


}






