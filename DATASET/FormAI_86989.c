//FormAI DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    // read user input
    char input[128];
    printf("Enter input to generate QR code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline

    // create QR code from input
    QRcode *qrcode;
    qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        printf("Error generating QR code.\n");
        exit(EXIT_FAILURE);
    }

    // print QR code image
    int size = qrcode->width + 4;
    for (int i = -2; i < size - 2; i++) {
        for (int j = -2; j < size - 2; j++) {
            if (i < 0 || j < 0 || i >= qrcode->width || j >= qrcode->width) {
                printf("  ");
            }
            else {
                printf("%c%c", qrcode->data[i*qrcode->width+j] ? '#' : ' ', qrcode->data[i*qrcode->width+j] ? '#' : ' ');
            }
        }
        printf("\n");
    }

    // free memory
    QRcode_free(qrcode);

    return 0;
}