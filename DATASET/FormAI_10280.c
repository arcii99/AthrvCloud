//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* Helper function to convert decimal to hexadecimal */
char decToHex(int num) {
    /* Return the hex character for a given decimal value */
    if (num >= 0 && num <= 9) {
        return (char) (num + '0');
    } else {
        return (char) (num - 10 + 'A');
    }
}

/* Recursive function to convert decimal to hexadecimal */
void decToHexRecursive(int num) {
    /* Base case: num is zero */
    if (num == 0) {
        return;
    }
    /* Recursively divide num by 16 and print the remainder in hex format */
    decToHexRecursive(num / 16);
    printf("%c", decToHex(num % 16));
}

int main() {
    int decimalNum;
    printf("Enter decimal number: ");
    scanf("%d", &decimalNum);
    /* Check if decimalNum is less than zero */
    if (decimalNum < 0) {
        printf("Invalid input. Decimal number cannot be negative.\n");
        return 1;
    }
    /* Call the recursive function to convert decimal to hex */
    printf("Hexadecimal equivalent: ");
    if (decimalNum == 0) {
        printf("0");
    } else {
        decToHexRecursive(decimalNum);
    }
    printf("\n");
    return 0;
}