//FormAI DATASET v1.0 Category: QR code reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

// Function to check if the given string is a QR code
bool isQRCode(char *str) {
    int len = strlen(str);
    if(len == 0 || len % 2 == 1) {
        return false;
    }
    for(int i = 0; i < len; i++) {
        if(str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

// Function to convert a QR code string to binary
void QRCodeToBinary(char *str, char *binary) {
    int len = strlen(str);
    for(int i = 0; i < len; i+=2) {
        if(str[i] == '0' && str[i+1] == '0') {
            strcat(binary, "0000");
        } else if(str[i] == '0' && str[i+1] == '1') {
            strcat(binary, "0001");
        } else if(str[i] == '1' && str[i+1] == '0') {
            strcat(binary, "0010");
        } else if(str[i] == '1' && str[i+1] == '1') {
            strcat(binary, "0011");
        }
    }
}

// Function to read a QR code from the user
void readQRCode(char *QRCode) {
    printf("Please scan the QR code:\n");
    fgets(QRCode, MAX_STRING_LENGTH, stdin);
    // Remove the newline character from the end of the string
    QRCode[strcspn(QRCode, "\n")] = 0;
}

int main() {
    char QRCode[MAX_STRING_LENGTH];
    char binary[MAX_STRING_LENGTH] = "";
    printf("Welcome to the QR code reader app!\n");
    while(true) {
        readQRCode(QRCode);
        if(isQRCode(QRCode)) {
            QRCodeToBinary(QRCode, binary);
            printf("QR code detected and converted to binary: %s\n", binary);
            break;
        } else {
            printf("Invalid QR code. Please try again.\n");
        }
    }
    return 0;
}