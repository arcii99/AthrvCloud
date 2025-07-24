//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include<stdio.h>

void convertToBinary(int decimal) // function to convert decimal to binary
{
    int binary[32]; // declare an array to hold binary digits
    int i=0;

    while(decimal>0)
    {
        binary[i] = decimal % 2; // binary digit is either 0 or 1
        decimal /= 2; // update decimal by dividing by 2
        i++; // move to the next binary digit
    }

    printf("Binary of given decimal is: ");

    for(int j=i-1;j>=0;j--) // print binary digits in reverse order
    {
        printf("%d",binary[j]);
    }

    printf("\n");
}

int main()
{
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d",&decimal);

    convertToBinary(decimal); // call function to convert decimal to binary

    return 0;
}