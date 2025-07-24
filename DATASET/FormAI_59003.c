//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hex string to int
int hex_to_int(char hex[]) {
    int len = strlen(hex);
    int val = 0;
    for (int i = 0; i < len; i++) {
        int c = hex[i];
        if (c >= '0' && c <= '9') {
            val += (c - '0') * (1 << (4 * (len - 1 - i)));
        } else if (c >= 'A' && c <= 'F') {
            val += (c - 'A' + 10) * (1 << (4 * (len - 1 - i)));
        } else if (c >= 'a' && c <= 'f') {
            val += (c - 'a' + 10) * (1 << (4 * (len - 1 - i)));
        } else {
            return -1;  // Invalid hex string
        }
    }
    return val;
}

// Function to convert int to hex string
char* int_to_hex(int val) {
    char* hex = malloc(7*sizeof(char));
    sprintf(hex, "#%02X%02X%02X", (val & 0xFF0000) >> 16,
                                  (val & 0x00FF00) >> 8,
                                  (val & 0x0000FF));
    return hex;
}

int main() {
    char input[100];
    while (1) {
        printf("Enter a hex color code (e.g. #FF0000): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Check for quit command
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Convert input to int and handle errors
        int val = hex_to_int(input);
        if (val == -1) {
            printf("Invalid hex color code\n");
            continue;
        }

        // Convert int to hex string and print
        char* hex = int_to_hex(val);
        printf("RGB color: %s\n", hex);
        free(hex);
    }
    return 0;
}