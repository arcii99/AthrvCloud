//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Let's sort some numbers!\n");
    printf("Enter the size of the array to sort: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the %d numbers to sort:\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble sort
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\n\nSorted array (in ascending order):\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}