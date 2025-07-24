//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a, *b, *c;
    
    // allocate memory for a, b, and c
    a = (int*) malloc(sizeof(int));
    b = (int*) malloc(sizeof(int));
    c = (int*) malloc(sizeof(int));
    
    // check if memory allocation was successful
    if (a == NULL || b == NULL || c == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // set values for a, b, and c
    *a = 1;
    *b = 2;
    *c = 3;
    
    // print the values of a, b, and c
    printf("a = %d\n", *a);
    printf("b = %d\n", *b);
    printf("c = %d\n", *c);
    
    // free memory allocated for a, b, and c
    free(a);
    free(b);
    free(c);
    
    return 0;
}