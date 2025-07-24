//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#define WATERMARK_LENGTH 10

void embedWatermark(char* message, char* watermark, int watermarkLength) {
    int messageLength = strlen(message);
    int i, j;

    for (i = 0; i < messageLength && i < watermarkLength; i++) {
        message[i] = message[i] | watermark[i];
        if (i == watermarkLength - 1) {
            for (j = i + 1; j < messageLength; j++) {
                message[j] = message[j] | watermark[0];
            }
        }
    }
}

void extractWatermark(char* message, char* watermark, int watermarkLength) {
    int messageLength = strlen(message);
    int i, j;

    for (i = 0; i < messageLength && i < watermarkLength; i++) {
        watermark[i] = message[i] & 1;
        if (i == watermarkLength - 1) {
            for (j = i + 1; j < messageLength; j++) {
                watermark[i] = message[j] & 1;
            }
        }
    }
}

int main() {
    char message[] = "This is my secret message";
    char watermark[WATERMARK_LENGTH] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    
    printf("Original message: %s\n", message);
    
    embedWatermark(message, watermark, WATERMARK_LENGTH);
    printf("Message after embedding watermark: %s\n", message);
    
    char extractedWatermark[WATERMARK_LENGTH];
    extractWatermark(message, extractedWatermark, WATERMARK_LENGTH);
    printf("Extracted watermark: ");
    for (int i = 0; i < WATERMARK_LENGTH; i++) {
        printf("%d ", extractedWatermark[i]);
    }
    printf("\n");
    
    return 0;
}