#pragma once

#include <QtWidgets/QOpenGLWidget>
#include <QtCore/QTimer>

class MyGlWindow : public QOpenGLWidget
{
	Q_OBJECT

public:
	MyGlWindow();
	~MyGlWindow();
	
	GLuint vertexBufferID;
	QTimer myTimer;
protected:
	virtual void initializeGL() override;
	virtual void paintGL() override;

private slots:
	void myUpdate();
	void rotateShip();
	void updateVelocity();

public:
	bool initialize();
	bool shutdown();
};

