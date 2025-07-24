//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_SIZE 100
#define MESSAGE_SIZE 20

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

int main() {
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // read image pixels
    Pixel pixels[IMG_SIZE][IMG_SIZE];
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            fread(&pixels[i][j], sizeof(Pixel), 1, fp);
        }
    }

    // read message
    char message[MESSAGE_SIZE];
    printf("Enter message to hide (max length is %d): ", MESSAGE_SIZE);
    fgets(message, MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    // hide message in image pixels
    int bit_pos = 0;
    for (int i = 0; i < strlen(message); i++) {
        char letter = message[i];
        for (int j = 0; j < 8; j++) {
            int bit = (letter >> j) & 1;
            int pixel_x = (bit_pos / IMG_SIZE) % IMG_SIZE;
            int pixel_y = bit_pos % IMG_SIZE;
            pixels[pixel_x][pixel_y].blue = (pixels[pixel_x][pixel_y].blue & 0xFE) | bit;
            bit_pos++;
        }
    }

    // write modified pixels to new image file
    FILE *fp_out = fopen("image_out.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, fp_out);
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            fwrite(&pixels[i][j], sizeof(Pixel), 1, fp_out);
        }
    }
    printf("Message hidden successfully!\n");

    fclose(fp);
    fclose(fp_out);
    return 0;
}