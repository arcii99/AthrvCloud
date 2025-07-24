//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>

int main() {
    char hex[17], hexnum;
    int i, decimal = 0, base = 1;

    printf("Enter any Hexadecimal Number: ");
    fgets(hex, sizeof(hex), stdin);

    for (i = 0; hex[i] != '\n'; i++) {
        hexnum = hex[i];

        if (hexnum >= '0' && hexnum <= '9') {
            decimal += (hexnum - '0') * base;
            base *= 16;
        }
        else if (hexnum >= 'A' && hexnum <= 'F') {
            decimal += (hexnum - 'A' + 10) * base;
            base *= 16;
        }
        else if (hexnum >= 'a' && hexnum <= 'f') {
            decimal += (hexnum - 'a' + 10) * base;
            base *= 16;
        }
    }

    printf("The equivalent decimal number is: %d", decimal);
    return 0;
}