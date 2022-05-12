#include "HealthBar.h"
#include "gl_canvas2d.h"

HealthBar::HealthBar(int life){
   startingPosition = 10;
   safeDistance = 4;
   height = 30;
   width = 200 + safeDistance;
   unityHeight = 20;
   unityWidth = (width - safeDistance) / (float)life - safeDistance;
//   unityWidth = 16;
}

HealthBar::~HealthBar()
{
   //dtor
}

void HealthBar::print(int life){
   Point p;
   color(RED_DARK);
   rectFill(p.floatToPoint(startingPosition, TELA_Y-startingPosition),
            p.floatToPoint(startingPosition + width, TELA_Y-startingPosition-height));
   color(YELLOW);
   for(int i=0; i<life; i++){
      rectFill(p.floatToPoint(startingPosition + safeDistance + i * (unityWidth + safeDistance),
                              TELA_Y - startingPosition - (height - unityHeight) * 0.5),
               p.floatToPoint(startingPosition + safeDistance + unityWidth + i * (unityWidth + safeDistance),
                              TELA_Y - startingPosition - (height - unityHeight) * 0.5 - unityHeight));
   }
   if(life == 0){
      text(p.floatToPoint(startingPosition + width * 0.01,
                          TELA_Y - startingPosition - height * 0.7),
           "Press 'r' to restart");
   }
}
