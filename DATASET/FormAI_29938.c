//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

// Bitwise Function Declarations
void setBit(int *num, int position);
void clearBit(int *num, int position);
void toggleBit(int *num, int position);
int checkBit(int num, int position);

int main()
{
    // Testing the Bitwise Functions
    int num = 32; // 00100000 in binary
    printf("Original Number: %d\n", num);
    
    printf("Setting Bit 1: ");
    setBit(&num, 1);
    printf("%d\n", num);
    
    printf("Clearing Bit 3: ");
    clearBit(&num, 3);
    printf("%d\n", num);
    
    printf("Toggling Bit 4: ");
    toggleBit(&num, 4);
    printf("%d\n", num);
    
    printf("Checking Bit 5: ");
    int bitValue = checkBit(num, 5);
    if (bitValue == 1)
        printf("Bit is Set\n");
    else
        printf("Bit is Not Set\n");
    
    return 0;
}

// Function Definitions
void setBit(int *num, int position)
{
    *num |= (1 << position);
}

void clearBit(int *num, int position)
{
    *num &= ~(1 << position);
}

void toggleBit(int *num, int position)
{
    *num ^= (1 << position);
}

int checkBit(int num, int position)
{
    int bitValue = (num >> position) & 1;
    return bitValue;
}