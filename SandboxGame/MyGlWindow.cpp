#include <gl\glew.h>
#include "MyGlWindow.h"
#include <cassert>
#include <Math\Vector2D.h>
#include <Timing\Clock.h>
using Math::Vector2D;
using Timing::Clock;

namespace
{
	static Vector2D verts[] =
	{
		Vector2D(0.0f, 0.1f),
		Vector2D(-0.1f, -0.1f),
		Vector2D(0.1f, -0.1f),
	};

	const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
	Vector2D shipPosition;
	Vector2D shipVelocity;
	Clock clock;
}

MyGlWindow::MyGlWindow() 
{
}


MyGlWindow::~MyGlWindow()
{
}

void MyGlWindow::initializeGL()
{
	GLenum errorCode = glewInit();
	assert(errorCode == 0);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);
	
	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);
}

void MyGlWindow::paintGL()
{
	glViewport(0, 0, width(), height());
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	Vector2D translatedVerts[NUM_VERTS];
	for (unsigned int i = 0; i < NUM_VERTS; i++)
		translatedVerts[i] = verts[i] + shipPosition;

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGlWindow::myUpdate()
{
	clock.newFrame();
	updateVelocity();
	shipPosition += shipVelocity * clock.timeElapsedLastFrame();
	repaint();
}

void MyGlWindow::updateVelocity()
{
	const float ACCELERATION = 0.5f * clock.timeElapsedLastFrame();
	
	if (GetAsyncKeyState(VK_UP))
		shipVelocity.y += ACCELERATION;
	if (GetAsyncKeyState(VK_DOWN))
		shipVelocity.y -= ACCELERATION;
	if (GetAsyncKeyState(VK_RIGHT))
		shipVelocity.x += ACCELERATION;
	if (GetAsyncKeyState(VK_LEFT))
		shipVelocity.x -= ACCELERATION;
	
}

bool MyGlWindow::initialize()
{
	return clock.initialize();
}

bool MyGlWindow::shutdown()
{
	return clock.shutdown();
}
