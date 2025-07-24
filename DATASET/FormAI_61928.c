//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>

int main()
{
    printf("Welcome to my Hexadecimal Converter Program!\n\n");
    printf("Enter a positive integer: ");

    int decimal;
    scanf("%d", &decimal);

    char hexadecimal[20];
    int remainder, i = 0;

    while (decimal != 0)
    {
        remainder = decimal % 16;
        if (remainder < 10)
            hexadecimal[i++] = 48 + remainder;
        else
            hexadecimal[i++] = 55 + remainder;
        decimal /= 16;
    }

    printf("\nIn hexadecimal, your number is:\n");

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
      
    printf("\n\nThank you for using my program! Keep programming!\n"); 

    return 0;
}