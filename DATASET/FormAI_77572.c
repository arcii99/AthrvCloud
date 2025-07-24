//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int array[], int size) {
    int bucket[BUCKET_SIZE] = {0};
    for (int i = 0; i < size; i++) {
        bucket[array[i]]++;
    }
    for (int i = 0, j = 0; j < BUCKET_SIZE; j++) {
        while (bucket[j]-- > 0) {
            array[i++] = j;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    bucket_sort(array, size);
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}