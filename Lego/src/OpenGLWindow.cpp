#include "stdafx.h"
#include "OpenGLWindow.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Quarto.h"
#include "CuboQuarto.h"
#include "Cross.h"

#include <algorithm>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <string>
#include <cstring>
#include <typeinfo>

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :

	mBackground(background)
{

	setParent(parent);

	setMinimumSize(300, 250);

	const QStringList list = { "vShader.glsl","fShader.glsl" };

	mShaderWatcher = new QFileSystemWatcher(list, this);
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &OpenGLWindow::extractVerticesFromMShapes);
	timer->start(16);
	connect(mShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);
}

OpenGLWindow::~OpenGLWindow()
{
}

void OpenGLWindow::paintGL() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	mProgram->bind();

	matrix_proj.setToIdentity();
	matrix_view.setToIdentity();
	matrix_model.setToIdentity();

	matrix_model.rotate(rotationAngle);

	matrix_proj.ortho(-40.0f, 40.0f, -40.0f, 40.0f, -100.0f, 100.0f);

	matrix_model.translate(mPanFactor);
	matrix_model.scale(zoomFactor);

	mProgram->setUniformValue(m_matrixUniform, (matrix_proj*matrix_model));
	//mProgram->setUniformValue(m_matrixUniform, matrix);

	GLfloat* verticesData = mVertices.data();

	GLfloat* colorsData = mColors.data();

	glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);

	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

	glEnableVertexAttribArray(m_posAttr);

	glEnableVertexAttribArray(m_colAttr);

	glDrawArrays(GL_TRIANGLES, 0, mVertices.size() / 3);
}

void OpenGLWindow::shaderWatcher()
{
	QString vertexShaderSource = readShaderSource("./Shaders/vShader.glsl");

	QString fragmentShaderSource = readShaderSource("./Shaders/fShader.glsl");

	mProgram->release();

	mProgram->removeAllShaders();

	mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);

	mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);

	mProgram->link();
}

QString OpenGLWindow::readShaderSource(QString filePath)

{

	QFile* file = new QFile(filePath);

	if (!file->open(QFile::ReadOnly | QFile::Text))

	{

		std::cerr << "Invalid File !";

		return "Invalid File !";

	}

	QTextStream stream(file);

	QString fileString = stream.readLine();

	while (!stream.atEnd())

	{

		fileString.append(stream.readLine());

	}
	return fileString;
}

void OpenGLWindow::extractVerticesFromMShapes()
{
	mVertices.clear();
	mColors.clear();
	for (auto& shape : mShapes)
	{
		fillVertices(shape->getTriangles(), shape->color());
	}
	update();
}

void OpenGLWindow::fillVertices(std::vector<GeometricEntity::Triangle> triangles, GeometricEntity::Point3D color)
{
	for (Triangle triangle : triangles)
	{
		mVertices.push_back(triangle.p1().x());
		mVertices.push_back(triangle.p1().y());
		mVertices.push_back(triangle.p1().z());

		mVertices.push_back(triangle.p2().x());
		mVertices.push_back(triangle.p2().y());
		mVertices.push_back(triangle.p2().z());

		mVertices.push_back(triangle.p3().x());
		mVertices.push_back(triangle.p3().y());
		mVertices.push_back(triangle.p3().z());

		mColors.push_back(color.x());
		mColors.push_back(color.y());
		mColors.push_back(color.z());

		mColors.push_back(color.x());
		mColors.push_back(color.y());
		mColors.push_back(color.z());

		mColors.push_back(color.x());
		mColors.push_back(color.y());
		mColors.push_back(color.z());
	}
}

void OpenGLWindow::initializeGL()
{
	QString vertexShaderSource = readShaderSource("./Shaders/vShader.glsl");

	QString fragmentShaderSource = readShaderSource("./Shaders/fShader.glsl");

	initializeOpenGLFunctions();

	setMouseTracking(true);

	mProgram = new QOpenGLShaderProgram(this);

	mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);

	mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);

	mProgram->link();

	m_posAttr = mProgram->attributeLocation("posAttr");

	m_colAttr = mProgram->attributeLocation("colAttr");

	m_matrixUniform = mProgram->uniformLocation("matrix");

	if (m_posAttr == -1 || m_colAttr == -1 || m_matrixUniform == -1)
	{
		qDebug() << "Shader attribute or uniform location error.";
	}
}

void OpenGLWindow::setVectorOfLines(QVector<GLfloat>& vectorOfLines)
{
	mVertices = vectorOfLines;
}

void OpenGLWindow::setColorOfLines(QVector<GLfloat>& colorOfLines)
{
	mColors = colorOfLines;
}

void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors)
{
	mVertices = vertices;
	mColors = colors;
	update();
}

void OpenGLWindow::addCube(float side)
{
	Cube* cube = Cube::getCube(side);
	mShapes.push_back(cube);
	if (mShapes.empty())
	{
		cube->setIndex(1);
	}
	cube->setIndex(mShapes.size());
}

void OpenGLWindow::addCuboid(float length, float breadth, float height)
{
	Cuboid* cuboid = Cuboid::getCuboid( length,  breadth,  height);
	mShapes.push_back(cuboid);
	if (mShapes.empty())
	{
		cuboid->setIndex(1);
	}
	cuboid->setIndex(mShapes.size());
}

void OpenGLWindow::addCylinder()
{
	Cylinder* cylinder = Cylinder::getCylinder();
	mShapes.push_back(cylinder);
	if (mShapes.empty())
	{
		cylinder->setIndex(1);
	}
	cylinder->setIndex(mShapes.size());
}

void OpenGLWindow::addQuarto()
{
	Quarto* quarto = Quarto::getQuarto();
	mShapes.push_back(quarto);
	if (mShapes.empty())
	{
		quarto->setIndex(1);
	}
	quarto->setIndex(mShapes.size());
}

void OpenGLWindow::addCuboQuarto()
{
	CuboQuarto* cuboQuarto = CuboQuarto::getCuboQuarto();
	mShapes.push_back(cuboQuarto);
	if (mShapes.empty())
	{
		cuboQuarto->setIndex(1);
	}
	cuboQuarto->setIndex(mShapes.size());
}

void OpenGLWindow::addCross()
{
	Cross* cross = Cross::getCross();
	mShapes.push_back(cross);
	if (mShapes.empty())
	{
		cross->setIndex(1);
	}
	cross->setIndex(mShapes.size());
}

void OpenGLWindow::changeCurrIndex(int& inCurrShapeIndex)
{
	inCurrShapeIndex = mShapes[mShapes.size()-1]->getIndex();
}

void OpenGLWindow::resetSpace()
{
	mShapes.clear();
	mVertices.clear();
	mColors.clear();
	update();
}

void OpenGLWindow::removeShape(int index)
{
	mShapes.erase(mShapes.begin() + index );

	extractVerticesFromMShapes();
}

std::string OpenGLWindow::copyShape(int index)
{
	if (mShapes[index]->shapeType() == "Cube")
	{
		addCube(4.5f);
		return "Cube";
	}
	else if (mShapes[index]->shapeType() == "Cuboid")
	{
		addCuboid(4.0f, 4.0f, 4.0f);
		return "Cuboid";
	}
	else if (mShapes[index]->shapeType() == "Cylinder")
	{
		addCylinder();
		return "Cylinder";
	}
	else if (mShapes[index]->shapeType() == "Quarto")
	{
		addQuarto();
		return "Quarto";
	}
	else if (mShapes[index]->shapeType() == "CuboQuarto")
	{
		addCuboQuarto();
		return "CuboQuarto";
	}
	else if (mShapes[index]->shapeType() == "Cross")
	{
		addCross();
		return "Cross";
	}
	else
	{
		return "";
	}
}

void OpenGLWindow::translateShape(int index, Point3D translateVector)
{
	float tX = translateVector.x();
	float tY = translateVector.y();
	float tZ = translateVector.z();

	std::vector<Triangle> nTriangles;

	for (int i = 0; i < mShapes[index]->getTriangles().size(); i++) {
		Triangle &t = mShapes[index]->getTriangles()[i];
		t.p1().setX(t.p1().x() + tX);
		t.p1().setY(t.p1().y() + tY);
		t.p1().setZ(t.p1().z() + tZ);

		t.p2().setX(t.p2().x() + tX);
		t.p2().setY(t.p2().y() + tY);
		t.p2().setZ(t.p2().z() + tZ);

		t.p3().setX(t.p3().x() + tX);
		t.p3().setY(t.p3().y() + tY);
		t.p3().setZ(t.p3().z() + tZ);
		nTriangles.push_back(t);
	}
	mShapes[index]->setTriangles(nTriangles);

	update();
}

void OpenGLWindow::rotateShape(int index, Point3D rotateVector)
{
	mShapes[index]->rotate(rotateVector);
}

void OpenGLWindow::colorChanger(int shapeIndex)
{
	QColorDialog colorDialog(this);
	QColor selectedColor = colorDialog.getColor();

	if (selectedColor.isValid()) 
	{
		// Set the selected color to the curves or store it for later use
		r = selectedColor.redF();
		g = selectedColor.greenF();
		b = selectedColor.blueF();
	}
	mShapes[shapeIndex]->setColor(Point3D(r, g, b));
	update();  // Trigger an update to redraw the curves with the new color
}

void OpenGLWindow::wheelEvent(QWheelEvent* event)
{
	int delta = event->angleDelta().y();

	if (delta > 0) {

		zoomFactor *= 1.1f;
	}
	else {
		zoomFactor /= 1.1f;
	}
	update();
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton)
	{
		QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.1f * dx);
		QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.1f * dy);

		rotationAngle = rotX * rotY * rotationAngle;
		
	}
	else if (event->buttons() & Qt::RightButton)
	{
		mPanFactor += QVector3D(0.1f * dx, -0.1f * dy, 0.0f);
	}
	update();
	lastPos = event->pos();
}