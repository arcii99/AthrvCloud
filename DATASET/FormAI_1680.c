//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_MSG_LEN 10000
#define MAX_IMG_SIZE 1000000
#define HEADER_SIZE 54
#define BYTE_SIZE 8

// define function prototypes
int hide_message(char *msg, char *img_path, char *output_path);
int extract_message(char *img_path);

// main function
int main(int argc, char** argv) {
    // check command line arguments
    if (argc < 3) {
        printf("Usage: %s <msg_file> <img_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // read message from file
    char msg[MAX_MSG_LEN];
    FILE *msg_file = fopen(argv[1], "r");
    if (!msg_file) {
        printf("Error opening message file!\n");
        exit(EXIT_FAILURE);
    }
    fgets(msg, MAX_MSG_LEN, msg_file);
    fclose(msg_file);
    
    // hide message in image
    int result = hide_message(msg, argv[2], "output.bmp");
    if (result == -1) {
        printf("Error hiding message!\n");
        exit(EXIT_FAILURE);
    }
    printf("Message hidden successfully!\n");
    
    // extract message from image
    result = extract_message("output.bmp");
    if (result == -1) {
        printf("Error extracting message!\n");
        exit(EXIT_FAILURE);
    }
    printf("Message extracted successfully!\n");
    
    return 0;
}

/**
 * Hides a message in an image using LSB steganography.
 * @param msg The message to hide.
 * @param img_path The path to the input image.
 * @param output_path The path to the output image.
 * @return 0 if successful, -1 otherwise.
 */
int hide_message(char *msg, char *img_path, char *output_path) {
    // open input and output files
    FILE *img_file = fopen(img_path, "rb");
    if (!img_file) {
        printf("Error opening image file!\n");
        return -1;
    }
    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        printf("Error creating output file!\n");
        fclose(img_file);
        return -1;
    }
    
    // read image header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, img_file);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, output_file);
    
    // read image data
    unsigned char img_data[MAX_IMG_SIZE];
    int img_size = fread(img_data, sizeof(unsigned char), MAX_IMG_SIZE, img_file);
    if (img_size == MAX_IMG_SIZE) {
        printf("Image too large!\n");
        fclose(img_file);
        fclose(output_file);
        return -1;
    }
    
    // iterate over each character in the message
    int msg_len = strlen(msg);
    int bit_count = 0;
    for (int i = 0; i < msg_len; i++) {
        // get ASCII value of character
        unsigned char c = (unsigned char) msg[i];
        // iterate over each bit in the character
        for (int j = 0; j < BYTE_SIZE; j++) {
            // update least significant bit of image data
            unsigned char bit = (c >> j) & 1;
            img_data[bit_count] &= 0xFE;
            img_data[bit_count] |= bit;
            bit_count++;
        }
    }
    
    // write modified image data to output file
    fwrite(img_data, sizeof(unsigned char), img_size, output_file);
    
    // close input and output files
    fclose(img_file);
    fclose(output_file);
    
    return 0;
}

/**
 * Extracts a message from an image using LSB steganography.
 * @param img_path The path to the input image.
 * @return 0 if successful, -1 otherwise.
 */
int extract_message(char *img_path) {
    // open input file
    FILE *img_file = fopen(img_path, "rb");
    if (!img_file) {
        printf("Error opening image file!\n");
        return -1;
    }
    
    // read image header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, img_file);
    
    // read image data
    unsigned char img_data[MAX_IMG_SIZE];
    int img_size = fread(img_data, sizeof(unsigned char), MAX_IMG_SIZE, img_file);
    
    // iterate over each bit in the image data
    unsigned char c = 0;
    int bit_count = 0;
    int msg_len = 0;
    int msg_index = 0;
    while (bit_count < img_size * BYTE_SIZE) {
        // extract least significant bit of image data
        unsigned char bit = img_data[bit_count] & 1;
        c |= (bit << msg_index);
        bit_count++;
        msg_index++;
        // if we've extracted a full character, add it to the message
        if (msg_index == BYTE_SIZE) {
            msg_len++;
            printf("%c", c);
            // stop extracting characters if we've reached the end of the message
            if (c == '\0') {
                break;
            }
            c = 0;
            msg_index = 0;
        }
    }
    
    // close input file
    fclose(img_file);
    
    return 0;
}