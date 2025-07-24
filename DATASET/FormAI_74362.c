//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double temperatureC; // global variable to store temperature in Celsius
pthread_mutex_t mutex_lock; // lock to prevent race conditions

void * readSensor(void * arg) {
    while (1) {
        // simulate sensor readings
        temperatureC = (double)rand() / (double)RAND_MAX * 100.0;
        printf("Temperature reading: %.2lf°C\n", temperatureC);
        sleep(1); // wait for 1 second
    }
}

void * displayTemperature(void * arg) {
    while (1) {
        pthread_mutex_lock(&mutex_lock); // acquire lock
        printf("Current temperature: %.2lf°C\n", temperatureC);
        pthread_mutex_unlock(&mutex_lock); // release lock
        sleep(5); // wait for 5 seconds
    }
}

int main() {
    pthread_t sensorThread, displayThread;

    if (pthread_mutex_init(&mutex_lock, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    if (pthread_create(&sensorThread, NULL, readSensor, NULL) != 0) {
        printf("Sensor thread creation failed.\n");
        return 1;
    }

    if (pthread_create(&displayThread, NULL, displayTemperature, NULL) != 0) {
        printf("Display thread creation failed.\n");
        return 1;
    }

    pthread_join(sensorThread, NULL);
    pthread_join(displayThread, NULL);

    pthread_mutex_destroy(&mutex_lock);

    return 0;
}