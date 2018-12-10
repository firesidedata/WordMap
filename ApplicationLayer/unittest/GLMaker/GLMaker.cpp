//Group7 10/23/2018
#define NDEBUG  // link in non-debug version of freeglut.dll
#include "WordMap.h"
#include <fstream>
#include <vector>
#include "glut.h"
#include "IRenderMaker.h"
#include "GLMaker.h"
#include "MapItem.h"
#include <string>
#include <iostream>
using namespace std;

int WindowWidth = 800; int WindowHeight = 1000;
WordMap *tem = new WordMap();
GLMaker::GLMaker() {}


const double glRenderSizes[10] = {
	0.100,
	0.133,
	0.166,
	0.200,
	0.233,
	0.266,  // char width is about 20
	0.300,
	0.333,
	0.366,
	0.4
};

void PrintText(MapItem *m)//double x, double y, string text, unsigned int size)
{
	// Display text at position (x,y) using fontsize size
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0f, WindowHeight, 0.0f, WindowWidth, -1.0f, 1.0f); // (x,y) position is relative to this

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPushAttrib(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	cout << "x:" << m->getX() << " Y:" << m->getY()<<" Font Size:"<< m->getFontSize()<<" word:" << m->getWord()<<"\n";
	glTranslatef((GLfloat)m->getX(), (GLfloat)m->getY(), (GLfloat)0);
	glScalef((GLfloat)glRenderSizes[m->getFontSize()], (GLfloat)glRenderSizes[m->getFontSize()], (GLfloat)1);

	for (unsigned int i = 0; i < m->getWord().size(); i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, m->getWord().c_str()[i]);
	}

	glScalef(1, 1, 1);

	glPopAttrib();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glColor3f(0.5, 0.7, 1.0); // set the color for drawing

	for (int i = 0; i < tem->size(); i++)
	{
		PrintText(tem->at(i));
	}
	glutSwapBuffers();
}
void 
GLMaker::generateDoc(WordMap* wordMap, string s)
{
	glutInit(&Largc, Largv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(500, 300);  // width, height
	glutInitWindowSize(800, 800);  // width, height of display window-- output is scaled to fit in here, so keep the aspect ratio
	glutCreateWindow("An Amazing Demo");
	tem = wordMap;
	glutDisplayFunc(Display);  // maker does this
	glutMainLoop();  // maker does this
}



