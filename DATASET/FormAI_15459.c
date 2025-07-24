//FormAI DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

unsigned long long get_time_in_nanos(struct timespec start_time,
                                     struct timespec end_time)
{
    return (end_time.tv_sec - start_time.tv_sec) * 1000000000 +
           (end_time.tv_nsec - start_time.tv_nsec);
}

void fill_array_rand(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
}

void bubble_sort(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];
    struct timespec start_time, end_time;

    srand(time(0));
    fill_array_rand(array1, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i];
    }

    printf("Sorting %d integers using Bubble Sort Algorithm:\n", ARRAY_SIZE);

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    bubble_sort(array1, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    printf("Bubble Sort Took %llu nanoseconds\n",
           get_time_in_nanos(start_time, end_time));

    return 0;
}