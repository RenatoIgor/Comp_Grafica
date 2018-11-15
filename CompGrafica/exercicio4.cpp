/*
  Name:        quad_transform.cpp
  Copyright:   Version 0.1
  Author:      Rodrigo Luis de Souza da Silva
  Edited:	   Bruno José Dembogurski
  Update:      10/07/2018
  Date:        16/09/2004
  Description: Transformations using of OpenGL commands
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angle = 0, scale = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;
int enableMenu = 0;

void display(void);
void init (void);
void desenhaEixos();
void showMenu();
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x ,int y);
void specialKeyboard(int key ,int x ,int y);

int main(int argc, char** argv)
{



   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (300, 300);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Exercicio 4");
   glutMouseFunc( mouse );
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeyboard);
   init ();
   //printf("\nPosicione as janelas e clique na janela do OpenGL para habilitar o menu.\n");
   printf("\n=== MENU ===");
   printf("\nDirecionais - Translacao");
   printf("\nR/r - Rotacao");
   printf("\n+/- - Escala");
   printf("\nEsc - Sair");
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}

// Mouse callback
void mouse(int button, int state, int x, int y)
{
   if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
      enableMenu = 1;
}

void specialKeyboard(int key, int x ,int y){

    switch(key){

    case GLUT_KEY_DOWN:
            ytrans -= 5;
        break;

    case GLUT_KEY_UP:
            ytrans += 5;
        break;

    case GLUT_KEY_LEFT:
            xtrans -= 5;
        break;

    case GLUT_KEY_RIGHT:
            xtrans += 5;
        break;

    }

}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 27 :
         exit(0);
      break;

      case 'a':

        xtrans -= 5;
         //printf("Y : ");
         //scanf("%f", &ytrans);
      break;

       case 'w':

         ytrans += 5;
      break;

       case 'd':

    xtrans += 5;
     //    printf("Y : ");
      //   scanf("%f", &ytrans);
      break;

       case 's':

        ytrans -= 5;
      break;


      case 'R':
        // printf("\n\nInforme o angulo de rotacao (em graus): ");
         angle += 9;
      break;

      case 'r':
        // printf("\n\nInforme o angulo de rotacao (em graus): ");
         angle -= 9;
      break;


      case '+':
        // printf("\n\nInforme o fator de escala: ");
        if(scale < 100){
            scale +=1;
            }
      break;

      case '-':
        if(scale >1){
        scale--;
        }
      break;

      default:
         printf("\n\nOpcao invalida\n\n");
      break;
   }


   glutPostRedisplay();
}

/*void showMenu()
{
   //char op;
   //system("cls");
   printf("\n=== MENU ===");
   printf("\nDirecionais - Translacao");
   printf("\nR/r - Rotacao");
   printf("\n+/- - Escala");
   printf("\nEsc - Sair");
   //printf("\nOpcao: ");
*//*
   scanf(" %c", &op);
   switch(op)
   {
      case 'a':

        xtrans -= 5;
         //printf("Y : ");
         //scanf("%f", &ytrans);
      break;

       case 'w':

         ytrans += 5;
      break;

       case 'd':

    xtrans += 5;
     //    printf("Y : ");
      //   scanf("%f", &ytrans);
      break;

       case 's':

        ytrans -= 5;
      break;


      case 'R':
        // printf("\n\nInforme o angulo de rotacao (em graus): ");
         angle += 9;
      break;
      case '+':
        // printf("\n\nInforme o fator de escala: ");
        scale +=1;
      break;

      case '-':
        scale--;
      break;

      case 27:
         exit(1);
      break;
      default:
         printf("\n\nOpcao invalida\n\n");
      break;
   }
}*/
//}

void desenhaEixos()
{
   glColor3f (0.0, 1.0, 0.0);
   glBegin(GL_LINES);
      glVertex2f (0.0, -100.0);
      glVertex2f (0.0, 100.0);
      glVertex2f (-100.0, 0.0);
      glVertex2f (100.0, 0.0);
   glEnd();
}

void display(void)
{
   // Limpar todos os pixels
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity(); // Inicializa com matriz identidade

   desenhaEixos();

   glColor3f (1.0, 0.0, 0.0);

   glPushMatrix();
      glTranslatef(xtrans, ytrans, 0.0);
      glRotatef(angle, 0.0, 0.0, 1.0);
      glScalef(scale, scale, scale);
      glutWireCube(10);
   glPopMatrix();

   glutSwapBuffers ();
   glutPostRedisplay();

   //if(enableMenu) showMenu();
}

void init (void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


