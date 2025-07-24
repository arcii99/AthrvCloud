//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char hex[17], c;
    int decimal, i, amount = 0, position;
    
    printf("Enter hexadecimal number:\n");
    fflush(stdout);
    scanf("%s", hex);

    decimal = 0;
    position = strlen(hex)-1;

    for(i=0;hex[i]!='\0';i++)
    {
        if(hex[i]>='0' && hex[i]<='9')          
        {
            amount = hex[i] - 48;       
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            amount = hex[i] - 87;        
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            amount = hex[i] - 55;        
        }
        decimal += amount * pow(16, position);
        position--;
    }

    printf("Decimal number: %d", decimal);
    return 0;
}