//FormAI DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>

int main() {
    int arr[10] = {9, 4, 7, 2, 8, 1, 3, 5, 10, 6};
    int n = 10, i, j, temp;
    
    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}