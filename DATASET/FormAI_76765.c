//FormAI DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <math.h>

int main()
{
    int num, decimal_num, remainder, base = 1, binary = 0;
    
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    decimal_num = num;
    
    while (num > 0)
    {
        remainder = num % 2;
        binary = binary + remainder * base;
        num = num / 2;
        base = base * 10;
    }
    
    printf("The binary equivalent of %d is %d.\n", decimal_num, binary);

    return 0;
}