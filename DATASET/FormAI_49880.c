//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

// Function prototypes
void bitwise_AND(int a, int b);
void bitwise_OR(int a, int b);
void bitwise_XOR(int a, int b);
void bitwise_NOT(int a);
void left_shift(int a, int n);
void right_shift(int a, int n);

int main() {

    int a = 60;
    int b = 13;
    
    printf("Given a = %d and b = %d\n", a, b);
    
    bitwise_AND(a,b);
    bitwise_OR(a,b);
    bitwise_XOR(a,b);
    bitwise_NOT(a);
    left_shift(a,2);
    right_shift(a,2);

    return 0;
}

void bitwise_AND(int a, int b) {
    int result = a & b;
    printf("The AND result of %d and %d is %d\n", a, b, result);
}

void bitwise_OR(int a, int b) {
    int result = a | b;
    printf("The OR result of %d and %d is %d\n", a, b, result);
}

void bitwise_XOR(int a, int b) {
    int result = a ^ b;
    printf("The XOR result of %d and %d is %d\n", a, b, result);
}

void bitwise_NOT(int a) {
    int result = ~a;
    printf("The NOT result of %d is %d\n", a, result);
}

void left_shift(int a, int n) {
    int result = a << n;
    printf("The left shift result of %d by %d is %d\n", a, n, result);
}

void right_shift(int a, int n) {
    int result = a >> n;
    printf("The right shift result of %d by %d is %d\n", a, n, result);
}