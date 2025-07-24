//FormAI DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
    QRcode *qrcode;
    QRinput *qrinput;
    unsigned char *string;
    int i, j, size;
    char input[256];

    printf("Enter the text you want to encode as QR code: ");
    scanf("%s", input);

    qrinput = QRinput_new();
    QRinput_append(qrinput, QR_MODE_8, strlen(input), (unsigned char*)input);

    qrcode = QRcode_encodeInput(qrinput);
    size = qrcode->width;

    // Print QR code as ASCII art
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (qrcode->data[i*size + j] & 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    QRinput_free(qrinput);
    QRcode_free(qrcode);

    return 0;
}