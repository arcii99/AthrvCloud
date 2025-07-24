//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000 //declaring a constant for array size

int main(){

    int *arr; //declaring pointer for dynamic array
    int num = 0; //declaring variable to read input from user

    //allocating memory for dynamic array
    arr = (int*) malloc(SIZE * sizeof(int));

    //checking if memory allocation was successful
    if(arr == NULL){
        printf("Failed to allocate memory");
        exit(1);
    }

    //populating dynamic array with random numbers
    for(int i=0; i<SIZE; i++){
        arr[i] = rand() % 100;
    }

    //performing mathematical operation on dynamic array
    for(int i=0; i<SIZE; i++){
        num += arr[i];
    }

    //outputting result of mathematical operation
    printf("Sum of all elements in dynamic array: %d", num);

    //freeing memory allocated to dynamic array
    free(arr);

    return 0;
}