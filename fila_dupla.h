// estrutura da fila
typedef struct fila FilaDupla;
// criação da fila
FilaDupla* fila_start ();
// inserção de elemento no início da fila: enfileirar
FilaDupla* fila_enqueue_b (FilaDupla* f, float v);
// remoção de elemento no início da fila
float fila_dequeue_b (FilaDupla* f);
// inserção de elemento no fim da fila: enfileirar
FilaDupla* fila_enqueue_e (FilaDupla* f, float v);
// remoção de elemento no fim da fila
float fila_dequeue_e (FilaDupla* f);
// testa se a fila está vazia
int fila_empty (FilaDupla* f);
// exibe os elementos da fila
void fila_show (FilaDupla* f);
// libera espaço de memória ocupado pela fila
void fila_free (FilaDupla* f);