//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to generate a random number between 0 and 9 */
int generateRandomNumber() {
    srand(time(NULL));
    int r = rand() % 10;
    return r;
}

/* Function to check if the QR code is valid */
int isQRCodeValid(char* code) {
    int checkSum = 0;
    int len = strlen(code);
    
    /* Add all the values of the QR code and take modulo 10*/
    for (int i = 0; i < len; i++) {
        checkSum += (int)code[i];
    }
    checkSum %= 10;
    
    /* Add the random number generated to the checksum */
    checkSum += generateRandomNumber();
    checkSum %= 10;
    
    /* If the final checksum is 0, then the QR code is valid */
    if (checkSum == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char qrCode[100];
    
    /* Prompt user to input QR code */
    printf("Please input the QR code: ");
    fgets(qrCode, sizeof(qrCode), stdin);
    
    /* Remove newline character from input */
    qrCode[strcspn(qrCode, "\n")] = 0;
    
    /* Check if QR code is valid */
    if (isQRCodeValid(qrCode)) {
        printf("QR code is valid!\n");
    }
    else {
        printf("QR code is not valid!\n");
    }
    
    /* Overwrite input with random characters for security */
    for (int i = 0; i < strlen(qrCode); i++) {
        qrCode[i] = (char)(generateRandomNumber() + 48);
    }
    
    printf("QR code overwritten with random characters!\n");
    
    return 0;
}