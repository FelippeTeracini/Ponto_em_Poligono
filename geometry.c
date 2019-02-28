#include <math.h>
#include "geometry.h"

int verify(point p, point a, point b) {

  int largerX;
  int smallerX;
  int largerY;
  int smallerY;

  // Checa qual ponto (entre a e b) tem o maior x
  if(a.x - b.x > 0){
    largerX = a.x;
    smallerX = b.x;
  }
  else{
    largerX = b.x;
    smallerX = a.x;
  }

  // Checa qual ponto (entre a e b) tem o maior y
  if(a.y - b.y > 0){
    largerY = a.y;
    smallerY = b.y;
  }
  else{
    largerY = b.y;
    smallerY = a.y;
  }

  // Checa se os pontos a e b tem o mesmo y, o que significa que eles formam uma reta horizontal
  if((a.y == b.y)){
    // Checa se os pontos a e p tem o mesmo y e se o x do ponto p esta entra o x dos pontos a e b
    if(p.y == a.y && smallerX <= p.x && largerX >= p.x){
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
    if (p.x == a.x && smallerY <= p.y && largerY >= p.y){
      return 2;

    }
    // Checa se o ponto esta entre o intervalo de a.y e b.y levando em conta a perturbação 
    // Checa se o p.x está à esquerda da reta vertical
    else if(p.x < a.x && smallerY < p.y && largerY >= p.y){
        return 1;
      }
    else{
      return 0;
    }

  }
  // Se os pontos nao tem o mesmo x nem o mesmo y, significa que eles formam uma reta diagonal
  else{
    // Calcula o coeficiente angular da equacao da reta
    double numerador = a.y-b.y;
    double denominador = a.x-b.x;
    double m = numerador/denominador;
    // Calcula o coeficiente linear da equacao da reta
    double n = a.y - (m * a.x);
    //Calcula valor de Y da reta dado x do ponto
    double resY = m * p.x + n;
    //Calcula valor de X da reta dado y do ponto
    double resX = (p.y - n) / m;

    //Subtrai os valores do y do ponto e o y na reta dado o x do ponto
    double pyD = (double) p.y;
    double sub = fabs(pyD - resY);

    // Checa se o y do ponto p eh igual ao y da reta dado o x de p
    if( sub <= 0.000001 && smallerY <= p.y && largerY >= p.y){
      return 2;
    }

    // Checa se o x da reta dado o y do ponto está à diretia do x do ponto
    // Checa se o y do ponto esta entre os y do segmento de reta levando em conta a perturbação
    else if(resX>p.x && smallerY < p.y && largerY >= p.y){
      return 1;
    }
    else{
      return 0;
    }
  }
}

int inside(point p, point poly[], int n) {

  //Itera sobre os pontos de 0 < n-1 e checa se cruza a aresta
  //Se cruzar soma 1 no contador, caso o ponto esteja em cima de alguma aresta já retorna 1
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
  //Faz os mesmos checks na reta de n-1 com 0
  int check = verify(p, poly[n-1], poly[0]);
  if (check == 2){
    return 1;
  }
  else if (check == 1){
    n_cruza++;
  }

  //Divide o contador por 2 para checar se é par ou ímpar
  double resto = n_cruza % 2;
  if (resto != 0){
    return 1;
  }
  else{
    return 0;
  }
}
