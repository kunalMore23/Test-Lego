#include "stdafx.h"
#include "Lego.h"
#include "Cube.h"
#include <string>
#include <fstream>
#include <iostream>

Lego::Lego(QWidget* parent)
	: QMainWindow(parent),
	cubeCount(0),
	cuboidCount(0),
	cylinderCount(0),
	quartoCount(0),
	cuboQuartoCount(0),
	crossCount(0)
{
	setConnections();
}

Lego::~Lego()
{}

void Lego::setConnections()
{
	setupUi();

	connect(mNewButton, &QPushButton::clicked, this, &Lego::newSpace);
	connect(mCopyButton, &QPushButton::clicked, this, &Lego::copySelectedShape);

	connect(mTranslateButton, &QPushButton::clicked, this, &Lego::translateSelectedShape);
	connect(mRotateButton, &QPushButton::clicked, this, &Lego::rotateSelectedShape);

	connect(mRemoveButton, &QPushButton::clicked, this, &Lego::removeSelectedShape);
	connect(mColorButton, &QPushButton::clicked, this, &Lego::colorSelectedShape);

	connect(mCubeButton, &QPushButton::clicked, this, &Lego::placeCube);
	connect(mCuboidButton, &QPushButton::clicked, this, &Lego::placeCuboid);
	connect(mCylinderButton, &QPushButton::clicked, this, &Lego::placeCylinder);
	connect(mQuartoButton, &QPushButton::clicked, this, &Lego::placeQuarto);
	connect(mCuboQuartoButton, &QPushButton::clicked, this, &Lego::placeCuboQuarto);
	connect(mCrossButton, &QPushButton::clicked, this, &Lego::placeCross);

	connect(mResetButton, &QPushButton::clicked, this, &Lego::resetSpace);
}

void Lego::setupUi()
{
	resize(1525, 1333);
	mCentralWidget = new QWidget(this);
	mCentralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
	mRenderer->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	mTabs = new QTabWidget(mCentralWidget);
	mTabs->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);

	// Action tab
	mActionTab = new QWidget();
	QHBoxLayout* actionLayout = new QHBoxLayout(mActionTab);
	mNewButton = new QPushButton("New Space");
	mCopyButton = new QPushButton("Copy");

	actionLayout->addWidget(mNewButton);
	actionLayout->addWidget(mCopyButton);
	mTabs->addTab(mActionTab, QString("Actions"));

	// Lego shape tab
	mLegoShapeTab = new QWidget();
	QVBoxLayout* legoShapeLayout = new QVBoxLayout(mLegoShapeTab);
	QHBoxLayout* firstShapeLayout = new QHBoxLayout(mLegoShapeTab);
	QHBoxLayout* secondShapeLayout = new QHBoxLayout(mLegoShapeTab);
	mCubeButton = new QPushButton("Cube");
	mCuboidButton = new QPushButton("Cuboid");
	mCylinderButton = new QPushButton("Cylinder");
	mQuartoButton = new QPushButton("Quarto");
	mCuboQuartoButton = new QPushButton("CuboQuarto");
	mCrossButton = new QPushButton("Cross");

	firstShapeLayout->addWidget(mCubeButton);
	firstShapeLayout->addWidget(mCuboidButton);
	firstShapeLayout->addWidget(mCylinderButton);
	secondShapeLayout->addWidget(mQuartoButton);
	secondShapeLayout->addWidget(mCuboQuartoButton);
	secondShapeLayout->addWidget(mCrossButton);
	legoShapeLayout->addLayout(firstShapeLayout);
	legoShapeLayout->addLayout(secondShapeLayout);
	mTabs->addTab(mLegoShapeTab, QString("Shapes"));

	// Transform tab
	mTransformTab = new QWidget();
	QHBoxLayout* transformLayout = new QHBoxLayout(mTransformTab);

	QVBoxLayout* translateVerticalLayout = new QVBoxLayout();
	mTranslateButton = new QPushButton("Translate");

	QHBoxLayout* takeTranslationValues = new QHBoxLayout(mTransformTab);
	xTranslationInputBox = new QDoubleSpinBox(mTransformTab);
	yTranslationInputBox = new QDoubleSpinBox(mTransformTab);
	zTranslationInputBox = new QDoubleSpinBox(mTransformTab);

	takeTranslationValues->addWidget(xTranslationInputBox);
	takeTranslationValues->addWidget(yTranslationInputBox);
	takeTranslationValues->addWidget(zTranslationInputBox);

	QHBoxLayout* showTranslationValues = new QHBoxLayout(mTransformTab);
	QLabel* xTranslationLabel = new QLabel("x-values", mTransformTab);
	QLabel* yTranslationLabel = new QLabel("y-values", mTransformTab);
	QLabel* zTranslationLabel = new QLabel("z-values", mTransformTab);

	showTranslationValues->addWidget(xTranslationLabel);
	showTranslationValues->addWidget(yTranslationLabel);
	showTranslationValues->addWidget(zTranslationLabel);

	QVBoxLayout* rotateVerticalLayout = new QVBoxLayout(mTransformTab);
	mRotateButton = new QPushButton("Rotate");

	QHBoxLayout* takeRotationValues = new QHBoxLayout(mTransformTab);
	xRotationInputBox = new QDoubleSpinBox(mTransformTab);
	yRotationInputBox = new QDoubleSpinBox(mTransformTab);
	zRotationInputBox = new QDoubleSpinBox(mTransformTab);

	takeRotationValues->addWidget(xRotationInputBox);
	takeRotationValues->addWidget(yRotationInputBox);
	takeRotationValues->addWidget(zRotationInputBox);

	QHBoxLayout* showRotationValues = new QHBoxLayout(mTransformTab);
	QLabel* xRotationLabel = new QLabel("x-values", mTransformTab);
	QLabel* yRotationLabel = new QLabel("y-values", mTransformTab);
	QLabel* zRotationLabel = new QLabel("z-values", mTransformTab);

	showRotationValues->addWidget(xRotationLabel);
	showRotationValues->addWidget(yRotationLabel);
	showRotationValues->addWidget(zRotationLabel);

	translateVerticalLayout->addWidget(mTranslateButton);
	translateVerticalLayout->addLayout(showTranslationValues);
	translateVerticalLayout->addLayout(takeTranslationValues);
	transformLayout->addLayout(translateVerticalLayout);

	rotateVerticalLayout->addWidget(mRotateButton);
	rotateVerticalLayout->addLayout(showRotationValues);
	rotateVerticalLayout->addLayout(takeRotationValues);
	transformLayout->addLayout(rotateVerticalLayout);
	mTabs->addTab(mTransformTab, QString("Transform"));

	// Tools tab
	mToolsTab = new QWidget();
	QSizePolicy* sizePolicy = new QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
	mToolsTab->setSizePolicy(*sizePolicy);
	QHBoxLayout* toolsLayout = new QHBoxLayout(mToolsTab);
	mRemoveButton = new QPushButton("Remove");
	mColorButton = new QPushButton("Color");

	toolsLayout->addWidget(mRemoveButton);
	toolsLayout->addWidget(mColorButton);

	mTabs->addTab(mToolsTab, QString("Tools"));

	mResetButton = new QPushButton("Reset", mCentralWidget);
	mResetButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

	mTableView = new QTableView(mCentralWidget);
	mTableView->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

	mTableModel = new QStandardItemModel(0, 1, this);
	mTableView->setModel(mTableModel);
	mTableModel->setHorizontalHeaderLabels(QStringList() << "Added Objects");
	mTableView->setColumnWidth(0, 250);

	QHBoxLayout* mainHLayout = new QHBoxLayout(mCentralWidget);
	QVBoxLayout* mainLayout = new QVBoxLayout(mCentralWidget);

	QHBoxLayout* mButtonsLayout = new QHBoxLayout(mCentralWidget);
	mButtonsLayout->addWidget(mTabs);
	mButtonsLayout->addWidget(mResetButton);
	mainLayout->addLayout(mButtonsLayout);
	mainLayout->addWidget(mRenderer);
	mainHLayout->addLayout(mainLayout);
	mainHLayout->addWidget(mTableView);

	mTabs->setCurrentIndex(0);
	setCentralWidget(mCentralWidget);
	showMaximized();
}

void Lego::newSpace()
{
	mRenderer->resetSpace();
	mTableModel->clear();
	mTableModel->setHorizontalHeaderLabels(QStringList() << "Added Objects");
	mTableView->setColumnWidth(0, 250);
}

void Lego::copySelectedShape()
{
	QModelIndex currIndex = mTableView->currentIndex();
	std::string shapeReturned = mRenderer->copyShape(currIndex.row());
	if (shapeReturned.size())
	{
		increaseCount(shapeReturned);
		QStandardItem* newItem = new QStandardItem("Added Copy of shape " + QString::number(currIndex.row() + 1));
		mTableModel->appendRow(newItem);
	}
}

void Lego::pasteSelectedShape()
{

}

void Lego::translateSelectedShape()
{
	QModelIndex currIndex = mTableView->currentIndex();
	Point3D traslateVector(xTranslationInputBox->value(), yTranslationInputBox->value(), zTranslationInputBox->value());
	mRenderer->translateShape(currIndex.row(), traslateVector);
}

void Lego::rotateSelectedShape()
{
	QModelIndex currIndex = mTableView->currentIndex();
	Point3D rotateVector(xRotationInputBox->value(), yRotationInputBox->value(), zRotationInputBox->value());
	mRenderer->rotateShape(currIndex.row(), rotateVector);
}

void Lego::removeSelectedShape()
{
	QModelIndex currIndex = mTableView->currentIndex();
	mRenderer->removeShape(currIndex.row());
	mTableModel->removeRow(currIndex.row());
}

void Lego::colorSelectedShape()
{
	mRenderer->colorChanger(mTableView->currentIndex().row());
}

void Lego::resetSpace()
{
	mRenderer->resetSpace();
	mTableModel->clear();
	mTableModel->setHorizontalHeaderLabels(QStringList() << "Added Objects");
	mTableView->setColumnWidth(0, 250);
}

void Lego::placeCube()
{
	mRenderer->addCube(4.5f);
	cubeCount++;
	QString addedText = "Cube added"; 
	QStandardItem* newItem = new QStandardItem(addedText);
	mTableModel->appendRow(newItem);
}

void Lego::placeCuboid()
{
	mRenderer->addCuboid(4.5f, 4.5f, 4.5f);
	cuboidCount++;

	QString addedText = "Cuboid added"; 
	QStandardItem* newItem = new QStandardItem(addedText);
	mTableModel->appendRow(newItem);
}

void Lego::placeCylinder()
{
	mRenderer->addCylinder();
	cylinderCount++;

	QString addedText = "Cylinder added"; 
	QStandardItem* newItem = new QStandardItem(addedText);
	mTableModel->appendRow(newItem);
}

void Lego::placeQuarto()
{
	mRenderer->addQuarto();
	quartoCount++;
	QString addedText = "Quarto added"; 
	QStandardItem* newItem = new QStandardItem(addedText);
	mTableModel->appendRow(newItem);
}

void Lego::placeCuboQuarto()
{
	mRenderer->addCuboQuarto();
	cuboQuartoCount++;
	mRenderer->changeCurrIndex(mCurrShapeIndex);
	QString addedText = "CuboQuarto added"; 
	QStandardItem* newItem = new QStandardItem(addedText);
	mTableModel->appendRow(newItem);
}

void Lego::placeCross()
{
	mRenderer->addCross();
	crossCount++;
	QString addedText = "Cross added"; 
	QStandardItem* newItem = new QStandardItem(addedText);
	mTableModel->appendRow(newItem);
}

void Lego::increaseCount(std::string compareStr)
{
	if (compareStr == "Cube")
	{
		cubeCount++;
	}
	else if (compareStr == "Cuboid")
	{
		cuboidCount++;
	}
	else if (compareStr == "Cylinder")
	{
		cylinderCount++;
	}
	else if (compareStr == "Quarto")
	{
		quartoCount++;
	}
	else if (compareStr == "CuboQuarto")
	{
		cuboQuartoCount++;
	}
	else if (compareStr == "Cross")
	{
		crossCount++;
	}
	else
	{
		return;
	}
}