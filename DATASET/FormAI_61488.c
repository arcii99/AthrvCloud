//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i = 0, rem;
    char hex[100];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num != 0) {
        rem = num % 16;
        if (rem < 10) {
            hex[i] = rem + 48;
        } else {
            hex[i] = rem + 55;
        }
        i++;
        num /= 16;
    }
    printf("Hexadecimal equivalent is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    return 0;
}