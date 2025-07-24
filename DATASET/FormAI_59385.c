//FormAI DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void generateQRCode(char *data, int size, char *path) {
    QRcode *qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    unsigned char *dataBuffer = qr->data;
    int dimension = qr->width;
    FILE *file = fopen(path,"wb");
    for(int i=0; i<dimension; i++) {
        for(int j=0; j<dimension; j++) {
            fprintf(file,"%c", dataBuffer[i*dimension+j]? '1' : '0');
        }
        fprintf(file,"\n");
    }
    fclose(file);
    QRcode_free(qr);
}

int main() {
    char *data = "Hello, World!";
    int size = strlen(data);
    char *path = "qrcode.pgm";
    generateQRCode(data, size, path);
    printf("QR Code generated successfully\n");
    return 0;
}