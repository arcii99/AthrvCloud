//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_hex(char str[]) {
    int len = strlen(str);
    int num = 0;
    int base = 1;
    int i;

    // Convert hexadecimal to decimal
    for (i = len - 1; i >= 0; i--) {
        if (isdigit(str[i])) {
            num += (str[i] - 48) * base;
            base *= 16;
        }
        else if (isalpha(str[i])) {
            num += (tolower(str[i]) - 87) * base;
            base *= 16;
        }
    }

    // Display the result
    printf("Decimal Equivalent: %d\n", num);
}

int main() {
    char hex[50]; 

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Check if input is a valid hexadecimal number
    for (int i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    convert_hex(hex);

    return 0;
}