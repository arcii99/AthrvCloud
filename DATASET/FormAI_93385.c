//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decToHex(int num)
{
    char hexNum[50]; // array to store hexadecimal number
    int i = 0; // counter for array index

    // Loop to convert decimal to hexadecimal
    while (num > 0)
    {
        int rem = num % 16; // get remainder
        if (rem < 10) // if remainder is less than 10, add to array
            hexNum[i++] = rem + 48; // add 48 to get ASCII value of digit
        else // if remainder is greater than or equal to 10, add corresponding character to array
            hexNum[i++] = rem + 55; // add 55 to get ASCII value of character
        num /= 16; // divide decimal by 16 to get quotient
    }

    // Print hexadecimal number in reverse order
    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexNum[j]);
}

int main()
{
    int decimalNum;

    // Input decimal number from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    // Call function to convert decimal to hexadecimal
    decToHex(decimalNum);

    return 0;
}