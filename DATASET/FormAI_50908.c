//FormAI DATASET v1.0 Category: QR code generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
    char text[100];
    QRcode *qrcode;
    unsigned char *row, *p, *q;
    int width, x, y, len;

    printf("Enter the text you want in the QR code: ");
    fgets(text, sizeof(text), stdin);
    len = strlen(text);
    if (len > 0 && text[len-1] == '\n') {
        text[len-1] = '\0';
        len--;
    }

    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("QR code generation failed\n");
        exit(EXIT_FAILURE);
    }

    width = qrcode->width;
    row = (unsigned char *)malloc((width+1)*sizeof(unsigned char));
    if (row == NULL) {
        printf("Memory allocation error\n");
        QRcode_free(qrcode);
        exit(EXIT_FAILURE);
    }

    for (y = 0; y < width; y++) {
        p = qrcode->data + y*qrcode->width;
        for (x = 0; x < width; x++) {
            q = p + x;
            if (*q & 1) {
                row[x] = ' ';
            } else {
                row[x] = '\u2588';
            }
        }
        row[width] = '\0';
        printf("%s\n", row);
    }
    QRcode_free(qrcode);
    free(row);

    return 0;
}