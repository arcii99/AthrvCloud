//FormAI DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <math.h>

void printBinary(int num);

int main()
{
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("Binary Equivalent: ");
    printBinary(decimal);
    printf("\n");
    return 0;
}

void printBinary(int num)
{
    if(num == 0)
    {
        return;
    }
    int remainder = num % 2;
    printBinary(num/2);
    printf("%d", remainder);
}