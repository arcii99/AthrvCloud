//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() 
{
    printf("Hello curious mind! Let's play with some bitwise operations.\n");
    printf("Enter two numbers (a and b) separated by space: ");
    int a, b;
    scanf("%d %d", &a, &b);
    
    printf("Binary representation of a: ");
    binary(a);
    printf("\n");
    printf("Binary representation of b: ");
    binary(b);
    printf("\n\n");
    
    printf("Bitwise AND operation (a & b): ");
    binary(a & b);
    printf("\n");
    printf("Bitwise OR operation (a | b): ");
    binary(a | b);
    printf("\n");
    printf("Bitwise XOR operation (a ^ b): ");
    binary(a ^ b);
    printf("\n\n");

    printf("Left shift operation (a << 2): ");
    binary(a << 2);
    printf("\n");
    printf("Right shift operation (a >> 2): ");
    binary(a >> 2);
    printf("\n\n");

    printf("One's complement of a (~a): ");
    binary(~a);
    printf("\n");
    printf("One's complement of b (~b): ");
    binary(~b);
    printf("\n\n");
    
    printf("Set bit 3 in a: ");
    binary(a | (1 << 3));
    printf("\n");
    printf("Clear bit 4 in b: ");
    binary(b & ~(1 << 4));
    printf("\n");
    
    return 0;
}

void binary(int n) 
{
    if (n > 1) 
        binary(n/2);

    printf("%d", n % 2);
}