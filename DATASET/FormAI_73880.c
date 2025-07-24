//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct message {
    char text[1000];
    char watermark[20];
};

int main() {
    char str[1000];
    char wmark[20];
    struct message msg;

    printf("Enter the text message (max 1000 characters):\n");
    fgets(str, sizeof(str), stdin);

    printf("\nEnter the watermark (max 20 characters):\n");
    fgets(wmark, sizeof(wmark), stdin);

    // Add the watermark to the message
    sprintf(msg.text, "%s%s", str, wmark);
    strcpy(msg.watermark, wmark);

    // Display the message with watermark
    printf("\nThe watermarked message is:\n%s", msg.text);

    // Verify the watermark
    if(strstr(msg.text, msg.watermark) != NULL) {
        printf("\nWatermark verified successfully!\n");
    }
    else {
        printf("\nWatermark verification failed!\n");
    }

    return 0;
}