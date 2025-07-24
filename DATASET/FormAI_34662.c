//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>

int main() {
    int decimal;
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);

    char hexadecimal[16];
    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }

    printf("\nThe hexadecimal equivalent is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");

    return 0;
}