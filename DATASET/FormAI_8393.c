//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>

int main() {
    int num, temp, rem, i, j = 0;
    char hex[50];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0) {
        rem = temp % 16;

        // If rem < 10, store the ASCII value of the digit
        if (rem < 10) {
            hex[j++] = rem + 48;
        }

        // If rem >= 10, store the appropriate character
        else {
            hex[j++] = rem + 55;
        }

        temp /= 16;
    }

    printf("Hexadecimal representation of %d is: ", num);

    // Display the hexadecimal value
    for (i = j - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }

    return 0;
}