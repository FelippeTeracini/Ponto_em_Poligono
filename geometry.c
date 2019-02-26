#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b) {

  double m;
  double n;
  int largerx;
  int smallerx;
  int largery;
  int smallery;

  // Checa qual ponto (entre a e b) tem o maior x
  if(a.x - b.x > 0){
    largerx = b.x;
    smallerx = a.x;
  }
  else{
    largerx = a.x;
    smallerx = b.x;
  }

  // Checa qual ponto (entre a e b) tem o maior y
  if(a.y - b.y > 0){
    largery = b.y;
    smallery = a.y;
  }
  else{
    largery = a.y;
    smallery = b.y;
  }

  // Checa se os pontos a e b tem o mesmo y, o que significa que eles formam uma reta horizontal
  if((a.y == b.y)){
    // Checa se os pontos a e p tem o mesmo y
    if(p.y == a.y){
      // Checa se o x do ponto p esta entra o x dos pontos a e b
      if(smallerx <= p.x && largerx >= p.x){
        return 2;
      }
    }
    // else{
    //   return 0;
    // }
  }
  // Checa se os pontos a e b tem o mesmo x, o que significa que eles formam uma reta vertical
  else if(a.x == b.x){
    // Checa se os pontos a e p tem o mesmo x
    if(p.x == a.x){
      // Checa se o y do ponto p esta entra o y dos pontos a e b
      if(smallery <= p.y && largery >= p.y){
        return 2;
      }
    }
    else{
      if(p.y>smallery && p.y<=largery){
        return 1;
      }
      // else{
      //   return 0;
      // }
    }

  }
  // Se os pontos nao tem o mesmo x nem o mesmo y, significa que eles formam uma reta diagonal
  else{
    // Calcula o m da equacao da reta
    m = (a.y - b.y) / (a.x - b.x);
    // Calcula o B da equacao da reta
    n = a.y - (m*a.x);
    double res = m*p.x + n;
    // Checa se o y do ponto p eh igual ao y da reta dado o x de p
    if(abs(p.y - res) <= 0.000001){
      return 2;
    }
  }
  return 0;
}

int inside(point p, point poly[], int n) {
  return 0;
}
