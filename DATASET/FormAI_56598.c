//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>

const char hex[] = "0123456789ABCDEF";

void toHexadecimal(int num) {
    char hexa[50] = {0};
    int i = 0, j;

    while (num != 0) {
        int remainder = num % 16;
        hexa[i++] = hex[remainder];
        num /= 16;
    }

    printf("Hexadecimal value: ");

    for (j = i - 1; j >= 0; j--)
        printf("%c", hexa[j]);
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    toHexadecimal(num);
    return 0;
}