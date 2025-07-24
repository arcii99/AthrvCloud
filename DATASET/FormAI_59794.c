//FormAI DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_TEXT_LENGTH 1024

int main() {
    char text[MAX_TEXT_LENGTH];
    QRcode *qr_code;
    int qr_size;
    
    // Take input from user
    printf("Enter the text to convert into QR code: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character
    
    // Generate QR code
    qr_size = 10;
    qr_code = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    // Print QR code to console
    for (int i = 0; i < qr_code->width + 2; i++) {
        printf("██");
    }
    printf("\n");
    for (int i = 0; i < qr_code->width; i++) {
        printf("██");
        for (int j = 0; j < qr_code->width; j++) {
            printf(qr_code->data[i * qr_code->width + j] ? "  " : "██");
        }
        printf("██\n");
    }
    for (int i = 0; i < qr_code->width + 2; i++) {
        printf("██");
    }
    printf("\n");
    
    // Free memory
    QRcode_free(qr_code);
    
    return 0;
}