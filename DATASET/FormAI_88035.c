//FormAI DATASET v1.0 Category: QR code reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_QR_CODE_LENGTH 20

bool validate_qr_code(char qr_code[]) {
    int qr_code_length = strlen(qr_code);
    if (qr_code_length != MAX_QR_CODE_LENGTH) {
        return false;
    }
    for (int i = 0; i < qr_code_length; i++) {
        if (!isdigit(qr_code[i])) {
            return false;
        }
    }
    return true;
}

int read_qr_code() {
    char input[MAX_INPUT_LENGTH];
    printf("Please input a QR code: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    int input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
    }
    if (!validate_qr_code(input)) {
        printf("Error: Invalid QR code. Please try again.\n");
        return read_qr_code();
    }
    int qr_code = atoi(input);
    return qr_code;
}

int main() {
    int qr_code = read_qr_code();
    printf("QR code input successful. The code you entered is: %d\n", qr_code);
    return 0;
}