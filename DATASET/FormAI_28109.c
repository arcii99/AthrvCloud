//FormAI DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <math.h>

void print_binary(int n);

int main()
{
    int decimal_number;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    printf("The binary equivalent of %d is: ", decimal_number);
    print_binary(decimal_number);
    
    return 0;
}

void print_binary(int n)
{
    int binary_number[32];
    int i = 0;
    
    while(n > 0)
    {
        binary_number[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary_number[j]);
    }
}