//FormAI DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 256

bool is_valid_qr_code(const char* qr_code) {
    /* Checks if the qr code meets the required format */
    /* E.g. It should start with "QR-", followed by a 6-digit number and a hyphen, followed by a 4-letter string */
    const char* valid_pattern = "QR-[0-9]{6}-[a-zA-Z]{4}";
    return (bool) (strlen(qr_code) == strlen(valid_pattern) && strncmp(qr_code, valid_pattern, strlen(valid_pattern)) == 0);
}

void read_qr_code(char* qr_code) {
    /* Helper function that prompts and reads in the qr code */
    printf("Please scan the QR code: ");
    fgets(qr_code, MAX_QR_CODE_LENGTH, stdin);
}

void decode_qr_code(const char* qr_code, char* decoded_data) {
    /* Strips the meaningful data from the qr code */
    /* E.g. QR-123456-ABCD -> 123456-ABCD */
    const char* data_start = qr_code + 3; /* Skip past "QR-" at the start */
    const char* data_end = strchr(qr_code, '\n'); /* Strip the newline at the end */
    int data_length = (int) (data_end - data_start);
    strncpy(decoded_data, data_start, data_length);
    decoded_data[data_length] = '\0';
}

int main() {
    char qr_code[MAX_QR_CODE_LENGTH];
    char decoded_data[MAX_QR_CODE_LENGTH - 4]; /* Maximum length of data portion of qr code */

    while (true) {
        /* Continuously prompt user to scan qr code until a valid one is read */
        read_qr_code(qr_code);

        if (is_valid_qr_code(qr_code)) {
            /* If qr code format is valid, decode it and output the results */
            decode_qr_code(qr_code, decoded_data);
            printf("QR code scanned!\n");
            printf("Data: %s\n", decoded_data);
            break;
        } else {
            /* If qr code format is invalid, prompt the user to try again */
            printf("Invalid QR code format! Please try again.\n");
        }
    }

    return 0;
}