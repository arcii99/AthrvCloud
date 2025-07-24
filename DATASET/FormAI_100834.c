//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program generates random numbers and sorts them in ascending order using insertion sort algorithm

void insertionSort(int arr[], int n) { 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main() {
    int n;
    printf("Enter the number of random elements to generate: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    srand(time(NULL));
    printf("Generated random elements:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}