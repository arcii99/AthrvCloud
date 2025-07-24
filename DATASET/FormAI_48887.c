//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

void Bucket_Sort(int array[], int size) {
    int i, j;
    int count[size];
    for (i = 0; i < size; i++) {
        count[i] = 0;
    }
    for (i = 0; i < size; i++) {
        (count[array[i]])++;
    }
    for (i = 0, j = 0; i < size; i++) {
        for (; count[i] > 0; (count[i])--) {
            array[j++] = i;
        }
    }
}

int main() {
    int i, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    for (i = 0; i < size; ++i) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("\nUnsorted array is: ");
    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    Bucket_Sort(array, size);
    printf("\nSorted array is: ");
    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}