#include "geracao.h"

void insercaoPorCor(int *array, int n, int cor, int h){
    for (int i = (h + cor); i < n; i+=h) {
        int tmp = array[i];
        int j = i - h;
        while ((j >= 0) && (array[j] > tmp)) {
            array[j + h] = array[j];
            j-=h;
        }
        array[j + h] = tmp;
    }
}

void quicksortRec(int *array, int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array[(dir+esq)/2];
    while (i <= j) {
        while (array[i] < pivo) i++;
        while (array[j] > pivo) j--;
        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}

void meuAlgoritmo(int *array, int n) {
    insercaoPorCor(array, n, 0, 1);
    quicksortRec(array, 0, n-1);
}