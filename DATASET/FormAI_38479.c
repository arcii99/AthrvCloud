//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() { 
    int num, *arr, i, j, temp;

    printf("Enter the number of elements in array: ");
    scanf("%d", &num);

    arr = (int*)malloc(num * sizeof(int));

    if(arr == NULL) {
        printf("Memory allocation failed...Exiting.\n");
        exit(0);
    }

    printf("Enter %d elements: ", num);

    for(i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort algorithm (a performance-critical component)
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}