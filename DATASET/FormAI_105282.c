//FormAI DATASET v1.0 Category: QR code generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to generate QR code using QRcode library
void generateQRCode(char *string, int version, QRecLevel level, QRcode *qrCode){
    qrCode = QRcode_encodeString(string, version, level, QR_MODE_8, 1);
}

// Function to print QR code to console
void printQRCode(QRcode *qrCode){
    for(int i = 0; i < qrCode->width; i++){
        for(int j = 0; j < qrCode->width; j++){
            if(qrCode->data[i * qrCode->width + j] & 1){
                printf("\u2588"); // Unicode character for a full block
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    char inputString[100];
    printf("Enter the data you want to encode: ");
    scanf("%s", inputString);

    int version = 2; // QR code version (ranges from 1 to 40)
    QRecLevel level = QR_ECLEVEL_L; // Error correction level (L, M, Q, H)

    QRcode *qrCode;
    generateQRCode(inputString, version, level, qrCode);

    printf("=== QR CODE ===\n");
    printQRCode(qrCode);
    printf("===============");

    QRcode_free(qrCode); // Free memory used by QR code

    return 0;
}