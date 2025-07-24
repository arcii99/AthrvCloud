//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr = NULL;
    int size;
    
    printf("Enter array size: ");
    scanf("%d", &size);
    
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Error: unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    
    // initialize array with random values
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // values between 0 and 99
    }
    
    // print statistics
    int sum = 0;
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("Array statistics:\n");
    printf("Size: %d\n", size);
    printf("Sum: %d\n", sum);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    
    free(arr); // release memory
    
    return 0;
}