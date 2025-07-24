//FormAI DATASET v1.0 Category: QR code generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    
    char *input;
    if (argc < 2) {
        printf("Please input your message:\n");
        fgets(input, 100, stdin);
    }
    else {
        input = argv[1];
    }

    int version = 1;
    int level = QR_ECLEVEL_L;
    int width = 256;
    QRcode *qr;
    unsigned char *row;
    int i,j;
    int size;
    
    qr = QRcode_encodeString(input, 0, level, QR_MODE_8, 1);
    size = qr->width * width;
    row = (unsigned char *) malloc(size);
    
    for (i = 0; i < qr->width; i++) {
        memset(row, 255, size);
        for (j = 0; j < qr->width; j++) {
            if (qr->data[i * qr->width + j] & 1) {
                memset(&row[j * width], 0, width);
            }
        }
        fwrite(row, 1, size, stdout);
    }
    
    printf("\nQR code generated successfully!\n");

    free(input);
    free(row);
    QRcode_free(qr);
    
  return 0;
}