#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura dos nós da fila
typedef struct elemento {
int info;
struct elemento* prox;
}ElementoFila;
/* Estrutura para representar a fila: para facilitar a remoção, será mantido
um ponteiro para o início e para o fim da fila */
typedef struct fila {
ElementoFila* primeiro;
ElementoFila* ultimo;
}Fila;


// alocação dinâmica da estrutura de fila
// inicialização do endereço do primeiro e último para
// NULL: ainda não tem ninguém

Fila* fila_start ( ){
Fila* f = (Fila*) malloc(sizeof(Fila));
f->primeiro = NULL;
f->ultimo = NULL;
return f;
}

// Testa se a fila não aponta para nenhum elemento

int fila_empty (Fila* p ){
if (p->primeiro == NULL)
return 1;
return 0;
}

// inserção de elementos na fila - no fim da lista

Fila* fila_enqueue (Fila* f, int info ){
ElementoFila* novo = (ElementoFila*)malloc(sizeof(ElementoFila));

novo->info = info;
novo->prox = NULL; //novo será o último elemento

if (fila_empty(f))
    f->primeiro = novo;
else
    f->ultimo->prox = novo;
    f->ultimo = novo; // novo passa a ser o último
return f;
}

// remoção de elementos na fila - remove do início

int fila_dequeue (Fila* f ){
if (fila_empty(f))
return -1;
ElementoFila* deq = f->primeiro;
int info = deq->info;
if (f->primeiro == f->ultimo) //apenas um elemento
f->ultimo = NULL;
f->primeiro = deq->prox;
free(deq);
return info;
}

// Exibição de elementos da pilha: igual a qualquer lista
//encadeada

void fila_show (Fila* f ){
ElementoFila* percorre = f->primeiro;
if (!fila_empty(f)){
while (percorre != NULL){
printf("%d\n", percorre->info);
percorre = percorre->prox;
}
}
}

// Libera primeiro os elementos e depois a fila

void fila_free (Fila* f ){
ElementoFila* percorre = f->primeiro;
while (percorre != NULL){

ElementoFila* aux = percorre->prox;
free(percorre);
percorre = aux;

}
free(f);
}

