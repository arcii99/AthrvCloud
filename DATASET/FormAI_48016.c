//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
/* 
   The following C code is a threading library implementation using a bakery algorithm.
   It allows for multiple threads to execute concurrently while preventing the problem of race conditions.
   Enjoy the art in code!
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 20

int numThreads = 0;

struct Bakery {
    int entering[MAX_THREADS];
    int ticket[MAX_THREADS];
};

struct Bakery shop;

void Bakery_Init() {
    int i;
    for(i = 0; i < MAX_THREADS; i++) {
        shop.entering[i] = 0;
        shop.ticket[i] = 0;
    }
}

void Bakery_Lock(int threadNumber) {
    shop.entering[threadNumber] = 1;
    int max_ticket = 0;
    int i;
    for(i = 0; i < MAX_THREADS; i++) {
        if(shop.ticket[i] > max_ticket) {
            max_ticket = shop.ticket[i];
        }
    }
    shop.ticket[threadNumber] = max_ticket + 1;
    shop.entering[threadNumber] = 0;
    for(i = 0; i < MAX_THREADS; i++) {
        if(i != threadNumber) {
            while(shop.entering[i]) { }
            while(shop.ticket[i] && 
                  (shop.ticket[i] < shop.ticket[threadNumber] || 
                   (shop.ticket[i] == shop.ticket[threadNumber] && i < threadNumber))) { }
        }
    }
}

void Bakery_Unlock(int threadNumber) {
    shop.ticket[threadNumber] = 0;
}

void *threadFunc(void *arg) {
    int threadNumber = *(int *)arg;
    Bakery_Lock(threadNumber);
    printf("Thread %d entered critical section\n", threadNumber);
    sleep(1);
    printf("Thread %d exiting critical section\n", threadNumber);
    Bakery_Unlock(threadNumber);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;
    int threadArgs[MAX_THREADS];
    Bakery_Init();
    printf("How many threads would you like to create? (max %d): ", MAX_THREADS);
    scanf("%d", &numThreads);
    if(numThreads > MAX_THREADS) {
        printf("Error: too many threads requested\n");
        return 1;
    }
    for(i = 0; i < numThreads; i++) {
        threadArgs[i] = i;
        pthread_create(&threads[i], NULL, threadFunc, (void *)&threadArgs[i]);
    }
    for(i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}