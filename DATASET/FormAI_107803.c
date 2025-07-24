//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {
    int num1 = 56;
    int num2 = 89;
    
    // Using Bitwise OR operator to combine two numbers
    int resultOR = num1 | num2;
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, resultOR);
    
    // Using Bitwise AND operator to check if bit is set or not
    int bitMask = 0b1000; // Suppose we want to check if bit 4 is set or not in num1
    int resultAND = num1 & bitMask;
    if(resultAND != 0) {
        printf("Bit 4 is set in num1!\n");
    } else {
        printf("Bit 4 is not set in num1.\n");
    }
    
    // Using Bitwise XOR operator to toggle bits of a number
    int toggleMask = 0b11111111; // This mask contains all 1's
    int resultXOR = num2 ^ toggleMask;
    printf("Toggling all bits of %d gives us %d\n", num2, resultXOR);
    
    // Using Bitwise Left Shift operator to multiply a number by power of 2
    int multiplyMe = 3;
    int powerOfTwo = 4;
    int resultLS = multiplyMe << powerOfTwo;
    printf("%d multiplied by 2 to the power of %d is %d\n", multiplyMe, powerOfTwo, resultLS);
    
    // Using Bitwise Right Shift operator to divide a number by power of 2
    int divideMe = 240;
    int divideBy = 4;
    int resultRS = divideMe >> divideBy;
    printf("%d divided by 2 to the power of %d is %d\n", divideMe, divideBy, resultRS);
    
    return 0;
}