//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber)
{
    char hexadecimal[100];
    int index = 0;

    // Convert decimal number to hexadecimal using loop
    while(decimalNumber != 0)
    {
        int remainder = decimalNumber % 16;
        if(remainder < 10)
            hexadecimal[index++] = remainder + 48;
        else
            hexadecimal[index++] = remainder + 55;

        decimalNumber /= 16;
    }

    // Display the hexadecimal number
    printf("Hexadecimal number: ");
    for(int i = index - 1; i >= 0; i--)
        printf("%c", hexadecimal[i]);
}

int main()
{
    int decimalNumber;

    // Take input from user
    printf("Enter a decimal number:");
    scanf("%d", &decimalNumber);

    // Convert decimal to hexadecimal and display the result
    decimalToHexadecimal(decimalNumber);

    return 0;
}