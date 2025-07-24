//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 1000000

int arr[SIZE];

void fillArray(){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() % SIZE;
    }
}

typedef struct {
    int threadNum;
    int startIndex;
    int endIndex;
    int target;
    int foundIndex;
} threadParams;

int searchInRange(int startIndex, int endIndex, int target, int *foundIndex){
    for(int i = startIndex; i < endIndex; i++){
        if(arr[i] == target){
            *foundIndex = i;
            return 1;
        }
    }
    return 0;
}

void *threadFunction(void *params){
    threadParams *p = (threadParams *)params;
    printf("Thread %d starting search from index %d to %d\n", p->threadNum, p->startIndex, p->endIndex);
    int foundIndex = -1;
    searchInRange(p->startIndex, p->endIndex, p->target, &foundIndex);
    if(foundIndex != -1){
        p->foundIndex = foundIndex;
    }
    pthread_exit(NULL);
}

int search(int target){
    int numThreads = 4;
    int chunkSize = SIZE / numThreads;
    pthread_t threads[numThreads];
    threadParams params[numThreads];
    for(int i = 0; i < numThreads; i++){
        params[i].threadNum = i;
        params[i].startIndex = i * chunkSize;
        params[i].endIndex = (i + 1) * chunkSize;
        params[i].target = target;
        params[i].foundIndex = -1;
        pthread_create(&threads[i], NULL, threadFunction, &params[i]);
    }
    int foundIndex = -1;
    for(int i = 0; i < numThreads; i++){
        pthread_join(threads[i], NULL);
        if(params[i].foundIndex != -1){
            foundIndex = params[i].foundIndex;
        }
    }
    return foundIndex;
}

int main(){
    fillArray();
    int target = arr[rand() % SIZE];
    printf("Searching for %d\n", target);
    int foundIndex = search(target);
    if(foundIndex != -1){
        printf("Found %d at index %d\n", target, foundIndex);
    } else {
        printf("%d not found\n", target);
    }
    return 0;
}