//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>

int main() {
    int decimal_num, remainder, quotient, i = 1, j, temp;
    char hexadecimal_num[100];

    printf("Enter decimal number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    while (quotient != 0) {
        temp = quotient % 16;

        if(temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;

        hexadecimal_num[i++] = temp;
        quotient = quotient / 16;
    }

    printf("Equivalent hexadecimal value of decimal number %d: ", decimal_num);

    for (j = i - 1; j > 0; j--)
        printf("%c", hexadecimal_num[j]);

    return 0;
}