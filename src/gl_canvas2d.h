/// Nome: Rafael Holzschuh de Araujo
/// Matrícula: 201311194

#ifndef __CANVAS_2D__H__
#define __CANVAS_2D__H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Point.h"
#include "Color.h"

#include <GL/glut.h>

#define TELA_X 1000
#define TELA_Y 700
#define DIM_TELA 600

#define PI_2 6.28318530717958

#define RED_LIGHT 1.0f, 0.0f, 0.0f
#define RED_DARK 0.4f, 0.0f, 0.0f
#define GREEN_LIGHT 0.0f, 1.0f, 0.0f
#define BLUE 0.0f, 0.0f, 1.0f
#define CYAN 0.0f, 1.0f, 1.0f
#define MAGENTA 1.0f, 0.0f, 1.0f
#define YELLOW 1.0f, 1.0f, 0.0f
#define WHITE 1.0f, 1.0f, 1.0f
#define BLACK 0.0f, 0.0f, 0.0f
#define GREY_LIGHT 0.8f, 0.8f, 0.8f
#define GREY_DARK 0.2f, 0.2f, 0.2f
#define BROWN_DARK 0.55f, 0.3f, 0.1f
#define BROWN_LIGHT 0.7f, 0.4f, 0.1f

//funcoes da biblioteca
void point(Point p); //coordeandas do ponto
void line( Point p1, Point p2 ); //coordenadas da linha x1, y1, x2, y2

//desenha um retangulo alinhado nos eixos x e y
void rect( Point p1, Point p2 ); //coordenadas do retangulo x1, y1, x2, y2
void rectFill( Point p1, Point p2 ); //coordenadas do retangulo x1, y1, x2, y2

///desenha um poligono CONVEXO. Para um retangulo, deve-se passar 4 vertices
//void polygon(float vx[], float vy[], int n_elems);
//void polygonFill(float vx[], float vy[], int n_elems);

void polygon(Point p[], int n_elems);
void polygonFill(Point p[], int n_elems);

//centro e raio do circulo
void circle( Point c, int raio, int div );
void circleFill( Point c, int raio, int div );

//especifica a cor de desenho e de limpeza de tela
void color(float r, float g, float b);
void clear(float r, float g, float b);

void color(Color* color);
void clear(Color* color);

//desenha texto
void text(int x, int y, char *t);
void text(Point p, char *t);

//funcoes de gerenciamento da biblioteca (CALLBACKS)
void keyboard(int key);
void keyboardUp(int key);
void specialUp(int key);
void mouse(int bt, int st, int x, int y);
void render();

//funcao de inicializacao da Canvas2D. Recebe a largura e altura
void initCanvas(int w, int h);

//funcao para executar a Canvas2D
void runCanvas();


#endif
