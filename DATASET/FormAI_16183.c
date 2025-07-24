//FormAI DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int binary[1000];
    int count = 0;

    printf("*** RETRO BINARY CONVERTER ***\n\n");

    printf("Enter a decimal number: ");
    scanf("%d", &x);

    while (x > 0)
    {
        binary[count] = x % 2;
        count++;
        x /= 2;
    }

    printf("\nBinary equivalent: ");

    if (count == 0)
    {
        printf("0");
    }
    else
    {
        for (int i = count - 1; i >= 0; i--)
        {
            printf("%d", binary[i]);
        }
    }

    printf("\n\n");
    return 0;
}