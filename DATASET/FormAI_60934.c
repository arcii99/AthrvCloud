//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 2

void* recursive(void* arg){
    int n = *(int*)arg;
    if(n <= 1){
        int* result = calloc(1, sizeof(int));
        *result = 1;
        return result;
    }
    pthread_t threads[N_THREADS];
    int args[N_THREADS][2];
    for(int i = 0; i < N_THREADS; i++){
        args[i][0] = n-1;
        pthread_create(&threads[i], NULL, recursive, (void*)args[i]);
    }
    void* results[N_THREADS];
    for(int i = 0; i < N_THREADS; i++){
        pthread_join(threads[i], &results[i]);
    }
    int* result = calloc(1, sizeof(int));
    for(int i = 0; i < N_THREADS; i++){
        *result *= *(int*)results[i];
    }
    *result *= n;
    return result;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s [n]\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    pthread_t thread;
    int arg[2] = {n};
    pthread_create(&thread, NULL, recursive, (void*)arg);
    void* result;
    pthread_join(thread, &result);
    printf("%d! = %d\n", n, *(int*)result);
    return 0;
}