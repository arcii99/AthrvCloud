//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3 // RGB values
#define HEADER_SIZE 54 

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// function to extract the LSB of an integer
int get_lsb(int num)
{
    return num & 1;
}

// function to embed message into the image
void embed_message(FILE *image, char *message)
{
    // read the header of the image
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, image);

    // read the pixels of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int padding = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;

    pixel *image_pixels = (pixel *)malloc(width * height * sizeof(pixel));
    fseek(image, HEADER_SIZE, SEEK_SET);
    int i, j, k = 0;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            fread(&image_pixels[i * width + j], sizeof(pixel), 1, image);
        }
        fseek(image, padding, SEEK_CUR);
    }

    // embed the message into the LSBs of the pixel values
    int message_len = strlen(message);
    if (message_len > width * height) {
        printf("Message too long to embed into the image.\n");
        return;
    }
    for (i = 0; i < message_len; ++i) {
        char c = message[i];
        for (j = 0; j < BYTES_PER_PIXEL; ++j) {
            int lsb = get_lsb(c);
            c >>= 1;
            if (k < width * height) {
                image_pixels[k].r = (image_pixels[k].r & 0xFE) | lsb;
                image_pixels[k].g = (image_pixels[k].g & 0xFE) | lsb;
                image_pixels[k].b = (image_pixels[k].b & 0xFE) | lsb;
                ++k;
            }
        }
    }

    // write the modified pixels back into the image
    fseek(image, HEADER_SIZE, SEEK_SET);
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            fwrite(&image_pixels[i * width + j], sizeof(pixel), 1, image);
        }
        fwrite(&(int){0}, padding, 1, image); // write padding
    }

    free(image_pixels);
    printf("Message embedded successfully!\n");
}

// function to extract message from the image
void extract_message(FILE *image)
{
    // read the header of the image
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, image);

    // read the pixels of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int padding = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;

    pixel *image_pixels = (pixel *)malloc(width * height * sizeof(pixel));
    fseek(image, HEADER_SIZE, SEEK_SET);
    int i, j, k = 0;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            fread(&image_pixels[i * width + j], sizeof(pixel), 1, image);
        }
        fseek(image, padding, SEEK_CUR);
    }

    // extract the message from the LSBs of the pixel values
    char message[width * height + 1];
    memset(message, 0, sizeof(message));
    for (i = 0; i < width * height; ++i) {
        int lsb = get_lsb(image_pixels[i].r);
        message[k] = (message[k] << 1) | lsb;
        ++k;

        lsb = get_lsb(image_pixels[i].g);
        message[k] = (message[k] << 1) | lsb;
        ++k;

        lsb = get_lsb(image_pixels[i].b);
        message[k] = (message[k] << 1) | lsb;
        ++k;
    }

    // print the extracted message
    printf("Extracted message: %s\n", message);

    free(image_pixels);
}

int main()
{
    FILE *image = fopen("image.bmp", "rb+");
    if (!image) {
        printf("Error opening image file.\n");
        return 1;
    }

    char message[100];
    printf("Enter message to embed (max 100 characters): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\r\n")] = 0; // remove newline characters

    embed_message(image, message);
    extract_message(image);
    
    fclose(image);
    return 0;
}