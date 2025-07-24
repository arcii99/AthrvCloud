//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>

int main() {
    int array[10];
    printf("Enter array elements:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    printf("Before sorting: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Implementing bubble sort algorithm
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("After sorting: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}