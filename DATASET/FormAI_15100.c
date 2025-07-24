//FormAI DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

// Define a macro for getting the bit value of a given number at a particular position
#define GETBIT(x, pos) ( ( x & (1 << pos) ) ? 1 : 0 )

// Define a macro for setting a bit value of a given number at a particular position
#define SETBIT(x, pos) ( x | (1 << pos) )

// Define a macro for resetting a bit value of a given number at a particular position
#define RESETBIT(x, pos) ( x & ~(1 << pos) )

// Function to read an image file and return its pixel data
unsigned char* read_image(char* filename, int* width, int* height, int* channels) {
    // Open the image file in binary mode
    FILE* fp = fopen(filename, "rb");

    // Check if file was opened successfully
    if(!fp) {
        printf("Error: Unable to open file '%s'!\n", filename);
        return NULL;
    }

    // Read the image file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Get the image dimensions
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Get the number of color channels
    *channels = *(int*)&header[28] / 8;

    // Allocate memory for the image pixel data
    unsigned char* data = (unsigned char*)malloc((*width)*(*height)*(*channels)*sizeof(unsigned char));

    // Read the image pixel data
    fread(data, sizeof(unsigned char), (*width)*(*height)*(*channels), fp);

    // Close the image file
    fclose(fp);

    // Return the image pixel data
    return data;
}

// Function to write an image file from the given pixel data
void write_image(char* filename, unsigned char* data, int width, int height, int channels) {
    // Open the image file in binary mode
    FILE* fp = fopen(filename, "wb");

    // Check if file was opened successfully
    if(!fp) {
        printf("Error: Unable to open file '%s'!\n", filename);
        return;
    }

    // Write the image header
    unsigned char header[54] = {
        0x42, 0x4D, 0x36, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x64, 0x00,
        0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(int*)&header[28] = channels*8;
    fwrite(header, sizeof(unsigned char), 54, fp);

    // Write the image pixel data
    fwrite(data, sizeof(unsigned char), width*height*channels, fp);

    // Close the image file
    fclose(fp);
}

// Function to perform steganography on the given pixel data
unsigned char* steganography(unsigned char* data, int width, int height, int channels, char* message) {
    // Calculate the maximum length of the message that can be hidden in the image
    int max_message_len = (width*height*channels)/8;

    // Calculate the length of the message
    int message_len = 0;
    while(message[message_len] != '\0') {
        message_len++;
    }

    // Check if the message can be hidden in the image
    if(message_len > max_message_len) {
        printf("Error: Maximum message length exceeded!\n");
        return NULL;
    }

    // Copy the original pixel data into a new buffer
    unsigned char* new_data = (unsigned char*)malloc(width*height*channels*sizeof(unsigned char));
    for(int i = 0; i < width*height*channels; i++) {
        new_data[i] = data[i];
    }

    // Loop through each byte of the message
    for(int i = 0; i < message_len; i++) {
        // Loop through each bit of the byte
        for(int j = 0; j < 8; j++) {
            // Calculate the index of the current bit in the new_data array
            int index = i*8 + j;

            // Calculate the position of the current bit in the corresponding byte in the pixel data
            int pos = index % channels;

            // Get the original bit value of the current bit in the corresponding byte in the pixel data
            int original_bit = GETBIT(new_data[index/channels], 7-pos);

            // Get the bit value of the current bit in the current byte of the message
            int message_bit = GETBIT(message[i], 7-j);

            // Set the new bit value of the current bit in the corresponding byte in the pixel data
            if(original_bit != message_bit) {
                new_data[index/channels] = (unsigned char)SETBIT(new_data[index/channels], 7-pos);
            }
        }
    }

    // Return the new pixel data with the message hidden in it
    return new_data;
}

int main() {
    // Read the original image file and get its pixel data
    int width, height, channels;
    unsigned char* data = read_image("original_image.bmp", &width, &height, &channels);
    if(!data) {
        return 0;
    }

    // Ask the user for the message to be hidden in the image
    char message[256];
    printf("Enter the message to be hidden in the image: ");
    fgets(message, sizeof(message), stdin);

    // Perform steganography on the original image pixel data to hide the message in it
    unsigned char* new_data = steganography(data, width, height, channels, message);
    if(!new_data) {
        free(data);
        return 0;
    }

    // Write the new image file with the message hidden in it
    write_image("new_image.bmp", new_data, width, height, channels);

    // Free the allocated memory
    free(data);
    free(new_data);

    return 0;
}