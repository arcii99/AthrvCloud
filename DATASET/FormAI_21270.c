//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 256

bool checkQRCode(const char *qrString) {
    // Checks the validity of the QR code string
    int len = strlen(qrString);

    if (len != 21) {
        return false;
    }

    int checksum = 0;

    for (int i = 0; i < len-1; i++) {
        if (qrString[i] < '0' || qrString[i] > '9') {
            return false;
        }

        checksum += qrString[i] - '0';
    }

    int expectedChecksum = (10 - (checksum % 10)) % 10;
    int actualChecksum = qrString[len-1] - '0';

    if (actualChecksum != expectedChecksum) {
        return false;
    }

    return true;
}

int main(void) {
    char qrString[MAX_LENGTH];

    printf("Enter QR code string: ");
    fgets(qrString, MAX_LENGTH, stdin);

    // Remove newline character from input
    qrString[strcspn(qrString, "\n")] = '\0';

    if (checkQRCode(qrString)) {
        printf("Valid QR code!\n");
    } else {
        printf("Invalid QR code.\n");
        exit(EXIT_FAILURE);
    }

    // QR code is valid, extract information
    char name[MAX_LENGTH];
    char age[MAX_LENGTH];
    char gender[MAX_LENGTH];

    strncpy(name, qrString, 8);
    name[8] = '\0';

    strncpy(age, qrString+8, 2);
    age[2] = '\0';

    strncpy(gender, qrString+10, 1);
    gender[1] = '\0';

    printf("Name: %s\nAge: %s\nGender: %s\n", name, age, gender);

    return 0;
}