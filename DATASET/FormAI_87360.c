//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char hexaDecimal[]="0123456789ABCDEF";

void convert_to_hex(int decimal_num)
{
    char hexadec[50];
    int temp = decimal_num, i = 0;
    while(temp != 0)
    {
        int r = temp % 16;
        hexadec[i] = hexaDecimal[r];
        i++;
        temp/=16;
    }
    printf("The hexadecimal equivalent of %d is: ",decimal_num);
    for(int j=i-1;j>=0;j--)
        printf("%c",hexadec[j]);
}

int main()
{
    int decimal_num;
    printf("Enter decimal number: ");
    scanf("%d",&decimal_num);
    if(decimal_num<0)
    {
        printf("Invalid input");
        exit(0);
    }
    else
        convert_to_hex(decimal_num);
    return 0; 
}