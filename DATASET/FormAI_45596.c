//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_BAGS 100
#define MAX_THREADS 20

typedef struct {
    int id;
    int weight;
    int origin;
    int destination;
} Bag;

int currentBagIndex = 0;
Bag baggageArray[MAX_BAGS];
pthread_mutex_t baggageMutex = PTHREAD_MUTEX_INITIALIZER;
sem_t full_bags;
int threadsWaiting = 0;

void* baggage_handler(void* arg) {
    int* thread_id = (int*) arg;
    while(1) {
        sem_wait(&full_bags);
        pthread_mutex_lock(&baggageMutex);
        Bag currentBag = baggageArray[currentBagIndex];
        currentBagIndex++;
        pthread_mutex_unlock(&baggageMutex);
        printf("Thread[%d] is handling Bag[%d] from origin %d going to destination %d...\n", *thread_id, currentBag.id, currentBag.origin, currentBag.destination);
        // simulate baggage handling process
        sleep(2);
        printf("Done handling Bag[%d].\n", currentBag.id);
        if(currentBagIndex == MAX_BAGS) {
            break;
        }
    }
    threadsWaiting++;
    pthread_exit(NULL);
}

int main() {
    // initialize baggage array with random values
    srand(time(NULL));
    for(int i = 0; i < MAX_BAGS; i++) {
        baggageArray[i].id = i+1;
        baggageArray[i].weight = rand() % 50 + 1;
        baggageArray[i].origin = rand() % 10 + 1;
        baggageArray[i].destination = rand() % 10 + 1;
    }
    // initialize semaphore
    sem_init(&full_bags, 0, MAX_BAGS);
    // create threads
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    for(int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, baggage_handler, (void*) &thread_ids[i]);
    }
    // join threads
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All bags have been handled by all threads.\n");
    printf("Waiting for all threads to exit...\n");
    while(threadsWaiting != MAX_THREADS);
    printf("All threads have exited.\n");
    sem_destroy(&full_bags);
    return 0;
}