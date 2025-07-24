//FormAI DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
#include <stdio.h>

// Define an XOR function to perform bit-level arithmetic
int XOR(int a, int b) {
    int result = 0;
    int i;
    for (i = 31; i >= 0; i--) {
        int x = (a >> i) & 1;
        int y = (b >> i) & 1;
        // XOR the bits and set result
        result |= ((x ^ y) << i);
    }
    return result;
}

int main() {
    // Initialize variables
    int num1 = 7;
    int num2 = 11;
    int num3 = 2;
    
    // Perform XOR arithmetic on variables
    int result1 = XOR(num1, num2);
    int result2 = XOR(num2, num3);
    int result3 = XOR(num1, num3);
    
    // Print results
    printf("The result of (%d ^ %d) is: %d\n", num1, num2, result1);
    printf("The result of (%d ^ %d) is: %d\n", num2, num3, result2);
    printf("The result of (%d ^ %d) is: %d\n", num1, num3, result3);
    
    return 0;
}