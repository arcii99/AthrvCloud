//FormAI DATASET v1.0 Category: QR code generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    int version = 1;
    QRecLevel eclevel = QR_ECLEVEL_L;
    int width = 256, height = 256;
    
    char* text = "Hello World"; //the text you want to generate the QR code for

    QRcode* qrcode = QRcode_encodeString(text, version, eclevel, QR_MODE_8, 1);
    if(qrcode == NULL) {
        printf("Error: Failed to generate QR code!\n");
        return -1;
    }
    
    FILE* fp;
    fp = fopen("qrcode.txt", "wb");
    if(fp == NULL) {
        printf("Error: Failed to open file!");
        QRcode_free(qrcode);
        return -1;
    }
    
    int x, y;
    for(y = 0; y < qrcode->width; y++) {
        for(x = 0; x < qrcode->width; x++) {
            int point = (y * qrcode->width) + x;
            fprintf(fp, "%c", (qrcode->data[point] & 1) ? '#' : ' ');
        }
        fprintf(fp, "\n");
    }

    printf("QR code generated and saved to file!\n");
    fclose(fp);
    QRcode_free(qrcode);
    return 0;
}