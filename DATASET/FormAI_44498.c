//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 1000000

int main() {

    clock_t start, end;
    double cpu_time_used;

    int array[ARRAY_SIZE];

    printf("Generating random numbers...\n");

    // Generating random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000 + 1;
    }

    // Sorting the array using bubble sort
    printf("Sorting the array...\n");
    start = clock();
    for (int i = 0; i < ARRAY_SIZE-1; i++) {
        for (int j = 0; j < ARRAY_SIZE-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array is: %f seconds\n", cpu_time_used);

    // Searching for a particular number
    int search_num = 500;
    int index = -1;
    printf("Searching for number %d...\n", search_num);
    start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] == search_num) {
            index = i;
            break;
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index != -1) {
        printf("Number %d found at index %d.\n", search_num, index);
    } else {
        printf("Number %d not found.\n", search_num);
    }

    printf("Time taken to search the number is: %f seconds\n", cpu_time_used);

    return 0;
}