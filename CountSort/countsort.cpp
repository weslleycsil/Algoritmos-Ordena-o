#include <stdio.h>
#include <stdlib.h>

int *zeraVetor(int * vetor, int tamanho){
    for(int i=0; i < tamanho; i++){
        vetor[i] = 0;
    }
    return vetor;
}


int *countsort(int *array, int tamanho){
     int valorMaior = array[0];
     int passei=0;
     for(int i = 1; i < tamanho; i++){
         if(valorMaior < array[i]){
             valorMaior = array[i];
         }
         passei++;
     }

     int *arrayAux = new int[valorMaior+1];
     arrayAux = zeraVetor(arrayAux,valorMaior+1);
     //percorro o array procurando repetições
     
     for(int i = 0; i < valorMaior+1; i++){
         for(int j= 0; j < tamanho; j++){
             if(i == array[j]){
                 arrayAux[i]++;
             }
             passei++;
         }
         
     }
     
     //acumulo os valores
     int *arrayFinal = new int[tamanho];
     arrayFinal = zeraVetor(arrayFinal,tamanho);
     for(int i=1; i < valorMaior+1; i++){
         arrayAux[i] = arrayAux[i]+ arrayAux[i-1];
     }

     printf("\n");
     //inserçao de valores no array final
     for(int i=0; i < tamanho; i++){
         arrayAux[array[i]]--;
         arrayFinal[arrayAux[array[i]]]= array[i];
     }
     
     return arrayFinal;
}

int main(){
    
    int tamanho = 13;
    int * array = new int[tamanho];
    srand(time(NULL));

    printf("Array Original:\n");
    
    for(int i = 0; i < tamanho; i++){
        array[i] =(rand()%100)+1;
        printf("%d ",array[i]);
    }
    
    printf("\n");
    array = countsort(array,tamanho);
    
    for(int i=0; i < tamanho; i++){
         printf("%d ",array[i]);
     }
     printf("\n");
}
