#include<stdio.h>
#include<GL/glut.h>
#include "Intro.h"
#include "Background.h"
#include "Buildings.h"

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	Background();
	Buildings();
}