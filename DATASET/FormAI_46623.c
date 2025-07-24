//FormAI DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>

// Define the bitwise operators as macros
#define AND &
#define OR |
#define XOR ^

// Define switches to configure the program
#define USE_AND 1
#define USE_OR 1
#define USE_XOR 1

int main() {
    // Initialize two integer variables
    int a = 5;
    int b = 3;
    
    // Perform bitwise operations based on the switches
    #if USE_AND
        int result_and = a AND b;
        printf("a AND b = %d\n", result_and);
    #endif
    
    #if USE_OR
        int result_or = a OR b;
        printf("a OR b = %d\n", result_or);
    #endif
    
    #if USE_XOR
        int result_xor = a XOR b;
        printf("a XOR b = %d\n", result_xor);
    #endif
    
    return 0;
}