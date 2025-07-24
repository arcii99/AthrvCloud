//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LEN 1000
#define WATERMARK_LEN 10

int main() {
    char inputStr[MAX_STRING_LEN];
    printf("Enter the message you want to watermark: ");
    fgets(inputStr, MAX_STRING_LEN, stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0'; // Remove newline character from input

    // Generate random string for watermark
    char watermark[WATERMARK_LEN+1];
    const char possibleChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL));
    for(int i=0; i<WATERMARK_LEN; i++) {
        watermark[i] = possibleChars[rand() % strlen(possibleChars)];
    }
    watermark[WATERMARK_LEN] = '\0';

    // Apply watermark to input
    char outputStr[MAX_STRING_LEN+WATERMARK_LEN+1];
    strcpy(outputStr, watermark);
    strcat(outputStr, inputStr);

    printf("Watermark generated: %s\n", watermark);
    printf("Watermarked message: %s\n", outputStr);

    // Extract watermark from watermarked message
    char extractedWatermark[WATERMARK_LEN+1];
    memcpy(extractedWatermark, outputStr, WATERMARK_LEN);
    extractedWatermark[WATERMARK_LEN] = '\0';

    // Check if extracted watermark matches generated watermark
    if(strcmp(extractedWatermark, watermark) == 0) {
        printf("Watermark successfully extracted!\n");
    } else {
        printf("Error: Failed to extract watermark.\n");
    }

    return 0;
}