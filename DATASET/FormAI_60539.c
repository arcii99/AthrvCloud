//FormAI DATASET v1.0 Category: QR code generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_CODE_SIZE 21

int main(int argc, char **argv) {

    // Get user input
    char user_string[QR_CODE_SIZE];
    printf("Enter string to encode as QR code: ");
    fgets(user_string, QR_CODE_SIZE, stdin);
    user_string[strcspn(user_string, "\n")] = 0;

    // Encode user input as QR code
    QRcode *qrcode = QRcode_encodeString(user_string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    // Print QR code to console
    for (int i = 0; i < qrcode->width + 4; i++) {
        printf("\033[47m  \033[0m");
    }
    printf("\n");
    for (int i = 0; i < qrcode->width; i++) {
        printf("\033[47m  \033[0m");
        for (int j = 0; j < qrcode->width; j++) {
            if (qrcode->data[i * qrcode->width + j] & 1) {
                printf("\033[40m  \033[0m");
            } else {
                printf("\033[47m  \033[0m");
            }
        }
        printf("\033[47m  \033[0m\n");
    }
    for (int i = 0; i < qrcode->width + 4; i++) {
        printf("\033[47m  \033[0m");
    }
    printf("\n");

    // Free memory allocated to QR code
    QRcode_free(qrcode);
    
    return 0;
}