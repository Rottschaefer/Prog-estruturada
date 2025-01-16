#include "fila_dupla.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura dos nós da fila
typedef struct elemento {
float info;
struct elemento* prox;
struct elemento* ant;
}ElementoFila;
/* Estrutura para representar a fila: para facilitar a remoção, será mantido
um ponteiro para o início e para o fim da fila */
typedef struct fila_dupla {
ElementoFila* primeiro;
ElementoFila* ultimo;
}FilaDupla;

// alocação dinâmica da estrutura de fila
// inicialização do endereço do primeiro e último para
// NULL: ainda não tem ninguém

FilaDupla* fila_dupla_start ( ){
FilaDupla* f = (FilaDupla*) malloc(sizeof(FilaDupla));
f->primeiro = NULL;
f->ultimo = NULL;
return f;
}

// Testa se a pilha não aponta para nenhum elemento

int* fila_dupla_empty (FilaDupla* p ){
if (p->primeiro == NULL)
return 1;
return 0;
}

// inserção de elementos na fila - no início da lista
FilaDupla* fila_enqueue_b(FilaDupla* f, float info ){
ElementoFila* novo = (ElementoFila*)
malloc(sizeof(ElementoFila));
novo->info = info;
novo->ant = NULL; //ninguém antes dele
novo->prox = f->primeiro;
if (fila_dupla_empty(f))
f->ultimo = novo;
else
f->primeiro->ant = novo;
f->primeiro = novo; // novo passa a ser o primeiro
return f;
}

// inserção de elementos na fila - no fim da lista
FilaDupla* fila_enqueue_e(FilaDupla* f, float info ){
ElementoFila* novo = (ElementoFila*)
malloc(sizeof(ElementoFila));
novo->info = info;
novo->prox = NULL; //novo será o último elemento
novo->ant = f->ultimo;
if (fila_empty(f))
f->primeiro = novo;
else
f->ultimo->prox = novo;
f->ultimo = novo; // novo passa a ser o último
return f;
}

// remoção de elementos na fila - remove do início
float fila_dequeue_b(FilaDupla* f ){
if (fila_empty(f))
return -1;
ElementoFila* deq = f->primeiro;
float info = deq->info;
if (f->primeiro == f->ultimo) //apenas um elemento
f->ultimo = NULL;
else
deq->prox->ant = NULL;
f->primeiro = deq->prox;
free(deq);
return info;
}

// remoção de elementos na fila - remove do fim da lista
float fila_dequeue_e(FilaDupla* f ){
if (fila_empty(f))
return -1;
ElementoFila* deq = f->ultimo;
float info = deq->info;
if (f->primeiro == f->ultimo) //apenas um elemento
f->primeiro = NULL;
else
deq->ant->prox = NULL;
f->ultimo = deq->ant;
free(deq);
return info;
}