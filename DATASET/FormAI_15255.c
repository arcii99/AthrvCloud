//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

void hexadecimal_converter(int decimal_number) {
    int quotient, remainder, i=1, j, temp;
    char hex_value[100];
    quotient = decimal_number;
    while(quotient != 0) {
        temp = quotient % 16;
        if(temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hex_value[i++] = temp;
        quotient = quotient/16;
    }
    printf("\nEquivalent hexadecimal value of decimal number %d: ", decimal_number);
    for(j = i -1; j > 0; j--) {
        printf("%c", hex_value[j]);
    }
}

int main() {
    int decimal_number;
    printf("Enter Decimal Number: ");
    scanf("%d", &decimal_number);
    hexadecimal_converter(decimal_number);
    return 0;
}