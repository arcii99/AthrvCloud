//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bucket_sort(int array[], int size, int max_val) {
    int *bucket = calloc(max_val + 1, sizeof(int));
    if (bucket == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        bucket[array[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            array[index++] = i;
        }
    }

    free(bucket);
}

int main() {
    int array[ARRAY_SIZE];
    int max_val = 0;

    // Populate array with random integers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 51; // Random value between 0 and 50
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }

    printf("Before sorting: ");
    print_array(array, ARRAY_SIZE);

    bucket_sort(array, ARRAY_SIZE, max_val);

    printf("After sorting: ");
    print_array(array, ARRAY_SIZE);

    return 0;
}