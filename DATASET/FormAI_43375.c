//FormAI DATASET v1.0 Category: QR code reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

// Define the size of QR code version to be read
#define QR_VERSION 1

// Define a struct to hold QR code information
struct qr_code {
    uint8_t version;
    uint8_t data[26];
};

// Define a function to read and parse a QR code
int read_qr_code(struct qr_code *code)
{
    // Check if version is supported
    if (code->version != QR_VERSION) {
        printf("QR code version not supported\n");
        return 1;
    }
    
    // Parse data and display result
    char data_str[27];
    memcpy(data_str, code->data, sizeof(code->data));
    data_str[sizeof(data_str) - 1] = '\0';
    printf("QR code data: %s\n", data_str);
    
    return 0;
}

// Define main program function
int main()
{
    // Create a sample QR code
    struct qr_code code = {
        .version = QR_VERSION,
        .data = "Calm QR code example"
    };
    
    // Read and parse QR code
    int result = read_qr_code(&code);
    if (result != 0) {
        printf("Error reading QR code\n");
        return 1;
    }
    
    return 0;
}