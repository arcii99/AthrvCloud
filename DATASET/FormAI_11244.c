//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define image size
#define ROWS 10
#define COLS 10

// define secret message to embed
#define SECRET_MESSAGE "Hello World!"

// define secret key to encrypt watermark
#define SECRET_KEY 1234

// function to encrypt message using secret key
void encryptMessage(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        message[i] = message[i] ^ key;
        i++;
    }
}

// function to embed watermark into image using least significant bit algorithm
void embedWatermark(int image[][COLS], char *message) {
    // generate random starting point within image
    int row = rand() % ROWS;
    int col = rand() % COLS;
    
    // get length of message
    int len = strlen(message);
    
    // ensure message length does not exceed max capacity of image
    if (len > (ROWS * COLS - row * COLS - col)) {
        printf("Error: Message is too large for image capacity.\n");
        return;
    }
    
    // encrypt message using secret key
    encryptMessage(message, SECRET_KEY);
    
    // iterate through pixels in image starting from random point
    int i = 0, j = 0;
    for (i = row; i < ROWS; i++) {
        for (j = col; j < COLS; j++) {
            int pixel = image[i][j];
            // get least significant bit of pixel
            int lsb = pixel & 1;
            // get corresponding bit in message
            int bit = (message[(i - row) * COLS + (j - col)] >> 7 - (j - col) % 8) & 1;
            // if bits are different, modify the least significant bit of the pixel to match the message bit
            if (lsb != bit) {
                if (bit == 1) {
                    // set least significant bit to 1
                    image[i][j] |= 1;
                }
                else {
                    // set least significant bit to 0
                    image[i][j] &= ~1;
                }
            }
            // stop embedding message once all bits have been embedded
            if ((i - row) * COLS + (j - col) + 1 == len) {
                printf("Message successfully embedded in image.\n");
                return;
            }
        }
    }
}

// function to extract watermark from image
char *extractWatermark(int image[][COLS], int key) {
    // allocate memory for extracted watermark
    char *watermark = malloc(sizeof(char) * ROWS * COLS / 8);
    memset(watermark, 0, sizeof(char) * ROWS * COLS / 8);
    
    // generate random starting point within image
    int row = rand() % ROWS;
    int col = rand() % COLS;
    
    // iterate through pixels in image starting from random point
    int i = 0, j = 0, k = 0;
    for (i = row; i < ROWS; i++) {
        for (j = col; j < COLS; j++) {
            int pixel = image[i][j];
            // get least significant bit of pixel
            int lsb = pixel & 1;
            // add least significant bit to extracted watermark
            watermark[k / 8] |= lsb << 7 - k % 8;
            k++;
            // stop extracting once all bits have been extracted
            if (k == ROWS * COLS / 8) {
                // decrypt extracted watermark using secret key
                encryptMessage(watermark, key);
                printf("Watermark successfully extracted from image: %s\n", watermark);
                return watermark;
            }
        }
    }
    
    // free memory for extracted watermark
    free(watermark);
    printf("Error: Watermark not found in image.\n");
    return NULL;
}

int main() {
    // initialize image with randomly generated pixel values
    int image[ROWS][COLS];
    srand(time(NULL));
    int i = 0, j = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    // embed secret message in image
    embedWatermark(image, SECRET_MESSAGE);
    
    // extract watermark from image
    extractWatermark(image, SECRET_KEY);
    
    return 0;
}