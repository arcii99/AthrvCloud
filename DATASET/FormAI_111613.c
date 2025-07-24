//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUM 4
#define DATA_SIZE 100000000

int data[DATA_SIZE];
int result[THREAD_NUM];

void *sum(void *arg){
    int thread_id = *(int*) arg;
    int thread_sum = 0;
    int start = thread_id * (DATA_SIZE / THREAD_NUM);
    int end = start + (DATA_SIZE / THREAD_NUM);

    for (int i = start; i < end; i++) {
        thread_sum += data[i];
    }

    result[thread_id] = thread_sum;

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[THREAD_NUM];
    int id[THREAD_NUM];

    for(int i = 0; i < DATA_SIZE; i++){
        data[i] = rand() % 10;
    }

    for(int i = 0; i < THREAD_NUM; i++) {
        id[i] = i;
        pthread_create(&threads[i], NULL, sum, &id[i]);
    }

    for(int i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_sum = 0;
    for(int i = 0; i < THREAD_NUM; i++) {
        total_sum += result[i];
    }

    printf("Total sum: %d\n", total_sum);
    
    return 0;
}