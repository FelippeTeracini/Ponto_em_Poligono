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
  int n_cruza = 0;
  for (int i = 1; i < n; i++){
    int check = verify(p, poly[i-1], poly[i]);
    if (check == 2){
      return 1;
    }
    else if(check == 1){
      n_cruza++;
    }
  }
  int check = verify(p, poly[n-1], poly[0]);
  if (check == 2){
    return 1;
  }
  else if (check == 1){
    n_cruza++;
  }


  double resto = n_cruza % 2;
  if (resto != 0){
    return 1;
  }
  else{
    return 0;
  }
}
