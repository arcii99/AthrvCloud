//FormAI DATASET v1.0 Category: Bitwise operations ; Style: careful
#include<stdio.h>

int main(){

    // Bitwise OR operator
    unsigned int a = 10;    // Binary representation of 10 is 1010
    unsigned int b = 11;    // Binary representation of 11 is 1011
    unsigned int c = a | b; // Bitwise OR operation between 10 and 11 results in 1111
    printf("The result of bitwise OR operation is %d\n", c);

    // Bitwise AND operator
    unsigned int d = 28;    // Binary representation of 28 is 11100
    unsigned int e = 21;    // Binary representation of 21 is 10101
    unsigned int f = d & e; // Bitwise AND operation between 28 and 21 results in 00100
    printf("The result of bitwise AND operation is %d\n", f);

    // Bitwise XOR operator
    unsigned int g = 67;    // Binary representation of 67 is 1000011
    unsigned int h = 49;    // Binary representation of 49 is 110001
    unsigned int i = g ^ h; // Bitwise XOR operation between 67 and 49 results in 1101010
    printf("The result of bitwise XOR operation is %d\n", i);

    // Bitwise Complement operator
    unsigned int j = 25;    // Binary representation of 25 is 11001
    unsigned int k = ~j;    // Bitwise Complement operation on 25 results in 11111111111111111111111110010110
    printf("The result of bitwise Complement operation is %u\n", k);

    // Bitwise Shift Left operator
    unsigned int l = 17;   // Binary representation of 17 is 10001
    unsigned int m = l<<2; // Bitwise Shift Left operation on 17 by 2 bits results in 1000100
    printf("The result of bitwise Shift Left operation is %d\n", m);

    // Bitwise Shift Right operator
    unsigned int o = 48;   // Binary representation of 48 is 110000
    unsigned int p = o>>2; // Bitwise Shift Right operation on 48 by 2 bits results in 1100
    printf("The result of bitwise Shift Right operation is %d\n", p);

    return 0;
}