//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// function to convert decimal to binary
void decimal_to_binary(int decimal, int* binary) {
    int i = 0;
    while(decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
}

// function to convert binary to decimal
int binary_to_decimal(int* binary, int length) {
    int i, decimal = 0;
    for(i = length-1; i >= 0; i--) {
        if(binary[i] == 1) {
            decimal += pow(2, length-i-1);
        }
    }
    return decimal;
}

// function to hide message in the image
void hide_message(char* message, char* image) {
    int message_len = strlen(message);
    int image_len = strlen(image);
    int i, j, binary[8], index, bit_index = 0;

    for(i = 0; i < message_len; i++) {
        char character = message[i];
        decimal_to_binary(character, binary);
        index = i*8;

        for(j = 0; j < 8; j++) {
            if(index+j < image_len) {
                if(binary[j]) {
                    image[index+j] |= (1 << bit_index);
                } else {
                    image[index+j] &= ~(1 << bit_index);
                }
                bit_index++;
                bit_index %= 8;
            }
        }
    }
}

// function to retrieve message from the image
char* retrieve_message(char* image) {
    int image_len = strlen(image);
    int i, j, binary[8], index, bit_index = 0;
    char* message = (char*) malloc(sizeof(char) * (image_len/8));
    int message_index = 0;

    for(i = 0; i < image_len; i += 8) {
        index = i;
        for(j = 0; j < 8; j++) {
            binary[j] = (image[index+j] >> bit_index) & 1;
            bit_index++;
            bit_index %= 8;
        }
        int decimal = binary_to_decimal(binary, 8);
        message[message_index++] = (char) decimal;
    }
    message[message_index] = '\0';
    return message;
}

int main() {
    char message[] = "Hello, World";
    char image[] = "This is an image for steganography example";
    printf("Original Message: %s\n", message);

    hide_message(message, image);
    printf("Image with hidden message: %s\n", image);

    char* retrieved_message = retrieve_message(image);
    printf("Retrieved Message: %s\n", retrieved_message);

    free(retrieved_message);
    return 0;
}