//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 32

void printWatermark(const char* watermark) {
    printf("Watermark: %s\n", watermark);
}

int main() {
    char watermark[WATERMARK_SIZE + 1];
    memset(watermark, 0, WATERMARK_SIZE + 1);

    printf("-- Watermark Configuration --\n");
    printf("Enter the watermark string (max %d characters): ", WATERMARK_SIZE);
    fgets(watermark, WATERMARK_SIZE + 1, stdin);

    if (watermark[strlen(watermark) - 1] == '\n') {
        watermark[strlen(watermark) - 1] = '\0';
    }

    printWatermark(watermark);

    // Example usage of the watermark in a file
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[256];
    memset(buffer, 0, 256);

    // Read the file content and add the watermark
    while (fgets(buffer, 256, file)) {
        strcat(buffer, watermark);
        printf("%s", buffer);
        memset(buffer, 0, 256);
    }
    fclose(file);

    return 0;
}