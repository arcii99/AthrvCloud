//FormAI DATASET v1.0 Category: QR code generator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {

    char input[1000];
    printf("Enter the text to generate QR code:\n");
    fgets(input, sizeof(input), stdin);

    QRcode *qr;
    unsigned char *row;
    int i, j;

    qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    for(i=0; i<qr->width; i++){
        row = qr->data + i*qr->width;
        for(j=0; j<qr->width; j++){
            if (*row & 1) {
                printf(" ");
            } else {
                printf("#");
            }
            row++;   
        }
        printf("\n");
    }

    QRcode_free(qr);
    return 0;
}