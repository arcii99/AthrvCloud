//FormAI DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_PAYLOAD_LENGTH 1000

int main() {
    // Allocate memory to store QR code text data
    char* qrCodeText = (char*)malloc(MAX_PAYLOAD_LENGTH * sizeof(char));
    
    // Get input from user
    printf("Enter QR code text (max %d characters): ", MAX_PAYLOAD_LENGTH);
    scanf("%s", qrCodeText);
    
    // Generate QR code image from text data
    int version = 1;
    int level = QR_ECLEVEL_L;
    QRcode* qrCode = QRcode_encodeString(qrCodeText, 0, level, QR_MODE_8, 1);
    
    // Print QR code data to console
    printf("QR code data:\n");
    for (int i = 0; i < qrCode->width; i++) {
        for (int j = 0; j < qrCode->width; j++) {
            putchar(qrCode->data[i * qrCode->width + j] ? '#' : ' ');
        }
        printf("\n");
    }
    
    // Free allocated memory
    free(qrCodeText);
    QRcode_free(qrCode);
    
    return 0;
}