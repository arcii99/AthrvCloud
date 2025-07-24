//FormAI DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ARRAY_SIZE 100000

double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

void bubble_sort(int* arr, size_t n) {
    int tmp;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void fill_random_array(int* arr, size_t n) {
    srand(time(NULL));
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    fill_random_array(arr, ARRAY_SIZE);
    double start_time = get_wall_time();
    bubble_sort(arr, ARRAY_SIZE);
    double end_time = get_wall_time();
    printf("Time taken to sort array: %f seconds\n", end_time - start_time);
    return EXIT_SUCCESS;
}