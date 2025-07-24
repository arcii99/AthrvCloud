//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

// This program demonstrates the genius of bitwise operations

int main() {
    
    int a = 10;
    int b = 5;
    int c = a ^ b; // bitwise XOR operation on a and b
    
    printf("a = %d\n", a); // prints 10
    printf("b = %d\n", b); // prints 5
    printf("c = a ^ b = %d\n", c); // prints 15
    
    int d = c >> 1; // right shift c by 1 bit
    
    printf("d = c >> 1 = %d\n", d); // prints 7
    
    int e = ~d; // bitwise negation of d
    
    printf("e = ~d = %d\n", e); // prints -8
    
    printf("The absolute value of e is %d\n", (e ^ (e >> 31)) - (e >> 31));
    // absolute value of e using bitwise operations
    
    int f = a << 2; // left shift a by 2 bits
    
    printf("f = a << 2 = %d\n", f); // prints 40
    
    int g = b & 3; // bitwise AND operation on b and 3
    
    printf("g = b & 3 = %d\n", g); // prints 1
    
    int h = c | 1; // bitwise OR operation on c and 1
    
    printf("h = c | 1 = %d\n", h); // prints 15
    
    int i = d ^ 6; // bitwise XOR operation on d and 6
    
    printf("i = d ^ 6 = %d\n", i); // prints 1
    
    printf("The bitwise complement of i is %d\n", ~i); // bitwise complement of i
    
    return 0;
}