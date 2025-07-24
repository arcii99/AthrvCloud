//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBin(int dec)
{
    // Create an array to store binary representation
    int bin[32];
    int i = 0;
    
    // Convert decimal to binary representation
    while(dec > 0)
    {
        bin[i] = dec%2;
        dec = dec/2;
        i++;
    }
    
    // Print binary representation in reverse order
    printf("Binary representation: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", bin[j]);
    }
    printf("\n");
}

int main()
{
    int num;

    // Take user input for decimal value
    printf("Enter a decimal value: ");
    scanf("%d", &num);

    // Convert decimal to binary
    decToBin(num);

    return 0;
}