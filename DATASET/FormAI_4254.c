//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 4
#define SIZE 10000000

int nums[SIZE];

void fillArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 1000;
    }
}

void* min(void* arg){
    int threadNum = *(int*) arg;
    int start = threadNum * (SIZE / THREADS);
    int end = (threadNum + 1) * (SIZE / THREADS);

    int minValue = nums[start];
    for(int i = start + 1; i < end; i++){
        if(nums[i] < minValue)
            minValue = nums[i];
    }

    return (void*) minValue;
}

int main(){
    fillArray(nums, SIZE);

    pthread_t threads[THREADS];
    int threadNums[THREADS];

    int minValues[THREADS];

    for(int i = 0; i < THREADS; i++){
        threadNums[i] = i;
        pthread_create(&threads[i], NULL, min, (void*) &threadNums[i]);
    }

    for(int i = 0; i < THREADS; i++){
        pthread_join(threads[i], (void*) &minValues[i]);
    }

    int globalMin = minValues[0];
    for(int i = 1; i < THREADS; i++){
        if(minValues[i] < globalMin){
            globalMin = minValues[i];
        }
    }

    printf("The global minimum number is: %d\n", globalMin);

    return 0;
}