#include<stdio.h>

void output(char *s);

void Intro()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(34.0, 85.0, 0.0);
	output("Mangalore Institute of Technology & Engineering");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glRasterPos3f(34.0, 70.0, 0.0);
	output("Department of Computer Science and Engineering");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glRasterPos3f(43.0, 55.0, 0.0);
	output("Animated Time-Lapse");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(10.5, 33.0, 0.0);
	output("Maanikya");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(9.4, 28.0, 0.0);
	output("4MT19CS073");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(80.0, 33.0, 0.0);
	output("Rakshit Poojari");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(80.5, 28.0, 0.0);
	output("4MT19CS122");
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(40.0, 18.0, 0.0);
	output("UNDER THE GUIDANCE OF");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(44.0, 13.0, 0.0);
	output("MS. SUNITHA N V");
	glPopMatrix();
	
	glFlush();
}

void output(char *s)
{
	for(int k=0; k<strlen(s); k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[k]);
}