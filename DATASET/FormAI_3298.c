//FormAI DATASET v1.0 Category: QR code reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if the input string is a valid QR code
int isQRCode(char *str) {
    int len = strlen(str);
    if (len != 29) return 0; //QR code must be exactly 29 characters long
    if (strncmp(str, "QR-CODE-", 8) != 0) return 0; //QR code must start with "QR-CODE-"
    for (int i = 8; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'A' && str[i] <= 'F')) {
            return 0; //QR code must contain only hex characters (0-9 and A-F)
        }
    }
    return 1; //input string is a valid QR code
}

//Function to read a QR code from the user
void readQRCode(char *qr) {
    printf("Please enter the QR code: ");
    scanf("%s", qr);
}

//Function to decode a QR code and print the decoded message
void decodeQRCode(char *qr) {
    char decoded[13] = "";
    for (int i = 8; i < 28; i += 2) {
        char temp[3] = {qr[i], qr[i+1], '\0'};
        int val = strtol(temp, NULL, 16); //convert hex string to int
        char c = (char) val;
        strncat(decoded, &c, 1); //append decoded character to decoded message
    }
    printf("Decoded message: %s\n", decoded);
}

//Main function
int main() {
    char qr[30];
    readQRCode(qr);
    if (isQRCode(qr)) {
        decodeQRCode(qr);
    } else {
        printf("Invalid QR code\n");
    }
    return 0;
}