//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number you want to convert to hexadecimal: ");
    int decimal;
    scanf("%d", &decimal);

    char hexadecimal[20];
    int i = 0;

    while(decimal > 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hexadecimal[i] = remainder + 48;
        } else {
            hexadecimal[i] = remainder + 55;
        }
        i++;
        decimal /= 16;
    }

    printf("The hexadecimal equivalent is: ");

    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }

    printf("\n");

    return 0;
}