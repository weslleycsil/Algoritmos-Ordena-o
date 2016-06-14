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
                printf("A Fila está vazia.");
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
        
        FilaEncadeada quick(){
            
            int tamanho = getTam();
            FilaEncadeada menores, iguais, maiores, final;
            Nodo * pivo;
            
            //escolho o pivo
            pivo = getInicioFila(); //"randominacamente"
            
            //separo os maiores e menores
            
            for(int i=0; i < tamanho; i++){
                
                if(getInicioFila()->getX() < pivo->getX()){
                    //printf("Menores\n");
                    getInicioFila()->mostra();
                    menores.insere(remove());
                    
                } else if(getInicioFila()->getX() > pivo->getX()){
                    //printf("Maiores\n");
                    maiores.insere(remove());
                    
                } else {
                    //printf("Iguais\n");
                    iguais.insere(remove());
                }
                
            }
            
            /*printf("Vetor Menores:\n");
            menores.mostra();
            printf("\n");
            printf("Vetor Maiores:\n");
            maiores.mostra();
            printf("\n");
            printf("Vetor iguais:\n");
            iguais.mostra();
            printf("\n");*/
            
            //chamada da recursividade
            
            if(menores.getTam()>2){
                menores = menores.quick();
            } else if(menores.getTam() != 1 && menores.getTam() > 0){
                // caso trivial
                menores.insere(menores.remove());
            }
            if(maiores.getTam()>2){
                maiores = maiores.quick();
            } else if(maiores.getTam() != 1 && maiores.getTam() > 0){
                // caso trivial
                 maiores.insere(maiores.remove());
            }
            
            final = menores.concatena(iguais);
            final = final.concatena(maiores);
            return final;
            
            
        }
        
};

int main(){
    
    FilaEncadeada f1;
    
    for(int i = 0; i <30; i++){
        f1.insere(new Nodo((rand()%100)+1));
    }
    
    
    f1.mostra();
    printf("\n\n");
    f1 = f1.quick();
    f1.mostra();
    
}
