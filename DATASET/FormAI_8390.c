//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a watermark to a string
void addWatermark(char *str,char *watermark) {
    // Find the middle of the string
    int mid = strlen(str) / 2;
  
    // Add the watermark to the middle of the string
    memmove(str + mid + strlen(watermark), str + mid, strlen(str) - mid + 1);
    memcpy(str + mid, watermark, strlen(watermark));
}
  
// Function to extract the watermark from a string
void extractWatermark(char *str,char *watermark) {
    // Find the middle of the string
    int mid = strlen(str) / 2;
  
    // Extract the watermark from the middle of the string
    memcpy(watermark, str + mid, strlen(watermark));
    memset(str + mid, ' ', strlen(watermark));
}

int main() {
    char str[100], watermark[20];
    printf("Welcome to the Digital Watermarking Program!\n");
    printf("Please enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Please enter a watermark: ");
    fgets(watermark, sizeof(watermark), stdin);
  
    // Add the watermark to the string
    addWatermark(str, watermark);
    printf("The watermarked string is: %s\n", str);
  
    // Extract the watermark from the string
    extractWatermark(str, watermark);
    printf("The extracted watermark is: %s\n", watermark);
  
    return 0;
}