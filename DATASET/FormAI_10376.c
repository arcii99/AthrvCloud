//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>

void decimalToHexadecimal(int decimalNumber);
int hexadecimalToDecimal(char hexNumber[], int size);

int main()
{
    int choice, decimalNumber;

    printf("Enter 1 to convert Decimal to Hexadecimal.\nEnter 2 to convert Hexadecimal to Decimal.\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a Decimal number: ");
            scanf("%d", &decimalNumber);
            decimalToHexadecimal(decimalNumber);
            break;
        case 2:
            char hexNumber[20];
            int size;

            printf("Enter a Hexadecimal number: ");
            scanf("%s", hexNumber);
            size = strlen(hexNumber);
            printf("Decimal Equivalent: %d", hexadecimalToDecimal(hexNumber, size));
            break;
        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}

void decimalToHexadecimal(int decimalNumber)
{
    int remainder;
    char hexadecimalNumber[10];
    int i = 0;

    while(decimalNumber != 0)
    {
        remainder = decimalNumber % 16;

        if(remainder < 10)
            hexadecimalNumber[i] = remainder + '0';
        else
            hexadecimalNumber[i] = remainder + 55;  // 'A' = 65

        i++;
        decimalNumber /= 16;
    }

    if(i == 0)
        printf("0");

    printf("Hexadecimal Equivalent: ");
    for(int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimalNumber[j]);
}

int hexadecimalToDecimal(char hexNumber[], int size)
{
    int decimalNumber = 0, power = 1;

    for(int i = size - 1; i >= 0; i--)
    {
        if(hexNumber[i] >= '0' && hexNumber[i] <= '9')
        {
            decimalNumber += (hexNumber[i] - '0') * power;
            power *= 16;
        }
        else if(hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
        {
            decimalNumber += (hexNumber[i] - 55) * power;  // 'A' = 65
            power *= 16;
        }
        else
        {
            printf("Invalid Hexadecimal Number!");
            return -1;
        }
    }

    return decimalNumber;
}