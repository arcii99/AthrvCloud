//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>

/* Function to embed the secret message into the cover image */
void embedMessage(int coverImage[][3], int message[], int rows, int cols, int msgLength) {
    int msgIndex = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(msgIndex<msgLength) {
                coverImage[i][j] = (coverImage[i][j] & 0xFE) | ((message[msgIndex]>>7) & 0x1);
                coverImage[i][j+1] = (coverImage[i][j+1] & 0xFC) | ((message[msgIndex]>>5) & 0x3);
                coverImage[i][j+2] = (coverImage[i][j+2] & 0xF8) | ((message[msgIndex]>>2) & 0x7);
                msgIndex++;
            }
            if(msgIndex<msgLength) {
                coverImage[i][j] = (coverImage[i][j] & 0x7F) | ((message[msgIndex]>>6) & 0x80);
                coverImage[i][j+1] = (coverImage[i][j+1] & 0x3F) | ((message[msgIndex]>>4) & 0xC0);
                coverImage[i][j+2] = (coverImage[i][j+2] & 0x1F) | ((message[msgIndex]>>1) & 0xE0);
                msgIndex++;
            }
            if(msgIndex<msgLength) {
                coverImage[i][j] = (coverImage[i][j] & 0x3F) | ((message[msgIndex]>>5) & 0xC0);
                coverImage[i][j+1] = (coverImage[i][j+1] & 0x1F) | ((message[msgIndex]>>2) & 0xE0);
                coverImage[i][j+2] = (coverImage[i][j+2] & 0x07) | ((message[msgIndex]) & 0xF8);
                msgIndex++;
            }
            if(msgIndex>=msgLength) {
                break;
            }
        }
        if(msgIndex>=msgLength) {
            break;
        }
    }
}

/* Function to extract the secret message from the steganographically modified image */
void extractMessage(int coverImage[][3], int rows, int cols) {
    int msgLength = 0, msgIndex = 0, secretChar = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(msgIndex % 9 == 0) {
                secretChar = (coverImage[i][j] & 0x1) << 7;
                secretChar |= (coverImage[i][j+1] & 0x3) << 5;
                secretChar |= (coverImage[i][j+2] & 0x7) << 2;
            }
            else if(msgIndex % 9 == 3) {
                secretChar |= (coverImage[i][j] & 0x80) >> 6;
                secretChar |= (coverImage[i][j+1] & 0xC0) >> 4;
                secretChar |= (coverImage[i][j+2] & 0xE0) >> 1;
            }
            else if(msgIndex % 9 == 6) {
                secretChar |= (coverImage[i][j] & 0xC0) >> 5;
                secretChar |= (coverImage[i][j+1] & 0xE0) >> 2;
                secretChar |= (coverImage[i][j+2] & 0xF8);
                printf("%c", secretChar);
                if(secretChar == '\0') {
                    break;
                }
            }
            msgIndex++;
        }
        if(secretChar == '\0') {
            break;
        }
    }
}

int main() {
    // Load the cover image into a 2D array
    int coverImage[3][3] = {{0xFF, 0xFF, 0xFF},
                            {0xFF, 0xFF, 0xFF},
                            {0xFF, 0xFF, 0xFF}};

    // Load the secret message into an array
    int message[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};

    // Embed the secret message into the cover image
    embedMessage(coverImage, message, 3, 3, 13);

    // Print the steganographically modified image
    printf("Steganographically Modified Image:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%X ", coverImage[i][j]);
        }
        printf("\n");
    }

    // Extract the secret message from the steganographically modified image
    printf("\nExtracted Secret Message:\n");
    extractMessage(coverImage, 3, 3);

    return 0;
}