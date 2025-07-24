//FormAI DATASET v1.0 Category: QR code generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_QR_CODE_SIZE 512

int main(void) {

    char qr_code[MAX_QR_CODE_SIZE];
    int version = 1, data_capacity, error_correction_level;
    char input_data[256];
    bool running = true;

    while (running) {
        printf("Please enter the data you want to encode: ");
        fgets(input_data, sizeof(input_data), stdin);
        input_data[strcspn(input_data, "\n")] = '\0';

        // Determine the optimal version and error correction level based on the input data
        data_capacity = strlen(input_data) * 8;
        if (data_capacity <= 152) {
            version = 1;
            error_correction_level = 0;
        } else if (data_capacity <= 272) {
            version = 2;
            error_correction_level = 1;
        } else if (data_capacity <= 440) {
            version = 3;
            error_correction_level = 2;
        } else if (data_capacity <= 640) {
            version = 4;
            error_correction_level = 3;
        } else if (data_capacity <= 864) {
            version = 5;
            error_correction_level = 4;
        } else if (data_capacity <= 1088) {
            version = 6;
            error_correction_level = 5;
        } else if (data_capacity <= 1248) {
            version = 7;
            error_correction_level = 6;
        } else {
            printf("Error: Input data too large to encode in a QR code");
            continue;
        }

        // Generate the QR code string using the chosen version and error correction level
        snprintf(qr_code, sizeof(qr_code),
            "Version=%d, Error Correction Level=%d, Data=%s, Timestamp=%ld",
            version, error_correction_level, input_data, time(NULL));

        printf("QR code generated: %s\n", qr_code);
    }

    return EXIT_SUCCESS;
}