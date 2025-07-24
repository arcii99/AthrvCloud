//FormAI DATASET v1.0 Category: QR code generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a unique QR code
void generateQRCode(char* qrCode) {
    char characters[62] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int codeLength = 10; // Length of the QR code
    
    //Generate a random seed
    srand((unsigned) time(NULL));
    
    for (int i = 0; i < codeLength; i++) {
        int randomIndex = rand() % 62; // Get a random index from the characters array
        qrCode[i] = characters[randomIndex]; // Add the character to the QR code
    }
    
    qrCode[codeLength] = '\0'; // Terminate the QR code string with the null character
}

int main() {
    char qrCode[11]; // Array to hold the QR code

    generateQRCode(qrCode); // Generate the QR code
    
    // Print the QR code to the terminal
    printf("QR Code: \n");
    for (int i = 0; i < strlen(qrCode); i++) {
        printf("%c", qrCode[i]);
    }
    printf("\n");
    
    return 0;
}