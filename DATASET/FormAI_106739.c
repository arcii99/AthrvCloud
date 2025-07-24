//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to the HEX CONVERTER! Let's get started...\n");
    printf("Enter any decimal number: ");
    int decimal;
    scanf("%d", &decimal);
    printf("Oops! You entered decimal %d...wait for it...\n", decimal);
    printf("Converting to HEX...beep boop bop...\n");
    int bits[100], i = 0, j;
    while (decimal != 0) {
        bits[i] = decimal % 16;
        decimal = decimal / 16;
        i++;
    }
    printf("Hex value of input decimal is: 0x");
    for (j = i - 1; j >= 0; j--) {
        if (bits[j] > 9) {
            printf("%c", bits[j] + 55);
        } else {
            printf("%d", bits[j]);
        }
    }
    printf("\nMission accomplished! Isn't that amazing? Want to try again? Y/N: ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        main();
    }
    printf("Goodbye!\n");
    return 0;
}