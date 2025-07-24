//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert text to binary */
char *textToBinary(char *text) {
    int len = strlen(text);
    char *binary = (char *) calloc(len * 8 + 1, sizeof(char));
    for (int i = 0; i < len; i++) {
        unsigned int val = text[i];
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + (7 - j)] = (val & (1 << j)) ? '1' : '0';
        }
    }
    return binary;
}

/* Function to convert binary to text */
char *binaryToText(char *binary) {
    int len = strlen(binary) / 8;
    char *text = (char *) calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; i++) {
        unsigned int val = 0;
        for (int j = 0; j < 8; j++) {
            val += (binary[i * 8 + j] - '0') << (7 - j);
        }
        text[i] = val;
    }
    return text;
}

/* Function to embed a watermark in a binary string */
char *embedWatermark(char *binary, char *watermark, int len) {
    int len_watermark = strlen(watermark);
    char *binary_new = (char *) calloc(strlen(binary) + len_watermark * len + 1, sizeof(char));
    int start = 0;
    int end = start + len - 1;
    int i = 0;
    while (end <= strlen(binary) - 1) {
        if (watermark[i % len_watermark] == '0' && binary[start] == '1') {
            binary_new[start] = '0';
        } else if (watermark[i % len_watermark] == '1' && binary[start] == '0') {
            binary_new[start] = '1';
        } else {
            binary_new[start] = binary[start];
        }
        i++;
        start++;
        end++;
    }
    while (start <= strlen(binary) - 1) {
        binary_new[start] = binary[start];
        start++;
    }
    return binary_new;
}

/* Function to extract the watermark from a binary string */
char *extractWatermark(char *binary, int len) {
    char *watermark = (char *) calloc(len + 1, sizeof(char));
    int start = 0;
    int end = start + len - 1;
    int i = 0;
    while (end <= strlen(binary) - 1) {
        if (binary[start] == '1') {
            watermark[i] = '1';
        } else {
            watermark[i] = '0';
        }
        i++;
        start++;
        end++;
    }
    return watermark;
}

int main() {
    char text[] = "This is an example program to demonstrate digital watermarking.";
    char *binary = textToBinary(text);
    char *watermark = "011001010110111001100011";
    char *embedded = embedWatermark(binary, watermark, 3);
    char *extracted = extractWatermark(embedded, 3);
    char *extracted_text = binaryToText(extracted);
    printf("Original text: %s\n", text);
    printf("Embedded text: %s\n", binaryToText(embedded));
    printf("Extracted text: %s\n", extracted_text);
    free(binary);
    free(embedded);
    free(extracted);
    free(extracted_text);
    return 0;
}