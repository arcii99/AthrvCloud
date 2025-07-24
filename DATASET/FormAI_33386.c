//FormAI DATASET v1.0 Category: QR code reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 1024

typedef struct {
    unsigned char data[MAX_QR_CODE_SIZE];
    int size;
} QRCode;

bool readQRCodeFromFile(char *filename, QRCode *qrcode);
bool scanQRCode(QRCode *qrcode);

int main(int argc, char *argv[]) {
    QRCode qrcode;

    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return -1;
    }

    if (!readQRCodeFromFile(argv[1], &qrcode)) {
        printf("Error: Failed to read QR code from file\n");
        return -1;
    }

    if (scanQRCode(&qrcode)) {
        printf("QR code: %s\n", qrcode.data);
    }
    else {
        printf("Error: Failed to scan QR code\n");
        return -1;
    }

    return 0;
}

bool readQRCodeFromFile(char *filename, QRCode *qrcode) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    if (filesize > MAX_QR_CODE_SIZE) {
        fclose(file);
        return false;
    }

    qrcode->size = fread(qrcode->data, 1, filesize, file);

    fclose(file);

    return true;
}

bool scanQRCode(QRCode *qrcode) {
    if (qrcode->size == 0) {
        return false;
    }

    if (qrcode->data[0] != 'Q' || qrcode->data[1] != 'R') {
        return false;
    }

    char *data = (char*)malloc(qrcode->size + 1);
    if (data == NULL) {
        return false;
    }

    memcpy(data, qrcode->data, qrcode->size);
    data[qrcode->size] = '\0';

    // Some example validation checks:
    if (strstr(data, "https://") == NULL) {
        free(data);
        return false;
    }

    if (strlen(data) != qrcode->size) {
        free(data);
        return false;
    }

    free(data);

    return true;
}