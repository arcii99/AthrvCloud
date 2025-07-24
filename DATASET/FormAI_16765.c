//FormAI DATASET v1.0 Category: QR code reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Error: You need to input a QR code\n");
        return 1;
    }

    char* qrCode = argv[1];

    if(strlen(qrCode) != 21) {
        printf("Error: Invalid QR code\n");
        return 1;
    }

    bool isValid = true;

    for(int i=0; i<21; i++) {
        if(qrCode[i] != 'C' && qrCode[i] != 'Q' && !(qrCode[i] >= '0' && qrCode[i] <= '9')) {
            isValid = false;
            break;
        }
    }

    if(isValid) {
        printf("QR code read successfully! Here's what it says: %s\n", qrCode);
    } else {
        printf("Error: Invalid QR code\n");
        return 1;
    }

    return 0;
}