//FormAI DATASET v1.0 Category: QR code generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    // Variables for reading user input
    char text[1000];
    printf("Enter the text you want to encode into a QR Code: ");
    fgets(text, sizeof(text), stdin);

    // Remove the newline character from the input
    text[strcspn(text, "\n")] = '\0';

    // Generate the QR Code
    QRcode *code;
    code = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Check if the code was generated successfully
    if (code == NULL) {
        fprintf(stderr, "Failed to generate QR Code: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Print the QR Code to the console
    for (int y = 0; y < code->width; y++) {
        for (int x = 0; x < code->width; x++) {
            if (code->data[y * code->width + x] & 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    // Clean up the memory used by the QR Code
    QRcode_free(code);
    return EXIT_SUCCESS;
}