//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1024

char* hex_to_bin(char* hex_num) {
    int len = strlen(hex_num);
    char* bin_num = malloc(sizeof(char) * (4 * len));

    for(int i = 0; i < len; i++) {
        char hex_char = hex_num[i];
        int hex_value;

        if(hex_char >= '0' && hex_char <= '9')
            hex_value = hex_char - '0';
        else if(hex_char >= 'a' && hex_char <= 'f')
            hex_value = 10 + hex_char - 'a';
        else if(hex_char >= 'A' && hex_char <= 'F')
            hex_value = 10 + hex_char - 'A';

        for(int j = 3; j >= 0; j--) {
            bin_num[(i * 4) + (3 - j)] = ((hex_value >> j) & 1) ? '1' : '0';
        }
    }

    return bin_num;
}

int main(void) {
    char input[BUFFSIZE];

    printf("Enter a hexadecimal number: ");
    fgets(input, BUFFSIZE, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    printf("Hexadecimal: %s\nBinary: %s\n", input, hex_to_bin(input));

    return 0;
}