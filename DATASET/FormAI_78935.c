//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>

int main() {
    int arr[10] = {5, 4, 9, 2, 1, 0, 3, 8, 6, 7};
    int n = 10, i, j, temp;
    
    printf("Let's sort the array using an excited C program!\n");
    
    printf("The unsorted array is: ");
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
    
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    printf("Hurray! We did it!");
    
    return 0;
}