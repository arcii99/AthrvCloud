//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>

// Here, we define our function bubble_sort
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size = 7;
    int arr[7] = {12, 43, 6, 89, 65, 23, 9};
    int i;
    
    // Printing the unsorted array
    printf("Unsorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    // Calling the bubble_sort function
    bubble_sort(arr, size);
    
    // Printing the sorted array
    printf("\nSorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}