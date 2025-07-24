//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_SIZE 100

int main() {
    char qrCode[MAX_STRING_SIZE];
    bool isQRCode = false;

    printf("Enter the QR code:\n");
    scanf("%s", qrCode);

    // Check if the input code is a valid QR code
    if (strlen(qrCode) == 21 && strncmp(qrCode, "QR-", 3) == 0) {
        isQRCode = true;
    }

    if (isQRCode) {
        printf("Valid QR code detected!\n");
        printf("QR code details:\n");

        // Extracting the data from QR code
        char productId[MAX_STRING_SIZE], productName[MAX_STRING_SIZE], productPrice[MAX_STRING_SIZE];
        sscanf(qrCode, "%*[^-]-%[^-]-%[^-]-%s", productId, productName, productPrice);
        printf("Product ID: %s\n", productId);
        printf("Product Name: %s\n", productName);
        printf("Product Price: %s\n", productPrice);

    } else {
        printf("Invalid QR code detected. Please try again with a valid code.\n");
    }

    return 0;
}