//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multiplayer
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decToHex(int decimal, char hex[])
{
    int i = 0;
    while(decimal != 0)
    {
        int temp = 0;
        temp = decimal % 16;

        // Convert temp to hexadecimal value
        if(temp < 10)
        {
            hex[i] = temp + 48;
            i++;
        }
        else
        {
            hex[i] = temp + 55;
            i++;
        }

        decimal = decimal / 16;
    }
    // Displaying the hexadecimal value
    printf("Hexadecimal value: ");
    for(int j = i-1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
}

int main()
{
    int num;
    char hex[50];
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decToHex(num, hex);
    printf("\n");

    return 0;
}