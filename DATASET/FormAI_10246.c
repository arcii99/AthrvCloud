//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int num, rem, i = 0;
    char hex[100];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num != 0) {
        rem = num % 16;

        if (rem < 10) {
            hex[i] = rem + '0';
        } else {
            hex[i] = rem + 55;
        }

        i++;
        num = num / 16;
    }

    printf("Equivalent hexadecimal value: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }

    return 0;
}