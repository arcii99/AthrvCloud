//FormAI DATASET v1.0 Category: QR code generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    char data[1024];
    int index = 0;
    printf("Enter the data to be encoded as QR code: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0;   // Remove the trailing newline

    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    FILE *fp;
    fp = fopen("qrcode.html", "w");
    fprintf(fp, "<!DOCTYPE html>\n<html>\n<head>\n<title>QR Code</title>\n</head>\n<body>\n");
    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++, index++) {
            if (qrcode->data[index] & 1) {
                fprintf(fp, "<div style=\"width:10px;height:10px;background-color:black;float:left;\"></div>");
            } else {
                fprintf(fp, "<div style=\"width:10px;height:10px;background-color:white;float:left;\"></div>");
            }
        }
        fprintf(fp, "<div style=\"clear:both;\"></div>");
    }
    fprintf(fp, "</body>\n</html>");
    fclose(fp);

    printf("QR code has been saved as qrcode.html!\n");

    return 0;
}