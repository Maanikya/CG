#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Headers/Display.h"

void WindowInit();

int main(int argc, char *argv[]) 
{
	printf("\nName : Maanikya\n");
	printf("\nUSN : 4MT19CS073\n");
	printf("\nName : Rakshit Poojari\n");
	printf("\nUSN : 4MT19CS122\n");
	
	glutInit(&argc, argv);
	WindowInit();
	
	return 0;
}

void WindowInit()
{
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Mini Project");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.62, 0.69, 0.82, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, 0.0, 100.0);
	glutDisplayFunc(Display);
	glutMainLoop();
	glFlush();
}