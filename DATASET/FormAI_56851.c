//FormAI DATASET v1.0 Category: QR code reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char qrCode[100];
    printf("Please scan the QR code:\n");
    scanf("%s", qrCode);
    
    // Check if the QR code starts with C
    if (qrCode[0] != 'C') {
        printf("Invalid QR Code!\n");
        return 0;
    }
    
    // Split the QR code into different sections
    char* token;
    char* delim = ",";
    token = strtok(qrCode, delim);
    char company[20];
    memset(company, '\0', 20);
    strcpy(company, &token[1]);  // Ignore the first character (C)
    token = strtok(NULL, delim);
    char product[20];
    memset(product, '\0', 20);
    strcpy(product, token);
    token = strtok(NULL, delim);
    char expiry[20];
    memset(expiry, '\0', 20);
    strcpy(expiry, token);
    
    printf("Scanned QR Code details:\n");
    printf("Company: %s\n", company);
    printf("Product: %s\n", product);
    printf("Expiry Date: %s\n", expiry);
    
    return 0;
}