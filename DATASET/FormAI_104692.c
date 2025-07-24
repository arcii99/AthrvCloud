//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare integer variables and allocate memory using calloc()
    int *a, *b;
    a = (int*) calloc(1, sizeof(int));
    b = (int*) calloc(1, sizeof(int));
    
    // Check if memory allocation successful
    if(a == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    // Set values of variables
    *a = 5;
    *b = 3;
    
    // Print values of variables
    printf("a = %d\nb = %d\n", *a, *b);
    
    // Free allocated memory
    free(a);
    free(b);
    
    return 0;
}