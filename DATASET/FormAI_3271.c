//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <string.h>

void print_hex(int num);

int main() {
    int decimal;
    char input[10];

    printf("Enter decimal number: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &decimal);
    print_hex(decimal);

    return 0;
}

void print_hex(int num) {
    char hex[17] = "0123456789ABCDEF";
    char result[50] = "";
    int remainder;

    while (num != 0) {
        remainder = num % 16;
        num /= 16;
        char hex_digit[2];
        sprintf(hex_digit, "%c", hex[remainder]);
        strcat(result, hex_digit);
    }

    if(strlen(result) == 0) {
        printf("0");
    } else {
        printf("Hexadecimal value: ");
        for(int i = strlen(result) - 1; i >= 0; i--) {
            printf("%c", result[i]);
        }
    }

    printf("\n");
}