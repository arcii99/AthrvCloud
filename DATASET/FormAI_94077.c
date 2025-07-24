//FormAI DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>

int main(){
    int a = 8;
    int b = 6;
    int c = ((a&b) | (a^b) << 1) ^ (a|b); // bitwise operations on a, b

    printf("a = %d, b = %d\n", a, b);
    printf("(a&b) = %d\n", (a&b)); // bitwise AND operation
    printf("(a|b) = %d\n", (a|b)); // bitwise OR operation
    printf("(a^b) << 1 = %d\n", (a^b) << 1); // bitwise XOR operation, and left shift by 1
    printf("((a&b) | (a^b) << 1) = %d\n", ((a&b) | (a^b) << 1)); // performing OR and left shift operations
    printf("((a&b) | (a^b) << 1) ^ (a|b) = %d\n", c); // final result after performing XOR operation

    return 0;
}