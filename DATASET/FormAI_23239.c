//FormAI DATASET v1.0 Category: QR code reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_CAPACITY 100

typedef struct {
    uint8_t data[MAX_CAPACITY];
    int length;
} QRCode;

bool decode_qr_code(QRCode* qr_code) {
    FILE *fp;
    char path[1035];
 
    fp = popen("zbarimg --raw /path/to/qr/code.png", "r");
    if (fp == NULL) {
        printf("Failed to read QR code.\n" );
        return false;
    }
 
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        for(int i = 0; i < sizeof(path); i++) {
            if(path[i] == '\n') {
                qr_code->data[qr_code->length] = '\0';
                return true;
            }
            qr_code->data[qr_code->length] = path[i];
            qr_code->length++;
        }
    }
    pclose(fp);

    return false;
}

void print_qr_code(QRCode* qr_code) {
    for(int i = 0; i < qr_code->length; i++) {
        printf("%c", qr_code->data[i]);
    }
}

int main() {

    QRCode qr_code;
    qr_code.length = 0;

    if(decode_qr_code(&qr_code)) {
        printf("QR code read successfully!\n");
        print_qr_code(&qr_code);
    } else {
        printf("Failed to read QR code.\n");
    }

    return 0;
}