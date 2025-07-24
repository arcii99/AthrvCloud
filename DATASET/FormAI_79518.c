//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54

// Structure for storing pixel data
typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

// Function to read BMP file header data
void read_bmp_header(FILE* fp, int* width, int* height) {
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, fp);
    *width = *(int*)&header[18]; // Width is at offset 18
    *height = *(int*)&header[22]; // Height is at offset 22
}

// Function to read pixel data from BMP file
void read_bmp_data(FILE* fp, Pixel* pixels, int width, int height) {
    int padding = (4 - (width * 3) % 4) % 4; // Padding at end of each row
    unsigned char pixel[3];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fread(pixel, sizeof(unsigned char), 3, fp);
            pixels[row * width + col].blue = (int)pixel[0];
            pixels[row * width + col].green = (int)pixel[1];
            pixels[row * width + col].red = (int)pixel[2];
        }
        // Skip over any padding at the end of the row
        fseek(fp, padding, SEEK_CUR);
    }
}

// Function to write pixel data to BMP file
void write_bmp_data(FILE* fp, Pixel* pixels, int width, int height) {
    int padding = (4 - (width * 3) % 4) % 4;
    unsigned char pixel[3];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            pixel[0] = (unsigned char)pixels[row * width + col].blue;
            pixel[1] = (unsigned char)pixels[row * width + col].green;
            pixel[2] = (unsigned char)pixels[row * width + col].red;
            fwrite(pixel, sizeof(unsigned char), 3, fp);
        }
        // Write padding at the end of each row
        for (int i = 0; i < padding; i++) {
            fputc(0x00, fp);
        }
    }
}

// Function to hide a message in the least significant bit of each color channel
void hide_message(char* message, Pixel* pixels, int width, int height, int length) {
    int index = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // Check if entire message has been hidden
            if (index >= length * 8) {
                return;
            }
            // Hide bit in blue channel
            if (index % 3 == 0) {
                pixels[row * width + col].blue = (pixels[row * width + col].blue & ~1) | ((message[index / 8] >> (index % 8)) & 1);
            }
            // Hide bit in green channel
            else if (index % 3 == 1) {
                pixels[row * width + col].green = (pixels[row * width + col].green & ~1) | ((message[index / 8] >> (index % 8)) & 1);
            }
            // Hide bit in red channel
            else if (index % 3 == 2) {
                pixels[row * width + col].red = (pixels[row * width + col].red & ~1) | ((message[index / 8] >> (index % 8)) & 1);
            }
            index++;
        }
    }
}

// Function to retrieve a hidden message from the least significant bit of each color channel
char* get_message(Pixel* pixels, int width, int height, int length) {
    char* message = malloc(sizeof(char) * length);
    memset(message, 0, sizeof(char) * length);
    int index = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // Check if entire message has been retrieved
            if (index >= length * 8) {
                return message;
            }
            // Retrieve bit from blue channel
            if (index % 3 == 0) {
                message[index / 8] |= (pixels[row * width + col].blue & 1) << (index % 8);
            }
            // Retrieve bit from green channel
            else if (index % 3 == 1) {
                message[index / 8] |= (pixels[row * width + col].green & 1) << (index % 8);
            }
            // Retrieve bit from red channel
            else if (index % 3 == 2) {
                message[index / 8] |= (pixels[row * width + col].red & 1) << (index % 8);
            }
            index++;
        }
    }
    return message;
}

int main(int argc, char const *argv[]) {
    // Get filename from command line arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char* filename = (char*)argv[1];

    // Open file for reading in binary mode
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s for reading.\n", filename);
        return 1;
    }

    int width, height;
    // Read header data and pixel data from BMP file
    read_bmp_header(fp, &width, &height);
    fseek(fp, HEADER_SIZE, SEEK_SET);
    Pixel* pixels = malloc(sizeof(Pixel) * width * height);
    read_bmp_data(fp, pixels, width, height);
    fclose(fp);

    // Hide message in the image and write to new file
    char* message = "This message is hidden";
    int message_length = strlen(message);
    hide_message(message, pixels, width, height, message_length);
    fp = fopen("hidden_image.bmp", "wb");
    if (!fp) {
        printf("Error: could not open file hidden_image.bmp for writing.\n");
        return 1;
    }
    fwrite(pixels, sizeof(Pixel), width * height, fp);
    fclose(fp);

    // Retrieve hidden message from new file
    fp = fopen("hidden_image.bmp", "rb");
    if (!fp) {
        printf("Error: could not open file hidden_image.bmp for reading.\n");
        return 1;
    }
    read_bmp_header(fp, &width, &height);
    fseek(fp, HEADER_SIZE, SEEK_SET);
    pixels = malloc(sizeof(Pixel) * width * height);
    read_bmp_data(fp, pixels, width, height);
    fclose(fp);
    char* retrieved_message = get_message(pixels, width, height, message_length);
    printf("Hidden message: %s\n", retrieved_message);

    free(pixels);
    free(retrieved_message);
    
    return 0;
}