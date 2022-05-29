#include<stdio.h>

void Buildings()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	
	glBegin(GL_LINES);
	glColor3f(0.075, 0.157, 0.212);
	glVertex2i(0, 43);
	glVertex2i(100, 43);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1
	glColor3f(0.34, 0.46, 0.52);	
	glVertex2f(2, 40);
	glVertex2f(2, 55);
	glVertex2f(2.6, 55.0);
	glVertex2f(2.6, 55.2);
	glVertex2f(4.4, 55.2);
	glVertex2f(4.4, 55.0);
	glVertex2f(5, 55);
	glVertex2f(5, 40);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1 Windows
	glColor3f(0.161, 0.188, 0.1);	
	glVertex2f(2.4, 42.0);
	glVertex2f(2.4, 42.5);
	glVertex2f(4.5, 42.5);
	glVertex2f(4.5, 42.0);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1 Windows
	glColor3f(0.161, 0.188, 0.2);	
	glVertex2f(2.4, 44.0);
	glVertex2f(2.4, 44.5);
	glVertex2f(4.5, 44.5);
	glVertex2f(4.5, 44.0);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1 Windows
	glColor3f(0.161, 0.188, 0.2);	
	glVertex2f(2.4, 46.0);
	glVertex2f(2.4, 46.5);
	glVertex2f(4.5, 46.5);
	glVertex2f(4.5, 46.0);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1 Windows
	glColor3f(0.161, 0.188, 0.2);	
	glVertex2f(2.4, 48.0);
	glVertex2f(2.4, 48.5);
	glVertex2f(4.5, 48.5);
	glVertex2f(4.5, 48.0);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1 Windows
	glColor3f(0.161, 0.188, 0.2);	
	glVertex2f(2.4, 50.0);
	glVertex2f(2.4, 50.5);
	glVertex2f(4.5, 50.5);
	glVertex2f(4.5, 50.0);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 1 Windows
	glColor3f(0.161, 0.188, 0.2);	
	glVertex2f(2.4, 52.0);
	glVertex2f(2.4, 52.5);
	glVertex2f(4.5, 52.5);
	glVertex2f(4.5, 52.0);
	glEnd();
	
	glFlush();
}