//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>

int main(void) {

    unsigned int x = 0b11110000; // this is binary for 240 decimal
    unsigned int y = 0b00001111; // this is binary for 15 decimal
    
    // bitwise OR
    unsigned int z = x | y; // this is binary for 255 decimal
    
    // bitwise AND
    unsigned int w = x & y; // this is binary for 0 decimal
    
    printf("x = %u\n", x);
    printf("y = %u\n", y);
    printf("z = x | y = %u\n", z);
    printf("w = x & y = %u\n", w);
    
    // bitwise left shift
    unsigned int a = 0b00101010; // this is binary for 42 decimal
    unsigned int b = a << 2; // this is binary for 168 decimal
    printf("a = %u\n", a);
    printf("b = a << 2 = %u\n", b);
    
    // bitwise right shift
    unsigned int c = 0b10101010; // this is binary for 170 decimal
    unsigned int d = c >> 2; // this is binary for 42 decimal
    printf("c = %u\n", c);
    printf("d = c >> 2 = %u\n", d);
    
    // bitwise XOR
    unsigned int e = 0b11001100; // this is binary for 204 decimal
    unsigned int f = 0b00110011; // this is binary for 51 decimal
    unsigned int g = e ^ f; // this is binary for 255 decimal
    printf("e = %u\n", e);
    printf("f = %u\n", f);
    printf("g = e ^ f = %u\n", g);
    
    return 0;
}