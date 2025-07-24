//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *) malloc(5 * sizeof(int)); // allocating memory for array
    if (arr == NULL) { // checking if allocation was successful
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Memory allocated successfully!\n");
    
    // incrementing the values of the first 5 indices of the array
    for (int i=0; i<5; i++) {
        arr[i] = i + 1;
    }
    
    printf("Array values before reallocation:\n");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // reallocation of memory for array to double its size
    int *temp = (int *) realloc(arr, 10 * sizeof(int));
    if (temp == NULL) { // checking if reallocation was successful
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    
    arr = temp;
    for (int i=5; i<10; i++) {
        arr[i] = i + 1;
    }
    
    printf("Array values after reallocation:\n");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr); // freeing up the memory allocated for array
    
    printf("Memory freed successfully!\n");
    
    return 0;
}