//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {

    char message[MAX_SIZE];
    char watermark[MAX_SIZE] = "!@#$%^&*()_+";
    int i, message_length;

    printf("Enter your message to be watermarked: ");
    fgets(message, MAX_SIZE, stdin);

    //Removing newline character
    message[strcspn(message, "\n")] = 0;

    message_length = strlen(message);

    //Adding the watermark to the message
    for (i = 0; i < strlen(watermark); i++) {
        message[message_length + i] = watermark[i];
    }

    printf("\nWatermarked Message: \n");

    printf("%s\n", message);

    //Removing watermark from the message
    for(i = message_length; i < strlen(message); i++) {
        message[i] = '\0';
    }

    printf("\nOriginal Message: \n");

    printf("%s\n", message);

    return 0;
}