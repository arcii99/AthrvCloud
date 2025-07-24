//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

int main() {
    // Example using the & operator, which performs a bitwise AND
    int a = 12; // binary: 1100
    int b = 25; // binary: 11001
    int c = a & b; // binary: 1000 (decimal 8)
    printf("a & b = %d\n", c);

    // Example using the | operator, which performs a bitwise OR
    int d = 6; // binary: 110
    int e = 7; // binary: 111
    int f = d | e; // binary: 111 (decimal 7)
    printf("d | e = %d\n", f);

    // Example using the ^ operator, which performs a bitwise XOR
    int g = 26; // binary: 11010
    int h = 18; // binary: 10010
    int i = g ^ h; // binary: 01000 (decimal 8)
    printf("g ^ h = %d\n", i);

    // Example using the ~ operator, which performs a bitwise NOT (or one's complement)
    int j = 15; // binary: 1111
    int k = ~j; // binary: 0000 0000 0000 1110 (decimal -16)
    printf("~j = %d\n", k);

    // Example using the << operator, which performs a bitwise left shift
    int l = 10; // binary: 1010
    int m = l << 2; // binary: 101000 (decimal 40)
    printf("l << 2 = %d\n", m);

    // Example using the >> operator, which performs a bitwise right shift
    int n = 25; // binary: 11001
    int o = n >> 3; // binary: 11 (decimal 3)
    printf("n >> 3 = %d\n", o);

    return 0;
}