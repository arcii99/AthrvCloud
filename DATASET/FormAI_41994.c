//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>

int main() {
    char hex[17] = "0123456789ABCDEF"; // Hexadecimal characters
    long long decimal, tempDecimal;
    char hexadecimal[50]; // Array to store hexadecimal number
    int i = 0, rem;

    // Prompt user to enter decimal number
    printf("Enter a decimal number: ");
    scanf("%lld", &decimal);
    tempDecimal = decimal;

    // Convert decimal to hexadecimal
    while (tempDecimal != 0) {
        rem = tempDecimal % 16; // Get remainder
        hexadecimal[i] = hex[rem]; // Store hexadecimal character
        i++; // Move to next character
        tempDecimal /= 16; // Divide decimal by 16
    }
    hexadecimal[i] = '\0'; // Add null character to terminate string

    // Reverse the hexadecimal number
    int len = i;
    char reversedHex[len];
    for (int j = 0; j < len; j++) {
        reversedHex[j] = hexadecimal[i-1];
        i--;
    }

    // Display the hexadecimal number
    printf("Hexadecimal representation of %lld is: 0x%s\n", decimal, reversedHex);

    return 0;
}