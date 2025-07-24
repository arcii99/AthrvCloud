//FormAI DATASET v1.0 Category: QR code generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_BUFFER_LENGTH 256

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Error: Invalid arguments.\nUsage: qr_generator <message>\n");
        return 1;
    }

    char *message = argv[1];
    QRcode *qrcode;

    qrcode = QRcode_encodeString(message, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    int size = qrcode->width;
    unsigned char *data = qrcode->data;

    char buffer[MAX_BUFFER_LENGTH];
    memset(buffer, ' ', MAX_BUFFER_LENGTH);

    int x, y;

    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {

            if (data[y*size+x] & 1) {
                buffer[y*MAX_BUFFER_LENGTH+x] = 219;
            } else {
                buffer[y*MAX_BUFFER_LENGTH+x] = 32;
            }

        }
    }

    printf("\n");
    printf("%s\n", buffer);

    QRcode_free(qrcode);

    return 0;
}