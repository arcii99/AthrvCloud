//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
/*
Welcome to the world of bucket sort!

In this program, we will create a unique implementation of bucket sort using the magic of dragons and unicorns. 
Each element in the array will be assigned to a dragon or unicorn based on its value. The dragon/unicorn will then 
sort all the elements assigned to them and put them back in the array. Let's see how it works!
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

typedef struct {
    int num_elements;
    int *elements;
} Bucket;

void sort_ascending(int *arr, int size) {
    // Sorting algorithm of the dragons
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort_descending(int *arr, int size) {
    // Sorting algorithm of the unicorns
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bucket_sort(int *arr, int size) {
    // Assigning elements to the dragons and unicorns
    int i;
    Bucket dragons, unicorns;

    dragons.num_elements = 0;
    unicorns.num_elements = 0;
    dragons.elements = (int *) malloc(sizeof(int) * size);
    unicorns.elements = (int *) malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            dragons.elements[dragons.num_elements++] = arr[i];
        } else {
            unicorns.elements[unicorns.num_elements++] = arr[i];
        }
    }

    // Sorting the elements with the help of dragons and unicorns
    sort_ascending(dragons.elements, dragons.num_elements);
    sort_descending(unicorns.elements, unicorns.num_elements);

    // Combining the sorted elements
    int counter = 0;
    for (i = 0; i < dragons.num_elements; i++) {
        arr[counter++] = dragons.elements[i];
    }

    for (i = 0; i < unicorns.num_elements; i++) {
        arr[counter++] = unicorns.elements[i];
    }

    // Freeing memory once the job is done
    free(dragons.elements);
    dragons.elements = NULL;
    free(unicorns.elements);
    unicorns.elements = NULL;
}

int main() {
    // Creating an array and filling it with random integers
    int arr[ARRAY_SIZE], i;

    printf("Welcome to the magical world of bucket sort!\n\n");

    printf("Unsorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    // Sorting the array
    bucket_sort(arr, ARRAY_SIZE);

    printf("\n\nSorted array using bucket sort:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nThank you for visiting the realm of dragons and unicorns!");
    return 0;
}