/**
*   Programa para ilustrar os elementos mais basicos do OpenGL e Glut.
*   - Apresenta os principais recursos do sistema de Janelas GLUT
*
*   Autor: Cesar Tadeu Pozzer
*   UFSM - 2007
*
*   pozzer@inf.ufsm.br
*   pozzer3@gmail.com
*
* Referencias GLUT: http://www.opengl.org/documentation/specs/glut/
*                   http://www.opengl.org/documentation/specs/glut/spec3/node1.html
**/

/// Nome: Rafael Holzschuh de Araujo
/// Matrícula: 201311194

//*****************************************************************************
//modificacoes
//*****************************************************************************
//- passar tamanho da janela
//- retangulo preenchido em qualquer orientacao (polygon)
//-

#include "gl_canvas2d.h"
#include "Point.h"
#include <GL/glut.h>
#include <iostream>

int largura, altura;

void point(Point p)
{
   glBegin(GL_POINTS);
      glVertex2d(p.x, p.y);
   glEnd();
}

void line(Point p1, Point p2)
{
   glBegin(GL_LINES);
      glVertex2d(p1.x, p1.y);
      glVertex2d(p2.x, p2.y);
   glEnd();
}

void rect(Point p1, Point p2)
{
   glBegin(GL_LINE_LOOP);
      glVertex2d(p1.x, p1.y);
      glVertex2d(p1.x, p2.y);
      glVertex2d(p2.x, p2.y);
      glVertex2d(p2.x, p1.y);
   glEnd();
}

void rectFill( Point p1, Point p2 )
{
   glBegin(GL_QUADS);
      glVertex2d(p1.x, p1.y);
      glVertex2d(p1.x, p2.y);
      glVertex2d(p2.x, p2.y);
      glVertex2d(p2.x, p1.y);
   glEnd();
}

//void polygon(float vx[], float vy[], int elems)
void polygon(Point p[], int elems)
{
   float vx[100];
   float vy[100];
   int cont;

   for(cont=0; cont<elems; cont++){
      vx[cont] = p[cont].x;
      vy[cont] = p[cont].y;
   }

   glBegin(GL_LINE_LOOP);
      for(cont=0; cont<elems; cont++)
      {
         glVertex2d(vx[cont], vy[cont]);
      }
   glEnd();

}

void polygonFill(Point p[], int elems)
{
   float vx[100];
   float vy[100];
   int cont;

   for(cont=0; cont<elems; cont++){
      vx[cont] = p[cont].x;
      vy[cont] = p[cont].y;
   }
   glBegin(GL_POLYGON);
      for(cont=0; cont<elems; cont++)
      {
         glVertex2d(vx[cont], vy[cont]);
      }
   glEnd();

}

void text(Point p, char *t)
{
    int tam = (int)strlen(t);
    int c;

    for(c=0; c<tam; c++)
    {
      glRasterPos2i(p.x + c*10, p.y);
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13, t[c]);
    }
}



void circle( Point c, int raio, int div )
{
   float ang, x1, y1;
   float inc = PI_2/div;
   glBegin(GL_LINE_LOOP);
      for(ang=0; ang<6.27; ang+=inc) ///nao vai ateh PI_2 pois o ultimo ponto eh fechado automaticamente com o primeiro, pois tem o tipo LINE_LOOP
      {
         x1 = (cos(ang)*raio);
         y1 = (sin(ang)*raio);
         glVertex2d(x1+c.x, y1+c.y);
      }
   glEnd();
}

void circleFill( Point c, int raio, int div )
{
   float ang, x1, y1;
   float inc = PI_2/div;
   glBegin(GL_POLYGON);
      for(ang=0; ang<6.27; ang+=inc)
      {
         x1 = (cos(ang)*raio);
         y1 = (sin(ang)*raio);
         glVertex2d(x1+c.x, y1+c.y);
      }
   glEnd();
}

void color(float r, float g, float b)
{
   glColor3d(r, g, b  );
}

void clear(float r, float g, float b)
{
   glClearColor( r, g, b, 1 );
}

void color(Color* color){
      glColor3d(color->r, color->g, color->b);
}
void clear(Color* color){
   glClearColor( color->r, color->g, color->b, 1 );
}

void special(int key, int , int )
{
   keyboard(key+100);
}

void specialUp(int key, int , int )
{
   keyboardUp(key+100);
}

void keyb(unsigned char key, int , int )
{
   keyboard(key);
}

void keybUp(unsigned char key, int , int )
{
   keyboardUp(key);
}

void mouseClick(int button, int state, int x, int y)
{
   mouse(button, state, x, y);
   //printf("\nmouse %d %d", button, state);
}

void motion(int x, int y)
{
   mouse(-1, -1, x, y);
   //printf("\nmotion %d %d", x, y);
}

void reshape (int w, int h)
{
   largura = w;
   altura  = h;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   //cria uma projecao ortografica com z entre (-1, 1).
   //parametros: left, right, bottom, top, ou seja, (0,0) --> (largura,altura)
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
}

void inicializa()
{
   //definicao de valores para limpar buffers
   glClearColor(1,1,1,1);
   glColor3f(1, 0, 0);  // red
   glPolygonMode(GL_FRONT, GL_FILL);
   glClear(GL_COLOR_BUFFER_BIT );
}

void display (void)
{
   glClear(GL_COLOR_BUFFER_BIT );

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   //cria uma projecao ortografica com z entre (-1, 1).
   //parametros: left, right, bottom, top, ou seja, (0,0) --> (largura,altura)
   gluOrtho2D (0.0, largura, 0.0, altura);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   render();

   glFlush();
   glutSwapBuffers();
}

/// ///////////////////// ///
///  inicializa o OpenGL  ///
/// ///////////////////// ///
void initCanvas(int w, int h){
   int argc = 1;
   char arg1[] = "teste";
   char* argv[] = {arg1};

   glutInit(&argc, argv);

   largura = w;
   altura  = h;

   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   glutInitWindowSize (TELA_X, TELA_Y);
   glutInitWindowPosition (100, 0);
   glutCreateWindow ("Autorama");

//   glutFullScreen();

   inicializa();

   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyb);
   glutKeyboardUpFunc(keybUp);
   glutSpecialUpFunc(specialUp);
   glutSpecialFunc(special);

   glutIdleFunc(display);
   glutMouseFunc(mouseClick);
   glutPassiveMotionFunc(motion);
   glutMotionFunc(motion);

    printf("GL Version: %s", glGetString(GL_VERSION));

}

void runCanvas()
{
   glutMainLoop();
}

