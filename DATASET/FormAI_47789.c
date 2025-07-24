//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

// Function to allocate memory dynamically
int* allocateMemory(int size){
    int* ptr = (int*)malloc(size*sizeof(int));
    if(ptr == NULL){
        printf("ERROR: Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

// Function to deallocate the memory
void freeMemory(int* ptr){
    free(ptr);
    printf("Memory deallocated successfully!\n");
}

// Function to initialize the array
void initialize(int* ptr){
    for(int i=0; i<SIZE; i++){
        *(ptr+i) = i+1;
    }
}

// Function to display the elements of the array
void display(int* ptr){
    printf("Contents of the array:\n");
    for(int i=0; i<SIZE; i++){
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}

int main(){
    int* arr = allocateMemory(SIZE); // allocating memory for the array
    
    initialize(arr); // initializing the array
    display(arr); // displaying the contents of the array

    freeMemory(arr); // deallocating the memory
    
    return 0;
}