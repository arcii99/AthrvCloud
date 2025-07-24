//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[1000], watermark[20], result[1020];
    int messageLength, watermarkLength, i, j, k=0;

    printf("Enter the message: ");
    fgets(message, 1000, stdin);

    printf("Enter the watermark: ");
    fgets(watermark, 20, stdin);

    messageLength = strlen(message);
    watermarkLength = strlen(watermark);

    for (i=0; i<messageLength; i++) {
        result[k++] = message[i];

        if (i % 4 == 3) {
            for (j=0; j<watermarkLength; j++) {
                result[k++] = watermark[j];
            }
        }
    }
    result[k] = '\0';

    printf("\n\nOriginal Message: %s\n", message);
    printf("Watermark: %s\n", watermark);
    printf("Watermarked Message: %s\n", result);

    return 0;
}