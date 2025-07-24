//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int main() {

    int *ptr;  // declaring a pointer variable
    
    // allocating memory dynamically using malloc()
    ptr = (int*) malloc(3 * sizeof(int));
    
    if(ptr == NULL) {  // checking if memory could be allocated or not
        printf("Memory not available\n");
        exit(1);
    }
    
    // initializing the elements of the array
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    
    // displaying the elements of the array
    printf("Elements of the array: ");
    printf("%d ", ptr[0]);
    printf("%d ", ptr[1]);
    printf("%d ", ptr[2]);
    
    // deallocating the memory using free()
    free(ptr);
    
    return 0;
}