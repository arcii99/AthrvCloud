//FormAI DATASET v1.0 Category: QR code reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[25];
    int size;
} QR_Code;

QR_Code readQRCode(char *filepath) {
    FILE *fp;
    QR_Code qrCode;
    fp = fopen(filepath, "r");

    if(fp == NULL) {
        printf("Error reading file.");
        exit(1);
    }

    char line[25];
    int lineNumber = 0;
    while(fgets(line, sizeof(line), fp)) {
        lineNumber++;

        if(lineNumber == 1) {
            strcpy(qrCode.code, line);
        }
        else if(lineNumber == 2) {
            qrCode.size = atoi(line);
        }
    }

    fclose(fp);
    return qrCode;
}

int main() {
    char filepath[100];
    printf("Enter filepath of QR code file: ");
    scanf("%s", filepath);

    QR_Code qrCode = readQRCode(filepath);

    printf("QR Code: %s\n", qrCode.code);
    printf("Size: %d\n", qrCode.size);

    return 0;
}