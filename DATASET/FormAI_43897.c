//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Recursive function to embed a watermark in the given string
void embedWatermark(char* str, char* watermark, int strIndex, int watermarkIndex) {
    
    // Base case
    if (strIndex == strlen(str)) {
        printf("\nWatermark has been successfully embedded in the string!");
        return;
    }
    
    // Recursive case
    if (str[strIndex] == watermark[watermarkIndex]) {
        if (watermarkIndex == strlen(watermark) - 1) {
            str[strIndex + 1] = '0';
            embedWatermark(str, watermark, strIndex + 2, 0);
        } else {
            embedWatermark(str, watermark, strIndex + 1, watermarkIndex + 1);
        }
    } else {
        embedWatermark(str, watermark, strIndex + 1, 0);
    }
}

int main() {
    char str[MAX_SIZE];
    char watermark[MAX_SIZE];
    
    printf("Enter a string: ");
    gets(str);
    
    printf("Enter a watermark: ");
    gets(watermark);
    
    embedWatermark(str, watermark, 0, 0);
    
    printf("\nEmbedded string: %s", str);
    
    return 0;
}