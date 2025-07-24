//FormAI DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    printf("Hello there! I am a mind-bending binary converter.\n");
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    printf("\nGreat choice! Now, let's convert %d to binary:\n", n);

    int binary[32] = {0}; // An array to store binary digits (up to 32 bits)
    int i = 0;

    while (n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("\nHere is the binary representation of %d: \n", n);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n\nDo you want to be even more mind-bended? Let's convert that binary number back to decimal!\n");

    int decimal = 0;
    int power = 0;

    for (int k = i - 1; k >= 0; k--)
    {
        decimal += binary[k] * pow(2, power);
        power++;
    }

    printf("\nHere we go! %d in binary is %d in decimal.\n", i, decimal);

    printf("\nAmazing, isn't it? Hope you enjoyed the mind-bending binary conversion. :)");
  
    return 0;
}