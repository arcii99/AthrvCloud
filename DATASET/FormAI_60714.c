//FormAI DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter the text you want to generate QR code for: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Removing the newline character from input

    QRcode* code = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (code == NULL) {
        fprintf(stderr, "Could not generate QR code for the given input");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < code->width + 2; i++) {
        printf("##");
    }
    printf("\n");

    for (int y = 0; y < code->width; y++) {
        printf("##");
        for (int x = 0; x < code->width; x++) {
            printf((code->data[y * code->width + x] & 1) ? "  " : "##");
        }
        printf("##\n");
    }

    for (int i = 0; i < code->width + 2; i++) {
        printf("##");
    }
    printf("\n");

    QRcode_free(code);
    return EXIT_SUCCESS;
}