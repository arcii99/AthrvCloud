//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int *create_array(int n){
    /* 
        Allocates memory to store an array of n integers and returns a pointer to the allocated memory.
    */
    int *arr = (int *) malloc(n * sizeof(int));
    return arr;
}

void populate_array(int *arr, int n){
    /*
        Fills up the array with integers from 1 to n.
    */
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }
}

void print_array(int *arr, int n){
    /*
        Prints the elements of the array.
    */
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 10;
    int *arr = create_array(n);
    populate_array(arr, n);
    print_array(arr, n);

    /*
        Free the memory allocated to the array.
    */
    free(arr);
    return 0;
}