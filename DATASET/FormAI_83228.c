//FormAI DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 /* size of the array to be sorted */

/* function to swap two elements */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* function to perform bubble sort */
void bubble_sort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* function to perform selection sort */
void selection_sort(int arr[], int n) {
    int i, j, min;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

/* function to perform insertion sort */
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[SIZE], temp[SIZE], i, choice;

    /* filling the array with random values */
    srand(time(NULL));
    for(i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    /* displaying the menu */
    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    scanf("%d", &choice);

    /* making a copy of the array for sorting */
    for(i = 0; i < SIZE; i++) {
        temp[i] = arr[i];
    }

    /* performing the chosen sorting algorithm and measuring the time taken */
    clock_t start = clock();
    switch(choice) {
        case 1: bubble_sort(temp, SIZE); break;
        case 2: selection_sort(temp, SIZE); break;
        case 3: insertion_sort(temp, SIZE); break;
        default: printf("Invalid choice\n"); break;
    }
    clock_t end = clock();

    /* displaying the sorted array and the time taken */
    printf("Sorted array:\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}