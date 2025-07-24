//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

// Function to perform bitwise operations on given integers.
void bitwiseOperations(int x, int y) {
    int and = x & y;
    int or = x | y;
    int xor = x ^ y;
    int complement = ~x;
    int shift_left = x << 2;
    int shift_right = y >> 3;

    // Printing the results of the bitwise operations.
    printf("x & y = %d\n", and);
    printf("x | y = %d\n", or);
    printf("x ^ y = %d\n", xor);
    printf("~x = %d\n", complement);
    printf("Left shift of x by 2 bits = %d\n", shift_left);
    printf("Right shift of y by 3 bits = %d\n", shift_right);
}

int main() {
    int x, y;

    // Reading in the values of x and y from user.
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter value of y: ");
    scanf("%d", &y);

    // Passing in the values of x and y to the function to perform bitwise operations.
    bitwiseOperations(x, y);

    return 0;
}