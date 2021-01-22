#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
const float pi = 3.14159;
void drawCircle(float a, float b, float r, int i)
{
	glBegin(GL_TRIANGLE_FAN);
	// iterate from E[0, 2pi] 
	float inc = pi/i;
	for(float t = 0; t < 2*pi; t+=inc)
	{
		// parametric definition of a circle
		// x = a + r cos t
		// y = b + r sin t
		float x = a + r * cos(t);
		float y = b + r * sin(t);
		glVertex2f(x,y);
	}
	glEnd();
}
// initialization function
void start()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// frame based continous update
void update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	drawCircle(0.5, 0.5, 0.2, 4);
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);
	glutCreateWindow("2d");
	start();
	glutDisplayFunc(update);
	glutMainLoop();
	return 0;
}
