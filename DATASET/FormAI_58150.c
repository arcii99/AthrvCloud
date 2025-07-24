//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

int main()
{
    int decimal, binary[32], i;
    
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);

    // calculate the binary equivalent
    for(i=0; decimal>0; i++)
    {
        binary[i] = decimal%2;
        decimal = decimal/2;
    }
    
    printf("\nBinary equivalent: ");

    // print the binary equivalent in reverse order
    for(i=i-1; i>=0; i--)
    {
        printf("%d",binary[i]);
    }

    return 0;
}