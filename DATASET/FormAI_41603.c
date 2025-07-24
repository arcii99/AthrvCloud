//FormAI DATASET v1.0 Category: QR code generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <text to encode>\n", argv[0]);
        return 1;
    }

    const char *text = argv[1];
    const int size = strlen(text);

    // Create QR code object
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Print out QR code
    for (int y=0; y<qrcode->width; y++)
    {
        for (int x=0; x<qrcode->width; x++)
        {
            printf("%c", (qrcode->data[y*qrcode->width+x]&1)?'\x20':'\x28');
        }
        printf("\n");
    }

    // Clean up and exit
    QRcode_free(qrcode);
    return 0;
}