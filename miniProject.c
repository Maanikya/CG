#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void WindowInit();
void Scene();
void output(char *s);

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
	glutInitWindowPosition(300, 500);
	glutCreateWindow("Mini Project");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0, 1.0,	1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, 0.0, 100.0);
	glutDisplayFunc(Scene);
	glutMainLoop();
}

void Scene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(20.0, 60.0, 0.0);
	glScalef(0.0, 0.0, 0.0);
	output("Mangalore Institute of Technology & Engineering");
	glPopMatrix();
	glFlush();
}

void output(char *s)
{
	for(int k=0; k<strlen(s); k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[k]);
}