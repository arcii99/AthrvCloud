//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arrSize;
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    //Allocate memory of arrSize elements
    int *arr = (int*) malloc(arrSize * sizeof(int));

    if(arr == NULL){ //check if the memory is allocated or not
        printf("Memory allocation failed. Exiting...\n");
        exit(0);
    }

    //initialize the elements of the array
    for(int i=0; i<arrSize; i++){
        printf("Enter element %d of the array: ", i+1);
        scanf("%d", &arr[i]);
    }

    //print the entered array
    printf("Entered elements of the array: ");
    for(int i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }

    //free the allocated memory
    free(arr);

    return 0;
}