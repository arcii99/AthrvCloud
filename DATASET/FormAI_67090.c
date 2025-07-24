//FormAI DATASET v1.0 Category: Image Steganography ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define image dimensions
#define WIDTH 200
#define HEIGHT 200

// define secret message
char message[] = "Steganography is an art";

// function to convert character into binary form
void charToBinary(char ch, char *binary) {
    int i;
    for (i = 7; i >= 0; i--) {
        *(binary + 7 - i) = ch & (1 << i) ? '1' : '0';
    }
    *(binary + 8) = '\0';
}

int main() {
    // create image array
    char image[HEIGHT][WIDTH];

    // initialize all pixels to white
    memset(image, ' ', sizeof(image));

    // embed secret message into image
    int msgLen = strlen(message);
    int i, j, k = 0;
    char binary[9];
    for (i = 0; i < msgLen; i++) {
        // convert character to binary string
        charToBinary(message[i], binary);

        // embed binary string into image
        for (j = 0; j < 8; j++) {
            if (binary[j] == '1') {
                image[k / WIDTH][k % WIDTH] = '#'; // black pixel
            }
            k++;
        }
    }

    // print original image
    printf("Original Image:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(image[i][j]);
        }
        putchar('\n');
    }

    // extract secret message from image
    char extractedMsg[msgLen + 1];
    memset(extractedMsg, '\0', sizeof(extractedMsg));
    k = 0;
    for (i = 0; i < msgLen; i++) {
        memset(binary, '\0', sizeof(binary));
        for (j = 0; j < 8; j++) {
            binary[j] = (image[k / WIDTH][k % WIDTH] == '#') ? '1' : '0';
            k++;
        }
        extractedMsg[i] = strtol(binary, 0, 2);
    }

    // print extracted secret message
    printf("\nExtracted Secret Message: %s\n", extractedMsg);

    return 0;
}