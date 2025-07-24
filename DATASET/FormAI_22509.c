//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include <stdio.h>
#include <string.h>

#define MAX_MSG_SIZE 100000
#define MAX_WATERMARK_SIZE 1000

char *message;
char *watermark;
char watermarked_msg[MAX_MSG_SIZE + MAX_WATERMARK_SIZE];
char extracted_watermark[MAX_WATERMARK_SIZE];

void embed_watermark(char *msg, char *watermark) {
    int msg_len = strlen(msg);
    int watermark_len = strlen(watermark);
    // embed watermark at the end of the message
    int i, j;
    for (i=0; i<msg_len; i++) {
        watermarked_msg[i] = msg[i];
    }
    for (j=0; j<watermark_len; j++) {
        watermarked_msg[i+j] = watermark[j];
    }
    watermarked_msg[i+j] = '\0';
    printf("Watermark embedded successfully!\nWatermarked message: %s\n", watermarked_msg);
}

void extract_watermark(char *watermarked_msg) {
    int msg_len = strlen(watermarked_msg);
    int watermark_len = strlen(watermark);
    // extract watermark from the end of the message
    int i, j;
    for (i=msg_len-watermark_len, j=0; i<msg_len; i++, j++) {
        extracted_watermark[j] = watermarked_msg[i];
    }
    extracted_watermark[j] = '\0';
    printf("Watermark extracted successfully!\nExtracted watermark: %s\n", extracted_watermark);
}

int main() {
    message = "Hello, this is a secret message";
    watermark = "Watermark!";
    
    embed_watermark(message, watermark);
    extract_watermark(watermarked_msg);
    
    return 0;
}