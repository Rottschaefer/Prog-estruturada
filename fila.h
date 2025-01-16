// estrutura da fila
typedef struct fila Fila;
// criação da fila
Fila* fila_start ();
// inserção de elemento na fila: enfileirar
Fila* fila_enqueue (Fila* f, int v);
// remoção de elemento na fila
int fila_dequeue (Fila* f);
// testa se a fila está vazia
int fila_empty (Fila* f);
// exibe os elementos da fila
void fila_show (Fila* f);
// libera espaço de memória ocupado pela fila
void fila_free (Fila* f);

void separar_pares_impar(Fila* fila_normal, Fila* fila_par, Fila* fila_impar);