//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Function to perform bitwise AND recursively
int bitwiseAND(int x, int y) {
    // Base case
    if (x == 0 || y == 0)
        return 0;
    else if (x % 2 == 0 && y % 2 == 0)
        return 2 * bitwiseAND(x/2, y/2);
    else if (x % 2 == 0 && y % 2 != 0)
        return bitwiseAND(x/2, y);
    else if (x % 2 != 0 && y % 2 == 0)
        return bitwiseAND(x, y/2);
    else
        return bitwiseAND(x/2, y/2) * 2 + 1;
}

// Function to perform bitwise OR recursively
int bitwiseOR(int x, int y) {
    // Base case
    if (x == 0 && y == 0)
        return 0;
    else if (x % 2 == 0 && y % 2 == 0)
        return 2 * bitwiseOR(x/2, y/2);
    else if (x % 2 == 0 && y % 2 != 0)
        return bitwiseOR(x/2, y) * 2 + 1;
    else if (x % 2 != 0 && y % 2 == 0)
        return bitwiseOR(x, y/2) * 2 + 1;
    else
        return bitwiseOR(x/2, y/2) * 2 + 1;
}

// Function to perform bitwise XOR recursively
int bitwiseXOR(int x, int y) {
    // Base case
    if (x == 0 && y == 0)
        return 0;
    else if (x % 2 == 0 && y % 2 == 0)
        return 2 * bitwiseXOR(x/2, y/2);
    else if (x % 2 == 0 && y % 2 != 0)
        return bitwiseXOR(x/2, y) * 2 + 1;
    else if (x % 2 != 0 && y % 2 == 0)
        return bitwiseXOR(x, y/2) * 2 + 1;
    else
        return bitwiseXOR(x/2, y/2) * 2 + (x % 2 != y % 2);
}

int main() {
    int num1 = 12;
    int num2 = 25;
    
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwiseAND(num1, num2));
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwiseOR(num1, num2));
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwiseXOR(num1, num2));
    
    return 0;
}