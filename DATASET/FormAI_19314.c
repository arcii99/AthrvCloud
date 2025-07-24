//FormAI DATASET v1.0 Category: QR code generator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int modules;
    char *data;
} QR_Code;

QR_Code generateQRCode(char *data, int modules){
    QR_Code qrCode = {modules, data};
    return qrCode;
}

void printQRCode(QR_Code qrCode){
    printf("QR Code with %d modules and data: %s \n", qrCode.modules, qrCode.data);
}

int main(){
    char *data = "Hello World";
    QR_Code qrCode = generateQRCode(data, strlen(data));
    printQRCode(qrCode);

    return 0;
}