//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Interoperable C Searching Algorithm Example Program

// Function to search for an element in an array
bool search(int array[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

int main() {
    int size, element;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int *array = (int*) malloc(sizeof(int) * size);
    printf("Enter the elements of the array:\n");
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &element);
    
    if (search(array, size, element)) {
        printf("%d is present in the array\n", element);
    } else {
        printf("%d is not present in the array\n", element);
    }
    
    free(array);
    return 0;
}