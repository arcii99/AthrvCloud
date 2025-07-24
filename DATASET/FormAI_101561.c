//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void to_hexadecimal(int num);

int main()
{
    int decimal_num;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    printf("Hexadecimal equivalent: ");
    to_hexadecimal(decimal_num);

    return 0;
}

void to_hexadecimal(int num)
{
    int remainder;
    char *hexadecimal_num = (char*)malloc(sizeof(char)*100); // allocate memory dynamically
    int i = 0; // index for hexadecimal_num array

    while(num != 0)
    {
        remainder = num % 16;

        if(remainder < 10)
            hexadecimal_num[i++] = 48 + remainder; // convert digit value to its ASCII code
        else
            hexadecimal_num[i++] = 55 + remainder; // convert digit value to its ASCII code

        num /= 16;
    }

    for(int j = i-1; j >= 0; j--)
    {
        printf("%c", hexadecimal_num[j]); // print the hexadecimal number in reverse
    }

    free(hexadecimal_num); // free the memory allocated for hexadecimal_num
}