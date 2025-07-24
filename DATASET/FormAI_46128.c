//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void surreal_hex_converter(int dec_num)
{
    int surreal_hex[100];
    int counter = 0;

    while (dec_num > 0)
    {
        surreal_hex[counter] = dec_num % 16;
        dec_num /= 16;
        counter++;
    }

    printf("The surreal hexadecimal representation of %d is: ", dec_num);
    
    for (int i = counter - 1; i >= 0; i--)
    {
        switch (surreal_hex[i])
        {
            case 10:
                printf("banana ");
                break;
            case 11:
                printf("shoe ");
                break;
            case 12:
                printf("rainbow ");
                break;
            case 13:
                printf("mushroom ");
                break;
            case 14:
                printf("dragonfly ");
                break;
            case 15:
                printf("star ");
                break;
            default:
                printf("%d ", surreal_hex[i]);
        }
    }

    printf("\n");
}

int main()
{
    int decimal_number = 3024;
    surreal_hex_converter(decimal_number);
    return 0;
}