//FormAI DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, binary[1000], i=0, j;
    printf("Enter the decimal number you want to convert: ");
    scanf("%d",&num);

    while(num>0) //converting decimal to binary
    {
        binary[i]=num%2;
        num=num/2;
        i++;
    }

    printf("The binary representation of the number is: ");

    for(j=i-1;j>=0;j--) //printing the binary representation
    {
        printf("%d",binary[j]);
    }

    return 0;
}