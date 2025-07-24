//FormAI DATASET v1.0 Category: QR code generator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h>

int main(int argc, char const *argv[])
{
    QRcode *qrc;
    unsigned char *code;
    char data[256];

    // Input string
    printf("Enter data to be encoded: ");
    scanf("%s", data);

    // QRcode encoding
    qrc = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
 
    // Allocated memory to store the QRcode image
    int qrwidth = qrc->width;
    code = (unsigned char *)malloc(qrwidth * qrwidth);
 
    // Generate QRcode matrix
    for(int y = 0; y < qrwidth; y++) {
        for(int x = 0; x < qrwidth; x++) {
            *(code + y * qrwidth + x) = (*(qrc->data + y * qrwidth + x) & 1) ? '1' : '0';
        }
    }
 
    // Print QRcode image
    for(int y = 0; y < qrwidth; y++) {
        for(int x = 0; x < qrwidth; x++) {
            printf("%c ", *(code + y * qrwidth + x));
        }
        printf("\n");
    }
 
    free(qrc);
    free(code);
    return 0;
}