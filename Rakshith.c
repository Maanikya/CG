void Display3() {

	//mountain
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,204,0);
	glBegin(GL_POLYGON);
	glVertex2f(0,70);
	glVertex2f(57,75);
	glVertex2f(100,70);
	glVertex2f(100,100);
	glVertex2f(0,100);	
	glEnd();

	//ocean
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,70);
	glColor3f(0.10,0.55,1.0);
	glVertex2f(57,75);
	glVertex2f(100,70);
	glVertex2f(100,30);
	glVertex2f(45,34);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,30);
	glEnd();
	
	//DOWN
	glBegin(GL_POLYGON);
	glColor3f(0.30,0.60,0.00);
	glVertex2f(100,30);
	glColor3f(0.00,0.50,0.08);
	glVertex2f(45,34);
	glColor3f(0.10,0.30,0.00);
	glVertex2f(0,30);
	glVertex2f(0,0);
	glVertex2f(100,0);
	glEnd();
	
	//house1
	glColor3ub(148,98,101);
	glBegin(GL_POLYGON);
	glVertex2f(30,10);
	glColor3ub(148,98,101);
	glVertex2f(33.5,17);
	glVertex2f(42,17);
	glVertex2f(42,10);
	glEnd();
	
	glColor3ub(134,137,171);
	glBegin(GL_POLYGON);
	glVertex2f(30,10);
	glVertex2f(44,10);
	glVertex2f(44,0);
	glVertex2f(30,0);
	glEnd();
	
	glColor3ub(67,67,79);
	glBegin(GL_TRIANGLES);
	glVertex2f(39.5,10);
	glVertex2f(42,17);
	glVertex2f(44,10);
	glEnd();
	
	glColor3ub(91,99,119);
	glBegin(GL_TRIANGLES);
	glVertex2f(40,10.5);
	glVertex2f(42,16);
	glVertex2f(43.5,10.5);
	glEnd();
	
	glColor3ub(99,53,43);
	glBegin(GL_POINTS);
	glPointSize(16.0);
	glVertex2f(35,18);
	glEnd();
	
	glColor3ub(73,72,77);
	glBegin(GL_LINES);
	glLineWidth(16.0);
	glVertex2f(39.5,10);
	glVertex2f(39.5,0);
	glEnd();
	
	glColor3ub(73,72,77);
	glBegin(GL_POLYGON);
	glVertex2f(33,5);
	glVertex2f(33,7);
	glVertex2f(35,7);
	glVertex2f(35,5);
	glEnd();
	
	glColor3ub(73,72,77);
	glBegin(GL_POLYGON);
	glVertex2f(36,5);
	glVertex2f(36,7);
	glVertex2f(38,7);
	glVertex2f(38,5);
	glEnd();
	
	//house2
	glColor3ub(148,98,101);
	glBegin(GL_POLYGON);
	glVertex2f(50,20);
	glVertex2f(54,27);
	glVertex2f(62,27);
	glVertex2f(62,20);
	glEnd();
	
	glColor3ub(67,67,79);
	glBegin(GL_TRIANGLES);
	glVertex2f(59.5,20);
	glVertex2f(62,27);
	glVertex2f(64,20);
	glEnd();
	
	glColor3ub(91,99,119);
	glBegin(GL_TRIANGLES);
	glVertex2f(60,20.5);
	glVertex2f(62,26.5);
	glVertex2f(63.5,20.5);
	glEnd();
	
	glColor3ub(134,137,171);
	glBegin(GL_POLYGON);
	glVertex2f(50,20);
	glVertex2f(64,20);
	glVertex2f(64,10);
	glVertex2f(50,10);
	glEnd();
	
	glColor3ub(73,72,77);
	glBegin(GL_LINES);
	glLineWidth(4.0);
	glVertex2f(39.5,10);
	glVertex2f(39.5,0);
	glEnd();
	
	glColor3ub(73,72,77);
	glBegin(GL_POLYGON);
	glVertex2f(53,15);
	glVertex2f(53,17);
	glVertex2f(55,17);
	glVertex2f(55,15);
	glEnd();
	
	glColor3ub(73,72,77);
	glBegin(GL_POLYGON);
	glVertex2f(56,15);
	glVertex2f(56,17);
	glVertex2f(58,17);
	glVertex2f(58,15);
	glEnd();
	
	//boat
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(50,50);
	glVertex2f(53,55);
	glVertex2f(57,54.5);
	glVertex2f(56.5,49.7);
	glVertex2f(54,49.5);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLES);
	glVertex2f(53,55);
	glVertex2f(57,54.5);
	glVertex2f(55,56);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(50,50);
	glVertex2f(56.5,49.7);
	glColor3f(0.10,0.05,0.00);
	glVertex2f(56.2,48);
	glColor3f(0.10,0.05,0.00);
	glVertex2f(54,48.6);
	glColor3f(0.10,0.05,0.00);
	glVertex2f(50.5,49);
	glEnd();
	
	
	glColor3f(0.48,0.72,0.58);
	glBegin(GL_POLYGON);
	glVertex2f(50,50);
	glVertex2f(54,50);
	glVertex2f(56.5,49.7);
	glVertex2f(57,54.5);
	glVertex2f(56,54.5);
	glVertex2f(55,54.5);
	glVertex2f(53,55);
	glEnd();
	
	glFlush();

}