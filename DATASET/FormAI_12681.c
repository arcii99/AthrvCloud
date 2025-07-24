//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int decimalToBinary(int decimalNum)
{
    int binaryNum[1000];
    int i = 0;
    while(decimalNum > 0)
    {
        binaryNum[i] = decimalNum%2;
        i++;
        decimalNum = decimalNum/2;
    }
    for(int j = i-1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
}
 
int main()
{
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    
    if(decimalNum < 0)
    {
        printf("Only positive numbers can be converted to binary!");
    }
    else
    {
        printf("The binary conversion of %d is: ", decimalNum);
        decimalToBinary(decimalNum);
    }
    return 0;
}