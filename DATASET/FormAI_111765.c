//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000
#define MAX_MESSAGE_SIZE 100000

typedef struct {
    char digital_signature[MAX_STRING_SIZE];
} Watermark;

void embed_watermark(char *message, Watermark *wm) {
    int i, j = 0;
    char temp[MAX_STRING_SIZE];

    printf("\nEnter the digital signature for watermark: ");
    fgets(temp, MAX_STRING_SIZE, stdin);
    temp[strcspn(temp, "\n")] = 0;
    strcpy(wm->digital_signature, temp);

    for (i = strlen(message) - 1; i >= 0; i--) {
        message[i + j] = message[i];
        if (i == strlen(message) - 4) {
            message[i + j] = wm->digital_signature[0];
            j++;
            message[i + j] = wm->digital_signature[1];
            j++;
            message[i + j] = wm->digital_signature[2];
            j++;
            message[i + j] = wm->digital_signature[3];
            j++;
        }
    }
}

void read_watermark(char *message, Watermark *wm) {
    int i, j = 0;
    char temp[MAX_STRING_SIZE];

    for (i = strlen(message) - 1; i >= 0; i--) {
        if (i == strlen(message) - 4) {
            temp[0] = message[i + j];
            j++;
            temp[1] = message[i + j];
            j++;
            temp[2] = message[i + j];
            j++;
            temp[3] = message[i + j];
            j++;

            strcpy(wm->digital_signature, temp);
            printf("\nDigital signature found: %s\n", wm->digital_signature);
        } else {
            message[i + j] = message[i];
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    Watermark watermark;

    printf("Enter the message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    embed_watermark(message, &watermark);
    printf("\nWatermarking done.\n");

    read_watermark(message, &watermark);

    return 0;
}