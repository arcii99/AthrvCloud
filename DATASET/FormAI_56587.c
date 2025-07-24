//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 255

// This structure holds the message for which the watermarking has to be performed.
typedef struct WatermarkMessage {
    char message[MAX_STRING_SIZE];
} WatermarkMessage;

// This function performs the watermarking by manipulating the LSB of the given data.
void watermark(char *data, char message) {
    *data = (*data & ~1) | (message & 1);
}

// This function retrieves the watermark from the given data.
char deWatermark(char *data) {
    return (*data & 1);
}

// This function prints the given data in binary format.
void printBinary(char data) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (data >> i) & 1);
    }
}

int main() {
    // Initialize the message for watermarking.
    WatermarkMessage wmMessage = {"Hello C Digital Watermarking!"};

    // Generate a random data buffer to hold the message.
    char *data = (char *) malloc(strlen(wmMessage.message) + 1);
    strcpy(data, wmMessage.message);

    // Iterate over each character of the message and perform the watermarking.
    for (int i = 0; i < strlen(wmMessage.message); i++) {
        watermark(&data[i], wmMessage.message[i]);
    }

    printf("Watermarked data: ");

    // Print the watermarked data in binary format.
    for (int i = 0; i < strlen(wmMessage.message); i++) {
        printBinary(data[i]);
        printf(" ");
    }

    printf("\nDe-watermarked message: ");

    // Retrieve the watermarked data and print the de-watermarked message.
    for (int i = 0; i < strlen(wmMessage.message); i++) {
        printf("%c", deWatermark(&data[i]));
    }

    printf("\n");

    // Free the allocated memory.
    free(data);

    return 0;
}