// estrutura da fila
typedef struct fila Fila;
// criação da fila
Fila* fila_start ();
// inserção de elemento na fila: enfileirar
Fila* Fila_enqueue (Fila* f, float v);
// remoção de elemento na fila
float fila_dequeue (Fila* f);
// testa se a fila está vazia
int fila_empty (Fila* f);
// exibe os elementos da fila
void fila_show (Fila* f);
// libera espaço de memória ocupado pela fila
void fila_free (Fila* f);