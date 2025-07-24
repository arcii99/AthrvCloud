//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void to_hex(int num);

int main() {
    int num;

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("The hexadecimal equivalent of %d is: ", num);
    to_hex(num);

    return 0;
}

void to_hex(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int rem, i = 0;
    char hex[100];

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

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }

    printf("\nThank you for using our Hexadecimal Converter!\n");
}