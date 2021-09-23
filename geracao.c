#include "geracao.h"
//=============================================================================
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//=============================================================================
// PROCEDIMENTO PARA TROCAR DOIS ELEMENTOS DO VETOR
void swap(int *i, int *j) {
   int temp = *i;
   *i = *j;
   *j = temp;
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM CRESCENTE
void crescente(int *v, int n) {
   for (int i = 0; i < n; i++) {
      v[i] = i;
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM DECRESCENTE
void decrescente(int *v, int n) {
   for (int i = 0; i < n; i++) {
      v[i] = n - 1 - i;
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS EM ORDEM ALEATORIA
void aleatorio(int *v, int n) {
   crescente(v, n);
   srand(time(NULL));
   for (int i = 0; i < n; i++) {
      swap(&v[i], &v[rand() % n]);
   }
}
//=============================================================================
// PROCEDIMENTO PARA PREENCHER UM ARRANJO COM ELEMENTOS DA ENTRADA PADRAO
int entradaPadrao(int *v) {
   int n;
   scanf("%i", &n);
   v = (int*) malloc(n*sizeof(int));
   
   for (int i = 0; i < n; i++) {
      scanf("%i", &v[i]);
   }
   return n;
}
//=============================================================================
// PROCEDIMENTO PARA EXIBIR OS DADOS PRESENTES NO ARRANJO
void mostrar(int *v, int n) {
   printf("[ ");
   for (int i = 0; i < n; i++) {
      printf("%d ", v[i]);
   }
   printf("] \n");
}
//=============================================================================
// PROCEDIMENTO PARA VERIFICAR SE O ARRANJO ESTA ORDENADO
bool isOrdenado(int *v, int n){
   bool resp = true;
   for(int i = 1; i < n; i++){
      if(v[i-1] > v[i]){
         i = n;
         resp = false;
      }
   }
   return resp;
}
//=============================================================================
