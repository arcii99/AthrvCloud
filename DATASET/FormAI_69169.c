//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function to embed the watermark */
void embedWatermark(char *text, char *watermark) {
    strcat(text, watermark); // Concatenate the watermark to the text
}

/* Function to extract the watermark */
void extractWatermark(char *text, char *watermark) {
    int watermark_len = strlen(watermark);
    int text_len = strlen(text);
    if (text_len < watermark_len) {
        printf("Watermark not found\n");
    }
    else {
        char *pos = strstr(text, watermark); // Find the position of the watermark in the text
        if (pos == NULL) {
            printf("Watermark not found\n");
        }
        else {
            strncpy(watermark, pos, watermark_len); // Copy the watermark to the watermark string
            text[pos - text] = '\0'; // Remove the watermark from the text
        }
    }
}

int main() {
    char text[] = "This is a sample text.";
    char watermark[] = "mywatermark";
    
    embedWatermark(text, watermark);
    printf("Text after embedding watermark: %s\n", text);
    
    char extracted_watermark[20] = "";
    extractWatermark(text, extracted_watermark);
    printf("Extracted watermark: %s\n", extracted_watermark);
    
    return 0;
}