#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura dos nós da lista
typedef struct elemento {
float info;
struct elemento* prox;
}ElementoPilha;
/* Estrutura para representar a pilha: será um ponteiro para o primeiro
elemento, o topo da pilha */
typedef struct pilha {
ElementoPilha* topo;
}Pilha;

// alocação dinâmica da estrutura de pilha
// inicialização do endereço do topo da pilha para NULL
// ainda não tem ninguém

Pilha* pilha_start ( ){
Pilha* p = (Pilha*) malloc(sizeof(Pilha));
p->topo = NULL;
return p;
}

// Testa se a pilha não aponta para nenhum elemento

int pilha_empty (Pilha* p ){
if (p->topo == NULL)
return 1;
return 0;
}

// inserção de elementos na pilha - sempre no topo

Pilha* pilha_push (Pilha* p, float info ){
ElementoPilha* novo = (ElementoPilha*)
malloc(sizeof(ElementoPilha));
novo->info = info;
novo->prox = p->topo; /* se a pilha estiver vazia,
aponta para NULL */

p->topo = novo;
return p;
}

// remoção de elementos na pilha - sempre no topo

float pilha_pop (Pilha* p ){
if (pilha_empty(p))
return -1;
ElementoPilha* popped = p->topo;
float info = popped->info;
p->topo = popped->prox;
free(popped);
return info;
}

// Exibição de elementos da pilha: igual a qualquer lista
// encadeada

void pilha_show (Pilha* p ){
ElementoPilha* percorre = p->topo;
if (!pilha_empty(p)){
while (percorre != NULL){
printf("%.2f", percorre->info);
percorre = percorre->prox;
}
}
}

// Libera primeiro os elementos e depois a pilha

void pilha_free (Pilha* p ){
ElementoPilha* percorre = p->topo;
while (percorre != NULL){

ElementoPilha* aux = percorre->prox;
free(percorre);
percorre = aux;

}
free(p);
}