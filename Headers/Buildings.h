#include<stdio.h>
#include<GL/glut.h>

void Buildings()
{	
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
	
	for(int y=0; y<12; y+=2){
		glBegin(GL_POLYGON);				//Building 1 Windows
		glColor3f(0.161, 0.188, 0.1);	
		glVertex2f(2.4, 42.0+y);
		glVertex2f(2.4, 42.5+y);
		glVertex2f(4.5, 42.5+y);
		glVertex2f(4.5, 42.0+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);				//Building 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex2f(10, 36);
	glVertex2f(10, 55);
	glVertex2f(12.6, 56);
	glVertex2f(13.0, 56);
	glVertex2f(15, 55);
	glVertex2f(15, 36);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 2 Strip 1
	glColor3ub(69, 88, 104);	
	glVertex2f(10.6, 36);
	glVertex2f(10.6, 54);
	glVertex2f(10.8, 54);
	glVertex2f(10.8, 36);
	glEnd();
	
	glBegin(GL_POLYGON);				//Building 2 Strip 2	
	glColor3ub(69, 88, 104);
	glVertex2f(11.3, 36);
	glVertex2f(11.3, 54.5);
	glVertex2f(11.5, 54.5);
	glVertex2f(11.5, 36);
	glEnd();
	
	for(float y=0; y<15; y+=1.2) {
		glBegin(GL_POLYGON);				//Building 2 Windows Left
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(11.7, 38+y);
		glVertex2f(11.7, 38.2+y);
		glVertex2f(12.2, 38.2+y);
		glVertex2f(12.2, 38+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);				//Building 2 Strip 3
	glColor3ub(49, 69, 87);	
	glVertex2f(12.6, 36);
	glVertex2f(12.6, 55);
	glVertex2f(13.0, 55);
	glVertex2f(13.0, 36);
	glEnd();
	
	for(float y=0; y<15; y+=1.2) {
		glBegin(GL_POLYGON);				//Building 2 Windows Right
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(13.4, 38+y);
		glVertex2f(13.4, 38.2+y);
		glVertex2f(14.4, 38.2+y);
		glVertex2f(14.4, 38+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);				//Building 3
	glColor3ub(46, 65, 81);
	glVertex2f(19.5, 34);
	glVertex2f(19.5, 48);
	glVertex2f(20, 48);
	glVertex2f(20, 34);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.46, 0.52);
	glVertex2f(20, 34);
	glVertex2f(20, 48.5);
	glVertex2f(20.5, 48.5);
	glVertex2f(20.5, 34);
	glEnd();
	
	glFlush();
}