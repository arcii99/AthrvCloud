//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 16

int main() {
    char original[1000], watermarked[1000];
    int i, j;
    
    // Get input from user
    printf("Enter the original text: ");
    fgets(original, 1000, stdin);

    // Generate random watermark
    char watermark[WATERMARK_SIZE+1];
    for(i=0; i<WATERMARK_SIZE; i++) {
        watermark[i] = 'A' + rand() % 26;
    }
    watermark[WATERMARK_SIZE] = '\0';

    // Create watermarked text
    int watermark_index = 0;
    for(i=0; i<strlen(original); i++) {
        if(original[i] == '\n') break;  // End of input
        if(watermark_index >= WATERMARK_SIZE) watermark_index = 0;  // Wrap around
        char watermarked_char = original[i] + watermark[watermark_index];
        watermarked[2*i] = watermarked_char / 16;  // Store first 4 bits in even position
        watermarked[2*i + 1] = watermarked_char % 16;  // Store last 4 bits in odd position
        watermark_index++;
    }
    watermarked[2*i] = '\0';

    // Print the original and watermarked text
    printf("Original text:\n%s\n", original);
    printf("Watermark: %s\n", watermark);
    printf("Watermarked text:\n");
    for(i=0; i<strlen(original); i++) {
        if(watermarked[2*i] == '\0') break;  // End of watermarked text
        char watermarked_char = (watermarked[2*i] * 16) + watermarked[2*i + 1];
        printf("%c", (char)(watermarked_char - watermark[i%WATERMARK_SIZE]));
    }

    return 0;
}