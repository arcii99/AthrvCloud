//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include<stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal_num)
{
    char hexadecimal_num[100];
    int temp = decimal_num, i = 0, j;
    
    // Convert decimal number to hexadecimal string
    while(temp != 0)
    {
        int remainder = temp%16;
        if(remainder < 10)
        {
            hexadecimal_num[i] = remainder + 48;
        }
        else
        {
            hexadecimal_num[i] = remainder + 55;
        }
        i++;
        temp /= 16;
    }
    
    // Print hexadecimal number
    printf("\nHexadecimal number: ");
    for(j = i-1; j >= 0; j--)
    {
        printf("%c", hexadecimal_num[j]);
    }
    printf("\n");
}

int main()
{
    int decimal_num;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    
    decimalToHexadecimal(decimal_num);

    return 0;
}