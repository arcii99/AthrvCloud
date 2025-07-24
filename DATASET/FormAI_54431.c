//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("I can't believe what I just saw. This code is a disaster!\n");
    printf("It's as if someone deliberately tried to make it look terrible!\n\n");

    //declaring arrays to show a shocking memory allocation example
    int* a, *b, *c;
    a = (int*)malloc(5 * sizeof(int));
    b = (int*)malloc(100 * sizeof(int));
    c = (int*)malloc(2 * sizeof(int));

    //filling arrays with values to showcase memory access
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    printf("Array a:");
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    b[99] = 100;
    printf("Accessed b[99]: %d\n", b[99]);

    c[-1] = 0;
    printf("Unexpected: Accessed c[-1]: %d\n", c[-1]);
 
    //freeing the allocated memory
    free(a);
    free(b);
    free(c);
    printf("\nMemory freed successfully!\n");

    printf("\nThis code has left me speechless. It's a wonder it even runs!\n");
    printf("I feel like I need to re-evaluate my life choices after seeing this.\n");

    return 0;
}