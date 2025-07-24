//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h> 
#include <stdlib.h>

#define xyz(a) malloc(a)
#define pqr(a, b) realloc(a, b)
#define abc(a) free(a)

int main() {
    int* ptr;
    int n = 5;

    ptr = xyz(n * sizeof(int)); // allocating memory

    for(int i=0; i<n; i++){
        *(ptr + i) = i + 1; // filling data in allocated memory
    }

    printf("Before resizing:\n");

    for(int i=0; i<n; i++){
        printf("%d ", *(ptr + i)); // printing original data
    }

    ptr = pqr(ptr, 10 * sizeof(int)); // resizing memory

    for(int i=n; i<10; i++){
        *(ptr + i) = i + 1; // filling remaining data in resized memory
    }

    printf("\nAfter resizing:\n");

    for(int i=0; i<10; i++){
        printf("%d ", *(ptr + i)); // printing resized data
    }

    abc(ptr); // deallocating memory

    return 0;
}