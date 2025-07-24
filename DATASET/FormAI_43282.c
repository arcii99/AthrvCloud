//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MSG_LENGTH 1000
#define MAX_WATERMARK_LENGTH 100

char* generateWatermark(char* message, char* watermark) {
    // Append watermark at the end of message
    strcat(message, watermark);
    // Reverse the message
    int len = strlen(message);
    char* reversedMsg = (char*)malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++) {
        reversedMsg[i] = message[len - i - 1];
    }
    return reversedMsg;
}

void extractWatermark(char* reversedMsg, char* watermark) {
    // Reverse the reversed message to get the original message
    int len = strlen(reversedMsg);
    char* originalMsg = (char*)malloc(sizeof(char) * len);
    for(int i = 0; i < len; i++) {
        originalMsg[i] = reversedMsg[len - i - 1];
    }
    // Extract watermark from the original message
    int watermarkLen = strlen(watermark);
    strncpy(watermark, &originalMsg[strlen(originalMsg) - watermarkLen], watermarkLen);
}

int main() {
    char message[MAX_MSG_LENGTH], watermark[MAX_WATERMARK_LENGTH];
    printf("Enter the message: ");
    scanf("%[^\n]", message);
    printf("Enter the watermark: ");
    scanf("%s", watermark);
    char* stegoMessage = generateWatermark(message, watermark);
    printf("Stego message with watermark: %s\n", stegoMessage);
    char extractedWatermark[MAX_WATERMARK_LENGTH];
    extractWatermark(stegoMessage, extractedWatermark);
    printf("Extracted watermark: %s\n", extractedWatermark);
    free(stegoMessage);
    return 0;
}