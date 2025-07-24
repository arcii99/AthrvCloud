//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define SIZE 100

void *recursive(void*);

int main() {
    int input, result, i;
    pthread_t tid;
    printf("Enter a number: ");
    scanf("%d", &input);
    printf("Calculating factorial of %d asynchronously...\n", input);
    pthread_create(&tid, NULL, recursive, (void*) &input);
    pthread_join(tid, (void**) &result);
    printf("Factorial of %d is %d.\n", input, result);
    return 0;
}

void *recursive(void* arg) {
    int* n = (int*) arg;
    if (*n == 0) {
        return (void*) 1;
    } else {
        int* next = (int*) malloc(sizeof(int));
        *next = *n - 1;
        pthread_t tid;
        pthread_create(&tid, NULL, recursive, (void*) next);
        int result;
        pthread_join(tid, (void**) &result);
        free(next);
        return (void*) (*n * result);
    }
}