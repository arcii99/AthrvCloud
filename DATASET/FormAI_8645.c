//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE 1000000

double calculate_mean(int* array, int size) {
    int i;
    double sum = 0.0;
    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

double calculate_variance(int* array, int size, double mean) {
    int i;
    double variance = 0.0;
    for (i = 0; i < size; i++) {
        variance += (array[i] - mean) * (array[i] - mean);
    }
    return variance / size;
}

int main() {
    int array[ARRAY_SIZE], i;
    double mean, variance;
    while (1) {
        for (i = 0; i < ARRAY_SIZE; i++) {
            array[i] = rand();
        }
        mean = calculate_mean(array, ARRAY_SIZE);
        variance = calculate_variance(array, ARRAY_SIZE, mean);
        printf("CPU usage: %f%%\n", variance / mean * 100);
        sleep(1);
    }
    return 0;
}