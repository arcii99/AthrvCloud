//FormAI DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

//Function to allocate memory for an array
int *allocateArray(int size){
    int *array = (int*)malloc(size*sizeof(int)); //Allocate memory for the array
    if(array == NULL){ //Check if allocation was successful
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }
    return array; //Return the allocated array
}

//Function to free memory allocated for an array
void freeArray(int *array){
    free(array); //Free the memory allocated for the array
}

int main() {
    int size = 10; //Size of the array
    int *myArray = allocateArray(size); //Allocate memory for the array
    int i;
    //Populate the array with numbers from 1 to 10
    for(i=0; i<size; i++){
        myArray[i] = i+1;
    }
    //Print out the numbers in the array
    printf("Numbers in the array:");
    for(i=0; i<size; i++){
        printf(" %d", myArray[i]);
    }
    printf("\n");
    freeArray(myArray); //Free the memory allocated for the array
    return 0;
}