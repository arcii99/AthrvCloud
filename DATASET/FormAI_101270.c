//FormAI DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
    char *str_to_encode;
    QRcode* qr;
    int version = 5;
    int width;
    int margin = 2;
    
    printf("-- QR Code Generator --\n\n");
    printf("Enter the text to encode: ");
    scanf("%s", str_to_encode);
    
    qr = QRcode_encodeString(str_to_encode, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        printf("Unable to generate QR code\n");
        return 1;
    }
    
    width = qr->width;
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (qr->data[y * width + x] & 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    printf("\n-- QR Code Generated --\n");
    return 0;
}