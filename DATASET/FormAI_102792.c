//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QR_CODE_SIZE 21

bool isValidQRCode(char *qrCode) {

    int arr[QR_CODE_SIZE]; // integer array to hold the QR code values

    // convert the QR code string to integer array
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        arr[i] = qrCode[i] - '0';
    }

    int oddSum = 0; // sum of odd positioned digits
    int evenSum = 0; // sum of even positioned digits

    // calculate the sum of odd and even positioned digits
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        if (i % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }

    // check if the sum of odd and even positioned digits is equal
    int sum = oddSum + evenSum;
    return sum % 10 == 0;
}

int main() {
    char qrCode[QR_CODE_SIZE];
    printf("Enter the QR code: ");
    scanf("%s", qrCode);

    if (isValidQRCode(qrCode)) {
        printf("Valid QR code.\n");
    } else {
        printf("Invalid QR code.\n");
    }

    return 0;
}