# Algoritmo Merge Sort Implementado em C++

A implementação do código foi feita em C++ Orientado a Objetos.

Classes:
Nodo
A classe Nodo é composta de uma variável x que aceita somente valores inteiros.
O nodo foi implementado para ser utilizado em uma Lista encadeada, por esse motivo ele conta com os ponteiros *prox e *ant para armazernar o endereço do nodo anterior e/ou próximo.

Métodos:
Públicos:
Nodo() -> recebe o valor inicial da variável X do Nodo e constroi o objeto.
setX(int) -> seta o valor da variavel X do respectivo Nodo.
int getX() -> retorna o valor da variavel X do respectivo Nodo.
*getAnt() -> retorna o endereço do Nodo anterior em uma Lista Encadeada.
*getProx() -> retorna o endereço do proximo Nodo em uma Lista Encadeada.
mostra() -> mostra o valor da variavel X do respectivo Nodo.

FilaEncadeada
A classe FilaEncadeada

Variáveis:
Privadas:

Públicas:

Métodos:
Públicos:
insere(Nodo *) ->
Nodo *remove() ->
mostra() ->
Nodo *getInicioFila() ->
getTam() ->
FilaEncadeada concatena() ->
FilaEncadeada sort() ->
FilaEncadeada merge() ->