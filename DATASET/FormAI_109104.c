//FormAI DATASET v1.0 Category: QR code reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define QR_CODE_SIZE 21

int main() {
    char qrCode[QR_CODE_SIZE + 1] = {0};
    bool isCodeScanned = false;

    printf("\n\n==============================================\n\n");
    printf("Welcome to the unique QR Code reader program!\n\n");
    printf("Please scan your QR code to get started.\n\n");

    while (!isCodeScanned) {
        printf("Scanning...");
        sleep(2); // Simulate the QR code scanning process
        printf("\n\n");

        fgets(qrCode, sizeof(qrCode), stdin);

        if (strlen(qrCode) == QR_CODE_SIZE) {
            // Check if its a valid QR code
            printf("You have successfully scanned the following QR code:\n\n");
            printf("%s\n\n", qrCode);
            isCodeScanned = true;
        } else {
            printf("Invalid QR code. Please try again.\n\n");
            memset(qrCode, 0, sizeof(qrCode)); // Clear array for next scan
        }
    }

    printf("Thank you for using the unique QR Code reader program!\n\n");
    printf("Exiting...\n\n");

    return 0;
}