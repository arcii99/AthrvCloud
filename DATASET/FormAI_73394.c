//FormAI DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array = malloc(sizeof(int) * 10); // allocate memory for an array of 10 integers
    if(array == NULL){
        fprintf(stderr, "Error: unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter 10 integers:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &array[i]); // read in integers from the user
    }

    printf("\nHere are the integers in reverse order:\n");
    for(int i = 9; i >= 0; i--){
        printf("%d ", array[i]); // print the integers in reverse order
    }

    free(array); // release the memory allocated for the array

    return 0;
}