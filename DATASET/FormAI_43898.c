//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct Stats {
    int count;
    double sum;
    double avg;
    double min;
    double max;
};

struct Stats calculate_statistics(double *data, int size) {
    struct Stats stats = {0, 0, 0, 0, 0};
    double min = data[0];
    double max = data[0];
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += data[i];
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }

    stats.count = size;
    stats.sum = sum;
    stats.min = min;
    stats.max = max;
    stats.avg = sum / size;

    return stats;
}

int main() {
    double data[] = {12.5, 6.7, 8.9, 10.2, 11.4, 9.8};
    int size = sizeof(data) / sizeof(data[0]);

    struct Stats stats = calculate_statistics(data, size);

    printf("Count: %d\n", stats.count);
    printf("Sum: %.2f\n", stats.sum);
    printf("Minimum: %.2f\n", stats.min);
    printf("Maximum: %.2f\n", stats.max);
    printf("Average: %.2f\n", stats.avg);

    return 0;
}