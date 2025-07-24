//FormAI DATASET v1.0 Category: QR code reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 500

bool is_valid_qr_code(char* qr_code) {
    int len = strlen(qr_code);
    if (len != 25) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (qr_code[i] < '0' || qr_code[i] > '9') {
            return false;
        }
    }
    return true;
}

int get_qr_code_sum(char* qr_code) {
    int sum = 0;
    for (int i = 0; i < strlen(qr_code); i++) {
        sum += qr_code[i] - '0';
    }
    return sum;
}

int main(void) {
    char qr_code[MAX_QR_CODE_SIZE];
    printf("Welcome to the cheerful QR code reader program!\n");
    printf("Please enter a valid QR code: ");
    scanf("%s", qr_code);
    while (!is_valid_qr_code(qr_code)) {
        printf("Invalid QR code. Please enter a valid QR code: ");
        scanf("%s", qr_code);
    }
    printf("Your QR code is valid!\n");

    int sum = get_qr_code_sum(qr_code);
    printf("The sum of your QR code digits is: %d\n", sum);

    printf("We hope you enjoyed using our program! Goodbye!\n");

    return EXIT_SUCCESS;
}