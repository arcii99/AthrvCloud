//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LEN 16

int validate_hex(char* hex) {
    // Check if hex string is valid
    for (int i = 0; hex[i] != '\0'; i++) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F'))) {
            return 0;
        }
    }
    return 1;
}

unsigned long long hex_to_dec(char* hex) {
    // Convert hex string to decimal
    unsigned long long dec = 0;
    int len = strlen(hex);

    // Increasing power of 16 for each successive digit
    for (int i = 0; hex[i] != '\0'; i++) {
        int val = 0;
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - '0';
        } else {
            val = hex[i] - 'A' + 10;
        }

        int exp = len - i - 1;
        dec += (unsigned long long)val * (unsigned long long)(1ULL << (exp * 4));
    }
    return dec;
}

int main() {
    char hex[MAX_HEX_LEN];
    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_HEX_LEN, stdin);

    // Remove newline character added by fgets
    hex[strcspn(hex, "\n")] = 0;

    if (!validate_hex(hex)) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }

    unsigned long long dec = hex_to_dec(hex);

    printf("Hexadecimal Number: %s\n", hex);
    printf("Decimal Equivalent: %llu\n", dec);
    return 0;
}