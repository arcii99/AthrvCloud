//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {

    int* array;                  // pointer to integer
    int size, i;                 // integer variables
    printf("What is the size of the array?\n");
    scanf("%d", &size);          // get size of array from user
    
    array = (int*) malloc(size * sizeof(int)); // allocate memory for array
    
    if(array == NULL) {          // check if memory allocation was successful
        printf("Error. Memory Allocation unsuccessful.");
        exit(0);
    }

    printf("Enter the elements of the array: \n");
    for(i = 0; i < size; i++) {  // for loop to store elements in array
        scanf("%d", &array[i]);
    }

    printf("The array elements are: ");
    for(i = 0; i < size; i++) {  // for loop to print elements in array
        printf("%d ", array[i]);
    }

    free(array);                 // free the memory allocated for the array

    return 0;                    // end program
}