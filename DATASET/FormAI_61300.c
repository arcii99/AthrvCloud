//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 200
#define WATERMARK "GeneratedByBot"

void hideWatermark(char* msg, char* watermark) {
    int msgLength = strlen(msg), markLength = strlen(watermark);
    int i, j;
    for (i = 0, j = 0; i < msgLength; ++i, ++j) {
        if (j == markLength) j = 0;
        msg[i] = (msg[i] + watermark[j]) % 128;
    }
}

int checkWatermark(char* msg, char* watermark) {
    int msgLength = strlen(msg), markLength = strlen(watermark);
    int i, j;
    for (i = 0, j = 0; i < msgLength; ++i, ++j) {
        if (j == markLength) j = 0;
        if ((msg[i] - watermark[j]) % 128 != 0) return 0;
    }
    return 1;
}

int main() {
    int choice;
    char message[MAX_CHARS], watermark[MAX_CHARS];
    printf("Enter the message to be watermarked: ");
    fgets(message, MAX_CHARS, stdin);
    printf("Enter the watermark to hide: ");
    fgets(watermark, MAX_CHARS, stdin);
    hideWatermark(message, watermark);
    printf("Message with watermark: %s", message);
    printf("Do you want to check for watermark? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1 && checkWatermark(message, watermark)) {
        printf("Watermark found!\n");
    } else {
        printf("Watermark not found or not checked!\n");
    }
    return 0;
}