//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>

/*
 * This program is a simple example of using pointers in C.
 * It takes an integer as input and then uses a pointer to manipulate the value. 
 */

int main() {
    int number;
    int *ptr;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Assign the address of 'number' to the pointer
    ptr = &number;

    // Print the value of 'number' and its address using the pointer
    printf("\nValue of 'number': %d", *ptr);
    printf("\nAddress of 'number': %d\n", ptr);

    // Add 5 to the value of 'number' using the pointer
    *ptr += 5;

    printf("\nAfter adding 5 to the value of 'number': %d", *ptr);

    return 0;
}