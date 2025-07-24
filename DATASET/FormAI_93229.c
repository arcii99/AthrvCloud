//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables to share between threads
double distance = 0;
double weight = 0;

// function to convert distance from kilometers to miles
void *convert_distance(void *arg) {
    while(1) {
        double input;
        printf("Enter distance in kilometers: ");
        scanf("%lf", &input);
        distance = input * 0.621371;
        printf("%lf kilometers is equal to %lf miles\n", input, distance);
    }
    pthread_exit(NULL);
}

// function to convert weight from kilograms to pounds
void *convert_weight(void *arg) {
    while(1) {
        double input;
        printf("Enter weight in kilograms: ");
        scanf("%lf", &input);
        weight = input * 2.20462;
        printf("%lf kilograms is equal to %lf pounds\n", input, weight);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;

    // create threads for distance and weight conversion
    pthread_create(&tid1, NULL, convert_distance, NULL);
    pthread_create(&tid2, NULL, convert_weight, NULL);

    // wait for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}