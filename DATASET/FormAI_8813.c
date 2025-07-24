//FormAI DATASET v1.0 Category: QR code reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT_LENGTH 1024

bool isValidQR(char* qrString) {
    if (strlen(qrString) != 17) {
        return false;
    }
    for (int i = 0; i < 17; i++) {
        if (i == 4 || i == 9) {
            if (qrString[i] != '-') {
                return false;
            }
        } else if (!isdigit(qrString[i])) {
            return false;
        }
    }
    return true;
}

bool verifyChecksum(char* qrString) {
    int checksum = 0;
    int weights[] = {7, 3, 1};
    for (int i = 0; i < 14; i++) {
        if (i == 4 || i == 9) {
            continue;
        }
        checksum += weights[i % 3] * (qrString[i] - '0');
    }
    int calculatedCheck = (checksum % 10);
    int actualCheck = (int)(qrString[15] - '0');
    return calculatedCheck == actualCheck;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char qr[MAX_INPUT_LENGTH];
    printf("Welcome to the QR code reader.\n");
    printf("Please enter a valid QR code in the format '1234-5678-9012-3':\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    if (strlen(input) > 0 && input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    if (!isValidQR(input)) {
        printf("Invalid QR code format.\n");
        return EXIT_FAILURE;
    } else if (!verifyChecksum(input)) {
        printf("QR code checksum failed.\n");
        return EXIT_FAILURE;
    } else {
        memcpy(qr, input, strlen(input) + 1);
        srand(time(NULL));
        int randomNumber = rand() % 1000;
        printf("QR code scanned successfully.\n");
        printf("Congratulations, you have won %d points!\n", randomNumber);
        return EXIT_SUCCESS;
    }
}