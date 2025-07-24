//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_THREADS 4
#define RED 0
#define YELLOW 1
#define GREEN 2

pthread_mutex_t mutex;
pthread_cond_t cond;
int current_color = RED;

void* traffic_controller(void* arg) {
    int thread_id = *(int*)arg;
    while (true) {
        pthread_mutex_lock(&mutex);
        while (thread_id != current_color) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Traffic light %d is on\n", thread_id);

        // simulate the time the traffic light is on
        usleep(500000);

        if (current_color == RED) {
            current_color = GREEN;
        } else if (current_color == GREEN) {
            current_color = YELLOW;
        } else if (current_color == YELLOW) {
            current_color = RED;
        }

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    int ids[NUM_THREADS] = {RED, YELLOW, GREEN, RED};

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i=0; i<NUM_THREADS; i++) {
        int* id = &ids[i];
        pthread_create(&threads[i], &attr, traffic_controller, (void*)id);
    }

    for (int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    pthread_exit(NULL);

    return 0;
}