//FormAI DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define QR_CODE_LENGTH 21

// generate a unique QR code
void generateQRCode(char* qrCode){
    char validChars[36] = "0123456789ABCDEFHIJKLMNOPQRSTUVWXYZ";
    int i;

    // generate random QR code
    for(i = 0; i < QR_CODE_LENGTH; i++){
        qrCode[i] = validChars[rand() % 36];
    }
    qrCode[i] = '\0';
}

// main function
int main(){
    int i, j;
    char qrCode[QR_CODE_LENGTH];

    // generate a QR code
    generateQRCode(qrCode);

    // print QR code
    printf("QR Code: ");
    for(i = 0; i < QR_CODE_LENGTH; i++){
        if(i % 5 == 0 && i != 0){
            printf(" ");
        }
        printf("%c", qrCode[i]);
    }
    printf("\n");

    return 0;
}