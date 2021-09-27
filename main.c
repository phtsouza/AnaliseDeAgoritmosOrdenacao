#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"
#include "meuAlgoritmo.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>

double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}

void teste(int n, char ordem){

   //Delcaracao de variaveis
    //int n = (argc < 2) ? 10000 : atoi(argv[1]);
    int *array = (int*) malloc(n*sizeof(int));
    
    // VARIAVEIS PARA CALCULAR O TEMPO E MEMORIA
    clock_t inicio, fim;
    double total, memory_used;
    size_t peakSize;

    //Geracao do conjunto a ser ordenado
    switch(ordem){
      case 'C': crescente(array, n);
      break;
      case 'D': decrescente(array, n);
      break;
      case 'A':  aleatorio(array, n);
      break;
      //case 'P': piorCasoQuick(array, n);
      //break;
      default: aleatorio(array, n);
    }
		

    //Execucao do algoritmo de ordenacao
	inicio = clock();
    //bolha(array, n);
    //countingsort(array, n);
  //heapsort(array, n);
    //insercao(array, n);
    //mergesort(array, n);
    //quicksort(array, n);
    //selecao(array, n);
    //shellsort(array, n);
    //meuAlgoritmo(array, n);
	fim = clock();
  memory_used = get_memory_used_MB();
  total = ((fim - inicio) / (double)CLOCKS_PER_SEC);    
  printf("\nN: %d - MEMORIA: %0.3f - TEMPO DE PROCESSAMENTO: %0.3f", n, memory_used, total);

  free(array);

}


int main(int argc, char **argv) {
  
    printf("ORDENADO\n");
    for(int i=2000; i<=64000; i=i*2){      
      teste(i, 'C');
    }
    
    printf("NAO ORDENADO\n");
    for(int i=2000; i<=64000; i=i*2){
      teste(i, 'D');
    }
    
    printf("ALEATORIO\n");
    for(int i=2000; i<=64000; i=i*2){
      teste(i, 'A');
    }
    /*
   printf("PIOR CASO QUICK\n");
   for(int i=128000; i<=128000; i=i*2){      
      teste(i, 'P');
    }
    */
    return 0;
}
