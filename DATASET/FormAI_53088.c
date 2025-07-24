//FormAI DATASET v1.0 Category: QR code reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 100

bool is_valid_qr_code(char *code) {
    // Check if code starts with 'C' and is 10 characters long
    if (strlen(code) == 10 && code[0] == 'C') {
        // Check if all remaining characters are digits
        for (int i = 1; i < 10; i++) {
            if (!isdigit(code[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void read_qr_codes() {
    char input[MAX_INPUT];
    bool valid;
    int count = 0;
    
    printf("Please scan your C QR code:\n");
    
    while (fgets(input, MAX_INPUT, stdin)) {
        input[strcspn(input, "\n")] = 0; // Remove trailing newline
        valid = is_valid_qr_code(input);
        
        if (valid) {
            printf("Code %d: %s\n", ++count, input);
        } else {
            printf("Invalid QR code: %s\n", input);
        }
        
        printf("Please scan your C QR code (or type 'exit' to quit):\n");
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
    }
}

int main() {
    printf("Welcome to the C QR Code Reader!\n");
    read_qr_codes();
    printf("Thank you for using the C QR Code Reader!\n");
    return 0;
}