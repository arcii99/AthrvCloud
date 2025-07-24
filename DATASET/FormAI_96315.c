//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));  //Allocate a chunk of memory

    if (arr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    printf("Memory allocated successfully!\n");

    for(int i=0; i<size; i++) {
        arr[i] = i+1;
    }

    printf("Array elements are: \n");

    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);  //Free the allocated memory
    printf("\nMemory freed successfully!\n");

    return 0;
}