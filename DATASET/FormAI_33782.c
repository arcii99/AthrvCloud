//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);
        
        int pi = i + 1;
        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));
    int arr[10];
    
    printf("Unsorted Array:\n");
    
    // Generate 10 random integers between 0 and 100
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101;
        printf("%d ", arr[i]);
    }
    
    quicksort(arr, 0, 9);
    
    printf("\n\nSorted Array:\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}