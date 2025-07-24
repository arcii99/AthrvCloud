//FormAI DATASET v1.0 Category: QR code reader ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 50

//Function to check if a given string is a valid QR code
bool is_valid_qr(char* qr_code) {
    if (strlen(qr_code) != 17) {
        return false;
    }
    for (int i = 0; i < 17; i++) {
        if ((qr_code[i] < '0' || qr_code[i] > '9') && (qr_code[i] < 'A' || qr_code[i] > 'Z')) {
            return false;
        }
    }
    return true;
}

//Function to read QR code
void read_qr_code() {
    char qr_code[MAX_SIZE];
    printf("Enter the 17-character QR code: ");
    scanf("%s", qr_code);

    if (is_valid_qr(qr_code)) {
        printf("Valid QR code detected: %s\n", qr_code);
        //Additional processing logic can be added here
    } else {
        printf("Invalid QR code detected!\n");
    }
}

//Main function
int main() {
    printf("C QR Code Reader\n");
    printf("================\n");
    printf("Instructions: Only valid QR codes with 17 characters are accepted.\n");
    printf("Example: ABCDEFGHIJKLMNOPQ\n");
    printf("Enter 'Q' to quit.\n");

    while (true) {
        read_qr_code();
        char c;
        printf("Press 'Enter' to continue or 'Q' to quit: ");
        scanf(" %c", &c);
        if (c == 'Q' || c == 'q') {
            printf("Quitting...\n");
            exit(0);
        }
    }
    return 0;
}