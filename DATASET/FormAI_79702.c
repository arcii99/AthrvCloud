//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4
#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0

int currentTemp = 0;
int isRaining = 0;

pthread_mutex_t lock;

void *temperatureSensor(void *arg) {
    while(1) {
        pthread_mutex_lock(&lock);
        currentTemp = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
        pthread_mutex_unlock(&lock);
        sleep(3);
    }
}

void *rainSensor(void *arg) {
    while(1) {
        pthread_mutex_lock(&lock);
        if(currentTemp >= 50 && isRaining == 0) {
            isRaining = 1;
            printf("It is raining now!\n");
        } else if (currentTemp < 50 && isRaining == 1){
            isRaining = 0;
            printf("The rain has stopped!\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void *displayWeather(void *arg) {
    while(1) {
        pthread_mutex_lock(&lock);
        printf("The current temperature is %d degrees Fahrenheit.\n", currentTemp);
        if(isRaining == 1) {
            printf("It is currently raining.\n");
        } else {
            printf("It is not currently raining.\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(2);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    pthread_create(&threads[0], NULL, temperatureSensor, NULL);
    pthread_create(&threads[1], NULL, rainSensor, NULL);
    pthread_create(&threads[2], NULL, displayWeather, NULL);

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}