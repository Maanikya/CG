#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
//#include "Intro.h"

float sunx=0, suny=50, sunColor=0.0, bk1Color1=0, bk1Color2=0, bk1Color3=0;
float moonx=0, moony=50, bk2Color1=0, bk2Color2=0, bk2Color3=0, windows=0.0, ground=0, glow1=0, glow2=1;
float bird=0, bWing=0, shine1=0, shine2=0;
float shd=0.1, bk1=0, bk2=0;
int slide;

void WindowInit();
void Display();
void Intro();
void Display1();
void Display2();
void Display3();
void ThankYou();
void output(char *s);
void output2(char *s);
void EffielTower();
void Stars();
void Stars1();
void Stars2();
void seaShine();
void Timer1();
void Timer2();
void Timer3();
void Keyboard(unsigned char key, int x, int y);
void myReshape(int w, int h);

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
	glutCreateWindow("Mini Project 4MT19CS073 4MT19CS122");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -10.0, 10.0);
	glutDisplayFunc(Display);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(Keyboard);
	Timer1(0);
	Timer2(0);
	Timer3(0);
	glutMainLoop();
}

void Display() {
	
	if(slide == 1) {
		
		Intro();
	}
		
	else if(slide == 2) {

		Display1();
		
	}
		
	else if(slide == 3) {
		
		Display2();
		
	}
	
	else if(slide == 4) {
		
		Display3();
		
	}
	
	else if(slide == 5) {
		
		ThankYou();
	}
}

void Keyboard(unsigned char key, int x, int y) {
	
	if(key == '1') {
				
		slide = 1;
	}
	
	else if(key == '2') {
		
		sunx=0, suny=50, sunColor=0.0, bk1Color1=0, bk1Color2=0, bk1Color3=0, shd=0.1, bk1=0, bk2=0;
		slide = 2;

	}
	
	else if(key == '3') {
		
		bird=0, bWing=0, shine1=0, shine2=0;
		slide = 4;

	}
	
	else if(key == '4') {
		
		moonx=0, moony=50, bk2Color1=0.3, bk2Color2=0.2, bk2Color3=0.1, shd=0.1, bk1=0, bk2=0, windows=0.0, ground=0, glow1=0, glow2=1;
		slide = 3;
	}
	
	else if(key == '5') {
		
		slide = 5;
	}
	
	glutPostRedisplay();
}

void Timer1(int v) {
	
	suny = sqrt((50*50)-((sunx-50)*(sunx-50)) + 50);
	suny += 40;
	
	if(sunx >= 70)													//Sun Path
		sunx=sunx;
	else															//Sun Path		
		sunx += 0.8;
		
		
	if(sunColor >= 1)												//Sun Color			
		sunColor = sunColor;
	else															//Sun Color	
		sunColor += 0.015;
		
		
	if(shd >= 9)													//Building Shadow
		shd=shd;
	else															//Building Shadow
		shd += 0.005;
		
		
	if(bk1Color1 >= 0.5)
		bk1Color1 = bk1Color1;
	else
		bk1Color1 += 0.01; 
	
	
	if(bk1Color2 >= 0.6)
		bk1Color2 = bk1Color2;
	else
		bk1Color2 += 0.014;
		
		
	if(bk1Color3 >= 0.8)
		bk1Color3 = bk1Color3;
	else
		bk1Color3 += 0.018; 
	
	glutTimerFunc(40, Timer1, 0); 	
	glutPostRedisplay();
}

void Timer2(int v) {
	
	moony = sqrt((50*50)-((moonx-50)*(moonx-50)) + 50);
	moony += 40;
	
	if(moonx >= 70)													//Moon Path
		moonx=moonx;
	else															//Moon Path		
		moonx += 0.8;
		
		
	if(shd >= 9)													//Building Shadow
		shd=shd;
	else															//Building Shadow
		shd += 0.1;
		
		
	if(bk2Color1 <= 0.0)
		bk2Color1 = bk2Color1;
	else
		bk2Color1 -= 0.0035; 
	
	
	if(bk2Color2 <= 0.0)
		bk2Color2 = bk2Color2;
	else
		bk2Color2 -= 0.0045;
		
		
	if(bk2Color3 <= 0.0)
		bk2Color3 = bk2Color3;
	else
		bk2Color3 -= 0.0055;
		
	
	if(ground >= 80)
		ground=ground;
	else
		ground += 1;
		
		
	if(windows >= 1)
		windows = windows;
	else
		windows += 0.01;
		 
		 
	if(glow1 <= 1)													//Star Shine 1
		glow1 += 0.01;
	else
		glow1 = 0;
		
		
	if(glow2 <= 1)													//Star Shine 2
		glow2 += 0.015;
	else
		glow2 = 0;
	
	glutTimerFunc(40, Timer2, 0); 	
	glutPostRedisplay();
}

void Timer3(int v) {
	
	if(bWing <= 1)													//Bird Wing
		bWing += 0.03;
	else
		bWing = 0;


	if(bird >= 80)													//Bird
		bird = 0;
	else
		bird += 0.3;
		
		
	if(shine1 <= 1)													//Water Shine 1
		shine1 += 0.03;
	else
		shine1 = 0;
		
		
	if(shine2 <= 1)													//Water Shine 2
		shine2 += 0.04;
	else
		shine2 = 0;
	
	glutPostRedisplay();
	glutTimerFunc(40, Timer3, 0); 	
	
}

void Intro() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	Stars1();
	Stars2();
	
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
	glRasterPos3f(45.0, 55.0, 0.0);
	output("CG Project On : ");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glRasterPos3f(43.0, 45.0, 0.0);
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

void Display1() {
	
	glClearColor(bk1Color1, bk1Color2, bk1Color3, 0.0);						//Sky
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	glBegin(GL_POLYGON);													//Background
	glColor3ub(ground*1.8375, ground*2.0875, ground*2.25);
	glVertex3i(0, 43, -9);
	glColor3ub(ground*2.05, ground*2.05, ground*2.3375);
	glVertex3i(100, 43, -9);
	glColor3ub(ground*0.5375, ground*0.7, ground*0.8);
	glVertex3i(100, 0, -9);
	glColor3ub(ground*0.3875, ground*0.6, ground*0.75);
	glVertex3i(0, 0, -9);
	glEnd();
	
	//BUILDINGS AND WINDOWS
	
	glBegin(GL_POLYGON);													//Building 1
	glColor3f(0.34, 0.46, 0.52);	
	glVertex3f(2, 40, -4);
	glVertex3f(2, 55, -4);
	glVertex3f(2.6, 55.0, -4);
	glVertex3f(2.6, 55.2, -4);
	glVertex3f(4.4, 55.2, -4);
	glVertex3f(4.4, 55.0, -4);
	glVertex3f(5, 55, -4);
	glVertex3f(5, 40, -4);
	glEnd();
	
	for(int y=0; y<12; y+=2){
		glBegin(GL_POLYGON);						//Building 1 Windows
		glColor3f(0.161, 0.188, 0.1);	
		glVertex2f(2.4, 42.0+y);
		glVertex2f(2.4, 42.5+y);
		glVertex2f(4.5, 42.5+y);
		glVertex2f(4.5, 42.0+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 2
	glColor3f(0.34, 0.46, 0.52);	
	glVertex3f(10, 36, -4);
	glVertex3f(10, 55, -4);
	glVertex3f(12.6, 56, -4);
	glVertex3f(13.0, 56, -4);
	glVertex3f(15, 55, -4);
	glVertex3f(15, 36, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 2 Strip 1
	glColor3ub(69, 88, 104);	
	glVertex2f(10.6, 36);
	glVertex2f(10.6, 54);
	glVertex2f(10.8, 54);
	glVertex2f(10.8, 36);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 2 Strip 2	
	glColor3ub(69, 88, 104);
	glVertex2f(11.3, 36);
	glVertex2f(11.3, 54.5);
	glVertex2f(11.5, 54.5);
	glVertex2f(11.5, 36);
	glEnd();
	
	for(float y=0; y<15; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 2 Windows Left
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(11.7, 38+y);
		glVertex2f(11.7, 38.2+y);
		glVertex2f(12.2, 38.2+y);
		glVertex2f(12.2, 38+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 2 Strip 3
	glColor3ub(49, 69, 87);	
	glVertex2f(12.6, 36);
	glVertex2f(12.6, 55);
	glVertex2f(13.0, 55);
	glVertex2f(13.0, 36);
	glEnd();
	
	for(float y=0; y<15; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 2 Windows Right
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(13.4, 38+y);
		glVertex2f(13.4, 38.2+y);
		glVertex2f(14.4, 38.2+y);
		glVertex2f(14.4, 38+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 3 Part 1
	glColor3ub(46, 65, 81);
	glVertex3f(19.5, 34, -4);
	glVertex3f(19.5, 48, -4);
	glVertex3f(20, 48, -4);
	glVertex3f(20, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 3 Part 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex3f(20, 34, -4);
	glVertex3f(20, 48.5, -4);
	glVertex3f(20.5, 48.5, -4);
	glVertex3f(20.5, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 3 Part 3
	glColor3ub(79, 92, 100);
	glVertex3f(20.5, 34, -4);
	glVertex3f(20.5, 48, -4);
	glVertex3f(21.5, 48, -4);
	glVertex3f(21.5, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 3 Windows Right
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(20.6, 34.4+y);
		glVertex2f(20.6, 34.6+y);
		glVertex2f(21.4, 34.6+y);
		glVertex2f(21.4, 34.4+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 4 Part 1
	glColor3ub(46, 65, 81);
	glVertex3f(23.5, 34, -4);
	glVertex3f(23.5, 48, -4);
	glVertex3f(24, 48, -4);
	glVertex3f(24, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 4 Part 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex3f(24, 34, -4);
	glVertex3f(24, 48.5, -4);
	glVertex3f(24.5, 48.5, -4);
	glVertex3f(24.5, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 4 Part 3
	glColor3ub(79, 92, 100);
	glVertex3f(24.5, 34, -4);
	glVertex3f(24.5, 48, -4);
	glVertex3f(25.5, 48, -4);
	glVertex3f(25.5, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 4 Windows Right
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(24.6, 34.4+y);
		glVertex2f(24.6, 34.6+y);
		glVertex2f(25.4, 34.6+y);
		glVertex2f(25.4, 34.4+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 5
	glColor3ub(69, 93, 103);
	glVertex3f(28, 38, -3);
	glVertex3f(28, 45, -3);
	glVertex3f(30, 45, -3);
	glVertex3f(30, 38, -3);
	glEnd();
	
	for(float y=0; y<2; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 5 Windows
		glColor3ub(51, 75, 86);	
		glVertex2f(28.2+y, 38.4);
		glVertex2f(28.2+y, 44.6);
		glVertex2f(28.3+y, 44.6);
		glVertex2f(28.3+y, 38.4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 6 Face 1
	glColor3ub(59, 81, 90);
	glVertex3f(29.5, 38, -5);
	glVertex3f(29.5, 52, -5);
	glVertex3f(32.5, 52.5, -5);
	glVertex3f(32.5, 38, -5);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 6 Face 1 Windows
		glColor3ub(48, 70, 79);	
		glVertex3f(29.7, 38.6+y, -4);
		glVertex3f(29.7, 38.8+y, -4);
		glVertex3f(32.3, 38.8+y, -4);
		glVertex3f(32.3, 38.6+y, -4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 6 Face 1 Antenna
	glColor3ub(74, 89, 102);
	glVertex3f(31.5, 52, -4);
	glVertex3f(31.5, 54, -4);
	glVertex3f(31.8, 52, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 6 Face 2
	glColor3ub(194, 190, 170);
	glVertex3f(32.5, 38, -5);
	glVertex3f(32.5, 52.5, -5);
	glVertex3f(33.5, 52, -5);
	glVertex3f(33.5, 38, -5);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 6 Face 2 Windows
		glColor3ub(76, 89, 93);	
		glVertex2f(32.6, 38.6+y);
		glVertex2f(32.6, 38.8+y);
		glVertex2f(33.4, 38.8+y);
		glVertex2f(33.4, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 7
	glColor3ub(63, 90, 97);
	glVertex3f(33.3, 38, -3);
	glVertex3f(33.3, 45, -3);
	glVertex3f(35, 45, -3);
	glVertex3f(35, 38, -3);
	glEnd();
	
	for(float y=0; y<2; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 7 Windows
		glColor3ub(51, 75, 86);	
		glVertex2f(33.6+y, 38.4);
		glVertex2f(33.6+y, 44.6);
		glVertex2f(33.7+y, 44.6);
		glVertex2f(33.7+y, 38.4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 8
	glColor3ub(55, 79, 89);
	glVertex3f(35, 38, -4);
	glVertex3f(35, 45, -4);
	glVertex3f(36, 45, -4);
	glVertex3f(36, 38, -4);
	glEnd();
	
	for(float y=0; y<6; y+=0.8) {
		glBegin(GL_POLYGON);						//Building 8 Windows
		glColor3ub(51, 66, 75);	
		glVertex2f(35.2, 38.4+y);
		glVertex2f(35.2, 38.6+y);
		glVertex2f(36.4, 38.6+y);
		glVertex2f(36.4, 38.4+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 9
	glColor3ub(55, 79, 89);
	glVertex3f(36, 38, -4);
	glVertex3f(36, 50, -4);
	glVertex3f(36.5, 50, -4);
	glVertex3f(36.5, 38, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 9 Windows
		glColor3ub(76, 89, 93);	
		glVertex2f(32.6, 38.6+y);
		glVertex2f(32.6, 38.8+y);
		glVertex2f(33.4, 38.8+y);
		glVertex2f(33.4, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 10 Face 1
	glColor3ub(59, 80, 89);
	glVertex3f(36.7, 38, -4);
	glVertex3f(36.7, 50, -4);
	glVertex3f(37.6, 50, -4);
	glVertex3f(37.6, 38, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 10 Face 1 Windows
		glColor3ub(76, 89, 93);	
		glVertex2f(36.8, 38.6+y);
		glVertex2f(36.8, 38.8+y);
		glVertex2f(37.4, 38.8+y);
		glVertex2f(37.4, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 10 Top Face 1
	glColor3ub(59, 80, 89);
	glVertex3f(36.9, 50, -4);
	glVertex3f(36.9, 51, -4);
	glVertex3f(37.6, 51, -4);
	glVertex3f(37.6, 50, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 10 Face 2
	glColor3ub(167, 168, 149);
	glVertex3f(37.6, 38, -4);
	glVertex3f(37.6, 50, -4);
	glVertex3f(38.5, 50, -4);
	glVertex3f(38.5, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 10 Top Face 2
	glColor3ub(167, 168, 149);
	glVertex3f(37.6, 50, -4);
	glVertex3f(37.6, 51, -4);
	glVertex3f(38.3, 51, -4);
	glVertex3f(38.3, 50, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 11
	glColor3ub(55, 79, 89);
	glVertex3f(36.5, 38, -4);
	glVertex3f(36.5, 48, -4);
	glVertex3f(37.3, 48, -4);
	glVertex3f(37.3, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 11 Top
	glColor3ub(105, 127, 136);
	glVertex3f(36.5, 48, -4);
	glVertex3f(36.5, 48.4, -4);
	glVertex3f(37.3, 48.4, -4);
	glVertex3f(37.3, 48, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 12
	glColor3ub(105, 127, 136);
	glVertex3f(41, 40, -4);
	glVertex3f(41, 50, -4);
	glVertex3f(44, 50, -4);
	glVertex3f(44, 40, -4);
	glEnd();
	
	for(float y=2; y<11; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 12 Windows
		glColor3ub(76, 89, 93);	
		glVertex2f(41.2, 38.6+y);
		glVertex2f(41.2, 38.8+y);
		glVertex2f(43.8, 38.8+y);
		glVertex2f(43.8, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 12 Top
	glColor3ub(110, 127, 140);
	glVertex3f(41.5, 50, -4);
	glVertex3f(41.5, 50.3, -4);
	glVertex3f(41.7, 50.3, -4);
	glVertex3f(41.7, 50.5, -4);
	glVertex3f(43.2, 50.5, -4);
	glVertex3f(43.2, 50.3, -4);
	glVertex3f(43.5, 50.3, -4);
	glVertex3f(43.5, 50, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Left Face
	glColor3ub(71, 94, 106);
	glVertex3f(47.3, 38, -4);
	glVertex3f(47.3, 52.8, -4);
	glVertex3f(48, 52.8, -4);
	glVertex3f(48, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Right Face
	glColor3ub(62, 84, 93);
	glVertex3f(48, 38, -4);
	glVertex3f(48, 52, -4);
	glVertex3f(51, 52, -4);
	glVertex3f(51, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Triangular Outer-Top
	glColor3ub(142, 162, 172);
	glVertex3f(47.1, 53, -3);
	glVertex3f(48, 51, -3);
	glVertex3f(51.1, 52, -3);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Triangular Inner-Top
	glColor3ub(84, 103, 115);
	glVertex3f(47.3, 52.8, -2);
	glVertex3f(48, 51.3, -2);
	glVertex3f(51, 52.2, -2);
	glEnd();
			
	glBegin(GL_POLYGON);							//Building 13 Antenna Bottom
	glColor3ub(86, 97, 123);
	glVertex3f(48, 53, -4);
	glVertex3f(48, 53.6, -4);
	glVertex3f(48.2, 53.6, -4);
	glVertex3f(48.2, 53, -4);
	glEnd();
	
	glColor3ub(72, 86, 109);						//Building 13 Antenna Bottom Sphere
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(48.1, 54.0, -4);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();
	
	glColor3ub(100, 112, 128);						//Building 13 Antenna Top Sphere
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(48.1, 54.6, -4);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glBegin(GL_POLYGON);							//Building 13 Antenna Top
	glColor3ub(79, 118, 150);
	glVertex3f(48.0, 54.6, -4);
	glVertex3f(48.1, 57, -4);
	glVertex3f(48.2, 54.6, -4);
	glEnd();
	
	for(float y=4; y<14; y+=0.7) {
		glBegin(GL_POLYGON);						//Building 13 Windows
		glColor3ub(49, 69, 78);	
		glVertex2f(48.5, 35.6+y);
		glVertex2f(48.5, 35.8+y);
		glVertex2f(50.4, 36.4+y);
		glVertex2f(50.4, 36.2+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 14 Bottom
	glColor3ub(54, 69, 79);
	glVertex3f(54, 25, -4);
	glVertex3f(54, 32, -4);
	glVertex3f(57, 32, -4);
	glVertex3f(57, 25, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Middle
	glColor3ub(58, 75, 84);
	glVertex3f(54, 32, -2);
	glVertex3f(53.6, 34, -2);
	glVertex3f(57.4, 34, -2);
	glVertex3f(57, 32, -2);
	glEnd();
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glBegin(GL_POLYGON);							//Building 14 Top
	glColor3ub(62, 76, 82);
	glVertex3f(53.6, 34, -2);
	glVertex3f(53.6, 38, -2);
	glVertex3f(54, 39, -2);
	glVertex3f(57, 39, -2);
	glVertex3f(57.4, 38, -2);
	glVertex3f(57.4, 34, -2);
	glEnd();
	glPopMatrix();
	
	for(float y=2; y<10; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 14 Left Windows
		glColor3ub(76, 89, 93);	
		glVertex2f(54.2, 25.6+y);
		glVertex2f(54.2, 25.8+y);
		glVertex2f(54.8, 25.8+y);
		glVertex2f(54.8, 25.6+y);
		glEnd();
	}
	
	for(float y=7; y<12; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 14 Right Windows
		glColor3ub(76, 89, 93);	
		glVertex2f(56.2, 25.6+y);
		glVertex2f(56.2, 25.8+y);
		glVertex2f(56.8, 25.8+y);
		glVertex2f(56.8, 25.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 15 Bottom
	glColor3ub(83, 97, 108);
	glVertex3f(59, 37.5, -4);
	glVertex3f(59, 45, -4);
	glVertex3f(60.3, 44.7, -4);
	glVertex3f(61.5, 45, -4);
	glVertex3f(61.5, 37.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 15 Middle
	glColor3ub(93, 106, 113);
	glVertex3f(59.2, 44.9, -4);
	glVertex3f(59.2, 48, -4);
	glVertex3f(60.3, 47.7, -4);
	glVertex3f(61.3, 48, -4);
	glVertex3f(61.3, 44.9, -4);
	glVertex3f(60.3, 44.7, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 15 Top
	glColor3ub(93, 106, 113);
	glVertex3f(59.4, 47.8, -4);
	glVertex3f(59.4, 50, -4);
	glVertex3f(60.3, 49.7, -4);
	glVertex3f(61.1, 50, -4);
	glVertex3f(61.1, 48, -4);
	glVertex3f(60.3, 47.6, -4);
	glEnd();
	
	for(float y=3; y<9; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 15 Windows Left
		glColor3ub(52, 81, 108);	
		glVertex2f(59.3, 35.6+y);
		glVertex2f(59.3, 35.8+y);
		glVertex2f(59.9, 35.8+y);
		glVertex2f(59.9, 35.6+y);
		glEnd();
	}
	
	for(float y=3; y<9; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 15 Windows Left
		glColor3ub(52, 81, 108);	
		glVertex2f(60.6, 35.6+y);
		glVertex2f(60.6, 35.8+y);
		glVertex2f(61.2, 35.8+y);
		glVertex2f(61.2, 35.6+y);
		glEnd();
	}
	
	EffielTower();									//Effiel Tower
	
	glBegin(GL_POLYGON);							//Building 16
	glColor3ub(105, 127, 136);
	glVertex3f(72, 40, -4);
	glVertex3f(72, 53, -4);
	glVertex3f(75, 53, -4);
	glVertex3f(75, 40, -4);
	glEnd();
	
	for(int y=0; y<12; y+=2){
		glBegin(GL_POLYGON);						//Building 16 Windows
		glColor3f(0.161, 0.188, 0.1);	
		glVertex2f(72.4, 41.0+y);
		glVertex2f(72.4, 41.5+y);
		glVertex2f(74.5, 41.5+y);
		glVertex2f(74.5, 41.0+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 17 Part 1
	glColor3ub(46, 65, 81);
	glVertex3f(77.5, 34, -4);
	glVertex3f(77.5, 48, -4);
	glVertex3f(78, 48, -4);
	glVertex3f(78, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 17 Part 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex3f(78, 34, -4);
	glVertex3f(78, 48.5, -4);
	glVertex3f(78.5, 48.5, -4);
	glVertex3f(78.5, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 17 Part 3
	glColor3ub(79, 92, 100);	
	glVertex3f(78.5, 34, -4);
	glVertex3f(78.5, 48, -4);
	glVertex3f(79.5, 48, -4);
	glVertex3f(79.5, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 17 Windows Right
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(78.6, 34.4+y);
		glVertex2f(78.6, 34.6+y);
		glVertex2f(79.4, 34.6+y);
		glVertex2f(79.4, 34.4+y);
		glEnd();
	}
	
	glLineWidth(1.5);								//Building 17 Antenna Pole
	glBegin(GL_LINES);
	glColor3f(0.4, 0.424, 0.463);
	glVertex3f(79, 48, -4);
	glVertex3f(79, 50, -4);
	glEnd();
	
	glColor3f(0.8, 0.0, 0.0);						//Building 17 Antenna Bulb
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(79., 50, -3.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glBegin(GL_POLYGON);							//Building 18
	glColor3ub(71, 80, 78);
	glVertex3f(82, 34, -4);
	glVertex3f(82, 50, -4);
	glVertex3f(88, 50, -4);
	glVertex3f(88, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 1
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(82.5, 34.8+y);
		glVertex2f(82.5, 35.6+y);
		glVertex2f(83.0, 35.6+y);
		glVertex2f(83.0, 34.8+y);
		glEnd();
	}
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 2
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(83.7, 34.8+y);
		glVertex2f(83.7, 35.6+y);
		glVertex2f(84.2, 35.6+y);
		glVertex2f(84.2, 34.8+y);
		glEnd();
	}
	
	glLineWidth(4);									//Building 18 Middle Window
	glBegin(GL_LINES);
	glColor3f(0.161, 0.188, 0.2);
	glVertex3f(85, 35, -3);
	glVertex3f(85, 48, -3);
	glEnd();
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 3
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(85.9, 34.8+y);
		glVertex2f(85.9, 35.6+y);
		glVertex2f(86.4, 35.6+y);
		glVertex2f(86.4, 34.8+y);
		glEnd();
	}
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 4
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(87, 34.8+y);
		glVertex2f(87, 35.6+y);
		glVertex2f(87.5, 35.6+y);
		glVertex2f(87.5, 34.8+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 19 Face 1
	glColor3ub(71, 90, 108);
	glVertex3f(90, 25, -4);
	glVertex3f(90, 35, -4);
	glVertex3f(95, 34, -4);
	glVertex3f(95, 24, -4);
	glEnd();
	
	for(float y=0; y<8; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 19 Windows
		glColor3f(0.161, 0.188, 0.2);	
		glVertex2f(90.4, 25.9+y);
		glVertex2f(90.4, 26.6+y);
		glVertex2f(94.5, 25.8+y);
		glVertex2f(94.5, 25.1+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 19 Face 2
	glColor3ub(159, 136, 121);
	glVertex3f(95, 24, -4);
	glVertex3f(95, 34, -4);
	glVertex3f(97, 35, -4);
	glVertex3f(97, 25, -4);
	glEnd();
	
	glLineWidth(3);									//Building 19 Face 2 Vertical Window
	glBegin(GL_LINES);
	glColor3f(0.435, 0.376, 0.345);
	glVertex3f(96, 25, -3);
	glVertex3f(96, 33.5, -3);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 19 Top
	glColor3ub(111, 135, 154);
	glVertex3f(90, 35, -4);
	glVertex3f(92, 36.3, -4);
	glVertex3f(97, 35, -4);
	glVertex3f(95, 34, -4);
	glEnd();
	
	//	BUILDING SHADOWS
	
	glBegin(GL_POLYGON);							//Building 1 Shadow
	glColor3ub(62, 80, 87);	
	glVertex3f(2, 40, -4);
	glVertex3f(5, 40, -4);
	glVertex3f(8-shd, 30, -4);
	glVertex3f(5-shd, 30, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 2 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(10, 36, -4);
	glVertex3f(15, 36, -4);
	glVertex3f(20-(shd*1.4), 24, -4);
	glVertex3f(15-(shd*1.4), 24, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 3 Shadow
	glColor3ub(62, 80, 87);	
	glVertex3f(19.5, 34, -4);
	glVertex3f(21.5, 34, -4);
	glVertex3f(25.0-shd, 26, -4);
	glVertex3f(23.0-shd, 26, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 4 Shadow
	glVertex3f(23.5, 34, -4);
	glVertex3f(25.5, 34, -4);
	glVertex3f(29.0-shd, 26, -4);
	glVertex3f(27.0-shd, 26, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 5 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(28, 38, -4);
	glVertex3f(32-shd*0.7, 34, -4);
	glVertex3f(34-shd*0.7, 34, -4);
	glVertex3f(30, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 6 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(30, 38, -5);
	glVertex3f(33.3, 38, -5);
	glVertex3f(38.5-shd*0.9, 33, -5);
	glVertex3f(35-shd*0.9, 33, -5);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 7 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(33.3, 38, -4);
	glVertex3f(35, 38, -4);
	glVertex3f(39.2-shd*0.7, 34.5, -4);
	glVertex3f(37.5-shd*0.7, 34.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 8 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(35, 38, -4);
	glVertex3f(36.5, 38, -4);
	glVertex3f(40.5-shd*0.7, 34.5, -4);
	glVertex3f(39.2-shd*0.7, 34.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 9 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(36, 38, -4);
	glVertex3f(36.5, 38, -4);
	glVertex3f(41.5-shd*0.8, 33, -4);
	glVertex3f(41-shd*0.8, 33, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 10 & 11 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(36.7, 38, -4);
	glVertex3f(38.4, 38, -4);
	glVertex3f(43.3-shd*0.8, 32, -4);
	glVertex3f(41.4-shd*0.8, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 12 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(41, 40, -4);
	glVertex3f(44, 40, -4);
	glVertex3f(49.2-shd*0.8, 35, -4);
	glVertex3f(46.2-shd*0.8, 35, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(47.3, 38, -4);
	glVertex3f(51, 38, -4);
	glVertex3f(57-shd*0.82, 32, -4);
	glVertex3f(53-shd*0.82, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Antenna Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(54.0-shd*0.82, 32, -4);
	glVertex3f(55.8-shd*1.1, 29, -4);
	glVertex3f(54.2-shd*0.82, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Bottom Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(54, 25, -4);
	glVertex3f(57, 25, -4);
	glVertex3f(62-shd*0.7, 20, -4);
	glVertex3f(59-shd*0.7, 20, -4);	
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Middle Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(59-shd*0.7, 20, -4);
	glVertex3f(62-shd*0.7, 20, -4);
	glVertex3f(64.7-shd, 18.5, -4);
	glVertex3f(60.5-shd, 18.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 15 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(59, 37.5, -4);
	glVertex3f(61.5, 37.5, -4);
	glVertex3f(67.5-shd*0.8, 31, -4);
	glVertex3f(65-shd*0.8, 31, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Effiel Tower Shadow
	glColor3ub(62, 80, 87);	
	glVertex3f(65.4, 34, -4);
	glVertex3f(70.4, 34, -4);
	glVertex3f(71.4-shd*0.8, 16, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 16 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(72, 40, -5);
	glVertex3f(75, 40, -5);
	glVertex3f(83-shd*0.8, 33, -5);
	glVertex3f(80-shd*0.8, 33, -5);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 17 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(77.5, 34, -4);
	glVertex3f(79.5, 34, -4);
	glVertex3f(88-shd*0.8, 26, -4);
	glVertex3f(86-shd*0.8, 26, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 18 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(82, 34, -4);
	glVertex3f(88, 34, -4);
	glVertex3f(96-shd*0.7, 25, -4);
	glVertex3f(90-shd*0.7, 25, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 19 Face 1 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(90, 25, -4);
	glVertex3f(95, 24, -4);
	glVertex3f(103-shd*0.7, 17, -4);
	glVertex3f(98-shd*0.7, 18, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 19 Face 2 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(95, 24, -4);
	glVertex3f(97, 25, -4);
	glVertex3f(105-shd*0.7, 18, -4);
	glVertex3f(103-shd*0.7, 17, -4);
	glEnd();
	
	//SUN
	
	glColor3f(1.0, sunColor, 0.0);						//SUN
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(sunx, suny, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(2.0, 40, 40);
	glPopMatrix();
	
	glutSwapBuffers;
	glFlush();
	
}

void Display2() {
	
	glClearColor(bk2Color1, bk2Color2, bk2Color3, 0.0);						//Sky
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				
	
	glBegin(GL_POLYGON);													//Background
	glColor3ub(100-ground, 110-ground, 120-ground);
	glVertex3i(0, 43, -9);
	glColor3ub(134-ground*0.5, 134-ground*0.3, 157-ground*0.3);
	glVertex3i(100, 43, -9);
	glColor3ub(43-ground*0.2, 56-ground*0.2, 64-ground*0.2);
	glVertex3i(100, 0, -9);
	glColor3ub(31-ground*0.2, 48-ground*0.2, 60-ground*0.2);
	glVertex3i(0, 0, -9);
	glEnd();
	
	//BUILDINGS AND WINDOWS
	
	glBegin(GL_POLYGON);							//Building 1
	glColor3f(0.34, 0.46, 0.52);	
	glVertex3f(2, 40, -4);
	glVertex3f(2, 55, -4);
	glVertex3f(2.6, 55.0, -4);
	glVertex3f(2.6, 55.2, -4);
	glVertex3f(4.4, 55.2, -4);
	glVertex3f(4.4, 55.0, -4);
	glVertex3f(5, 55, -4);
	glVertex3f(5, 40, -4);
	glEnd();
	
	for(int y=0; y<12; y+=2){
		glBegin(GL_POLYGON);						//Building 1 Windows
		glColor3f(0.161+windows*0.7, 0.188+windows*0.7, 0.1-windows*0.1);	
		glVertex2f(2.4, 42.0+y);
		glVertex2f(2.4, 42.5+y);
		glVertex2f(4.5, 42.5+y);
		glVertex2f(4.5, 42.0+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 2
	glColor3f(0.34, 0.46, 0.52);	
	glVertex3f(10, 36, -4);
	glVertex3f(10, 55, -4);
	glVertex3f(12.6, 56, -4);
	glVertex3f(13.0, 56, -4);
	glVertex3f(15, 55, -4);
	glVertex3f(15, 36, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 2 Strip 1
	glColor3ub(69, 88, 104);	
	glVertex2f(10.6, 36);
	glVertex2f(10.6, 54);
	glVertex2f(10.8, 54);
	glVertex2f(10.8, 36);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 2 Strip 2	
	glColor3ub(69, 88, 104);
	glVertex2f(11.3, 36);
	glVertex2f(11.3, 54.5);
	glVertex2f(11.5, 54.5);
	glVertex2f(11.5, 36);
	glEnd();
	
	for(float y=0; y<15; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 2 Windows Left
		glColor3f(0.161+windows*0.7, 0.188+windows*0.7, 0.1-windows*0.1);	
		glVertex2f(11.7, 38+y);
		glVertex2f(11.7, 38.2+y);
		glVertex2f(12.2, 38.2+y);
		glVertex2f(12.2, 38+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 2 Strip 3
	glColor3ub(49, 69, 87);	
	glVertex2f(12.6, 36);
	glVertex2f(12.6, 55);
	glVertex2f(13.0, 55);
	glVertex2f(13.0, 36);
	glEnd();
	
	for(float y=0; y<15; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 2 Windows Right
		glColor3ub(52+windows*157, 81+windows*128, 108-windows*108);	
		glVertex2f(13.4, 38+y);
		glVertex2f(13.4, 38.2+y);
		glVertex2f(14.4, 38.2+y);
		glVertex2f(14.4, 38+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 3 Part 1
	glColor3ub(46, 65, 81);
	glVertex3f(19.5, 34, -4);
	glVertex3f(19.5, 48, -4);
	glVertex3f(20, 48, -4);
	glVertex3f(20, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 3 Part 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex3f(20, 34, -4);
	glVertex3f(20, 48.5, -4);
	glVertex3f(20.5, 48.5, -4);
	glVertex3f(20.5, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 3 Part 3
	glColor3ub(79, 92, 100);
	glVertex3f(20.5, 34, -4);
	glVertex3f(20.5, 48, -4);
	glVertex3f(21.5, 48, -4);
	glVertex3f(21.5, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 3 Windows Right
		glColor3f(0.161+windows*0.8, 0.188+windows*0.8, 0.1-windows*0.1);	
		glVertex2f(20.6, 34.4+y);
		glVertex2f(20.6, 34.6+y);
		glVertex2f(21.4, 34.6+y);
		glVertex2f(21.4, 34.4+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 4 Part 1
	glColor3ub(46, 65, 81);
	glVertex3f(23.5, 34, -4);
	glVertex3f(23.5, 48, -4);
	glVertex3f(24, 48, -4);
	glVertex3f(24, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 4 Part 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex3f(24, 34, -4);
	glVertex3f(24, 48.5, -4);
	glVertex3f(24.5, 48.5, -4);
	glVertex3f(24.5, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 4 Part 3
	glColor3ub(79, 92, 100);
	glVertex3f(24.5, 34, -4);
	glVertex3f(24.5, 48, -4);
	glVertex3f(25.5, 48, -4);
	glVertex3f(25.5, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 4 Windows Right
		glColor3f(0.161+windows*0.8, 0.188+windows*0.8, 0.2-windows*0.2);	
		glVertex2f(24.6, 34.4+y);
		glVertex2f(24.6, 34.6+y);
		glVertex2f(25.4, 34.6+y);
		glVertex2f(25.4, 34.4+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 5
	glColor3ub(69, 93, 103);
	glVertex3f(28, 38, -3);
	glVertex3f(28, 45, -3);
	glVertex3f(30, 45, -3);
	glVertex3f(30, 38, -3);
	glEnd();
	
	for(float y=0; y<2; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 5 Windows
		//glColor3ub(51, 75, 86);
		glColor3ub(51+windows*128, 75+windows*104, 86-windows*86);	
		glVertex2f(28.2+y, 38.4);
		glVertex2f(28.2+y, 44.6);
		glVertex2f(28.3+y, 44.6);
		glVertex2f(28.3+y, 38.4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 6 Face 1
	glColor3ub(59, 81, 90);
	glVertex3f(29.5, 38, -5);
	glVertex3f(29.5, 52, -5);
	glVertex3f(32.5, 52.5, -5);
	glVertex3f(32.5, 38, -5);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 6 Face 1 Windows
		//glColor3ub(48, 70, 79);	
		glColor3ub(48+windows*181, 70+windows*159, 79-windows*79);
		glVertex3f(29.7, 38.6+y, -4);
		glVertex3f(29.7, 38.8+y, -4);
		glVertex3f(32.3, 38.8+y, -4);
		glVertex3f(32.3, 38.6+y, -4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 6 Face 1 Antenna
	glColor3ub(74, 89, 102);
	glVertex3f(31.5, 52, -4);
	glVertex3f(31.5, 54, -4);
	glVertex3f(31.8, 52, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 6 Face 2
	glColor3ub(194, 190, 170);
	glVertex3f(32.5, 38, -5);
	glVertex3f(32.5, 52.5, -5);
	glVertex3f(33.5, 52, -5);
	glVertex3f(33.5, 38, -5);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 6 Face 2 Windows
		//glColor3ub(76, 89, 93);
		glColor3ub(76+windows*153, 89+windows*140, 93-windows*93);	
		glVertex2f(32.6, 38.6+y);
		glVertex2f(32.6, 38.8+y);
		glVertex2f(33.4, 38.8+y);
		glVertex2f(33.4, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 7
	glColor3ub(63, 90, 97);
	glVertex3f(33.3, 38, -3);
	glVertex3f(33.3, 45, -3);
	glVertex3f(35, 45, -3);
	glVertex3f(35, 38, -3);
	glEnd();
	
	for(float y=0; y<2; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 7 Windows
		//glColor3ub(51, 75, 86);
		glColor3ub(51+windows*128, 75+windows*104, 86-windows*86);	
		glVertex2f(33.6+y, 38.4);
		glVertex2f(33.6+y, 44.6);
		glVertex2f(33.7+y, 44.6);
		glVertex2f(33.7+y, 38.4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 8
	glColor3ub(55, 79, 89);
	glVertex3f(35, 38, -4);
	glVertex3f(35, 45, -4);
	glVertex3f(36, 45, -4);
	glVertex3f(36, 38, -4);
	glEnd();
	
	for(float y=0; y<6; y+=0.8) {
		glBegin(GL_POLYGON);						//Building 8 Windows
		//glColor3ub(51, 66, 75);
		glColor3ub(51+windows*178, 66+windows*163, 75-windows*75);
		glVertex2f(35.2, 38.4+y);
		glVertex2f(35.2, 38.6+y);
		glVertex2f(36.4, 38.6+y);
		glVertex2f(36.4, 38.4+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 9
	glColor3ub(55, 79, 89);
	glVertex3f(36, 38, -4);
	glVertex3f(36, 50, -4);
	glVertex3f(36.5, 50, -4);
	glVertex3f(36.5, 38, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 9 Windows
		//glColor3ub(76, 89, 93);
		glColor3ub(76+windows*153, 89+windows*140, 93-windows*93);	
		glVertex2f(32.6, 38.6+y);
		glVertex2f(32.6, 38.8+y);
		glVertex2f(33.4, 38.8+y);
		glVertex2f(33.4, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 10 Face 1
	glColor3ub(59, 80, 89);
	glVertex3f(36.7, 38, -4);
	glVertex3f(36.7, 50, -4);
	glVertex3f(37.6, 50, -4);
	glVertex3f(37.6, 38, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 10 Face 1 Windows
		//glColor3ub(76, 89, 93);
		glColor3ub(76+windows*153, 89+windows*140, 93-windows*93);	
		glVertex2f(36.8, 38.6+y);
		glVertex2f(36.8, 38.8+y);
		glVertex2f(37.4, 38.8+y);
		glVertex2f(37.4, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 10 Top Face 1
	glColor3ub(59, 80, 89);
	glVertex3f(36.9, 50, -4);
	glVertex3f(36.9, 51, -4);
	glVertex3f(37.6, 51, -4);
	glVertex3f(37.6, 50, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 10 Face 2
	glColor3ub(167, 168, 149);
	glVertex3f(37.6, 38, -4);
	glVertex3f(37.6, 50, -4);
	glVertex3f(38.5, 50, -4);
	glVertex3f(38.5, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 10 Top Face 2
	glColor3ub(167, 168, 149);
	glVertex3f(37.6, 50, -4);
	glVertex3f(37.6, 51, -4);
	glVertex3f(38.3, 51, -4);
	glVertex3f(38.3, 50, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 11
	glColor3ub(55, 79, 89);
	glVertex3f(36.5, 38, -4);
	glVertex3f(36.5, 48, -4);
	glVertex3f(37.3, 48, -4);
	glVertex3f(37.3, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 11 Top
	glColor3ub(105, 127, 136);
	glVertex3f(36.5, 48, -4);
	glVertex3f(36.5, 48.4, -4);
	glVertex3f(37.3, 48.4, -4);
	glVertex3f(37.3, 48, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 12
	glColor3ub(105, 127, 136);
	glVertex3f(41, 40, -4);
	glVertex3f(41, 50, -4);
	glVertex3f(44, 50, -4);
	glVertex3f(44, 40, -4);
	glEnd();
	
	for(float y=2; y<11; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 12 Windows
		//glColor3ub(76, 89, 93);
		glColor3ub(76+windows*153, 89+windows*140, 93-windows*93);	
		glVertex2f(41.2, 38.6+y);
		glVertex2f(41.2, 38.8+y);
		glVertex2f(43.8, 38.8+y);
		glVertex2f(43.8, 38.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 12 Top
	glColor3ub(110, 127, 140);
	glVertex3f(41.5, 50, -4);
	glVertex3f(41.5, 50.3, -4);
	glVertex3f(41.7, 50.3, -4);
	glVertex3f(41.7, 50.5, -4);
	glVertex3f(43.2, 50.5, -4);
	glVertex3f(43.2, 50.3, -4);
	glVertex3f(43.5, 50.3, -4);
	glVertex3f(43.5, 50, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Left Face
	glColor3ub(71, 94, 106);
	glVertex3f(47.3, 38, -4);
	glVertex3f(47.3, 52.8, -4);
	glVertex3f(48, 52.8, -4);
	glVertex3f(48, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Right Face
	glColor3ub(62, 84, 93);
	glVertex3f(48, 38, -4);
	glVertex3f(48, 52, -4);
	glVertex3f(51, 52, -4);
	glVertex3f(51, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Triangular Outer-Top
	glColor3ub(142, 162, 172);
	glVertex3f(47.1, 53, -3);
	glVertex3f(48, 51, -3);
	glVertex3f(51.1, 52, -3);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Triangular Inner-Top
	glColor3ub(84, 103, 115);
	glVertex3f(47.3, 52.8, -2);
	glVertex3f(48, 51.3, -2);
	glVertex3f(51, 52.2, -2);
	glEnd();
			
	glBegin(GL_POLYGON);							//Building 13 Antenna Bottom
	glColor3ub(86, 97, 123);
	glVertex3f(48, 53, -4);
	glVertex3f(48, 53.6, -4);
	glVertex3f(48.2, 53.6, -4);
	glVertex3f(48.2, 53, -4);
	glEnd();
	
	glColor3ub(72, 86, 109);						//Building 13 Antenna Bottom Sphere
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(48.1, 54.0, -4);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();
	
	glColor3ub(100, 112, 128);						//Building 13 Antenna Top Sphere
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(48.1, 54.6, -4);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glBegin(GL_POLYGON);							//Building 13 Antenna Top
	glColor3ub(79, 118, 150);
	glVertex3f(48.0, 54.6, -4);
	glVertex3f(48.1, 57, -4);
	glVertex3f(48.2, 54.6, -4);
	glEnd();
	
	for(float y=4; y<14; y+=0.7) {
		glBegin(GL_POLYGON);						//Building 13 Windows
		//glColor3ub(49, 69, 78);
		glColor3ub(49+windows*180, 69+windows*160, 78-windows*78);	
		glVertex2f(48.5, 35.6+y);
		glVertex2f(48.5, 35.8+y);
		glVertex2f(50.4, 36.4+y);
		glVertex2f(50.4, 36.2+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 14 Bottom
	glColor3ub(54, 69, 79);
	glVertex3f(54, 25, -4);
	glVertex3f(54, 32, -4);
	glVertex3f(57, 32, -4);
	glVertex3f(57, 25, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Middle
	glColor3ub(58, 75, 84);
	glVertex3f(54, 32, -4);
	glVertex3f(53.6, 34, -4);
	glVertex3f(57.4, 34, -4);
	glVertex3f(57, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Top
	glColor3ub(62, 76, 82);
	glVertex3f(53.6, 34, -4);
	glVertex3f(53.6, 38, -4);
	glVertex3f(54, 39, -4);
	glVertex3f(57, 39, -4);
	glVertex3f(57.4, 38, -4);
	glVertex3f(57.4, 34, -4);
	glEnd();
	
	for(float y=2; y<10; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 14 Left Windows
		//glColor3ub(76, 89, 93);
		glColor3ub(76+windows*153, 89+windows*140, 93-windows*93);	
		glVertex2f(54.2, 25.6+y);
		glVertex2f(54.2, 25.8+y);
		glVertex2f(54.8, 25.8+y);
		glVertex2f(54.8, 25.6+y);
		glEnd();
	}
	
	for(float y=7; y<12; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 14 Right Windows
		//glColor3ub(76, 89, 93);
		glColor3ub(76+windows*153, 89+windows*140, 93-windows*93);	
		glVertex2f(56.2, 25.6+y);
		glVertex2f(56.2, 25.8+y);
		glVertex2f(56.8, 25.8+y);
		glVertex2f(56.8, 25.6+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 15 Bottom
	glColor3ub(83, 97, 108);
	glVertex3f(59, 37.5, -4);
	glVertex3f(59, 45, -4);
	glVertex3f(60.3, 44.7, -4);
	glVertex3f(61.5, 45, -4);
	glVertex3f(61.5, 37.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 15 Middle
	glColor3ub(93, 106, 113);
	glVertex3f(59.2, 44.9, -4);
	glVertex3f(59.2, 48, -4);
	glVertex3f(60.3, 47.7, -4);
	glVertex3f(61.3, 48, -4);
	glVertex3f(61.3, 44.9, -4);
	glVertex3f(60.3, 44.7, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 15 Top
	glColor3ub(93, 106, 113);
	glVertex3f(59.4, 47.8, -4);
	glVertex3f(59.4, 50, -4);
	glVertex3f(60.3, 49.7, -4);
	glVertex3f(61.1, 50, -4);
	glVertex3f(61.1, 48, -4);
	glVertex3f(60.3, 47.6, -4);
	glEnd();
	
	for(float y=3; y<9; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 15 Windows Left
		//glColor3ub(52, 81, 108);
		glColor3ub(52+windows*137, 81+windows*108, 108-windows*108);	
		glVertex2f(59.3, 35.6+y);
		glVertex2f(59.3, 35.8+y);
		glVertex2f(59.9, 35.8+y);
		glVertex2f(59.9, 35.6+y);
		glEnd();
	}
	
	for(float y=3; y<9; y+=0.5) {
		glBegin(GL_POLYGON);						//Building 15 Windows Left
		//glColor3ub(52, 81, 108);
		glColor3ub(52+windows*157, 81+windows*128, 108-windows*108);	
		glVertex2f(60.6, 35.6+y);
		glVertex2f(60.6, 35.8+y);
		glVertex2f(61.2, 35.8+y);
		glVertex2f(61.2, 35.6+y);
		glEnd();
	}
	
	EffielTower();									//Effiel Tower
	
	glBegin(GL_POLYGON);							//Building 16
	glColor3ub(105, 127, 136);
	glVertex3f(72, 40, -4);
	glVertex3f(72, 53, -4);
	glVertex3f(75, 53, -4);
	glVertex3f(75, 40, -4);
	glEnd();
	
	for(int y=0; y<12; y+=2){
		glBegin(GL_POLYGON);						//Building 16 Windows
		//glColor3f(0.161, 0.188, 0.1);
		glColor3f(0.161+windows*0.839, 0.188+windows*0.812, 0.1-windows*0.1);	
		glVertex2f(72.4, 41.0+y);
		glVertex2f(72.4, 41.5+y);
		glVertex2f(74.5, 41.5+y);
		glVertex2f(74.5, 41.0+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 17 Part 1
	glColor3ub(46, 65, 81);
	glVertex3f(77.5, 34, -4);
	glVertex3f(77.5, 48, -4);
	glVertex3f(78, 48, -4);
	glVertex3f(78, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 17 Part 2
	glColor3f(0.34, 0.46, 0.52);
	glVertex3f(78, 34, -4);
	glVertex3f(78, 48.5, -4);
	glVertex3f(78.5, 48.5, -4);
	glVertex3f(78.5, 34, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 17 Part 3
	glColor3ub(79, 92, 100);	
	glVertex3f(78.5, 34, -4);
	glVertex3f(78.5, 48, -4);
	glVertex3f(79.5, 48, -4);
	glVertex3f(79.5, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.2) {
		glBegin(GL_POLYGON);						//Building 17 Windows Right
		//glColor3f(0.161, 0.188, 0.2);
		glColor3f(0.161+windows*0.839, 0.188+windows*0.812, 0.2-windows*0.2);	
		glVertex2f(78.6, 34.4+y);
		glVertex2f(78.6, 34.6+y);
		glVertex2f(79.4, 34.6+y);
		glVertex2f(79.4, 34.4+y);
		glEnd();
	}
	
	glLineWidth(1.5);								//Building 17 Antenna Pole
	glBegin(GL_LINES);
	glColor3f(0.4, 0.424, 0.463);
	glVertex3f(79, 48, -4);
	glVertex3f(79, 50, -4);
	glEnd();
	
	glColor3f(0.8, 0.0, 0.0);						//Building 17 Antenna Bulb
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(79., 50, -3.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glBegin(GL_POLYGON);							//Building 18
	glColor3ub(71, 80, 78);
	glVertex3f(82, 34, -4);
	glVertex3f(82, 50, -4);
	glVertex3f(88, 50, -4);
	glVertex3f(88, 34, -4);
	glEnd();
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 1
		glColor3f(0.161+windows*0.839, 0.188+windows*0.812, 0.2-windows*0.2);	
		glVertex2f(82.5, 34.8+y);
		glVertex2f(82.5, 35.6+y);
		glVertex2f(83.0, 35.6+y);
		glVertex2f(83.0, 34.8+y);
		glEnd();
	}
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 2
		glColor3f(0.161+windows*0.839, 0.188+windows*0.812, 0.2-windows*0.2);	
		glVertex2f(83.7, 34.8+y);
		glVertex2f(83.7, 35.6+y);
		glVertex2f(84.2, 35.6+y);
		glVertex2f(84.2, 34.8+y);
		glEnd();
	}
	
	glLineWidth(4);									//Building 18 Middle Window
	glBegin(GL_LINES);
	glColor3f(0.161, 0.188, 0.2);
	glVertex3f(85, 35, -3);
	glVertex3f(85, 48, -3);
	glEnd();
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 3
		glColor3f(0.161+windows*0.839, 0.188+windows*0.812, 0.2-windows*0.2);	
		glVertex2f(85.9, 34.8+y);
		glVertex2f(85.9, 35.6+y);
		glVertex2f(86.4, 35.6+y);
		glVertex2f(86.4, 34.8+y);
		glEnd();
	}
	
	for(float y=0; y<13; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 18 Windows 4
		glColor3f(0.161+windows*0.839, 0.188+windows*0.812, 0.2-windows*0.2);	
		glVertex2f(87, 34.8+y);
		glVertex2f(87, 35.6+y);
		glVertex2f(87.5, 35.6+y);
		glVertex2f(87.5, 34.8+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 19 Face 1
	glColor3ub(71, 90, 108);
	glVertex3f(90, 25, -4);
	glVertex3f(90, 35, -4);
	glVertex3f(95, 34, -4);
	glVertex3f(95, 24, -4);
	glEnd();
	
	for(float y=0; y<8; y+=1.4) {
		glBegin(GL_POLYGON);						//Building 19 Windows
		//glColor3f(0.161+windows*0.9, 0.188+windows*0.9, 0.2-windows*0.2);
		glColor3ub(52+windows*157, 81+windows*128, 108-windows*108);
		glVertex2f(90.4, 25.9+y);
		glVertex2f(90.4, 26.6+y);
		glVertex2f(94.5, 25.8+y);
		glVertex2f(94.5, 25.1+y);
		glEnd();
	}
	
	glBegin(GL_POLYGON);							//Building 19 Face 2
	glColor3ub(159, 136, 121);
	glVertex3f(95, 24, -4);
	glVertex3f(95, 34, -4);
	glVertex3f(97, 35, -4);
	glVertex3f(97, 25, -4);
	glEnd();
	
	glLineWidth(3);									//Building 19 Face 2 Vertical Window
	glBegin(GL_LINES);
	glColor3f(0.435, 0.376, 0.345);
	glVertex3f(96, 25, -3);
	glVertex3f(96, 33.5, -3);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 19 Top
	glColor3ub(111, 135, 154);
	glVertex3f(90, 35, -4);
	glVertex3f(92, 36.3, -4);
	glVertex3f(97, 35, -4);
	glVertex3f(95, 34, -4);
	glEnd();
	
	//	BUILDING SHADOWS
	
	glBegin(GL_POLYGON);							//Building 1 Shadow
	glColor3ub(62, 80, 87);	
	glVertex3f(2, 40, -4);
	glVertex3f(5, 40, -4);
	glVertex3f(8-shd, 30, -4);
	glVertex3f(5-shd, 30, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 2 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(10, 36, -4);
	glVertex3f(15, 36, -4);
	glVertex3f(20-(shd*1.4), 24, -4);
	glVertex3f(15-(shd*1.4), 24, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 3 Shadow
	glColor3ub(62, 80, 87);	
	glVertex3f(19.5, 34, -4);
	glVertex3f(21.5, 34, -4);
	glVertex3f(25.0-shd, 26, -4);
	glVertex3f(23.0-shd, 26, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 4 Shadow
	glVertex3f(23.5, 34, -4);
	glVertex3f(25.5, 34, -4);
	glVertex3f(29.0-shd, 26, -4);
	glVertex3f(27.0-shd, 26, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 5 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(28, 38, -4);
	glVertex3f(32-shd*0.7, 34, -4);
	glVertex3f(34-shd*0.7, 34, -4);
	glVertex3f(30, 38, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 6 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(30, 38, -5);
	glVertex3f(33.3, 38, -5);
	glVertex3f(38.5-shd*0.9, 33, -5);
	glVertex3f(35-shd*0.9, 33, -5);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 7 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(33.3, 38, -4);
	glVertex3f(35, 38, -4);
	glVertex3f(39.2-shd*0.7, 34.5, -4);
	glVertex3f(37.5-shd*0.7, 34.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 8 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(35, 38, -4);
	glVertex3f(36.5, 38, -4);
	glVertex3f(40.5-shd*0.7, 34.5, -4);
	glVertex3f(39.2-shd*0.7, 34.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 9 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(36, 38, -4);
	glVertex3f(36.5, 38, -4);
	glVertex3f(41.5-shd*0.8, 33, -4);
	glVertex3f(41-shd*0.8, 33, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 10 & 11 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(36.7, 38, -4);
	glVertex3f(38.4, 38, -4);
	glVertex3f(43.3-shd*0.8, 32, -4);
	glVertex3f(41.4-shd*0.8, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 12 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(41, 40, -4);
	glVertex3f(44, 40, -4);
	glVertex3f(49.2-shd*0.8, 35, -4);
	glVertex3f(46.2-shd*0.8, 35, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(47.3, 38, -4);
	glVertex3f(51, 38, -4);
	glVertex3f(57-shd*0.82, 32, -4);
	glVertex3f(53-shd*0.82, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 13 Antenna Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(54.0-shd*0.82, 32, -4);
	glVertex3f(55.8-shd*1.1, 29, -4);
	glVertex3f(54.2-shd*0.82, 32, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Bottom Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(54, 25, -4);
	glVertex3f(57, 25, -4);
	glVertex3f(62-shd*0.7, 20, -4);
	glVertex3f(59-shd*0.7, 20, -4);	
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 14 Middle Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(59-shd*0.7, 20, -4);
	glVertex3f(62-shd*0.7, 20, -4);
	glVertex3f(64.7-shd, 18.5, -4);
	glVertex3f(60.5-shd, 18.5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 15 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(59, 37.5, -4);
	glVertex3f(61.5, 37.5, -4);
	glVertex3f(67.5-shd*0.8, 31, -4);
	glVertex3f(65-shd*0.8, 31, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Effiel Tower Shadow
	glColor3ub(62, 80, 87);	
	glVertex3f(65.4, 34, -4);
	glVertex3f(70.4, 34, -4);
	glVertex3f(71.4-shd*0.8, 16, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 16 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(72, 40, -5);
	glVertex3f(75, 40, -5);
	glVertex3f(83-shd*0.8, 33, -5);
	glVertex3f(80-shd*0.8, 33, -5);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 17 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(77.5, 34, -4);
	glVertex3f(79.5, 34, -4);
	glVertex3f(88-shd*0.8, 26, -4);
	glVertex3f(86-shd*0.8, 26, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 18 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(82, 34, -5);
	glVertex3f(88, 34, -5);
	glVertex3f(96-shd*0.7, 25, -5);
	glVertex3f(90-shd*0.7, 25, -5);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 19 Face 1 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(90, 25, -4);
	glVertex3f(95, 24, -4);
	glVertex3f(103-shd*0.7, 17, -4);
	glVertex3f(98-shd*0.7, 18, -4);
	glEnd();
	
	glBegin(GL_POLYGON);							//Building 19 Face 2 Shadow
	glColor3ub(62, 80, 87);
	glVertex3f(95, 24, -4);
	glVertex3f(97, 25, -4);
	glVertex3f(105-shd*0.7, 18, -4);
	glVertex3f(103-shd*0.7, 17, -4);
	glEnd();
	
	//MOON
	
	glColor3f(1.0, 1.0, 1.0);						//Moon
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(moonx, moony, -8.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(2.8, 40, 40);
	glPopMatrix();
	
	
	
	Stars1();
	Stars2();
	
	glutSwapBuffers;
	glFlush();
}

void Display3() {
		
	//glClearColor(1.0, 1.0, 1.0, 0.0);					//Sky
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				
	
	glBegin(GL_POLYGON);								//Lake
	glColor3ub(201, 194, 222);
	glVertex3i(0, 80, -9);
	glColor3ub(170, 190, 223);
	glVertex3i(70, 80, -9);
	glColor3ub(174, 197, 223);
	glVertex3i(100, 76, -9);
	glColor3ub(131, 176, 212);
	glVertex3i(100, 25, -9);
	glColor3ub(160, 182, 223);
	glVertex3i(0, 25, -9);
	glEnd();
	
	glBegin(GL_POLYGON);								//Mountains and Other in the Sky
	glColor3ub(239, 233, 232);
	glVertex3f(0, 100, -9);
	glColor3ub(156, 185, 168);
	glVertex3f(100, 100, -9);
	glColor3ub(172, 170, 146);
	glVertex3f(100, 76, -9);
	glColor3ub(187, 198, 189);
	glVertex3f(70, 80, -9);
	glColor3ub(237, 224, 187);
	glVertex3f(0, 80, -9);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 1 Left Top
	glColor3f(0.604, 0.463, 0.353);
	glVertex3f(7, 24, -5);
	glVertex3f(10, 27, -5);
	glVertex3f(12, 24, -5);
	glVertex3f(9, 22, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 1 Right Top
	glColor3ub(154, 118, 90);
	glVertex3f(10, 27, -5);
	glVertex3f(14, 25, -5);
	glVertex3f(15, 23, -5);
	glVertex3f(12, 24, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 1 Left Front
	glColor3ub(141, 132, 107);
	glVertex3f(7.5, 19.5, -5);
	glVertex3f(7.5, 23.5, -5);
	glVertex3f(10, 22, -5);
	glVertex3f(10, 17.5, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 1 Window
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(8.3, 20.5, -4);
	glVertex3f(8.3, 21.7, -4);
	glVertex3f(9, 21.3, -4);
	glVertex3f(9, 20, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 1 Door
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(11.8, 18, -5);
	glVertex3f(11.8, 21.5, -5);
	glVertex3f(12.5, 21.5, -5);
	glVertex3f(12.5, 18, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 1 Front
	glColor3ub(141, 132, 107);
	glVertex3f(10, 17.5, -5);
	glVertex3f(10, 22, -5);
	glVertex3f(12, 24, -5);
	glVertex3f(14, 23.5, -5);
	glVertex3f(14, 19, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 2 Left Top
	glColor3ub(158, 129, 95);
	glVertex3f(9, 16, -4);
	glVertex3f(10, 19, -4);
	glVertex3f(14, 19, -4);
	glVertex3f(13, 16, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 2 Right Top
	glColor3ub(158, 129, 95);
	glVertex3f(11, 17, -4);
	glVertex3f(10, 19, -4);
	glVertex3f(14, 19, -4);
	glVertex3f(15, 17, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 2 Body Left
	glColor3ub(162, 178, 191);
	glVertex3f(9.5, 14, -4);
	glVertex3f(9.5, 16, -4);
	glVertex3f(13, 16, -4);
	glVertex3f(13, 14, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 2 Window
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(10.7, 14.5, -3.8);
	glVertex3f(10.7, 15.7, -3.8);
	glVertex3f(11.5, 15.7, -3.8);
	glVertex3f(11.5, 14.5, -3.8);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 2 Body Right
	glColor3ub(162, 178, 191);
	glVertex3f(13, 14, -4);
	glVertex3f(13, 17.2, -4);
	glVertex3f(14.5, 17.2, -4);
	glVertex3f(14.5, 14.7, -4);
	glEnd();
	
	glLineWidth(6);										//Light Pole 1
	glBegin(GL_LINES);
	glColor3ub(52, 58, 34);
	glVertex3f(22, 13, -5);
	glVertex3f(22, 34, -5);
	glEnd();
	
	glLineWidth(6);										//Light Pole Horizontal
	glBegin(GL_LINES);
	glColor3ub(52, 58, 34);
	glVertex3f(21, 31, -5);
	glVertex3f(23, 32, -5);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//House 3
	glColor3ub(132, 147, 156);
	glVertex3f(18, 16, -4.9);
	glVertex3f(23, 22, -4.9);
	glVertex3f(28, 16, -4.9);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//House 4
	glColor3ub(164, 147, 134);
	glVertex3f(18, 15, -4.8);
	glVertex3f(23, 21, -4.8);
	glVertex3f(28, 15, -4.8);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//House 5 Top
	glColor3ub(122, 100, 91);
	glVertex3f(17.5, 13.5, -4.7);
	glVertex3f(22.5, 19.5, -4.7);
	glVertex3f(27.5, 13.5, -4.7);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 5 Top Right
	glColor3ub(142, 126, 118);
	glVertex3f(22.5, 19.5, -4.7);
	glVertex3f(29, 23, -4.7);
	glVertex3f(33.5, 17.5, -4.7);
	glVertex3f(27.5, 13.5, -4.7);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 5 Left
	glColor3ub(169, 136, 102);
	glVertex3f(18.5, 6, -4.5);
	glVertex3f(18.5, 13.5, -4.5);
	glVertex3f(27, 13.5, -4.5);
	glVertex3f(27, 6, -4.5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 5 Right
	glColor3ub(169, 136, 102);
	glVertex3f(27, 6, -5);
	glVertex3f(27, 13.5, -5);
	glVertex3f(33, 17.5, -5);
	glVertex3f(33, 10, -5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 5 Door
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(21, 6, -4);
	glVertex3f(21, 10, -4);
	glVertex3f(23, 10, -4);
	glVertex3f(23, 6, -4);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 5 Window
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(29.5, 10.5, -4.5);
	glVertex3f(29.5, 12, -4.5);
	glVertex3f(31, 13, -4.5);
	glVertex3f(31, 11.5, -4.5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 6
	glColor3ub(145, 88, 81);
	glVertex3f(5, 0, -5);
	glVertex3f(6, 6, -5);
	glVertex3f(13, 6, -5);
	glVertex3f(12, 0, -5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 7 Top Left
	glColor3ub(148, 135, 118);
	glVertex3f(33, 26, -5);
	glVertex3f(35, 28, -5);
	glVertex3f(36, 26.5, -5);
	glVertex3f(34, 25, -5);
	glEnd();
	
	glBegin(GL_TRIANGLES); 								//House 7 Triangle
	glColor3ub(125, 108, 97);
	glVertex3f(34, 25, -5);
	glVertex3f(35, 28, -5);
	glVertex3f(37, 25, -5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 7 Top Right
	glColor3ub(148, 135, 118);
	glVertex3f(33, 26, -5);
	glVertex3f(35, 28, -5);
	glVertex3f(36, 26.5, -5);
	glVertex3f(34, 25, -5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 7 Body left
	glColor3ub(134, 121, 85);
	glVertex3f(33.2, 23, -5);
	glVertex3f(33.2, 26, -5);
	glVertex3f(34, 25, -5);
	glVertex3f(34, 22, -5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 7 Body Right
	glColor3ub(134, 121, 85);
	glVertex3f(34, 22, -5);
	glVertex3f(34, 25, -5);
	glVertex3f(37, 25, -5);
	glVertex3f(37, 22, -5);
	glEnd();
	
	glBegin(GL_POLYGON); 								//House 7 Door
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(35, 22, -4.5);
	glVertex3f(35, 23.5, -4.5);
	glVertex3f(36, 23.5, -4.5);
	glVertex3f(36, 22, -4.5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Left Roof Left Beeding
	glColor3ub(179, 174, 180);
	glVertex3f(34.5, 5, -4);
	glVertex3f(36.5, 15, -4);
	glVertex3f(37, 15, -4);
	glVertex3f(35, 5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Left Roof
	glColor3ub(173, 117, 116);
	glVertex3f(35, 5, -4);
	glVertex3f(37, 15, -4);
	glVertex3f(53, 15, -4);
	glVertex3f(51, 5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Left Roof Right Beeding
	glColor3ub(179, 174, 180);
	glVertex3f(51, 5, -4);
	glVertex3f(53, 15, -4);
	glVertex3f(53, 14, -4);
	glVertex3f(52, 5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Right Roof Right Beeding
	glColor3ub(179, 174, 180);
	glVertex3f(52.5, 14, -4);
	glVertex3f(53, 15, -4);
	glVertex3f(55, 5, -4);
	glVertex3f(54, 5, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Body
	glColor3ub(132, 135, 171);
	glVertex3f(35.5, 0, -5);
	glVertex3f(35.5, 10, -5);
	glVertex3f(53, 12, -5);
	glVertex3f(54.5, 5, -5);
	glVertex3f(54.5, 0, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Door
	glColor3ub(80, 79, 80);
	glVertex3f(52.5, 0, -4);
	glVertex3f(52.5, 5, -4);
	glVertex3f(53.5, 5, -4);
	glVertex3f(53.5, 0, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 8 Top 1
	glColor3ub(137, 126, 135);
	glVertex3f(52, 15, -5);
	glVertex3f(52, 18, -5);
	glVertex3f(53, 18, -5);
	glVertex3f(53, 15, -5);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//House 8 Top 1
	glColor3ub(108, 103, 109);
	glVertex3f(52, 18, -5);
	glVertex3f(52.5, 22, -5);
	glVertex3f(53, 18, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 9 Top Left
	glColor3ub(115, 109, 108);
	glVertex3f(60, 11, -4);
	glVertex3f(63, 16, -4);
	glVertex3f(69.5, 13, -4);
	glVertex3f(66.5, 8, -4);
	glEnd();
	
	glLineWidth(10);
	glBegin(GL_LINES);									//House 9 Top Left Beeding
	glColor3ub(80, 83, 81);
	glVertex3f(66.5, 7.5, -5);
	glVertex3f(69.5, 12.5, -5);
	glEnd();
	
	glBegin(GL_LINES);									//House 9 Top Right Beeding
	glColor3ub(80, 83, 81);
	glVertex3f(69.5, 12.5, -5);
	glVertex3f(72.5, 7.8, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 9 Top Body Left
	glColor3ub(218, 208, 214);
	glVertex3f(61, 5, -5);
	glVertex3f(61, 12, -5);
	glVertex3f(68, 10, -5);
	glVertex3f(68, 0, -5);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 9 Top Body Front
	glColor3ub(198, 186, 159);
	glVertex3f(67.1, 0, -4);
	glVertex3f(67.1, 8, -4);
	glVertex3f(69.5, 12, -4);
	glVertex3f(72, 8, -4);
	glVertex3f(72, 0, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 9 Lower Top Left
	glColor3ub(90, 91, 82);
	glVertex3f(59, 6, -4);
	glVertex3f(61, 8, -4);
	glVertex3f(65.5, 5, -4);
	glVertex3f(63.5, 3, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 9 Lower Left body
	glColor3ub(75, 66, 29);
	glVertex3f(60, 0, -4);
	glVertex3f(60, 6, -4);
	glVertex3f(65.5, 5, -4);
	glVertex3f(65.5, 0, -4);
	glEnd();
	
	glBegin(GL_POLYGON);								//House 9 Door									
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(68.5, 0, -3.9);
	glVertex3f(68.5, 6, -3.9);
	glVertex3f(70.5, 6, -3.9);
	glVertex3f(70.5, 0, -3.9);
	glEnd();
	
	glLineWidth(6);										//Pole 2 Vertical
	glBegin(GL_LINES);
	glColor3ub(93, 77, 65);
	glVertex3f(80, 5, -4);
	glVertex3f(80, 20, -4);
	glEnd();
	
	glLineWidth(5);										//Pole 2 Horizontal
	glBegin(GL_LINES);
	glVertex3f(79, 17.5, -4);
	glVertex3f(81, 19, -4);
	glEnd();
	
	glLineWidth(2);										//Current Line
	glBegin(GL_LINE_STRIP);
	glColor3ub(80, 60, 26);
	glVertex3f(22, 32, -4.5);
	glVertex3f(33, 20, -4.5);
	glVertex3f(38, 16, -4.5);
	glVertex3f(45, 14, -4.5);
	glVertex3f(55, 13, -4.5);
	glVertex3f(65, 14, -4.5);
	glVertex3f(80, 18, -4.5);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//Bird
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(80-bird, 57+bird*0.2, -4);
	glVertex3f(80.3-bird, 58.5-bWing+(bird*0.2), -4);
	glVertex3f(80.5-bird, 57+bird*0.2, -4);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//Bird
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(80-bird, 57+bird*0.2, -4);
	glVertex3f(81.5-bird, 57+bird*0.2, -4);
	glVertex3f(80-bird, 56.6+bird*0.2, -4);
	glEnd();
	
	glBegin(GL_TRIANGLES);								//Bird
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(80-bird, 56.6+bird*0.2, -4);
	glVertex3f(79.8-bird, 57.3-(bWing*2.6)+(bird*0.2), -4);
	glVertex3f(80.5-bird, 57+bird*0.2, -4);
	glEnd();
	
	//SEA SHINE
	seaShine();
	
	// LAKE BORDER
	
	glLineWidth(4);										//Lake Border
	glBegin(GL_LINE_STRIP);
	glColor3ub(158, 144, 119);
	glVertex3f(0, 40, -8);
	glVertex3f(10, 35, -8);
	glVertex3f(15, 36, -8);
	glVertex3f(18, 35, -8);
	glVertex3f(21, 34, -8);
	glVertex3f(25, 33, -8);
	glVertex3f(27, 34.5, -8);
	glVertex3f(32, 31, -8);
	glVertex3f(42, 30, -8);
	glVertex3f(52, 32, -8);
	glVertex3f(59, 28, -8);
	glVertex3f(65, 30, -8);
	glVertex3f(69, 29, -8);
	glVertex3f(72, 34, -8);
	glVertex3f(76, 30, -8);
	glVertex3f(88, 26, -8);
	glVertex3f(90, 31, -8);
	glVertex3f(93, 28, -8);
	glVertex3f(100, 35, -8);
	glVertex3f(100, 0, -8);
	glVertex3f(0, 0, -8);
	glEnd();
	
	// BOTTOM BACKGROUND
	
	glBegin(GL_POLYGON);
	glColor3ub(82, 79, 44);
	glVertex3f(0, 0, -8);
	glVertex3f(0, 40, -8);
	glColor3ub(107, 119, 72);
	glVertex3f(10, 35, -8);
	glVertex3f(10, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(107, 119, 72);
	glVertex3f(10, 35, -8);
	glVertex3f(15, 36, -8);
	glVertex3f(15, 0, -8);
	glVertex3f(10, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(107, 119, 72);
	glVertex3f(15, 0, -8);
	glVertex3f(15, 36, -8);
	glColor3ub(85, 105, 86);
	glVertex3f(18, 35, -8);
	glVertex3f(18, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	//glColor3ub(85, 105, 86);
	glVertex3f(18, 0, -8);
	glVertex3f(18, 35, -8);
	//glColor3ub(62, 85, 49);
	glVertex3f(21, 34, -8);
	glVertex3f(21, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	//glColor3ub(62, 85, 49);
	glVertex3f(21, 0, -8);
	glVertex3f(21, 34, -8);
	//glColor3ub(151, 168, 92);
	glVertex3f(25, 33, -8);
	glVertex3f(25, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	//glColor3ub(151, 168, 92);
	glVertex3f(25, 0, -8);
	glVertex3f(25, 33, -8);
	//glColor3ub(81, 89, 67);
	glVertex3f(27, 34.5, -8);
	glVertex3f(27, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	//glColor3ub(81, 89, 67);
	glVertex3f(27, 0, -8);
	glVertex3f(27, 34.5, -8);
	glColor3ub(84, 98, 74);
	glVertex3f(32, 31, -8);
	glVertex3f(32, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(84, 98, 74);
	glVertex3f(32, 0, -8);
	glVertex3f(32, 31, -8);
	glColor3ub(107, 132, 88);
	glVertex3f(42, 30, -8);
	glVertex3f(42, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(107, 132, 88);
	glVertex3f(42, 0, -8);
	glVertex3f(42, 30, -8);
	glColor3ub(126, 167, 95);
	glVertex3f(52, 32, -8);
	glVertex3f(52, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(126, 167, 95);
	glVertex3f(52, 0, -8);
	glVertex3f(52, 32, -8);
	glColor3ub(128, 133, 64);
	glVertex3f(59, 28, -8);
	glVertex3f(59, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(128, 133, 64);
	glVertex3f(59, 0, -8);
	glVertex3f(59, 28, -8);
	//glColor3ub(54, 109, 90);
	glVertex3f(65, 30, -8);
	glVertex3f(65, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	//glColor3ub(54, 109, 90);
	glVertex3f(65, 0, -8);
	glVertex3f(65, 30, -8);
	glColor3ub(90, 145, 113);
	glVertex3f(69, 29, -8);
	glVertex3f(69, 0, -8);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3ub(90, 145, 113);
	glVertex3f(69, 0, -8);
	glVertex3f(69, 29, -8);
	//glColor3ub(67, 111, 72);
	glVertex3f(72, 34, -8);
	glVertex3f(72, 0, -8);
	glEnd();		
	
	glBegin(GL_POLYGON);
	//glColor3ub(67, 111, 72);
	glVertex3f(72, 0, -8);
	glVertex3f(72, 34, -8);
	//glColor3ub(75, 126, 43);
	glVertex3f(76, 30, -8);
	glVertex3f(76, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	//glColor3ub(75, 126, 43);
	glVertex3f(76, 0, -8);
	glVertex3f(76, 30, -8);
	glColor3ub(159, 176, 122);
	glVertex3f(88, 26, -8);
	glVertex3f(88, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(159, 176, 122);
	glVertex3f(88, 0, -8);
	glVertex3f(88, 26, -8);
	glColor3ub(179, 173, 78);
	glVertex3f(90, 31, -8);
	glVertex3f(90, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(179, 173, 78);
	glVertex3f(90, 0, -8);
	glVertex3f(90, 31, -8);
	glColor3ub(160, 153, 68);
	glVertex3f(93, 28, -8);
	glVertex3f(93, 0, -8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(160, 153, 68);
	glVertex3f(93, 0, -8);
	glVertex3f(93, 28, -8);
	glColor3ub(135, 155, 90);
	glVertex3f(100, 35, -8);
	glVertex3f(100, 0, -8);
	glEnd();
		
	glFlush();
	
}

void ThankYou() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	Stars1();
	Stars2();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(25.0, 55.0, 0.0);
	glScalef(0.1, 0.1, 0.1);
	output2("THANK");
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(34.0, 40.0, 0.0);
	glScalef(0.1, 0.1, 0.1);
	output2("YOU");
	glPopMatrix();
	
	glFlush();	
}

void output(char *s) {
	
	for(int k=0; k<strlen(s); k++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[k]);
}

void output2(char *s) {
	
	for(int k=0; k<strlen(s); k++) {
		glLineWidth(4);
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, s[k]);
	}
}

void EffielTower(){
	
	glLineWidth(1.9);										//Effiel Tower
	glBegin(GL_LINE_STRIP);
	glColor3f(0.8, 0.0, 0.0);	
	glVertex3f(65.4, 34, -4);
	glVertex3f(66.4, 38, -4);
	glVertex3f(69.4, 38, -4);
	glVertex3f(70.4, 34, -4);
	glEnd();
	
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(65.4, 34, -4);
		glVertex3f(69.4, 38, -4);
		glEnd();
		
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(65.4, 34, -4);
		glVertex3f(69.8, 36.5, -4);
		glEnd();
		
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(70.4, 34, -4);
		glVertex3f(66.4, 38, -4);
		glEnd();
		
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(70.4, 34, -4);
		glVertex3f(66, 36.5, -4);
		glEnd();
	
	glLineWidth(1.9);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.8, 0.0, 0.0);	
	glVertex3f(66.4, 38, -4);
	glVertex3f(66.9, 43, -4);
	glVertex3f(68.9, 43, -4);
	glVertex3f(69.4, 38, -4);
	glEnd();
	
	for(float i=0; i<5; i+=1.4) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(66.4, 38, -4);
		glVertex3f(69.25, 38+i, -4);
		glEnd();
	}
	
	for(float i=0; i<5; i+=1.4) {
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(69.5, 38, -4);
		glVertex3f(66.7, 38+i, -4);
		glEnd();
	}
	
	for(float i=0; i<5; i+=1.4) {
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(66.9, 43, -4);
		glVertex3f(69.1, 43-i, -4);
		glEnd();
	}
	
	for(float i=0; i<5; i+=1.4) {
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(68.9, 43, -4);
		glVertex3f(66.6, 43-i, -4);
		glEnd();
	}
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.894, 0.859);
	glVertex3f(66.8, 43, -3.0);
	glVertex3f(66.6, 44.7, -3.0);
	glVertex3f(69.2, 44.7, -3.0);
	glVertex3f(69, 43, -3.0);
	glEnd();
	
	for(float i=0; i<5; i+=1.4) {
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(67, 44.7, -4);
		glVertex3f(68.6, 44.7+i, -4);
		glEnd();
	}
	
	for(float i=0; i<5; i+=1.4) {
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(68.8, 44.7, -4);
		glVertex3f(67.2, 44.7+i, -4);
		glEnd();
	}
	
	glLineWidth(1.9);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.8, 0.0, 0.0);	
	glVertex3f(66.9, 43, -4);
	glVertex3f(67.9, 60, -4);
	glVertex3f(68.9, 43, -4);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(67.9, 35.5, -4);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(67.9, 58.8, -4);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(67.3, 49, -3);
	glVertex3f(67.5, 52, -3);
	glVertex3f(68.3, 52, -3);
	glVertex3f(68.5, 49, -3);
	glEnd();
	
	for(float i=0; i<5; i+=1.4) {
		glLineWidth(0.5);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(67.5, 52, -4);
		glVertex3f(68.25, 52+i, -4);
		glEnd();
	}
	
	for(float i=0; i<5; i+=1.4) {
		glLineWidth(0.5);
		glBegin(GL_LINES);
		glColor3f(0.7, 0.0, 0.0);
		glVertex3f(68.3, 52, -4);
		glVertex3f(67.6, 52+i, -4);
		glEnd();
	}
}

void Stars1() {
	
	//STARS
	
	glColor3f(glow1, glow1, glow1);						//Star 1
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(8, 85, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glColor3f(glow1, glow1, glow1);							//Star 2
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(30, 65, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();
	
	glColor3f(glow1, glow1, glow1);							//Star 3
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(50, 95, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glColor3f(glow1, glow1, glow1);						//Star 4
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(70, 75, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();
	
	glColor3f(glow1, glow1, glow1);						//Star 5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(90, 88, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
}

void Stars2() {
	//STARS
	
	glColor3f(glow2, glow2, glow2);						//Star 1.5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(18, 90, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glColor3f(glow2, glow2, glow2);							//Star 2.5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(40, 75, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.2, 40, 40);
	glPopMatrix();
	
	glColor3f(glow2, glow2, glow2);							//Star 3.5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(55, 78, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.3, 40, 40);
	glPopMatrix();
	
	glColor3f(glow2, glow2, glow2);							//Star 4.5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(80, 65, -9.0);
	glScalef(0.6, 1.0, 1.0);
	glutSolidSphere(0.4, 40, 40);
	glPopMatrix();
	
}

void seaShine() {
	
	for(float y=0; y<=36; y+=5) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 1
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(1, 42+y, -9.0-shine1*0.8);
		glScalef(0.4, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=5) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 2
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(2.3, 40+y, -9.0-shine2*0.9);
		glScalef(0.45, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=5) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 3
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(4, 42+y, -9.0-shine1*0.8);
		glScalef(0.5, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=5) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 4
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(6, 39+y, -9.0-shine2*0.9);
		glScalef(0.6, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=5) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 5
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(8, 41+y, -9.0-shine1*0.8);
		glScalef(0.7, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=5) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 6
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(10, 38+y, -9.0-shine2*0.9);
		glScalef(0.8, 0.32, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=6) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 7
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(12, 40+y, -9.0-shine1*0.8);
		glScalef(0.9, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
	
	for(float y=0; y<=36; y+=6) {
		glColor3f(1.0, 1.0, 1.0);						//Sea Shine 8
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(14, 38+y, -9.0-shine2*0.9);
		glScalef(1.0, 0.3, 1.0);
		glutSolidSphere(1, 100, 100);
		glPopMatrix();
	}
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(0.0, 52, 0.0*h/(GLfloat)w, 100.0*h/(GLfloat)w, -10.0, 10.0);

	else
		glOrtho(0.0*(GLfloat)w/(GLfloat)h, 52*(GLfloat)w/(GLfloat)h, 0.0, 100.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
}
