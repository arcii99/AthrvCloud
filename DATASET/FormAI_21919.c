//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

// Function to iterate through the array and swap elements
void bubbleSort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {        
        // Last i elements are already in place   
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted array in ascending order: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}