/*
  Program: parallelized Fibonacci

  This program implements a Fibonacci summation using threads.
  
  # Input:
  N: Number of steps in the sum (N > 0)
  
  # Output:
  The Fibonacci sum
  
 # Compile:
 gcc -o <my-program>.out <my-program>.c -lpthread
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

pthread_mutex_t mutex_formiga;

double total = 0;

typedef struct Formiga {
    int lenght;
    double angulo;
} Formiga;

Formiga *formigaPtr;

void *caminhar(void *data); // Thread function

int main(int argc, char *argv[]) {
    int a, N;

    formigaPtr = (Formiga *)malloc(sizeof(Formiga));

    pthread_mutex_init(&mutex_formiga, NULL);
    
    // Input validation
    if(argc != 3) {
        fprintf(stderr, "Sintax: <my-program.out> <number-of-steps> <side-lenght>\n");
        exit(-1);
    }

    N = atoi(argv[1]);
    a = atoi(argv[2]);

    if(N < 0) {
        fprintf(stderr, "<number-of-steps> %d must be non-negative\n", N);
        exit(-1);
    }

    if(a < 0) {
        fprintf(stderr, "<side-lenght> %d must be non-negative\n", N);
        exit(-1);
    }
    
    pthread_t tid[N];
    pthread_attr_t attr;
    
    // Initialization
    formigaPtr->lenght = a;
    formigaPtr->angulo = (PI/2) - atan(N);

    // 1. Define threads with default attributes
    pthread_attr_init(&attr);

    // 2. Create threads
    for(int k=0; k<N; k++) {
        pthread_create(&tid[k], &attr, caminhar, formigaPtr);
    }

    // 3. Wait for threads to finish
    for(int k=0; k<N; k++) {
        pthread_join(tid[k], NULL);
    }
    
    pthread_mutex_destroy(&mutex_formiga);
    free(formigaPtr);
    formigaPtr = NULL;
}

// Thread function
void *caminhar(void *data)  {
    pthread_mutex_lock(&mutex_formiga);
    
    Formiga *s = (Formiga *)data;
    
    double parcial = s->lenght / cos(s->angulo);
    total += parcial;
    printf("Parcial: %02lf, Total: %02lf\n", parcial, total);
    
    pthread_mutex_unlock(&mutex_formiga);
    
    pthread_exit(0);
}

