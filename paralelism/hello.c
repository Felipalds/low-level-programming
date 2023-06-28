/* Olá Mundo não tão simples
	exemplo 01.c 

   compilar:
      gcc -fopenmp 01.c -o 01.x 
*/
#include <stdio.h>
#include "omp.h"

int main()
{
    //omp_set_num_threads(8);
    #pragma omp parallel // anotations, not a C command
    { // (fork)
        int ID = omp_get_thread_num();
        // ID é variável privada de cada thread

        printf(" Olá %d", ID);
        printf(" Mundo %d\n", ID);
    } // (join)
    return 0;
}
