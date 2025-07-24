//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include<stdio.h>
#include<string.h>

void binaryConversion(int decimalNum)
{
    int binaryRep[10], i = 0, j;
    while(decimalNum>0)
    {
        binaryRep[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }
    printf("The binary equivalent is: ");
    for(j=i-1;j>=0;j--)
        printf("%d",binaryRep[j]);
    printf("\n");
}

int main()
{
    int decimalNum;
    printf("Please enter a decimal number:");
    scanf("%d", &decimalNum);
    binaryConversion(decimalNum);
    return 0;
}