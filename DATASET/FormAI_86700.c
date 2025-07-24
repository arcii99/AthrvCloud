//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int car_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* simulate_traffic(void* arg) {
    long id = (long)arg;
    int cars = rand() % 10 + 1;

    printf("Lane %ld is now open. Expecting %d cars.\n", id, cars);
    sleep(1);

    for (int i=0; i<cars; i++) {
        pthread_mutex_lock(&mutex);
        car_count++;
        pthread_mutex_unlock(&mutex);
        printf("Car %d has crossed lane %ld.\n", car_count, id);
        sleep(2);
    }

    printf("Lane %ld has closed.\n", id);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t thread_ids[5];

    for (long i=0; i<5; i++) {
        pthread_create(&thread_ids[i], NULL, simulate_traffic, (void*)i);
    }

    for (int i=0; i<5; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    printf("All lanes have closed. Total cars crossed: %d.\n", car_count);

    return 0;
}