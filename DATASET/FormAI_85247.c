//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h> //standard input/output library

int main() {
    int decimalNum, binaryNum = 0, placeVal = 1, remainder;

    printf("Enter a decimal number to be converted to binary: ");
    scanf("%d", &decimalNum); //taking input decimal number from the user

    while(decimalNum > 0) { //loop to convert decimal to binary
        remainder = decimalNum % 2; //finding the remainder of the division by 2
        decimalNum = decimalNum / 2; //getting the quotient by dividing with 2
        binaryNum += (remainder * placeVal); //calculating the binary number
        placeVal *= 10; //updating the place value
    }

    printf("The binary equivalent is: %d", binaryNum); //displaying the binary number

    return 0;
}