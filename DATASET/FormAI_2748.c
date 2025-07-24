//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Define the message to be watermarked */
char message[] = "The quick brown fox jumped over the lazy dog.";

/* Define the watermark */
char watermark[] = "This is a surrealist digital watermarking example.";

/* Function to convert a character to binary */
void charToBinary(char c, char* binary) {
    for (int i = 0; i < 8; i++) {
        binary[7-i] = (c >> i) & 1 ? '1' : '0';
    }
}

/* Function to convert binary to a character */
char binaryToChar(char* binary) {
    char c = 0;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == '1') {
            c += pow(2, 7-i);
        }
    }
    return c;
}

/* Function to embed the watermark into the message */
void embedWatermark(char* message, char* watermark) {
    int watermarkIndex = 0;
    for (int i = 0; i < strlen(message); i++) {
        char binary[9];
        charToBinary(message[i], binary);
        if (watermarkIndex < strlen(watermark)) {
            binary[7] = watermark[watermarkIndex];
            watermarkIndex++;
        }
        message[i] = binaryToChar(binary);
    }
}

/* Function to extract the watermark from the message */
void extractWatermark(char* message, char* watermark) {
    int watermarkIndex = 0;
    for (int i = 0; i < strlen(message); i++) {
        char binary[9];
        charToBinary(message[i], binary);
        if (watermarkIndex < strlen(watermark)) {
            watermark[watermarkIndex] = binary[7];
            watermarkIndex++;
        }
    }
}

int main() {
    printf("Original message: %s\n", message);

    // Embed the watermark into the message
    embedWatermark(message, watermark);
    printf("Watermarked message: %s\n", message);

    // Extract the watermark from the message
    char extractedWatermark[strlen(watermark) + 1];
    extractWatermark(message, extractedWatermark);
    printf("Extracted watermark: %s\n", extractedWatermark);

    return 0;
}