//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int* p = (int*) malloc(sizeof(int)); // allocate space for an integer
    if (p == NULL) // check if allocation was successful
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    *p = 10; // set value of allocated integer
    printf("Value of p: %d\n", *p);

    int* q = (int*) calloc(3, sizeof(int)); // allocate space for an array of 3 integers
    if (q == NULL) // check if allocation was successful
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    q[0] = 1; // set values of allocated array
    q[1] = 2;
    q[2] = 3;
    printf("Values of q: %d %d %d\n", q[0], q[1], q[2]);

    int* r = (int*) realloc(q, 5 * sizeof(int)); // reallocate space for array of 5 integers
    if (r == NULL) // check if reallocation was successful
    {
        printf("Memory reallocation failed!\n");
        free(q); // free previously allocated space
        return 1;
    }
    r[3] = 4; // set values of extended array
    r[4] = 5;
    printf("Values of r: %d %d %d %d %d\n", r[0], r[1], r[2], r[3], r[4]);

    free(p); // free allocated space for integer
    free(r); // free allocated space for array
    return 0;
}