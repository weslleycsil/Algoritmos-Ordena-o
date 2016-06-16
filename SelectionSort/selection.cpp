#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

int main(){
    int tamanho = 5;
    int * vetor = new int[tamanho];
    int menor;
    int cont, aux, passei;
    srand(time(NULL));

    //criar vetor
    for(int i = 0; i < tamanho; i++){
        vetor[i] = (rand()%100)+1;
        printf("%d ",vetor[i]);
    }
    printf("\n");
    
    for(int i = 0; i < tamanho; i++){
        //verificar o menor
        menor = vetor[i];
        
        for(int j = i; j < tamanho; j++){
            if(vetor[j] <=  menor){ menor = vetor[j]; cont = j;}
        }
        aux = vetor[i];
        vetor[i] = menor;
        vetor[cont] = aux;
    }
    //printar o vetor ordenado
    for(int i = 0; i < tamanho; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}
