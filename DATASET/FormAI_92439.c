//FormAI DATASET v1.0 Category: QR code generator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h>

int main(){

    // user input
    char input[50];
    printf("Enter text to generate QR code: ");
    scanf("%s", input);

    // Encode input to QR code
    QRcode *qr;
    qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Write QR code to file
    FILE *fp;
    fp = fopen("qr-code.png", "wb");
    fwrite(qr->data, qr->width, qr->width, fp);
    fclose(fp);

    // Output success message
    printf("QR code generated successfully and saved to qr-code.png!\n");

    // Free memory
    QRcode_free(qr);

    return 0;
}