//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

void fill_array(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
}

long long get_time_difference(struct timespec start_time, struct timespec end_time) {
    return ((long long) (end_time.tv_sec - start_time.tv_sec) * 1000000
            + (end_time.tv_nsec - start_time.tv_nsec) / 1000);
}

void benchmark_linear_search(int array[], int number_to_find) {
    struct timespec start_time, end_time;
    int found = 0;

    clock_gettime(CLOCK_REALTIME, &start_time);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] == number_to_find) {
            found = 1;
            break;
        }
    }

    clock_gettime(CLOCK_REALTIME, &end_time);

    long long duration = get_time_difference(start_time, end_time);

    if (found) {
        printf("Linear search found %d in %lld microseconds\n", number_to_find, duration);
    } else {
        printf("Linear search did not find %d in %lld microseconds\n", number_to_find, duration);
    }
}

void benchmark_binary_search(int array[], int number_to_find) {
    struct timespec start_time, end_time;
    int found = 0;
    int left = 0;
    int right = ARRAY_SIZE - 1;

    clock_gettime(CLOCK_REALTIME, &start_time);

    while (left <= right) {
        int middle = (left + right) / 2;

        if (array[middle] == number_to_find) {
            found = 1;
            break;
        } else if (array[middle] > number_to_find) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    clock_gettime(CLOCK_REALTIME, &end_time);

    long long duration = get_time_difference(start_time, end_time);

    if (found) {
        printf("Binary search found %d in %lld microseconds\n", number_to_find, duration);
    } else {
        printf("Binary search did not find %d in %lld microseconds\n", number_to_find, duration);
    }
}

int main() {
    int array[ARRAY_SIZE];
    int number_to_find = rand() % 100;

    fill_array(array);

    benchmark_linear_search(array, number_to_find);

    benchmark_binary_search(array, number_to_find);

    return 0;
}