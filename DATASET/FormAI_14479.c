//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>

int main() {
    int a=10, b=20, c=30;

    // Adding element to array using shift operator
    int arr[5];
    for(int i=0; i<5; i++) {
        arr[i] = (i+1) << 2;
    }

    // Subtraction of two integers
    int diff = b - a;

    // Division of two integers using ternary operator
    int quotient = (c!=0) ? (b / c) : 0;

    // Multiplication of two integers
    int product = a * b;

    // Modulus operator and do-while loop
    int i=0;
    do {
        printf("%d ", i);
        i++;
    } while(i%5 != 0);

    printf("\nArray contents are: ");
    for(int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    // Increment and decrement operators
    int x=5, y=7;
    x--;
    y++;
    printf("\nValue of x is now: %d", x);
    printf("\nValue of y is now: %d\n", y);

    return 0;
}