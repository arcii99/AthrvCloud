//FormAI DATASET v1.0 Category: QR code generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <text> <file>\n", argv[0]);
        return 1;
    }
    
    // Create QR code
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        printf("Error: Failed to encode QR code\n");
        return 1;
    }
    
    // Open file
    FILE *fout = fopen(argv[2], "wb");
    if (!fout) {
        printf("Error: Failed to open file %s\n", argv[2]);
        QRcode_free(qrcode);
        return 1;
    }
    
    // Write QR code to file
    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++) {
            int val = qrcode->data[i * qrcode->width + j];
            fputc(val ? '#' : '.', fout);
        }
        fputc('\n', fout);
    }
    
    // Clean up
    fclose(fout);
    QRcode_free(qrcode);
    
    return 0;
}