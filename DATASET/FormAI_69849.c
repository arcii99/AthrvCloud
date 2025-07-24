//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_MSG_LEN 100
#define WATERMARK 0xAA

// Function to print an array in hexadecimal format
void print_hex(uint8_t* arr, int size) 
{
    for(int i = 0; i < size; i++) {
        printf("%02x ", arr[i]);
    }
    printf("\n");
}

// Function to embed a watermark in a given message
void embed_watermark(uint8_t* msg, int msg_size, uint8_t* watermark) 
{
    int watermark_size = strlen(watermark);
    int index = 0;
    for(int i = 0; i < msg_size; i++) {
        if(index == watermark_size) {
            index = 0;
        }
        msg[i] ^= watermark[index] ^ WATERMARK;
        index++;
    }
}

// Function to extract a watermark from a given message
void extract_watermark(uint8_t* msg, int msg_size, uint8_t* watermark) 
{
    int watermark_size = strlen(watermark);
    int index = 0;
    for(int i = 0; i < msg_size; i++) {
        if(index == watermark_size) {
            index = 0;
        }
        watermark[index] = msg[i] ^ WATERMARK;
        index++;
    }
}

int main() 
{
    uint8_t msg[MAX_MSG_LEN] = "Hello, World!";
    uint8_t watermark[] = "This is a watermark.";
    
    printf("Original message:\n");
    print_hex(msg, strlen((char*)msg));
    
    embed_watermark(msg, strlen((char*)msg), watermark);
    printf("\nMessage after embedding watermark:\n");
    print_hex(msg, strlen((char*)msg));
    
    uint8_t extracted_watermark[strlen((char*)watermark)];
    memset(extracted_watermark, 0, strlen((char*)watermark));
    extract_watermark(msg, strlen((char*)msg), extracted_watermark);
    printf("\nExtracted watermark:\n%s\n", extracted_watermark);
    
    return 0;
}