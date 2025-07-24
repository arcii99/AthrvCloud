//FormAI DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>

int main() {
    int a = 10, b = 5;
    unsigned int c = 12, d = 7;
    char x = 'a'; 

    // Bitwise AND operator example
    printf("Bitwise AND operator: %d\n", a & b);
    printf("Bitwise AND operator: %u\n", c & d);

    // Bitwise OR operator example
    printf("Bitwise OR operator: %d\n", a | b);
    printf("Bitwise OR operator: %u\n", c | d);

    // Bitwise XOR operator example
    printf("Bitwise XOR operator: %d\n", a ^ b);
    printf("Bitwise XOR operator: %u\n", c ^ d);

    // Bitwise NOT operator example
    printf("Bitwise NOT operator: %d\n", ~a);
    printf("Bitwise NOT operator: %u\n", ~c);

    // Left shift operator example
    printf("Left shift operator: %d\n", a << 2);
    printf("Left shift operator: %u\n", c << 1);

    // Right shift operator example
    printf("Right shift operator: %d\n", a >> 2);
    printf("Right shift operator: %u\n", c >> 1);

    // Bitwise AND operator with character example
    printf("Bitwise AND operator with character: %c\n", x & 30);

    return 0;
}