//FormAI DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[])
{
    int size = 4;
    char *text = "Hello World!";
    QRcode *code = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (code == NULL) {
        printf("Error: Failed to generate QR code.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < code->width; i++) {
        for (int j = 0; j < code->width; j++) {
            if (code->data[i * code->width + j] & 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    QRcode_free(code);
    return EXIT_SUCCESS;
}