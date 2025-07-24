//FormAI DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

/* Function to perform bitwise left shift */
unsigned char leftShift(unsigned char num, int shift) {
    return (num << shift) | (num >> (8 - shift));
}

/* Function to perform bitwise right shift */
unsigned char rightShift(unsigned char num, int shift) {
    return (num >> shift) | (num << (8 - shift));
}

/* Function to perform image steganography */
void steganography(char *image_path, char *message) {
    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    unsigned char image_data[MAX_SIZE];
    int image_size = fread(image_data, 1, MAX_SIZE, image_file);
    fclose(image_file);

    if (image_size == 0) {
        printf("Error reading image file\n");
        exit(1);
    }

    /* Steganography algorithm */
    int message_len = strlen(message);
    int message_index = 0;

    for (int i = 0; i < image_size; i += 4) {
        unsigned char b1 = image_data[i];
        unsigned char b2 = image_data[i + 1];
        unsigned char b3 = image_data[i + 2];
        unsigned char b4 = image_data[i + 3];

        /* Perform left shift on each byte */
        b1 = leftShift(b1, 2);
        b2 = leftShift(b2, 2);
        b3 = leftShift(b3, 2);

        /* If message is not yet fully encoded */
        if (message_index < message_len) {
            unsigned char msg_byte = message[message_index];

            /* Perform bitwise right shift on message byte */
            msg_byte = rightShift(msg_byte, 6);

            /* Embed message in the 2 highest bits of each byte */
            b1 |= (msg_byte << 6);

            /* If there's still more message to be encoded */
            if (message_index + 1 < message_len) {
                msg_byte = message[message_index + 1];

                /* Embed message in the 2 highest bits of each byte */
                b2 |= (msg_byte << 6);

                /* If there's still more message to be encoded */
                if (message_index + 2 < message_len) {
                    msg_byte = message[message_index + 2];

                    /* Embed message in the 2 highest bits of each byte */
                    b3 |= (msg_byte << 6);

                    /* If there's still more message to be encoded */
                    if (message_index + 3 < message_len) {
                        msg_byte = message[message_index + 3];

                        /* Embed message in the 2 highest bits of each byte */
                        b4 |= (msg_byte << 6);
                    }
                }
            }

            message_index += 4;
        }

        /* Perform right shift on each byte */
        b1 = rightShift(b1, 2);
        b2 = rightShift(b2, 2);
        b3 = rightShift(b3, 2);

        /* Place modified bytes back in image data */
        image_data[i] = b1;
        image_data[i + 1] = b2;
        image_data[i + 2] = b3;
        image_data[i + 3] = b4;
    }

    /* Save modified image data */
    image_file = fopen(image_path, "wb");
    if (image_file == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    fwrite(image_data, 1, image_size, image_file);
    fclose(image_file);

    printf("Message successfully encoded in image file\n");
}

/* Function to extract message from image */
void extractMessage(char *image_path) {
    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    unsigned char image_data[MAX_SIZE];
    int image_size = fread(image_data, 1, MAX_SIZE, image_file);
    fclose(image_file);

    if (image_size == 0) {
        printf("Error reading image file\n");
        exit(1);
    }

    char message[MAX_SIZE];
    int message_index = 0;

    /* Iterate through each pixel of the image */
    for (int i = 0; i < image_size; i += 4) {
        unsigned char b1 = image_data[i];
        unsigned char b2 = image_data[i + 1];
        unsigned char b3 = image_data[i + 2];

        /* Perform left shift on each byte */
        b1 = leftShift(b1, 2);
        b2 = leftShift(b2, 2);
        b3 = leftShift(b3, 2);

        /* Extract message from 2 highest bits of each byte */
        char msg_byte = (b1 & 0xC0) >> 6;
        message[message_index++] = msg_byte;

        /* If message is not yet fully extracted */
        if (message_index < MAX_SIZE) {
            msg_byte = (b2 & 0xC0) >> 6;
            message[message_index++] = msg_byte;

            /* If there's still more message to be extracted */
            if (message_index < MAX_SIZE) {
                msg_byte = (b3 & 0xC0) >> 6;
                message[message_index++] = msg_byte;
            }
        }

        /* Perform right shift on each byte */
        b1 = rightShift(b1, 2);
        b2 = rightShift(b2, 2);
        b3 = rightShift(b3, 2);
    }

    printf("Extracted message: %s\n", message);
}

/* Test the steganography function */
int main() {
    char *image_path = "image.jpg";
    char *message = "This is a secret message";

    steganography(image_path, message);
    extractMessage(image_path);

    return 0;
}