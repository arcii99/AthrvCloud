//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>

int main()
{
    int decimal, binary[20], index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while(decimal > 0)
    {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    printf("Binary equivalent: ");
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }

    return 0;
}