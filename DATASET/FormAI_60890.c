//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() { 

    printf("Oh hex! Oh hex! wherefore art thou hex?\n");
    printf("Deny thy base and refuse thy code;\n");
    printf("Or if thou wilt not, be but sworn my love,\n");
    printf("And I’ll no longer be a decimal.\n");

    int decimal, remainder, quotient;
    char hex[100];
    int i = 0;

    printf("Speak fair, for I am listening...\n");
    printf("What decimal number shall we convert into a hex?\n");
    scanf("%d", &decimal);

    quotient = decimal;

    while(quotient != 0) {

        remainder = quotient % 16;

        if( remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 55 + remainder;

        quotient = quotient/16;
    }

    printf("Hark! Thy hex be: ");

    for(int j = i-1; j>= 0; j--)
        printf("%c", hex[j]);

    printf("\nSo, wilt thou not love me in hex?\n");

    return 0;
}