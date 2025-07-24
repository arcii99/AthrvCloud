//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void allocate_memory(int** ptr){
    *ptr = (int*) malloc(sizeof(int)); // allocate memory on heap
    if (*ptr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
}

void use_memory(int* ptr, int num){
    *ptr = num; // write to the memory location pointed to by ptr
}

void free_memory(int* ptr){
    free(ptr); // free the memory allocated by malloc
    ptr = NULL; // set the pointer to NULL to avoid dangling pointer
}

int main(){
    int* ptr = NULL;
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    
    allocate_memory(&ptr); // allocate memory
    use_memory(ptr, num); // use memory
    printf("The number you entered was: %d\n", *ptr);

    free_memory(ptr); // free memory

    return 0;
}