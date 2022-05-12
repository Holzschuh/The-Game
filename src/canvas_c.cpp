/*********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         10/2007
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Instruções:
//	  Para alterar a animacao, digite numeros entre 1 e 5
/*********************************************************************/

/// Nome: Rafael Holzschuh de Araujo
/// Matrícula: 201311194

#include <iostream>
#include <time.h>

//#include "Point.h"
//#include "Form.h"
//#include "Player.h"
//#include "Enemy.h"
//#include "Matrix2d.h"
//#include "BlindBird.h"
//#include "Bezier.h"

#include "gl_canvas2d.h"
#include "GameManager.h"

using namespace std;


//Bezier curveBez;
class GameManager;



bool keyMap[12];
/// KEYMAP KEYS:
/// 0. LEFT
/// 1. RIGHT
/// 2. UP
/// 3. DOWN
/// 4. SHOOT (Z)
/// 5. SPECIAL (SPACE)
/// 6. BRAKE (X)

static GameManager *game = new GameManager(keyMap);

///funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
///globais que podem ser setadas pelo metodo keyboard()
void render() {
   game->render();
//   Sleep(10);
//   clear(BLACK);
//   color(WHITE);
//
//   if(firstTime){
//      srand(time(NULL));
//      player = new Player();
//      for(int i=0; i<1; i++){
//         enemies.push_back(new BlindBird());
//         enemies[i]->player = player;
//      }
//      firstTime = false;
//   }
//
//   player->render(keyMap);
//
//   for(int i=0; i<enemies.size(); i++){
//      enemies[i]->render();
//   }
//
//   rectFill(0, 0, 1400, 20);

}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key){
//   printf("\nTecla: %d" , key);


   switch(key){
      case 27:
         exit(0);
         break;
      case 200:
         keyMap[0] = true;
         break;
      case 202:
         keyMap[1] = true;
         break;
      case 201:
         keyMap[2] = true;
         break;
      case 203:
         keyMap[3] = true;
         break;
      case 'z':
         keyMap[4] = true;
         break;
      case 32:
         keyMap[5] = true;
         break;
      case 'x':
         keyMap[6] = true;
         break;
      case 'r':
         delete(game);
         game = new GameManager(keyMap);
         break;
   }
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key){
   //printf("\nLiberou: %d" , key);

   switch(key){
       case 200:
         keyMap[0] = false;
         break;
      case 202:
         keyMap[1] = false;
         break;
      case 201:
         keyMap[2] = false;
         break;
      case 203:
         keyMap[3] = false;
         break;
      case 'z':
         keyMap[4] = false;
         break;
      case 32:
         keyMap[5] = false;
         break;
      case 'x':
         keyMap[6] = false;
         break;
      case 'p':
         system("cls");
         break;

   }
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y){
   y = TELA_Y - y;
//   printf("\nmouse %d %d %d %d", button, state, x, y);
   if(button == 0 && state == 0){
      Point click(x,y);

//      if((curveBez.controlPoints.size() > 3) && ((curveBez.controlPoints.size() - 1 ) % 3 == 0)){
//         curveBez.calcNextC1Point();
//      }
//
//      curveBez.addPoint(click);
//
//      if((curveBez.controlPoints.size() != 1)  && ((curveBez.controlPoints.size() - 1) % 3 == 0)){
//         curveBez.calcPoints(100);
//      }
   }
}

int main(void){

   initCanvas(DIM_TELA, DIM_TELA);

   runCanvas();

}
