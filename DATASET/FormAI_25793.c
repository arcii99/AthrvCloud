//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

// function prototypes
void printBinary(int n);
int getBit(int n, int pos);
int setBit(int n, int pos);
int clearBit(int n, int pos);
int toggleBit(int n, int pos);
int updateBit(int n, int pos, int value);

int main() {
    int num = 43; // number to perform operations on
    printf("Original number: %d\n", num);
    
    printf("Binary representation: ");
    printBinary(num); // print binary representation of num
    
    // test getBit function
    printf("\nBit at position 3: %d\n", getBit(num, 3));
    
    // test setBit function
    printf("\nSetting bit at position 5...\n");
    num = setBit(num, 5);
    printf("New number: %d\n", num);
    printf("Binary representation: ");
    printBinary(num);
    
    // test clearBit function
    printf("\nClearing bit at position 4...\n");
    num = clearBit(num, 4);
    printf("New number: %d\n", num);
    printf("Binary representation: ");
    printBinary(num);
    
    // test toggleBit function
    printf("\nToggling bit at position 6...\n");
    num = toggleBit(num, 6);
    printf("New number: %d\n", num);
    printf("Binary representation: ");
    printBinary(num);
    
    // test updateBit function
    printf("\nUpdating bit at position 2 to 0...\n");
    num = updateBit(num, 2, 0);
    printf("New number: %d\n", num);
    printf("Binary representation: ");
    printBinary(num);
    
    return 0;
}

// function to print binary representation of a number
void printBinary(int n) {
    for (int i = sizeof(n)*8-1; i >= 0; i--) {
        printf("%d", getBit(n, i));
    }
}

// function to get a specific bit of a number
int getBit(int n, int pos) {
    return ((n >> pos) & 1);
}

// function to set a specific bit of a number to 1
int setBit(int n, int pos) {
    return (n | (1 << pos));
}

// function to clear a specific bit of a number to 0
int clearBit(int n, int pos) {
    return (n & ~(1 << pos));
}

// function to toggle a specific bit of a number (from 1 to 0 or from 0 to 1)
int toggleBit(int n, int pos) {
    return (n ^ (1 << pos));
}

// function to update a specific bit of a number to a given value (either 0 or 1)
int updateBit(int n, int pos, int value) {
    if (value == 0) {
        return clearBit(n, pos);
    } else {
        return setBit(n, pos);
    }
}