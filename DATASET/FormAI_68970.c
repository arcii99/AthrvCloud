//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include<stdio.h>

void decToHexa(unsigned int num)
{
    char hexaDeciNum[100];
    int i = 0;
    while(num!=0)
    {
        int temp = 0;
        temp = num % 16;
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        num = num/16;
    }
    printf("Hexadecimal number: ");
    for(int j=i-1 ;j>=0; j--)
        printf("%c", hexaDeciNum[j]);
}

int main()
{
    unsigned int decimalNum;
    printf("Enter a Decimal Number: ");
    scanf("%u", &decimalNum);

    decToHexa(decimalNum);
    return 0;
}