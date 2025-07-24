//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include<stdio.h>

int main(){
    int x, y; // declaring two variables x and y

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y); // Taking input from user

    // Performing the bitwise AND operation
    int AND = x & y;
    printf("\nThe result of and operator is: %d\n", AND);

    // Performing the bitwise OR operation
    int OR = x | y;
    printf("The result of or operator is: %d\n", OR);

    // Performing the bitwise XOR operation
    int XOR = x ^ y;
    printf("The result of xor operator is: %d\n", XOR);

    // Performing the bitwise NOT operation
    int NOTx = ~x;
    printf("The result of not operator on x is: %d\n", NOTx);

    // Performing the left shift operation
    int leftshift = x << y;
    printf("The result of left shift operator is: %d\n", leftshift);

    // Performing the right shift operation
    int rightshift = x >> y;
    printf("The result of right shift operator is: %d\n", rightshift);

    printf("\nHope you enjoyed performing bitwise operations with me!\n");

    return 0;
}