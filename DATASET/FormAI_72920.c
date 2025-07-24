//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE 0

typedef struct {
    int temp;
    pthread_mutex_t mutex;
} Weather;

Weather currentWeather;

void *increaseTemperature(void *threadId) {
    int id = *(int *)threadId;

    while (1) {
        pthread_mutex_lock(&currentWeather.mutex);
        if (currentWeather.temp >= MAX_TEMPERATURE) {
            pthread_mutex_unlock(&currentWeather.mutex);
            break;
        }
        printf("Thread %d increased temperature by 1\n", id);
        currentWeather.temp++;
        printf("Current temperature is %d\n", currentWeather.temp);
        pthread_mutex_unlock(&currentWeather.mutex);
    }

    pthread_exit(NULL);
}

void *decreaseTemperature(void *threadId) {
    int id = *(int *)threadId;

    while (1) {
        pthread_mutex_lock(&currentWeather.mutex);
        if (currentWeather.temp <= MIN_TEMPERATURE) {
            pthread_mutex_unlock(&currentWeather.mutex);
            break;
        }
        printf("Thread %d decreased temperature by 1\n", id);
        currentWeather.temp--;
        printf("Current temperature is %d\n", currentWeather.temp);
        pthread_mutex_unlock(&currentWeather.mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    currentWeather.temp = 20;
    pthread_mutex_init(&currentWeather.mutex, NULL);

    // Create threads to increase temperature
    for (int i = 0; i < NUM_THREADS / 2; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, increaseTemperature, &threadIds[i]);
    }

    // Create threads to decrease temperature
    for (int i = NUM_THREADS / 2; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, decreaseTemperature, &threadIds[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&currentWeather.mutex);

    return 0;
}