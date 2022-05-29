#include<stdio.h>

void Background()
{
	glBegin(GL_POLYGON);
	glColor3f(0.075, 0.157, 0.212);
	glVertex2i(0, 43);
	glVertex2i(100, 43);
	glVertex2i(100, 0);
	glVertex2i(0, 0);
	glEnd();
	glFlush();
}