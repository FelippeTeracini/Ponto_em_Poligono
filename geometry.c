#include <math.h>
//#include <stdio.h>

#include "geometry.h"

int verify(point p, point a, point b) {

  int largerx;
  int smallerx;
  int largery;
  int smallery;

  // Checa qual ponto (entre a e b) tem o maior x
  if(a.x - b.x > 0){
    largerx = a.x;
    smallerx = b.x;
  }
  else{
    largerx = b.x;
    smallerx = a.x;
  }

  // Checa qual ponto (entre a e b) tem o maior y
  if(a.y - b.y > 0){
    largery = a.y;
    smallery = b.y;
  }
  else{
    largery = b.y;
    smallery = a.y;
  }

  // Checa se os pontos a e b tem o mesmo y, o que significa que eles formam uma reta horizontal
  if((a.y == b.y)){
    // Checa se os pontos a e p tem o mesmo y e se o x do ponto p esta entra o x dos pontos a e b
    if(p.y == a.y && smallerx <= p.x && largerx >= p.x){
      return 2; 
    }
    else{
      return 0;
    }
  }
  // Checa se os pontos a e b tem o mesmo x, o que significa que eles formam uma reta vertical
  else if(a.x == b.x){
    // Checa se os pontos a e p tem o mesmo x
    // Checa se o y do ponto p esta entra o y dos pontos a e b
    if (p.x == a.x && smallery <= p.y && largery >= p.y){
      return 2;

    }
    else if(p.x < a.x && smallery < p.y && largery >= p.y){
        return 1;
      }
    else{
      return 0;
    }

  }
  // Se os pontos nao tem o mesmo x nem o mesmo y, significa que eles formam uma reta diagonal
  else{
    // Calcula o m da equacao da reta
    double numerador = a.y-b.y;
    double denominador = a.x-b.x;
    double m = numerador/denominador;
    // Calcula o B da equacao da reta
    double n = a.y - (m * a.x);
    //Calcula valor de Y da reta dado x do ponto
    double resy = m * p.x + n;
    //Calcula valor de X da reta dado y do ponto
    double resx = (p.y - n) / m;
    double pyd = (double) p.y;
    double sub = fabs(pyd - resy);

    // printf("RESY: %lf    RESX: %lf   PYD: %lf     M: %lf    N %lf    SUB: %lf  \n",resy,resx,pyd,m,n,sub);



    // Checa se o y do ponto p eh igual ao y da reta dado o x de p
    if( sub <= 0.000001 && smallery <= p.y && largery >= p.y){
      return 2;
    }
    else if(resx>p.x && smallery < p.y && largery >= p.y){
      return 1;
    }
    else{
      return 0;
    }
  }
}

int inside(point p, point poly[], int n) {
  return 0;
}

// int main(){
//   point a;
//   point b;
//   point p;
//   a.x = 0;
//   a.y = 1;
//   p.x = 2;
//   p.y = 2;
//   b.x = 4;
//   b.y = 4;

//   int res = verify(p,a,b);
//   printf("%d",res);
//   return 1;
// }