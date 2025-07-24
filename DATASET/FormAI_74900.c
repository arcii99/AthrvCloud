//FormAI DATASET v1.0 Category: QR code generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

int main()
{
    char str[100];
    printf("Enter the text you want to generate QR code for: ");
    fgets(str, 100, stdin);

    QRcode *qr = QRcode_encodeString(str, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if(qr) {
        FILE *fp = fopen("qrcode.txt", "w"); // Creates a file named qrcode.txt to save the QR code
        if(fp == NULL) {
            printf("Error creating file!\n");
            exit(1);
        }

        // Writes the QR code into the file
        for(int i = 0; i < qr->width; i++) {
            for(int j = 0; j < qr->width; j++) {
                if(qr->data[i*qr->width+j]&1)
                    fprintf(fp, "  "); // Black Pixel
                else
                    fprintf(fp, "##"); // White Pixel
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
        printf("QR code generated successfully and saved in qrcode.txt file.\n");
    }
    else {
        printf("Error generating QR code!\n");
        exit(1);
    }
    QRcode_free(qr);
    return 0;
}