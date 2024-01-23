#pragma once
#include "Point3D.h"
#include <QtWidgets/QMainWindow>
#include "OpenGLWindow.h"
class Lego : public QMainWindow
{
	Q_OBJECT

public:
	Lego(QWidget* parent = nullptr);
	~Lego();

private:
	void setConnections();

	void setupUi();

	void newSpace();

	void copySelectedShape();

	void pasteSelectedShape();

	void translateSelectedShape();

	void rotateSelectedShape();

	void removeSelectedShape();

	void colorSelectedShape();

	void resetSpace();

	void placeCube();

	void placeCuboid();

	void placeCylinder();

	void placeQuarto();

	void placeCuboQuarto();

	void placeCross();

	void increaseCount(std::string compareStr);

private:
	QWidget*		mCentralWidget;
	QTabWidget*		mTabs;
	QWidget*		mActionTab;
	QPushButton*	mNewButton;
	QPushButton*	mCopyButton;
	QWidget*		mTransformTab;
	QVBoxLayout*	lastVerticalLayout;

	QPushButton*	mTranslateButton;
	QPushButton*	mRotateButton;
	QSpinBox*		shapeIndexSpinBox;

	QWidget*		mToolsTab;
	QPushButton*	mRemoveButton;
	QPushButton*	mColorButton;
	QWidget*		mLegoShapeTab;
	QPushButton*	mCubeButton;
	QPushButton*	mCuboidButton;
	QPushButton*	mCylinderButton;
	QPushButton*	mQuartoButton;
	QPushButton*	mCuboQuartoButton;
	QPushButton*	mCrossButton;
	QPushButton*	mResetButton;
	QTableView*		mTableView;

	OpenGLWindow*	mRenderer;

	QHBoxLayout*	transformLayout;

	QVBoxLayout*	translateVerticalLayout;
	QHBoxLayout*	takeTranslationValues;
	QDoubleSpinBox* xTranslationInputBox;
	QDoubleSpinBox* yTranslationInputBox;
	QDoubleSpinBox* zTranslationInputBox;

	QHBoxLayout*	showTranslationValues;
	QLabel*			xTranslationLabel;
	QLabel*			yTranslationLabel;
	QLabel*			zTranslationLabel;

	QVBoxLayout*	rotateVerticalLayout;
	QHBoxLayout*	takeRotationValues;
	QDoubleSpinBox* xRotationInputBox;
	QDoubleSpinBox* yRotationInputBox;
	QDoubleSpinBox* zRotationInputBox;

	QHBoxLayout*	showRotationValues;
	QLabel*			xRotationLabel;
	QLabel*			yRotationLabel;
	QLabel*			zRotationLabel;
	QStandardItemModel* mTableModel;
	//vertices and colors
	QVector<GLfloat> mVertices;
	QVector<GLfloat> mColors;

	//shape counts
	int cubeCount;
	int cuboidCount;
	int cylinderCount;
	int quartoCount;
	int cuboQuartoCount;
	int crossCount;
	int	mCurrShapeIndex;
};