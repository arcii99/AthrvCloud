//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

void toHex(unsigned int num)
{
    char hex[100];
    int i = 0, rem;
    while(num != 0)
    {
        rem = num % 16;
        if(rem < 10)
            hex[i] = 48 + rem;
        else
            hex[i] = 87 + rem;
        i++;
        num /= 16;
    }
    printf("Hexadecimal: ");
    for(int j = i-1; j >= 0; j--)
        printf("%c", hex[j]);
}

int main()
{
    unsigned int num;
    printf("Please enter the number to convert to hexadecimal: ");
    scanf("%u", &num);
    toHex(num);
    return 0;
}