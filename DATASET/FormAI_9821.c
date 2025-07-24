//FormAI DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define HEIGHT 512
#define WIDTH 512

// function to calculate the bit status
int getBitStatus(int num, int bitPos) {
    return ((num >> bitPos) & 1);
}

// function to embed secret message into image
void embedMessage(unsigned char image[][WIDTH], char* message) {
    int bitPos = 0, charPos = 0, messageLength = 0;
    while(message[charPos] != '\0') {
        messageLength++;
        charPos++;
    }

    printf("Message length: %d\n", messageLength);
    printf("Message: %s\n", message);

    // loop through all image pixels
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(bitPos >= messageLength*8) {
                // stop if all message bits have been embedded
                return;
            }
            for(int k=7; k>=0; k--) {
                // retrieve kth bit of charPos character
                int bit = getBitStatus(message[charPos], k);
                // update least significant bit of image pixel
                image[i][j] = (image[i][j] & ~1) | bit;
                // move on to the next bit of secret message character
                bitPos++;
                // if all bits of current character have been embedded, move on to the next character
                if(bitPos%8 == 0) {
                    charPos++;
                }
                if(charPos >= messageLength) {
                    // stop if all message characters have been embedded
                    return;
                }
            }
        }
    }
}

// function to retrieve secret message from image
char* retrieveMessage(unsigned char image[][WIDTH], int messageLength) {
    char* message = (char*)malloc(messageLength*sizeof(char));
    int bitPos = 0, charPos = 0;

    // loop through all image pixels
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            for(int k=7; k>=0; k--) {
                // retrieve least significant bit of image pixel
                int bit = image[i][j] & 1;
                // update kth bit of current character in message
                message[charPos] |= (bit << k);
                // move on to the next bit of secret message
                bitPos++;
                // if all bits of current character have been retrieved, move on to the next character
                if(bitPos%8 == 0) {
                    charPos++;
                }
                if(charPos >= messageLength) {
                    // stop if all message characters have been retrieved
                    return message;
                }
            }
        }
    }
    return message;
}

int main() {
    unsigned char image[HEIGHT][WIDTH];
    char* message = "This is a secret message.";

    // initialize image with random values
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            image[i][j] = rand()%256;
        }
    }

    embedMessage(image, message);

    // retrieve message length from image
    int messageLength = 0;
    for(int i=0; i<8; i++) {
        if(getBitStatus(image[0][i], 0))
            messageLength += pow(2, i);
    }
    printf("Retrieved message length: %d\n", messageLength);

    // retrieve secret message from image
    char* retrievedMsg = retrieveMessage(image, messageLength);
    printf("Retrieved message: %s\n", retrievedMsg);

    return 0;
}