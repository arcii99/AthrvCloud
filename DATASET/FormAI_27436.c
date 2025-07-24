//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(int *arr, int size) {
    int i, j, temp;

    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int size, i;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arr = (int*) malloc(size * sizeof(int));
    srand(time(NULL));

    printf("Array before sorting:\n");

    for(i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, size);

    printf("Array after sorting:\n");

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}