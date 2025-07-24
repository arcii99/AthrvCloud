//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000], watermark[100];
    int i, j, len;

    printf("Enter the message to watermark: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = '\0'; // removes newline character from input

    printf("Enter the watermark: ");
    fgets(watermark, 100, stdin);
    watermark[strcspn(watermark, "\n")] = '\0';

    len = strlen(watermark);

    for (i = 0, j = 0; message[i] != '\0'; i++) {
        if (j < len) {
            message[i] ^= watermark[j];
            j++;
        }
        else {
            j = 0;
            message[i] ^= watermark[j];
            j++;
        }
    }

    printf("Watermarked message: %s\n", message);

    return 0;
}