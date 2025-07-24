//FormAI DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

char* generateQRCode(char* data) {
    char* qrCode = (char*) malloc(SIZE * sizeof(char)); // Allocate memory for the QR code string
    strcpy(qrCode, "QRCode: "); // Start with the QRCode: prefix
    strcat(qrCode, data); // Append the data to the qrCode string
    strcat(qrCode, "\n"); // Add a newline character at the end
    return qrCode; // Return the generated QR code
}

int main() {
    char data[SIZE]; // Allocate space for the QR code data
    printf("Enter data for the QR code: ");
    scanf("%s", data); // Get input data from the user
    char* qrCode = generateQRCode(data); // Generate the QR code
    printf("QR code generated: %s", qrCode); // Print the generated QR code
    free(qrCode); // Free the allocated memory
    return 0; // Exit the program
}