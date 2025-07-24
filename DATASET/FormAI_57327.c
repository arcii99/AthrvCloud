//FormAI DATASET v1.0 Category: QR code reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random QR code 
int generateCode() {
    srand(time(NULL));
    int code = rand() % 1000000;
    return code;
}

// Function to read QR code 
int readCode() {
    int qr_code;
    printf("Please scan the QR code:\n");
    scanf("%d", &qr_code);
    return qr_code;
}

// Main function
int main() {
    int qr_code = generateCode();
    int scanned_code;

    do {
        scanned_code = readCode();
        if (scanned_code == qr_code) {
            printf("QR code scanned successfully!\n");
        } else {
            printf("Invalid QR code, please try again.\n");
        }
    } while (scanned_code != qr_code);

    return 0;
}