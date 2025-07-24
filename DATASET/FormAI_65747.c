//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define MAX_TEMP 100
#define MIN_TEMP 0

int currentTemp = 50;
int isRunning = 1;

pthread_mutex_t lock;

void *maintainTemperature(void *threadid) {
    int tid = *(int*)threadid;
    while(isRunning) {
        pthread_mutex_lock(&lock);
        if (currentTemp > MAX_TEMP) {
            printf("Temperature too high! Cooling down.\n");
            currentTemp--;
        } else if(currentTemp < MIN_TEMP) {
            printf("Temperature too low! Heating up.\n");
            currentTemp++;
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *readTemperature(void *threadid) {
    int tid = *(int*)threadid;
    while(isRunning) {
        pthread_mutex_lock(&lock);
        printf("Current Temperature: %d\n", currentTemp);
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS] = {1, 2};

    pthread_mutex_init(&lock, NULL);

    pthread_create(&threads[0], NULL, maintainTemperature, (void *)&threadIds[0]);
    pthread_create(&threads[1], NULL, readTemperature, (void *)&threadIds[1]);

    // Let the threads run for 60 seconds
    sleep(60);

    // Stop running program
    isRunning = 0;

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}