//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 3
#define TEMP_THRESHOLD 100.0

double temperature = 0.0;
pthread_mutex_t temp_mutex;
pthread_cond_t temp_threshold_cv;

void* monitor_temperature(void*);
void* adjust_temperature(void*);

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&temp_mutex, NULL);
    pthread_cond_init(&temp_threshold_cv, NULL);

    pthread_create(&threads[0], NULL, monitor_temperature, NULL);
    pthread_create(&threads[1], NULL, adjust_temperature, NULL);
    pthread_create(&threads[2], NULL, adjust_temperature, NULL);

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&temp_mutex);
    pthread_cond_destroy(&temp_threshold_cv);

    return 0;
}

void* monitor_temperature(void* arg) {
    while(1) {
        pthread_mutex_lock(&temp_mutex);
        printf("Temperature: %f\n", temperature);

        if(temperature >= TEMP_THRESHOLD) {
            printf("Temperature threshold reached!\n");
            pthread_cond_broadcast(&temp_threshold_cv);
        }

        pthread_mutex_unlock(&temp_mutex);
        sleep(1);
    }
}

void* adjust_temperature(void* arg) {
    while(1) {
        double rand_num = (double)rand() / RAND_MAX;
        double adjustment = (rand_num * 20.0) - 10.0;

        pthread_mutex_lock(&temp_mutex);
        temperature += adjustment;

        if(temperature < 0.0) {
            temperature = 0.0;
        }

        pthread_cond_wait(&temp_threshold_cv, &temp_mutex);
        printf("Temperature being adjusted...\n");
        temperature -= 10.0;

        pthread_mutex_unlock(&temp_mutex);
    }
}