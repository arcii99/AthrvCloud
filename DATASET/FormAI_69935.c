//FormAI DATASET v1.0 Category: QR code generator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to validate input data
bool validateInputData(char *data) {
    int i = 0;
    while(data[i] != '\0') {
        if(data[i] < 32 || data[i] > 126) {
            return false;
        }
        i++;
    }
    return true;
}

// Function to generate QR code from data
char* generateQRCode(char *data) {
    char *qrCode = (char *)malloc(sizeof(char) * (strlen(data) + 6));
    strcpy(qrCode, "QR-");
    strcat(qrCode, data);
    strcat(qrCode, "-CODE");
    return qrCode;
}

// Main function to generate QR code
int main() {
    char data[100];
    printf("Enter data to generate QR code: ");
    scanf("%[^\n]s", data);

    if(validateInputData(data)) {
        char *qrCode = generateQRCode(data);
        printf("Generated QR code is: %s", qrCode);
        free(qrCode);
    } else {
        printf("Invalid input data!");
    }
    
    return 0;
}