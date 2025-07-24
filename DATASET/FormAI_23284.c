//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;

float computeMortgage(float P, float R, float N) {
    float r = (R/100)/12;
    float E = P * r * (pow((1+r), N)) / (pow((1+r), N) - 1);
    return E;
}

void *calculateMortgage(void *arg) {
    pthread_mutex_lock(&lock);

    float principal, rate, years;

    printf("Enter mortgage principal amount: ");
    scanf("%f", &principal);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter number of years: ");
    scanf("%f", &years);

    printf("\n");

    printf("Your monthly mortgage payment is $%.2f\n", computeMortgage(principal, rate, years));

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int i, numThreads = 5;

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, calculateMortgage, NULL);
    }

    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}