//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1000
#define WATERMARK "MyUniqueWatermark"

int main()
{
    // Define variables
    FILE *fp;
    char text[MAX_TEXT_LEN];
    char watermarked_text[MAX_TEXT_LEN + sizeof(WATERMARK)];
    char watermark[sizeof(WATERMARK)];
    int watermark_index;
    
    // Open file and read text
    fp = fopen("original_text.txt", "r");
    if(fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    fgets(text, MAX_TEXT_LEN, fp);
    fclose(fp);
    
    // Insert watermark in text
    srand(time(NULL));
    watermark_index = rand() % strlen(text);  // Random position to insert watermark
    strncpy(watermarked_text, text, watermark_index);
    strncpy(watermarked_text + watermark_index, WATERMARK, sizeof(WATERMARK));
    strncpy(watermarked_text + watermark_index + sizeof(WATERMARK) - 1, text + watermark_index, MAX_TEXT_LEN - sizeof(WATERMARK) - watermark_index);
    
    // Save watermarked text to file
    fp = fopen("watermarked_text.txt", "w");
    if(fp == NULL) {
        printf("Could not create output file.\n");
        return 1;
    }
    fputs(watermarked_text, fp);
    fclose(fp);
    
    // Extract watermark from watermarked text
    strncpy(watermark, watermarked_text + watermark_index, sizeof(WATERMARK) - 1);
    watermark[sizeof(WATERMARK) - 1] = '\0';
    printf("Extracted watermark: %s\n", watermark);
    
    return 0;
}