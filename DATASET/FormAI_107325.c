//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>
#include <stdbool.h>

// This program demonstrates the curious nature of C bitwise operations.

int main()
{
    int n1 = 123;  // Let's start with a random number
    int n2 = 456;  // Another random number

    // We're going to perform all sorts of curious bitwise operations on these numbers

    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", n2);
    printf("\n");

    // First, let's perform the curious NOT operation on n1
    int n3 = ~n1;
    printf("NOT n1 = %d\n", n3);
    printf("\n");

    // Next, let's perform the curious XOR operation on n1 and n2
    int n4 = n1 ^ n2;
    printf("n1 XOR n2 = %d\n", n4);
    printf("\n");

    // Now let's perform the curious AND operation on n1 and n2
    int n5 = n1 & n2;
    printf("n1 AND n2 = %d\n", n5);
    printf("\n");

    // Here we will shift n1 left by 2 bits, and see what happens
    int n6 = n1 << 2;
    printf("n1 shifted left by 2 bits = %d\n", n6);
    printf("\n");

    // Here we will shift n2 right by 3 bits, and see what happens
    int n7 = n2 >> 3;
    printf("n2 shifted right by 3 bits = %d\n", n7);
    printf("\n");

    // Let's see if n1 and n2 are equal using the curious NOT and XOR operations
    bool equal = !(n1 ^ n2);
    printf("Are n1 and n2 equal? %s\n", equal ? "true" : "false");
    printf("\n");

    // Finally, let's perform the curious bitwise OR operation on n1 and n2
    int n8 = n1 | n2;
    printf("n1 OR n2 = %d\n", n8);
    printf("\n");

    return 0;
}