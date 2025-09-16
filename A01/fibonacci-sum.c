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

pthread_mutex_t mutex_fibonacci;

int sum = 0;

typedef struct Operand {
    int x1; // First term of the sum
    int x2; // Second term of the sum
} Operand;

Operand *operandPtr;

void *summation(void *data); // Thread function

int main(int argc, char *argv[]) {
    int N;

    pthread_mutex_init(&mutex_fibonacci, NULL);
    
    operandPtr = (Operand *)malloc(sizeof(Operand));
    
    // Input validation
    if(argc != 2) {
        fprintf(stderr, "Sintax: <my-program.out> <number-of-steps>\n");
        exit(-1);
    }

    N = atoi(argv[1]);

    if(N < 0) {
        fprintf(stderr, "Argument %d must be non-negative\n", N);
        exit(-1);
    }
    
    pthread_t tid[N]; // TID - Thread identifier
    pthread_attr_t attr; // Thread attributes
    
    // Initialization
    operandPtr->x1 = 0;
    operandPtr->x2 = 1;

    printf("N  : %d terms\n", N);
    printf("Sum: %02d, Partials: %02d, %02d\n", sum, operandPtr->x1, operandPtr->x2);

    // 1. Define threads with default attributes
    pthread_attr_init(&attr);

    // 2. Create threads
    for(int k=0; k<N; k++) {
        pthread_create(&tid[k], &attr, summation, operandPtr);
    }

    // 3. Wait for threads to finish
    for(int k=0; k<N; k++) {
        pthread_join(tid[k], NULL);
    }

    pthread_mutex_destroy(&mutex_fibonacci);
    
    free(operandPtr);
    operandPtr = NULL;
}

// Thread function
void *summation(void *data)  {
    pthread_mutex_lock(&mutex_fibonacci);

    Operand *s = (Operand *)data;
    
    sum = s->x1 + s->x2;
    s->x1 = s->x2;
    s->x2 = sum;
    printf("Sum: %02d, Partials: %02d, %02d\n", sum, s->x1, s->x2);

    pthread_mutex_unlock(&mutex_fibonacci);
    
    pthread_exit(0);
}

