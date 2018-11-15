
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
#define partes 6

float altura = 480, largura = 480;

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
   glutCreateWindow ("Exercicio 2 seno em partes");
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
   glClearColor(0.0,0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);
}


// Eixos coordenados
void DesenhaEixos()
{

   glBegin(GL_LINES);
      glColor3f (0.0, 1.0, 0.0);
      glVertex3f(-10.0, 0.0, 0.0);
      glVertex3f( 10.0, 0.0, 0.0);
      glColor3f ( 0.0, 1.0, 0.0);
      glVertex3f(0.0, -10.0, 0.0);
      glVertex3f(0.0,  10.0, 0.0);
   glEnd();
}


void DesenhaObjetos1()
{

   glColor3d(1.0, 0.0, 1.0);

   float i = 0.0;
   glBegin(GL_LINE_STRIP);
   for(i = 0 ; i < 2*M_PI; i += (2*M_PI /partes)){
        glVertex2f(i, sin(i));
    }
    glEnd();


}

///////////////////////////////////////////////////////////
// Glut and image functions


void display(void)
{
    //unsigned char key;
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Define viewport do centro
   //glViewport ((int) 0, (int) 200, (int) 200, (int) 200);
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();
   glOrtho(-0.1, 10.0, -2.0, 2.0, -1, 1);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   DesenhaEixos();
   DesenhaObjetos1();


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





