//FormAI DATASET v1.0 Category: QR code generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void printQRCodeToConsole(QRcode* qrcode);

int main(int argc, char** argv) {
    char* data = "https://www.example.com"; // The data to be encoded into QR code
    QRcode* qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1); // Generate QR code
    
    printQRCodeToConsole(qrcode); // Print QR code to console
    
    QRcode_free(qrcode); // Free memory allocated to QR code
    
    return 0;
}

// Function to print QR code to console
void printQRCodeToConsole(QRcode* qrcode) {
    for(int y = 0; y < qrcode->width; y++) {
        for(int x = 0; x < qrcode->width; x++) {
            if(qrcode->data[x + y*qrcode->width] & 1) {
                printf("\033[40m  \033[0m"); // Black pixel
            } else {
                printf("\033[47m  \033[0m"); // White pixel
            }
        }
        printf("\n");
    }
}