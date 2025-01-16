# include <stdio.h>

# include "fila.h"

void separar_pares_impar(Fila* fila_normal, Fila* fila_par, Fila* fila_impar){
        
    int num = fila_dequeue(fila_normal);
    while(num != -1){
        if(num%2 == 0){
            fila_par = fila_enqueue(fila_par, num);
        }
        else{
            fila_impar = fila_enqueue(fila_impar, num);
        }
    }
        
}

int main(){
    Fila* fila_nums = fila_start();

    for (int i = 0; i < 10; i++)
    {
        fila_enqueue(fila_nums, i);
    }


    Fila* fila_par = fila_start();
    Fila* fila_impar = fila_start();

    separar_pares_impar(fila_nums, fila_par, fila_impar);

    fila_show(fila_par);
    puts("");
    fila_show(fila_impar);

    
    

return 0;
}