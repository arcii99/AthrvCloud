//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int main(void) {
    int image[SIZE][SIZE]; // original image
    int watermark[SIZE][SIZE]; // binary watermark
    int encodedImage[SIZE][SIZE]; // final encoded image
    int i, j;
    char message[100];

    printf("Enter the message to be encoded:\n");
    fgets(message, sizeof(message), stdin); // read input message

    // initialize image and watermark based on message
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(i < strlen(message) && j < strlen(message)) {
                image[i][j] = message[i] + message[j];
                watermark[i][j] = message[i] - message[j];
            } else {
                // fill remaining cells with random values
                image[i][j] = rand() % 255;
                watermark[i][j] = rand() % 2;
            }
        }
    }

    // perform image encoding by combining image and watermark
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            encodedImage[i][j] = image[i][j] + (watermark[i][j] * 255);
        }
    }

    // print the original image, watermark and encoded image
    printf("Original Image:\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("Watermark:\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", watermark[i][j]);
        }
        printf("\n");
    }

    printf("Encoded Image:\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", encodedImage[i][j]);
        }
        printf("\n");
    }

    return 0;
}