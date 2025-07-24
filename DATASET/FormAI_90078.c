//FormAI DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>

//Function to perform bitwise operations
void bitwise_operations(int a, int b) {
    int bitwise_and = a & b;
    int bitwise_or = a | b;
    int bitwise_xor = a ^ b;
    int bitwise_complement_a = ~a;
    int bitwise_left_shift = a << 2;
    int bitwise_right_shift = b >> 2;

    printf("a & b = %d\n", bitwise_and);
    printf("a | b = %d\n", bitwise_or);
    printf("a ^ b = %d\n", bitwise_xor);
    printf("~a = %d\n", bitwise_complement_a);
    printf("a << 2 = %d\n", bitwise_left_shift);
    printf("b >> 2 = %d\n", bitwise_right_shift);
}

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);

    printf("Performing bitwise operations on %d and %d:\n", a, b);
    bitwise_operations(a, b);
    return 0;
}