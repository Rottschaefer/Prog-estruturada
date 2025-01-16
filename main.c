# include <stdio.h>

# include "pilha.h"
int main(){
Pilha* p = pilha_start();
char frase[100];
int indice = 0;
printf("Digite uma frase: ");
scanf(" %[^\n]",frase);
while (frase[indice] != '\0'){
while ((frase[indice] != ' ') && (frase[indice] != '\0')){
pilha_push(p,frase[indice]);
indice++;
}
if (frase[indice] != '\0') indice++;
while (!pilha_empty(p)){
char letra = pilha_pop(p); printf("%c", letra);
}
printf(" ");
}
pilha_free(p);
}