//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 100 // maximum number of rows in the image
#define MAX_COLS 100 // maximum number of columns in the image
#define MAX_STRING_LENGTH 100 // maximum length of the secret message

// Function to convert integer to binary
void intToBinary(int n, int* binaryArray, int size) {
    for(int i = size-1; i >= 0; i--) {
        *(binaryArray+i) = n%2;
        n = n/2;
    }
}

// Function to convert binary to integer
int binaryToInt(int* binaryArray, int size) {
    int num = 0, base = 1;
    for(int i = size-1; i >= 0; i--) {
        num += *(binaryArray+i) * base;
        base *= 2;
    }
    return num;
}

// Function to embed the secret message in the image using LSB method
void embedMessage(int image[MAX_ROWS][MAX_COLS], char* message) {
    int messageSize = 0;
    while(*(message+messageSize) != '\0') messageSize++;
    int messageBinarySize = messageSize * 8; // each character takes 8 bits
    int messageBinary[messageBinarySize];
    for(int i = 0; i < messageSize; i++) {
        intToBinary(*(message+i), messageBinary+i*8, 8);
    }
    int x = 0, y = 0, bitNum = 0;
    while(bitNum < messageBinarySize) {
        if(image[x][y]%2 != messageBinary[bitNum]) {
            if(image[x][y] == 0) image[x][y] = 1;
            else image[x][y] = 0;
        }
        bitNum++;
        y++;
        if(y == MAX_COLS) {
            x++;
            y = 0;
        }
        if(x == MAX_ROWS) break;
    }
}

// Function to extract the secret message from the image
char* extractMessage(int image[MAX_ROWS][MAX_COLS], int messageSize) {
    int messageBinarySize = messageSize * 8; // each character takes 8 bits
    int messageBinary[messageBinarySize];
    int x = 0, y = 0, bitNum = 0;
    while(bitNum < messageBinarySize) {
        messageBinary[bitNum] = image[x][y]%2;
        bitNum++;
        y++;
        if(y == MAX_COLS) {
            x++;
            y = 0;
        }
        if(x == MAX_ROWS) break;
    }
    char* message = malloc((messageSize+1)*sizeof(char));
    for(int i = 0; i < messageSize; i++) {
        *(message+i) = binaryToInt(messageBinary+i*8, 8);
    }
    *(message+messageSize) = '\0';
    return message;
}

// Main function
int main() {
    // Example usage
    int image[MAX_ROWS][MAX_COLS] = {{1,0,1,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,1,1,1,0},{1,1,0,1,0}};
    char* message = "Digital Watermarking Example";
    printf("Original Message: %s\n", message);
    embedMessage(image, message);
    char* extractedMessage = extractMessage(image, 27);
    printf("Extracted Message: %s\n", extractedMessage);
    return 0;
}