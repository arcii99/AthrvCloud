//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000] = "This is a secret message";
    char watermark[100] = "My Watermark";
    int watermark_length = strlen(watermark);

    // Convert watermark to binary
    int binary_watermark[1000];
    for (int i = 0; i < watermark_length; i++) {
        int decimal_value = (int)watermark[i];
        for (int j = 0; j < 8; j++) {
            binary_watermark[i*8+j] = (decimal_value >> j) & 1;
        }
    }

    // Insert watermark into message
    for (int i = 0; i < watermark_length*8; i++) {
        if (binary_watermark[i] == 1) {
            message[i] = '1';
        }
    }

    // Read watermark from message
    char extracted_watermark[100];
    for (int i = 0; i < watermark_length; i++) {
        int binary_value = 0;
        for (int j = i*8; j < (i+1)*8; j++) {
            binary_value = binary_value << 1;
            if (message[j] == '1') {
                binary_value++;
            }
        }
        extracted_watermark[i] = (char)binary_value;
    }

    // Print extracted watermark
    printf("Extracted watermark: %s", extracted_watermark);

    return 0;
}