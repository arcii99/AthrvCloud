//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a = malloc(sizeof(int)); // allocate memory for a pointer variable 'a'
    if (a == NULL){
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    *a = 42; // set the value of a pointer variable to 42

    printf("Value of a: %d\n", *a);
    printf("Address of a: %p\n\n", a);

    int *b = malloc(sizeof(int) * 5); // allocate memory for an array of 5 integers
    if (b == NULL){
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        *(b + i) = i; // set the values of the array elements
        printf("Value of b[%d]: %d\n", i, *(b + i));
        printf("Address of b[%d]: %p\n\n", i, (b + i));
    }

    // reallocate memory for the array with new size
    int *c = realloc(b, sizeof(int) * 10);
    if (c == NULL){
        printf("Error: Memory reallocation failed!\n");
        free(b); // free the previously allocated memory
        exit(1);
    }

    for(int i = 5; i < 10; i++){
        *(c + i) = i; // set the values of the reallocated array elements
        printf("Value of c[%d]: %d\n", i, *(c + i));
        printf("Address of c[%d]: %p\n\n", i, (c + i));
    }

    free(a); // free allocated memory for 'a'
    free(c); // free reallocated memory for 'b'

    return 0;
}