//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    // "The game is afoot!"
    printf("Enter a decimal number: ");
    int decimal;
    scanf("%d", &decimal);

    printf("The hexadecimal conversion of %d is: ", decimal);

    char hex[100];
    int i = 0;

    // "Elementary, my dear Watson."
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;  // ASCII code of '0' is 48
        } else {
            hex[i] = remainder + 55;  // ASCII code of 'A' is 65, so we add 55 to get the ASCII code of the respective letter
        }
        i++;
        decimal /= 16;
    }

    // "The curious incident of the dog in the nighttime"
    printf("0x");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");

    return 0;
}