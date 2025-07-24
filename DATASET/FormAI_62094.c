//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to perform digital watermarking
void digitalWatermarking(char *message, char *watermark) {
    int len1 = strlen(message);
    int len2 = strlen(watermark);
    int i, j;

    // Insert 'watermark' into 'message' at the center
    for(i = len1/2, j = 0; i < len1/2 + len2; i++, j++) {
        message[i] = watermark[j];
    }

    printf("Digital Watermarking Successful!\n");
    printf("Watermarked Message: %s\n", message);
}

int main() {
    char message[100], watermark[20];

    printf("Enter the message:\n");
    fgets(message, 100, stdin);

    printf("Enter the watermark:\n");
    fgets(watermark, 20, stdin);

    digitalWatermarking(message, watermark);

    return 0;
}