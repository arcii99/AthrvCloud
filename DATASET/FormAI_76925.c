//FormAI DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char binary[100];
    int decimal = 0;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    if (strlen(binary) > 8) {
        printf("Sorry, the binary number must be less than 8 bits!\n");
        return 1;
    }

    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Sorry, the binary number can only contain 0's and 1's!\n");
            return 1;
        }
    }

    for (int i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
        decimal += (binary[i] - '0') * (1 << j);
    }

    printf("The decimal representation of %s is %d.\n", binary, decimal);

    return 0;
}