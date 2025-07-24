//FormAI DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>

#define LENGTH 10

int main(void) {

    int arr[LENGTH] = {9, 4, 2, 1, 8, 7, 5, 6, 3, 0};
    int i, j, temp;

    printf("Before sorting: ");

    for (i = 0; i < LENGTH; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nSorting the array using Bubble Sort:\n");

    for (i = 0; i < LENGTH - 1; i++) {
    
        for (j = 0; j < LENGTH - 1 - i; j++) {
        
            if (arr[j] > arr[j + 1]) {
            
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                printf("Swapping %d and %d\n", arr[j], arr[j + 1]);
            }
        }
    }

    printf("\nAfter sorting: ");

    for (i = 0; i < LENGTH; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}