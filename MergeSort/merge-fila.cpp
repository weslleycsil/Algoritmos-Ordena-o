#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
//Classe Nodo, contém uma variavel X
class Nodo {
    private:
        int x;
        Nodo *prox, *ant;
        
    public:
        Nodo(int valor) {
            x = valor;
        }
        
        void setX(int novo) {
            if (novo < 0) {
                novo = novo * -1;
            }
            x = novo;
        }
        
        int getX() {
            return x;
        }

        Nodo* getAnt() {
            return ant;
        }
        
        void setAnt(Nodo *P) {
            ant = P;
        }
        
        Nodo* getProx() {
		    return prox;
	    }

        void setProx(Nodo *P) {
            prox = P;
        }
        
        void mostra() {	
            printf("(%d)",x);	
        }
};

class FilaEncadeada {
    
    private:
        Nodo *inicioFila, *fimFila;
        int tamanho;
        
    public:
        FilaEncadeada() {
            tamanho = 0;
            inicioFila = NULL;
            fimFila = NULL;
        }
        
        int insere(Nodo *novoNodo) {
            
            Nodo *aux;            
            //Verifico se vazio
            if(inicioFila == NULL && fimFila == NULL){
                inicioFila = novoNodo;
                fimFila = novoNodo;
                fimFila->setProx(NULL);
                tamanho++;
                printf("Registro inserido com sucesso!\n");
                return 1;
            }         
            //insiro na fila
            fimFila->setProx(novoNodo);
            fimFila = novoNodo;
            fimFila->setProx(NULL);
            tamanho++;   
            printf("Registro inserido com sucesso!\n");
            return 1;
        }
        
        Nodo *remove() {
            //Verifico se vazio
            if(inicioFila == NULL && fimFila == NULL) {
                printf("A Fila está vazia.");
                return NULL;
            }
            Nodo *registro;
            registro = inicioFila;
            inicioFila = inicioFila->getProx();
            tamanho--;
            printf("Registro removido.\n");
            return registro;
        }
        
        void mostra(){
            //Pilha esta vazia?
            if(inicioFila == NULL && fimFila == NULL){
                printf("A Pilha está vazia.");
            } else {
                Nodo* Aux;
			    Aux = inicioFila;
                while (Aux != NULL) {
				Aux->mostra();
				Aux = Aux->getProx();
			    }
                printf("\n");
            }
        }
        Nodo *getInicioFila(){
            if(inicioFila == NULL && fimFila == NULL){
                printf("A Pilha está vazia.");
                return NULL;
            }
            Nodo* Aux;
			Aux = inicioFila;
            
            return Aux;
            
            
        }
        int getTam() { // Fornece o tamnaho da fila.
            return tamanho;
        }
        
        FilaEncadeada concatena(FilaEncadeada secondFila){
            int tamanhoA = getTam();
            int tamanhoB = secondFila.getTam();
            
            FilaEncadeada retorno;
            
            for(int cont = 0;cont < tamanhoA; cont++) {
                retorno.insere(remove());
            }
            
            for(int i = 0; i < tamanhoB; i++) {
                retorno.insere(secondFila.remove());                
            }
            
            return retorno;
        }
        
        FilaEncadeada sort() {
            int controle = (getTam()/2);
            int controle2 = (getTam()-controle);

            FilaEncadeada new1, new2;

            for(int cont = 0;cont < controle; cont++) {
                new1.insere(remove());
            }

            for(int cont = 0;cont < controle2; cont++) {
                new2.insere(remove());
            }
            new1.mostra();
            printf("\n");
            new2.mostra();
            //verificar variaveis de controle
            if((controle != 1 & controle2 != 1) || (controle != 1 & controle2 != 2)){
                //chamar recursividade
                new1 = new1.sort();
                new2 = new2.sort();
                
            }
            
            //chamo o merge
            return new1.merge(new2);

        }
        FilaEncadeada merge(FilaEncadeada fila2){
            FilaEncadeada filaOrdenada;
            if(getTam()== 1 && fila2.getTam()==2){
                if(fila2.getInicioFila()->getX() > fila2.getInicioFila()->getProx()->getX()){
                    fila2.insere(fila2.remove());
                }
            }
            while(!(getTam() != 0) ^ (fila2.getTam() != 0)){
                //printf("Teste Logico: %d\n",(getTam() != 0) ^ (fila2.getTam() != 0));
                if(getInicioFila()->getX() <= fila2.getInicioFila()->getX()){
                    //getInicioFila()->mostra();
                    filaOrdenada.insere(remove());
                    //printf("Fila 1 - %d\n",getTam());
                } else /*if(getInicioFila()->getX() > fila2.getInicioFila()->getX())*/{
                    //fila2.getInicioFila()->mostra();
                    filaOrdenada.insere(fila2.remove());
                    //printf("Fila 2 - %d\n",fila2.getTam());
                }
            }
            while(getTam() != 0){
                filaOrdenada.insere(remove());
            }
            while(fila2.getTam() != 0){
                filaOrdenada.insere(fila2.remove());
            }
            
            return filaOrdenada; 
            
        }
        
        FilaEncadeada mergeSort(FilaEncadeada fila2){
            fila2 = concatena(fila2);
            return fila2.sort();
        }
        
};



int main (){

	FilaEncadeada f1, f2, f3;
    
    for(int i = 0; i < 10; i++){
        f1.insere(new Nodo((rand()%100)+1));
        f2.insere(new Nodo((rand()%100)+1));
    }
    
    f1.insere(new Nodo(9));
    
    
    
	f1.mostra();
    f2.mostra();
    
    //concateno F1 e F2 em F3
    f3 = f1.concatena(f2);
    
    //Rodo Algoritmo MergeSort em F3
    f3 = f3.sort();
    
    printf("\n");
    f3.mostra();

}
