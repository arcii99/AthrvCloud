//FormAI DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_converter(int num);

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("\nBinary representation of %d is: ", num);

    binary_converter(num);

    return 0;
}

void binary_converter(int num)
{
    if(num != 0)
    {
        binary_converter(num/2);
        printf("%d", num%2);
    }
}