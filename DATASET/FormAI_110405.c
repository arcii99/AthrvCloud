//FormAI DATASET v1.0 Category: QR code generator ; Style: inquisitive
#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int qr_version = 5;
    int qr_error_correction_level = QR_ECLEVEL_Q;
    QRcode *qr_code;
    char *qr_data = "Hello, World!";
    
    qr_code = QRcode_encodeString(qr_data, qr_version, qr_error_correction_level, QR_MODE_8, 1);
    
    if (qr_code) {
        // Print QR code as ASCII art
        for (int y = 0; y < qr_code->width; y++) {
            for (int x = 0; x < qr_code->width; x++) {
                putchar(qr_code->data[y * qr_code->width + x] ? '#' : ' ');
            }
            putchar('\n');
        }
        
        QRcode_free(qr_code);
    } else {
        fprintf(stderr, "Failed to encode QR code\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}