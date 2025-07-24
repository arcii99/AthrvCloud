//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cryptic
//Welcome to the Airport Baggage Handling Simulation Program

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BAGGAGE 100
#define MAX_THREADS 5

int currentBaggage = 0; // Current count of baggage in the system
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to handle access to count of baggage

// Function to simulate baggage being added to the system
void addBaggage() {
    pthread_mutex_lock(&mutex);
    if(currentBaggage < MAX_BAGGAGE) {
        currentBaggage++;
        printf("One baggage added to the system. Current count is %d\n", currentBaggage);
    }
    pthread_mutex_unlock(&mutex);
}

// Function to simulate baggage being removed from the system
void removeBaggage() {
    pthread_mutex_lock(&mutex);
    if(currentBaggage > 0) {
        currentBaggage--;
        printf("One baggage removed from the system. Current count is %d\n", currentBaggage);
    }
    pthread_mutex_unlock(&mutex);
}

// Function to be executed by each thread
void *threadFunction(void *arg) {
    int threadNumber = *((int*)arg);
    while(1) {
        if(threadNumber == 0 || threadNumber == 1) { // Threads 0 and 1 simulate passengers adding baggage
            addBaggage();
        }
        else { // Threads 2, 3, and 4 simulate baggage handlers removing baggage
            removeBaggage();
        }
    }
}

int main() {
    pthread_t threads[MAX_THREADS];
    int threadNumbers[MAX_THREADS] = {0,1,2,3,4};

    for(int i=0; i<MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &threadNumbers[i]);
    }

    for(int i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}