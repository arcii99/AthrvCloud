//FormAI DATASET v1.0 Category: QR code reader ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char qr_code[101];
    printf("Enter QR code: ");
    scanf("%100[^\n]", qr_code);
    
    if (strlen(qr_code) < 21) {
        printf("Invalid QR code!");
        return 0;
    }
    
    int sum = 0;
    for (int i = 0; i < strlen(qr_code); i++) {
        sum += qr_code[i] - '0';
    }
    
    if (sum % 7 == 0) {
        printf("Valid QR code!\nData:\n");
        int data_length = qr_code[20] - '0';
        char* data = (char*)malloc(sizeof(char) * (data_length + 1));
        strncpy(data, &qr_code[21], data_length);
        data[data_length] = '\0';
        printf("%s", data);
    } else {
        printf("Invalid QR code!");
    }
    
    return 0;
}