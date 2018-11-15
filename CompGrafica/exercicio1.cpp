
/*
  Name:        05_viewport
  Copyright:   Version 0.1
  Author:      Rodrigo Luis de Souza da Silva
  Edited:	   Bruno José Dembogurski
  Update:      10/07/2018
  Date:        15/10/2013
  Description: Testing more than one viewports
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float altura = 400, largura = 400;

void  DesenhaEixos();
void  DesenhaObjetos1();
void  DesenhaObjetos2();
void  DesenhaObjetos3();
void  DesenhaObjetos4();
void  display();
void  keyboard(unsigned char key, int x, int y);
void keyboardPress(unsigned char key, int x, int y);
void  init(void);

////////////////////////////////////////////////
// Main Function
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize ((int)largura,(int)altura);
   glutInitWindowPosition (400,200);
   glutCreateWindow ("Exercicio 1");
   init ();
   glutDisplayFunc(display);  // Eh quem ira chamar todo o restante das funçoes
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

//////////////////////////////////////////////////
// Functions

// Inicializa opengl
void init(void)
{
   glClearColor(1.0,1.0, 1.0, 0.0);
   glShadeModel(GL_SMOOTH);
}

// Eixos coordenados
void DesenhaEixos()
{

   glBegin(GL_LINES);
      glColor3f (0.0, 1.0, 0.0);
      glVertex3f(-1.0, 0.0, 0.0);
      glVertex3f( 1.0, 0.0, 0.0);
      glColor3f ( 0.0, 1.0, 0.0);
      glVertex3f(0.0, -1.0, 0.0);
      glVertex3f(0.0,  1.0, 0.0);
   glEnd();
}

void DesenhaObjetos1()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glColor3d(1.0, 0.4, 0.4);
   glBegin(GL_POLYGON);
      glColor3f (1.0, 0.0, 0.0);
      glVertex3f(0.5, 1, 0.0);
      glVertex3f(0, 0, 0.0);
      glVertex3f(1, 0, 0.0);
   glEnd();
}


void DesenhaObjetos2()
{
   glColor3d(1.0, 0.0, 0.0);
   glBegin(GL_LINE_STRIP);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f,    1.0f);
    glVertex2f(1.0f,   0.0f);
    glVertex2f(0.0f,   0.0f);

   glEnd();
   glFlush();
}

void DesenhaObjetos3()
{

   DesenhaObjetos2();

   glColor3d(1.0, 0.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex3f(0.0, -0.00, 0.0);
      glVertex3f(-0.5, -1, 0.0);
      glVertex3f(-1.0, -0.00, 0.0);

   glEnd();
}

void DesenhaObjetos4()
{
   glColor3d(0.2, 0.1, 1.0);
   glBegin(GL_LINE_STRIP);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f,  -0.5f);
    glVertex2f(1.0f,  0.0f);
    glVertex2f(0.5f,  0.5f);

   glEnd();
}

///////////////////////////////////////////////////////////
// Glut and image functions


void display(void)
{
    //unsigned char key;
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Define viewport do centro
   glViewport ((int) 100, (int) 100, (int) 200, (int) 200);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1, 1);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   DesenhaEixos();


   glutSwapBuffers();
   glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 27 :
         exit(0);
      break;

   }
   glutPostRedisplay();
}





