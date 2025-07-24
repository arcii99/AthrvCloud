//FormAI DATASET v1.0 Category: QR code reader ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define QR_CODE_SIZE 21
#define MAX_QR_CODES 5

char qr_codes[MAX_QR_CODES][QR_CODE_SIZE] = {"JW2F-QGHT-4MDV-336T-CV8M",
                                             "B959-TKJS-1RUL-OR5E-9D1S",
                                             "I2F6-73O5-VNHZ-TX8W-PK0Q",
                                             "FNXW-0U2J-7Y5V-XS1Q-4D3D",
                                             "L3R9-56SD-PL8N-9VFW-0HQK"};

char* clean_input(char* input) {
    int input_len = strlen(input);
    char* cleaned_input = malloc(input_len + 1);
    memset(cleaned_input, 0, input_len + 1);
    for(int i = 0; i < input_len; i++) {
        if(isalnum(input[i]))
            cleaned_input[strlen(cleaned_input)] = toupper(input[i]);
    }
    return cleaned_input;
}

bool is_qr_code(char* input) {
    char* cleaned_input = clean_input(input);
    for(int i = 0; i < MAX_QR_CODES; i++) {
        if(strcmp(cleaned_input, qr_codes[i]) == 0) {
            free(cleaned_input);
            return true;
        }
    }
    free(cleaned_input);
    return false;
}

int main() {
    char input[QR_CODE_SIZE];
    printf("Enter a QR code: ");
    scanf("%s", input);
    if(is_qr_code(input))
        printf("Valid QR code!\n");
    else
        printf("Invalid QR code.\n");
    return 0;
}