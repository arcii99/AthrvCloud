//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
// Digital Watermarking Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 16 // size of the watermark in bytes
#define MAX_MSG_SIZE 256 // maximum size of the message in bytes

// function to add the watermark to the message
void add_watermark(unsigned char *msg, unsigned char *watermark) {
    int i, j;
    for (i = 0, j = WATERMARK_SIZE - 1; i < WATERMARK_SIZE; i++, j--) {
        msg[MAX_MSG_SIZE - i - 1] = (msg[MAX_MSG_SIZE - i - 1] & 0xF0) | (watermark[j] >> 4);
        msg[MAX_MSG_SIZE - i - 2] = (msg[MAX_MSG_SIZE - i - 2] & 0x0F) | (watermark[j] << 4);
    }
}

// function to extract the watermark from the message
void extract_watermark(unsigned char *msg, unsigned char *watermark) {
    int i, j;
    for (i = 0, j = WATERMARK_SIZE - 1; i < WATERMARK_SIZE; i++, j--) {
        watermark[j] = (msg[MAX_MSG_SIZE - i - 1] << 4) | (msg[MAX_MSG_SIZE - i - 2] >> 4);
    }
}

int main() {
    unsigned char msg[MAX_MSG_SIZE];
    unsigned char watermark[WATERMARK_SIZE] = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x90, 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10};
    unsigned char extracted_watermark[WATERMARK_SIZE];
    char input_msg[MAX_MSG_SIZE];
    int i;

    printf("Enter message to watermark (max size %d): ", MAX_MSG_SIZE - WATERMARK_SIZE);
    fgets(input_msg, MAX_MSG_SIZE - WATERMARK_SIZE, stdin);
    input_msg[strcspn(input_msg, "\n")] = 0; // remove newline character from input

    // copy message into buffer and add the watermark
    strncpy(msg, input_msg, MAX_MSG_SIZE - WATERMARK_SIZE);
    add_watermark(msg, watermark);

    printf("Watermarked message is:\n");
    for (i = 0; i < MAX_MSG_SIZE; i++) {
        printf("%02X ", msg[i]);
    }
    printf("\n");

    // extract the watermark from the message
    extract_watermark(msg, extracted_watermark);

    printf("Extracted watermark is:\n");
    for (i = 0; i < WATERMARK_SIZE; i++) {
        printf("%02X ", extracted_watermark[i]);
    }
    printf("\n");

    return 0;
}