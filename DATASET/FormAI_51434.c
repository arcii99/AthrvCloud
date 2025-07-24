//FormAI DATASET v1.0 Category: QR code generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(void) {
    // First, we prompt the user for the string to encode
    char input_str[1024];
    printf("Enter string to encode: ");
    fgets(input_str, sizeof(input_str), stdin);
    
    // Next, we create a QR code object using the string
    QRcode *qr = QRcode_encodeString(input_str, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    // If QR code creation succeeded, we print the code to the console
    if (qr != NULL) {
        for (int y = 0; y < qr->width; y++) {
            for (int x = 0; x < qr->width; x++) {
                if (qr->data[y * qr->width + x] & 1) {
                    printf("  ");
                } else {
                    printf("██");
                }
            }
            printf("\n");
        }
        QRcode_free(qr);
    } else {
        fprintf(stderr, "Failed to create QR code.\n");
        return 1;
    }
    
    return 0;
}