//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include <stdio.h>

int main() {
    printf("Enter a number in decimal: ");
    int decimal;
    scanf("%d", &decimal);
    int remainder, i = 0;
    char hex[100];

    while (decimal != 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = remainder + 55;
        }
        decimal /= 16;
        i++;
    }

    printf("The hexadecimal value is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");

    return 0;
}