//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Declaration of a function that will perform the bubble sort on the array
void bubble_sort(int *arr, int n);

int main(void) {
    int n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array based on the number of elements entered by the user
    int *arr = (int*) malloc(n * sizeof(int));

    printf("Enter %d integers: ", n);

    // Read the integers entered by the user into the array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the bubble sort function to sort the array
    bubble_sort(arr, n);

    // Display the sorted array
    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the dynamically allocated memory
    free(arr);
    return 0;
}

void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}