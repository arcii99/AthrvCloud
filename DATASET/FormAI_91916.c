//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    int num, i , j;
    char hex[100];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    i = 0;

    while(num>0)
    {
        int mod = num % 16;
        if(mod>9)
        {
            hex[i] = mod + 55;   //Add 55 to convert to ASCII value of A-F
        }
        else
        {
            hex[i] = mod + 48;   //Add 48 to convert to ASCII value of 0-9
        }
        i++;
        num = num/16;
    }

    printf("Hexadecimal equivalent: ");
    for(j=i-1;j>=0;j--)
    {
        printf("%c",hex[j]);
    }
    
    return 0;
}