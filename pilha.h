// estrutura da pilha
typedef struct pilha Pilha;
// criação da pilha
Pilha* pilha_start ();
// inserção de elemento na pilha
Pilha* pilha_push (Pilha* p, float v);
// remoção de elemento na pilha
float pilha_pop (Pilha* p);
// testa se a pilha está vazia
int pilha_empty (Pilha* p);
// exibe os elementos da pilha
void pilha_show (Pilha* p);
// libera espaço de memória ocupado pela pilha
void pilha_free (Pilha* p);