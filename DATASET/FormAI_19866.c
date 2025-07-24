//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

//Function to check if allocation was successful or not
void check_allocation(void* ptr){
    if(ptr == NULL){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

//Function to initialize the array with values
void initialize_array(int* arr, int size){
    for(int i=0; i<size; i++){
        arr[i] = i+1;
    }
}

//Function to print array
void print_array(int* arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int* ptr = NULL;
    int size = 10;
    
    //Allocate memory dynamically
    ptr = (int*) malloc(size * sizeof(int));
    check_allocation(ptr);
    
    //Initialize array
    initialize_array(ptr, size);
    
    //Print array
    printf("Initial array: ");
    print_array(ptr, size);
    
    //Reallocate memory dynamically to increase the size of array
    size = 15;
    ptr = (int*) realloc(ptr, size * sizeof(int));
    check_allocation(ptr);
    
    //Initialize new elements of array
    for(int i=10; i<size; i++){
        ptr[i] = i+1;
    }
    
    //Print array
    printf("Final array: ");
    print_array(ptr, size);
    
    //Free dynamically allocated memory
    free(ptr);
    
    return 0;
}