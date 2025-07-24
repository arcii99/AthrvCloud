//FormAI DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "qrencode.h"

// Function to generate a random character
char random_char() {
    char c = (rand() % 26) + 'a';
    return c;
}

// Function to generate a random string
void random_string(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = random_char();
    }
    str[length] = '\0';
}

int main() {
    int version = 6;
    int level = QR_ECLEVEL_L;
    QRcode *code;
    char data[100];
    // Generate random string
    random_string(data, 10);
    // Encode data into QR code
    code = QRcode_encodeString(data, 0, level, QR_MODE_8, 1);
    // Print QR code
    for (int y = 0; y < code->width; y++) {
        for (int x = 0; x < code->width; x++) {
            if (code->data[y * code->width + x] & 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    // Free QR code memory
    QRcode_free(code);
    return 0;
}