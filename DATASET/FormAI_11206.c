//FormAI DATASET v1.0 Category: Binary Converter ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int num, bin = 0, rem, place = 1;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    while(num > 0)
    {
        rem = num % 2;
        bin += rem * place;
        place *= 10;
        num /= 2;
    }
    printf("Binary equivalent: %d", bin);
    return 0;
}