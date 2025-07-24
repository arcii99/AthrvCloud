//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>

#define MAX_MSG_LENGTH 1024
#define MAX_WATERMARK_LENGTH 256
#define LSB_BIT_MASK 0xFE

// Function to embed the watermark into the message
void embedWatermark(unsigned char *msg, unsigned char *watermark)
{
    int msg_len = strlen(msg);
    int watermark_len = strlen(watermark);
    int watermark_bit_index = 0;

    // Embed watermark bit by bit into the message using LSB technique
    for(int i=0; i<msg_len; i++)
    {
        if(watermark_bit_index >= watermark_len) break; // if watermark has been fully embedded
        unsigned char msg_byte = msg[i];
        for(int j=0; j<8; j++)
        {
            if(watermark_bit_index >= watermark_len) break; // if watermark has been fully embedded
            unsigned char watermark_bit = (watermark[watermark_bit_index] >> j) & 0x01;
            msg_byte = (msg_byte & LSB_BIT_MASK) | watermark_bit; // replace LSB of message byte with watermark bit
            msg[i] = msg_byte;
            watermark_bit_index++;
        }
    }
}

// Function to extract the watermark from the message
void extractWatermark(unsigned char *msg, unsigned char *watermark)
{
    int msg_len = strlen(msg);
    int watermark_len = strlen(watermark);
    int watermark_bit_index = 0;

    // Extract watermark bit by bit from the message using LSB technique
    for(int i=0; i<msg_len; i++)
    {
        if(watermark_bit_index >= watermark_len) break; // if watermark has been fully extracted
        unsigned char msg_byte = msg[i];
        for(int j=0; j<8; j++)
        {
            if(watermark_bit_index >= watermark_len) break; // if watermark has been fully extracted
            unsigned char watermark_bit = msg_byte & 0x01; // extract LSB of message byte
            watermark[watermark_bit_index] |= watermark_bit << j; // set watermark bit
            watermark_bit_index++;
            msg_byte >>= 1;
        }
    }
}

int main()
{
    unsigned char msg[MAX_MSG_LENGTH] = "This is a secret message";
    unsigned char watermark[MAX_WATERMARK_LENGTH] = "12345";

    // Embed the watermark into the message
    embedWatermark(msg, watermark);
    printf("Watermark embedded message: %s\n", msg);

    // Extract the watermark from the message
    unsigned char extracted_watermark[MAX_WATERMARK_LENGTH] = {0};
    extractWatermark(msg, extracted_watermark);
    printf("Extracted watermark: %s\n", extracted_watermark);

    return 0;
}