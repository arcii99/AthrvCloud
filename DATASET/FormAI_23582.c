//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

int main() {
    // bitwise AND
    int a = 5; // 101 in binary
    int b = 3; // 011 in binary
    int c = a & b; // result is 001 in binary
    
    printf("5 & 3 = %d\n", c); // output: 1

    // bitwise OR
    int d = 5; // 101 in binary
    int e = 3; // 011 in binary
    int f = d | e; // result is 111 in binary
    
    printf("5 | 3 = %d\n", f); // output: 7

    // bitwise XOR
    int g = 5; // 101 in binary
    int h = 3; // 011 in binary
    int i = g ^ h; // result is 110 in binary

    printf("5 ^ 3 = %d\n", i); // output: 6
    
    // bitwise NOT
    int j = 5; // 101 in binary
    int k = ~j; // result is 010 in binary
    
    printf("~5 = %d\n", k); // output: -6

    // left shift
    int l = 5; // 101 in binary
    int m = l << 2; // result is 10100 (or 20 in decimal) in binary
    
    printf("5 << 2 = %d\n", m); // output: 20
    
    // right shift
    int n = 5; // 101 in binary
    int o = n >> 1; // result is 10 (or 2 in decimal) in binary
    
    printf("5 >> 1 = %d\n", o); // output: 2

    return 0;
}