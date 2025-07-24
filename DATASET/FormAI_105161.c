//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Finds the lowest element in the array and returns its index
int findLowest(int arr[], int start, int size) {
    int lowest = arr[start];
    int lowestIndex = start;

    for (int i = start; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

// Sorts an array of integers
void selectionSort(int arr[], int size) {
    int currentIndex = 0;

    // Loop through the array
    while (currentIndex < size) {

        // Find the lowest element from the currentIndex to the end of the array
        int lowestIndex = findLowest(arr, currentIndex, size);

        // Swap the lowest element with the element at the currentIndex
        swap(&arr[currentIndex], &arr[lowestIndex]);

        // Increment the currentIndex to continue with the next element
        currentIndex++;
    }
}

int main() {
    int arr[] = {30, 12, 56, 76, 3, 42, 89, 15, 49, 97};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Call the selectionSort function to sort the array
    selectionSort(arr, size);

    printf("\n\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}