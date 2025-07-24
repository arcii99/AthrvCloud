//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convert_hex(char* hex_string);

int main() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a hexadecimal value you would like to convert: ");
    char hex_string[256];
    fgets(hex_string, 256, stdin);
    convert_hex(hex_string);
    return 0;
}

void convert_hex(char* hex_string) {
    int hex_value = 0;
    int length = strlen(hex_string);
    
    if (hex_string[0] == '0' && (hex_string[1] == 'x' || hex_string[1] == 'X')) {
        int i;
        for (i = 2; i < length; i++) {
            if (isdigit(hex_string[i])) {
                hex_value = hex_value * 16 + (hex_string[i] - '0');
            } else if (hex_string[i] >= 'a' && hex_string[i] <= 'f') {
                hex_value = hex_value * 16 + (hex_string[i] - 'a' + 10);
            } else if (hex_string[i] >= 'A' && hex_string[i] <= 'F') {
                hex_value = hex_value * 16 + (hex_string[i] - 'A' + 10);
            } else {
                printf("Invalid Character\n");
                exit(1);
            }
        }
        printf("Decimal value is: %d\n", hex_value);
    } else {
        printf("Invalid Format\n");
        exit(1);
    }
}