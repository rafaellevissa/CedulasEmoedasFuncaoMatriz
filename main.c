#include <stdio.h>

//variáveis globais
double matriz[6][4]; //0-> notas, 1->qnt notas, 2-> moedas, 3-> qnt moedas
double valor;
//funções:
void iniciar();
void calcular();
void imprimir();

int main() {        
  iniciar();
  scanf("%lf",&valor);    
  calcular();
  imprimir();

  return 0;
}

void iniciar(){
  
  //Notas (real):
  matriz[0][0]=100.0;
  matriz[1][0]=50.0;
  matriz[2][0]=20.0;
  matriz[3][0]=10.0;
  matriz[4][0]=5.0;
  matriz[5][0]=2.0;
  //Moedas (real):
  matriz[0][2]=1.0; //1 centavo = 0.01 real
  matriz[1][2]=0.50;
  matriz[2][2]=0.25;
  matriz[3][2]=0.10;
  matriz[4][2]=0.05;
  matriz[5][2]=0.01;
}

void calcular(){  
  int i;
  int cedulas, moedas;
  int resto;

  cedulas = valor / 1.0;
  moedas = (valor-cedulas)*100;
  resto=cedulas;
  
  //calculando as cédulas:
  for(i=0;i<6;i++){ 
    matriz[i][1]=resto/(int)matriz[i][0]; 
    resto = resto%(int)matriz[i][0];
  }
  //calculando as moedas:
  matriz[0][3]=resto;
  resto=moedas;
  for(i=1;i<6;i++){  
    matriz[i][3]=resto/(int)(matriz[i][2]*100);
    resto = resto%(int)(matriz[i][2]*100);
  }
}

void imprimir(){
  int i;
  printf("NOTAS:\n");
  for(i=0;i<6;i++){
    printf("%.0lf nota(s) de R$ %.2lf\n",matriz[i][1],matriz[i][0]);
  }
  printf("MOEDAS:\n");
  for(i=0;i<6;i++){
    printf("%.0lf moeda(s) de R$ %.2lf\n",matriz[i][3],matriz[i][2]);
  }  
}