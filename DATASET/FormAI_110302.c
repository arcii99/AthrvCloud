//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include<stdio.h>
#include<stdlib.h>

// Memory Management Example Program
// Boldly creating an array of 100 integers dynamically
// And deallocating it after use to prevent memory leaks

int main(){
    int *arr;
    int i;

    // allocate memory for 100 integers
    arr = (int*)malloc(100 * sizeof(int));

    // if memory allocation fails, exit the program
    if(arr == NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }

    // initialize array with even numbers
    for(i=0; i<100; i++){
        arr[i] = i*2;
    }

    // print array elements
    printf("Array elements: ");
    for(i=0; i<100; i++){
        printf("%d ", arr[i]);
    }

    // deallocate memory for array
    free(arr);

    printf("\nMemory deallocated successfully\n");

    return 0;
}