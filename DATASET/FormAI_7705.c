//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include<stdio.h>
#include<math.h>
// Let's convert decimal to hexadecimal!

int main()
{
    int num, rem, decimal = 0; // Declaration of variables
    char hex[17] = "0123456789ABCDEF"; // Hexadecimal digits

    printf("Enter a decimal number: \n");
    scanf("%d", &num);

    for (int i = 0; num > 0; i++) // Converting decimal number to hexadecimal
    {
        rem = num % 16;
        decimal += rem * pow(10, i); // Converting remainder to decimal
        num /= 16;
    }

    int hexa[32], i = 0;

    while (decimal > 0) // Converting decimal to hexadecimal
    {
        hexa[i] = decimal % 16;
        i++;
        decimal /= 16;
    }

    printf("Hexadecimal number is: ");

    for (int j = i - 1; j >= 0; j--) // Displaying the hexadecimal number
    {
        printf("%c", hex[hexa[j]]);
    }

    return 0;
}