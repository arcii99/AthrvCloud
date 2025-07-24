//FormAI DATASET v1.0 Category: Binary Converter ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num, binary[100], i=0, j;
    
    //Input number to be converted to binary
    printf("Enter decimal number to convert to binary: ");
    scanf("%d", &num);
    
    //Generate binary digits in reverse order
    while(num>0)
    {
        binary[i++] = num%2;
        num /= 2;
    }
    
    //Printing the binary number in reverse order to get original binary value
    printf("\nBinary of the given number is: ");
    for(j=i-1; j>=0; j--)
        printf("%d", binary[j]);
    
    return 0;
}