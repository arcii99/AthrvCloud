//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define MAX_WATERMARK_LENGTH 10

char* watermark(char* message, char* mark) {
    int len = strlen(message);
    int mark_len = strlen(mark);
    char* watermarked_msg = (char*) malloc((len + mark_len) * sizeof(char));
    int i, j = 0;

    for (i = 0; i < len + mark_len; i++) {
        if (i < len) {
            watermarked_msg[i] = message[i];
        } else {
            watermarked_msg[i] = mark[j];
            j++;
        }
    }
    watermarked_msg[i] = '\0';
    return watermarked_msg;
}

int main() {
    char message[MAX_MSG_LENGTH];
    char mark[MAX_WATERMARK_LENGTH];
    printf("Enter the message: ");
    fgets(message, MAX_MSG_LENGTH, stdin);
    printf("Enter the mark: ");
    fgets(mark, MAX_WATERMARK_LENGTH, stdin);

    char* watermarked = watermark(message, mark);

    printf("Watermarked message: %s\n", watermarked);
    free(watermarked);
    return 0;
}