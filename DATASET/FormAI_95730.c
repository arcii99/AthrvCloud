//FormAI DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

//Function to generate QR Code
void generateQRCode(char *str, int size) {
    QRcode *qr = QRcode_encodeString(str, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if(qr == NULL) {
        printf("Error: Unable to generate QR Code\n");
        return;
    }
    FILE *fp = fopen("qrcode.txt", "w+");
    if(fp == NULL) {
        printf("Error: Unable to create QR Code File\n");
        QRcode_free(qr);
        return;
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            fprintf(fp, "%c", qr->data[i * size + j] ? '1' : '0');
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    QRcode_free(qr);
    printf("QR Code generated successfully!\n");
}

int main() {
    char str[100];
    printf("Enter the text to generate QR Code: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    generateQRCode(str, strlen(str));
    return 0;
}