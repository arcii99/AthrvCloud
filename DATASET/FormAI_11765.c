//FormAI DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>

int main() {
    // Welcome message
    printf("Hello there, I am your friendly Binary Converter Bot!\n");
    printf("Please enter a decimal number to convert to binary: ");

    // User input
    int decimalNum;
    scanf("%d", &decimalNum);

    // Conversion logic
    int binaryArr[64], i = 0;
    while (decimalNum > 0) {
        binaryArr[i] = decimalNum % 2;
        decimalNum /= 2;
        i++;
    }

    // Printing binary result
    printf("The binary equivalent of your number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArr[j]);
    }
    printf("\n");

    // Goodbye message
    printf("Thank you for using the Binary Converter Bot! Have a nice day :)\n");

    return 0;
}