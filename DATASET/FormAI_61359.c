//FormAI DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>

// Determining the highest order bit of a number
#define HOB(n) (sizeof(n) * 8 - __builtin_clz(n))

// Bitwise operations on a character array
void char_logic_operation(char* str1, char* str2, char* result, size_t len, char op) {
    for (int i = 0; i < len; i++) {
        if (op == '&') {
            *(result+i) = *(str1+i) & *(str2+i);
        } else if (op == '|') {
            *(result+i) = *(str1+i) | *(str2+i);
        } else if (op == '^') {
            *(result+i) = *(str1+i) ^ *(str2+i);
        } else {
            printf("Invalid operator!\n");
            return;
        }
    }
}

int main() {
    // Example variables
    int a = 4; // 100 in binary
    int b = 6; // 110 in binary
    char s1[5] = "1010";
    char s2[5] = "0110";
    char s3[5] = "0000";

    // Bitwise AND operation
    int c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR operation
    int d = a | b;
    printf("a | b = %d\n", d);

    // Bitwise XOR operation
    int e = a ^ b;
    printf("a ^ b = %d\n", e);

    // Determining the highest order bit of a number
    int f = 37; // 100101 in binary
    int hob = HOB(f);
    printf("The highest order bit in %d is %d\n", f, hob);

    // Bitwise operations on character arrays
    char_logic_operation(s1, s2, s3, 4, '&');
    printf("1010 & 0110 = %s\n", s3);

    char_logic_operation(s1, s2, s3, 4, '|');
    printf("1010 | 0110 = %s\n", s3);

    char_logic_operation(s1, s2, s3, 4, '^');
    printf("1010 ^ 0110 = %s\n", s3);

    return 0;
}