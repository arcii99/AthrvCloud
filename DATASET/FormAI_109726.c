//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 500
#define COL_SIZE 500
#define MAX_BIT_SIZE 8

// Function to get the binary equivalent of an integer
char* int_to_binary(int integer, int bit_size) {
    char* binary_num = (char*) malloc(bit_size + 1);
    binary_num[bit_size] = '\0';
    for(int i=bit_size-1; i >= 0; i--) {
        binary_num[i] = (integer & 1) ? '1' : '0';
        integer >>= 1;
    }
    return binary_num;
}

// Function to hide a secret message in a given pixel of an image
int hide_message(char pixel[], char message[], int bit_size, int pos) {
    // Check if the message has been fully hidden
    if(pos == strlen(message)) {
        return 1;
    }
    // Get the binary equivalent of the message character
    char* binary_num = int_to_binary(message[pos], MAX_BIT_SIZE);
    int j = 0;
    // Hide the bits one by one in the pixel LSBs
    for(int i=MAX_BIT_SIZE-bit_size; i<MAX_BIT_SIZE; i++) {
        if(binary_num[i] == '1') {
            if(pixel[j] % 2 == 0) {
                pixel[j] += 1;
            }
        }
        else {
            if(pixel[j] % 2 == 1) {
                pixel[j] -= 1;
            }
        }
        j++;
    }
    int ret = hide_message(pixel, message, bit_size, pos+1);
    free(binary_num);
    return ret;
}

// Function to extract a secret message from a given pixel of an image
char* extract_message(char pixel[], int bit_size) {
    char* binary_num = (char*) malloc(bit_size + 1);
    binary_num[bit_size] = '\0';
    int j = 0;
    // Extract the LSBs of the pixel one by one and convert to binary
    for(int i=MAX_BIT_SIZE-bit_size; i<MAX_BIT_SIZE; i++) {
        if(pixel[j] % 2 == 0) {
            binary_num[i] = '0';
        }
        else {
            binary_num[i] = '1';
        }
        j++;
    }
    // Convert binary to character
    char* message = (char*) malloc(sizeof(char));
    *message = (char) strtol(binary_num, NULL, 2);
    free(binary_num);
    return message;
}

// Function to hide a message in an image
void hide_message_in_image(char image[ROW_SIZE][COL_SIZE], char message[]) {
    int len = strlen(message);
    int bit_size = (int) ceil((float) MAX_BIT_SIZE / len);
    int pos = 0;
    // Hide the message in the LSBs of each pixel of the image
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            if(pos >= len) {
                return;
            }
            if(hide_message(image[i][j], message, bit_size, pos)) {
                pos++;
            }
        }
    }
}

// Function to extract a message from an image
char* extract_message_from_image(char image[ROW_SIZE][COL_SIZE]) {
    char* message = (char*) malloc(sizeof(char));
    message[0] = '\0';
    int bit_size = (int) ceil((float) MAX_BIT_SIZE / strlen(message));
    int pos = 0;
    // Extract the message from the LSBs of each pixel of the image
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            char* extracted_msg = extract_message(image[i][j], bit_size);
            strcat(message, extracted_msg);
            pos++;
            free(extracted_msg);
        }
    }
    return message;
}

int main() {
    char image[ROW_SIZE][COL_SIZE];
    char message[] = "This is a secret message!";
    hide_message_in_image(image, message);
    char* extracted_message = extract_message_from_image(image);
    printf("Extracted message: %s\n", extracted_message);
    free(extracted_message);
    return 0;
}