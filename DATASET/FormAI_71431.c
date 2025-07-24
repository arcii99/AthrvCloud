//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to Happy Memory Management!\n");
    printf("I am your guide for today, Mr. Smiley!\n\n");

    int *ptr1, *ptr2, *ptr3, *ptr4;

    ptr1 = (int*) malloc(sizeof(int)); // allocate memory for integer 1
    ptr2 = (int*) malloc(sizeof(int)); // allocate memory for integer 2
    ptr3 = (int*) malloc(sizeof(int)); // allocate memory for integer 3
    ptr4 = (int*) malloc(sizeof(int)); // allocate memory for integer 4

    printf("Four integers have been allocated. Let's fill them with some values!\n");

    *ptr1 = 10;
    *ptr2 = 20;
    *ptr3 = 30;
    *ptr4 = 40;

    printf("The values of the integers are: %d, %d, %d, %d\n", *ptr1, *ptr2, *ptr3, *ptr4);

    printf("\nOops, I made a mistake! Let's free memory for integer 3\n");
    free(ptr3);
    printf("Memory has been freed for integer 3\n");

    printf("\nNow, let's allocate memory for integer 5 and fill it with value 50\n");
    int *ptr5 = (int*) malloc(sizeof(int));
    *ptr5 = 50;
    printf("The value of integer 5 is %d\n", *ptr5);

    printf("\nGreat job! Now, let's clean up all the allocated memory\n");
    free(ptr1);
    free(ptr2);
    free(ptr4);
    free(ptr5);

    printf("Memory has been cleaned up. Goodbye!\n\n");
    return 0;
}