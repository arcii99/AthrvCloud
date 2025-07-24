//FormAI DATASET v1.0 Category: QR code generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
    char data[100];
    int size = 300;
    QRcode *qr;
    
    printf("Enter data to generate QR code: ");
    scanf("%s", data);
    
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("\033[40m  \033[0m");
            } else {
                printf("\033[47m  \033[0m");
            }
        }
        printf("\n");
    }
    QRcode_free(qr);
    
    return 0;
}