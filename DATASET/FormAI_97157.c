//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printHexadecimal(int num) {
    int rem, i = 0;
    char hexadecimalNum[100];

    while (num != 0) {
            rem = num % 16;
            if (rem < 10)
                hexadecimalNum[i] = 48 + rem;
            else
                hexadecimalNum[i] = 55 + rem;
            i++;
            num = num / 16;
        }

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimalNum[j]);
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Hexadecimal equivalent: ");
    printHexadecimal(num);
    return 0;
}