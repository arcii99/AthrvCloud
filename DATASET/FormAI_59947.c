//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
    // bitwise AND operator example
    int a = 10; // decimal representation: 1010
    int b = 6; // decimal representation: 0110
    int c = a & b; // decimal representation: 0010, which is equal to 2 in decimal
    printf("a & b = %d\n", c); // output: 2
    
    // bitwise OR operator example
    int d = 10; // decimal representation: 1010
    int e = 6; // decimal representation: 0110
    int f = d | e; // decimal representation: 1110, which is equal to 14 in decimal
    printf("d | e = %d\n", f); // output: 14
    
    // bitwise XOR operator example
    int g = 10; // decimal representation: 1010
    int h = 6; // decimal representation: 0110
    int i = g ^ h; // decimal representation: 1100, which is equal to 12 in decimal
    printf("g ^ h = %d\n", i); // output: 12
    
    // bitwise NOT operator example
    int j = 10; // decimal representation: 1010
    int k = ~j; // decimal representation: 0101, which is equal to -11 in decimal
    printf("~j = %d\n", k); // output: -11
    
    // bitwise left shift operator example
    int l = 10; // decimal representation: 1010
    int m = l << 2; // decimal representation: 101000, which is equal to 40 in decimal
    printf("l << 2 = %d\n", m); // output: 40
    
    // bitwise right shift operator example
    int n = 10; // decimal representation: 1010
    int o = n >> 2; // decimal representation: 10, which is equal to 2 in decimal
    printf("n >> 2 = %d\n", o); // output: 2
    
    return 0;
}