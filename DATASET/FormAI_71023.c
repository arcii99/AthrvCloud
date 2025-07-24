//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>

void swap(int *a, int *b) { // function to swap two elements
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n) { // selection sort function
    int i, j, min_index;

    for (i = 0; i < n-1; i++) {
        min_index = i;

        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(&arr[i], &arr[min_index]);
    }
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n);

    printf("The sorted array is:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}