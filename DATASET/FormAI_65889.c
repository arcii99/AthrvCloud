//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

// Creating a struct to hold the bit and its position
typedef struct {
    unsigned int bit;
    unsigned int position;
} BitPosition;

// Function to get the bit at a specific position
unsigned int getBit(unsigned int num, unsigned int position) {
    return (num >> position) & 1;
}

// Function to set a bit at a specific position
unsigned int setBit(unsigned int num, unsigned int position) {
  return num | (1 << position);
}

// Function to clear a bit at a specific position
unsigned int clearBit(unsigned int num, unsigned int position) {
    return num & ~(1 << position);
}

// Function to toggle a bit at a specific position
unsigned int toggleBit(unsigned int num, unsigned int position) {
    return num ^ (1 << position);
}

// Function to print the binary representation of a number
void printBinary(unsigned int num) {
    for(int i=31; i>=0; i--) {
        printf("%d", getBit(num, i));
    }
    printf("\n");
}

int main() {
    unsigned int num = 5;
    printf("The binary representation of %u is: ", num);
    printBinary(num);

    unsigned int position = 2;
    printf("Setting bit at position %u: ", position);
    num = setBit(num, position);
    printBinary(num);

    position = 0;
    printf("Clearing bit at position %u: ", position);
    num = clearBit(num, position);
    printBinary(num);

    position = 1;
    printf("Toggling bit at position %u: ", position);
    num = toggleBit(num, position);
    printBinary(num);

    return 0;
}