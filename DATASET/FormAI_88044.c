//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 3

int temperature = 25;
pthread_mutex_t tLock;
pthread_cond_t waitCon, below10Con;

void *monitorTemperature(void *arg) {
    int *id = (int*)arg;
    printf("Temperature monitor %d started\n", *id);

    while(1) {
        pthread_mutex_lock(&tLock);

        if(temperature < 10) {
            printf("Temperature too low, waiting for heater...\n");
            pthread_cond_wait(&below10Con, &tLock);
            printf("Temperature monitor %d received signal, resuming...\n", *id);
        }

        if(temperature > 30) {
            printf("Temperature too high, turning on fan...\n");
        } else {
            printf("Temperature is normal\n");
        }

        pthread_mutex_unlock(&tLock);
        sleep(3);
    }

    pthread_exit(NULL);
}

void *adjustTemperature(void *arg) {
    int *id = (int*)arg;

    while(1) {
        pthread_mutex_lock(&tLock);

        if(temperature < 10) {
            printf("Temperature too low, increasing...\n");
            temperature += 5;
            pthread_cond_signal(&below10Con);
        }

        if(temperature > 30) {
            printf("Temperature too high, decreasing...\n");
            temperature -= 5;
        } else {
            printf("Temperature is normal\n");
        }

        pthread_mutex_unlock(&tLock);
        sleep(2);
    }

    pthread_exit(NULL);
}

void *randomizeTemperature(void *arg) {
    srand(time(NULL));
    while(1) {
        pthread_mutex_lock(&tLock);

        temperature = rand() % 40;
        printf("Temperature randomized to %d\n", temperature);

        pthread_mutex_unlock(&tLock);
        sleep(5);
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int monitorIDs[NUM_THREADS] = {1, 2, 3};

    pthread_mutex_init(&tLock, NULL);
    pthread_cond_init(&waitCon, NULL);
    pthread_cond_init(&below10Con, NULL);

    pthread_create(&threads[0], NULL, monitorTemperature, &monitorIDs[0]);
    pthread_create(&threads[1], NULL, adjustTemperature, &monitorIDs[1]);
    pthread_create(&threads[2], NULL, randomizeTemperature, &monitorIDs[2]);

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&tLock);
    pthread_cond_destroy(&waitCon);
    pthread_cond_destroy(&below10Con);

    return 0;
}