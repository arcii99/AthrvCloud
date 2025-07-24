//FormAI DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define NUM_VALUES 1000000

int values[NUM_VALUES];

void *calculate_min(void *arg) {
    int min = values[0];
    for (int i = 1; i < NUM_VALUES; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    printf("Minimum Value: %d\n", min);
    pthread_exit(NULL);
}

void *calculate_max(void *arg) {
    int max = values[0];
    for (int i = 1; i < NUM_VALUES; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    printf("Maximum Value: %d\n", max);
    pthread_exit(NULL);
}

void *calculate_average(void *arg) {
    double sum = 0;
    double average = 0;
    for (int i = 0; i < NUM_VALUES; i++) {
        sum += values[i];
    }
    average = sum / NUM_VALUES;
    printf("Average Value: %.2lf\n", average);
    pthread_exit(NULL);
}

void *calculate_std_deviation(void *arg) {
    double sum = 0;
    double average = 0;
    for (int i = 0; i < NUM_VALUES; i++) {
        sum += values[i];
    }
    average = sum / NUM_VALUES;
    double variance = 0;
    for (int i = 0; i < NUM_VALUES; i++) {
        variance += (values[i] - average) * (values[i] - average);
    }
    double std_deviation = sqrt(variance / NUM_VALUES);
    printf("Standard Deviation: %.2lf\n", std_deviation);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_VALUES; i++) {
        values[i] = rand() % 1000;
    }

    pthread_t threads[NUM_THREADS];
    int rc;

    rc = pthread_create(&threads[0], NULL, calculate_min, NULL);
    if (rc) {
        printf("Error: Return code from pthread_create() %d\n", rc);
        exit(-1);
    }

    rc = pthread_create(&threads[1], NULL, calculate_max, NULL);
    if (rc) {
        printf("Error: Return code from pthread_create() %d\n", rc);
        exit(-1);
    }

    rc = pthread_create(&threads[2], NULL, calculate_average, NULL);
    if (rc) {
        printf("Error: Return code from pthread_create() %d\n", rc);
        exit(-1);
    }

    rc = pthread_create(&threads[3], NULL, calculate_std_deviation, NULL);
    if (rc) {
        printf("Error: Return code from pthread_create() %d\n", rc);
        exit(-1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}