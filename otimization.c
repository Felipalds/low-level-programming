/*
    Para fazer sentido esta prática, o código deve ser compilado sem otimização
    compilação simples sem otimização (-O0):    
        gcc -O0 prodEscOR.c -o prodEscOR.x
    para profiler (-gp):
        gcc -O0 -pg prodEscOR.c -o prodEscOR.x
*/

#include <stdio.h>
#include <stdlib.h>

#define N 600000000 // altere para +- 50% da sua memória RAM (N*8*2)

double prodEscalar(double* v1, double* v2){
    double s0 = 0, s1 = 0, s2 = 0, s3 = 0;

    for (int i = 0; i < N; i+=4) {
        s0 += v1[i] * v2[i];
        s1 += v1[i+1] * v2[i+1];
        s2 += v1[i+2] * v2[i+2];
        s3 += v1[i+3] * v2[i+3];
    }

    return s0 + s1 + s2 + s3;
}

void solucao(double n){
    printf("Produto Escalar: %0.2f\n", n);
}

double* inicializarVetor(){
    double *v;
    v = (double *) calloc(N, sizeof(double));
    for (int i = 0; i < N; i = i + 4) {
        v[i] = i;
        v[i+1] = i+1;
        v[i+2] = i+2;
        v[i + 3] = i+3;

    }
    return v;
}

int main() {
    double vsum = 0.0;
    double *v1, *v2;

    //printf("memória estimada: %0.2f GiB\n", ((((N*8.0*2.0) / 1024)/1024)/1024));

    v1 = inicializarVetor();
    v2 = inicializarVetor();

    if (v1 == NULL || v2 == NULL) {
        printf("calloc falhou para %u double\n", N);
        return -1;
    }

    vsum = prodEscalar(v1,v2);
    
    solucao(vsum);

    free(v1);
    free(v2);

    return 0;
}
