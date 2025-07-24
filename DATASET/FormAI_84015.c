//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cryptic_conversion(const char* input) {
    int len = strlen(input);
    char* output = (char*)malloc((len * 8) + 1);
    char* p_out = output;

    for (int i = 0; i < len; i++) {
        char bitmask = 0x01;
        char current_char = input[i];
        for (int j = 0; j < 8; j++) {
            if ((current_char & bitmask) == bitmask) {
                *p_out++ = '1';
            } else {
                *p_out++ = '0';
            }
            bitmask <<= 1;
        }
    }
    *p_out = '\0';
    return output;
}

int main() {
    char input[100];
    char* output;
    printf("Enter a string to convert to binary: ");
    scanf("%s", input);
    output = cryptic_conversion(input);
    printf("Binary: %s\n", output);
    free(output);
    return 0;
}