#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QMainWindow>
#include <QQuaternion>
#include <QWheelEvent>
#include "LegoShapeFactory.h"
#include "Triangulation.h"
#include "Cube.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWindow(const QColor& background, QMainWindow* parent);
    ~OpenGLWindow();

public:
    void setVectorOfLines(QVector<GLfloat>& vectorOfLines);
    void setColorOfLines(QVector<GLfloat>& colorOfLines);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors);


public:
    void addCube(float side);
    void addCuboid(float length, float breadth, float height);
    void addCylinder();
    void addQuarto();
    void addCuboQuarto();
    void addCross();
    void changeCurrIndex(int& inCurrShapeIndex);

    void resetSpace();
    void removeShape(int index);
    void translateShape(int index, Point3D translateVector);
    void rotateShape(int index, Point3D translateVector);
    void colorChanger(int shapeIndex);
    std::string copyShape(int index);

signals:
    void shapeSelected(QString shapeType, QString shapeProperties);
protected:
    void paintGL() override;
    void initializeGL() override;

private:
    void shaderWatcher();
    QString readShaderSource(QString filePath);
    void extractVerticesFromMShapes();

    void fillVertices(std::vector<GeometricEntity::Triangle> triangles, GeometricEntity::Point3D);

private:
    QOpenGLContext* mContext = nullptr;
    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    double mVertexAttr;
    double mNormalAttr;
    double mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    QMatrix4x4 matrix_proj;
    QMatrix4x4 matrix_view;
    QMatrix4x4 matrix_model;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
    QPoint lastPos;

    QQuaternion rotationAngle;

    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;

    float zoomFactor = 1.0f;

    float r = 1.0;
    float g = 1.0;
    float b = 0.0;

    QFileSystemWatcher* mShaderWatcher;
    QColorDialog* mColorPallete;

    QVector3D mPanFactor;

private:
    std::vector<LegoShapeFactory*> mShapes;
};