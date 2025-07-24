//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main() {
    //Defining variables
    int a = 9; //8 in binary: 1001
    int b = 12; //12 in binary: 1100

    //Performing Bitwise operations
    int c = a & b; //Bitwise AND: 1000 (Binary equivalent of 8 in decimal)
    int d = a | b; //Bitwise OR: 1101 (Binary equivalent of 13 in decimal)
    int e = a ^ b; //Bitwise XOR: 0101 (Binary equivalent of 5 in decimal)
    int f = ~a; //Bitwise NOT: 0110 (Binary equivalent of -10 in decimal)
    int g = b << 2; //Bitwise left shift by 2: 110000 (Binary equivalent of 48 in decimal)
    int h = b >> 2; //Bitwise right shift by 2: 000011 (Binary equivalent of 3 in decimal)

    //Printing the results
    printf("Bitwise AND: %d\n", c);
    printf("Bitwise OR: %d\n", d);
    printf("Bitwise XOR: %d\n", e);
    printf("Bitwise NOT: %d\n", f);
    printf("Bitwise left shift by 2: %d\n", g);
    printf("Bitwise right shift by 2: %d\n", h);

    return 0;
}