//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>

void binaryConverter(int num);

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("The binary representation of %d is: ", num);
    binaryConverter(num);
    return 0;
}

void binaryConverter(int num)
{
    if(num == 0)
        return;
    binaryConverter(num/2);
    printf("%d", num%2);
}