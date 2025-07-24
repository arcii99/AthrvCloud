//FormAI DATASET v1.0 Category: QR code reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21

int main() {
    char qr_code[QR_CODE_SIZE];
    
    // prompt user to enter QR code
    printf("Enter QR code: ");
    scanf("%s", qr_code);
    
    // check if QR code is valid
    if (strlen(qr_code) != QR_CODE_SIZE) {
        printf("Invalid QR code.\n");
        return 1;
    }
    
    // check if QR code starts with "CQR"
    if (strncmp(qr_code, "CQR", 3) != 0) {
        printf("Invalid QR code.\n");
        return 1;
    }
    
    // extract data from QR code
    char data[16];
    strncpy(data, qr_code + 3, 16);
    data[16] = '\0';
    
    // print extracted data
    printf("QR code data: %s\n", data);
    
    return 0;
}