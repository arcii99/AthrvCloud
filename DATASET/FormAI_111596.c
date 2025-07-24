//FormAI DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>

void sherlock_sort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        printf("Element %d has been sorted.\n", arr[i]);
    }
}

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nProcessing the data...\n\n");
    sherlock_sort(arr, size);
    printf("\nThe sorted array is:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nCase Closed!\n");
    return 0;
}