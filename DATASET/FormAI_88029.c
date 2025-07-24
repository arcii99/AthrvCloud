//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    unsigned int width;
    unsigned int height;
    Pixel *pixels;
} Image;

int main(int argc, char *argv[]) {

    char *msg = "This is a secret message";

    // Load cover image
    FILE *f = fopen("cover_image.bmp", "rb");
    Image image;
    fread(&image, sizeof(Image), 1, f);
    fclose(f);

    // Calculate number of pixels in image
    int num_pixels = image.width * image.height;

    // Convert message to binary
    int msg_len = strlen(msg);
    int bits_required = msg_len * 8;
    char *msg_binary = malloc(bits_required + 1);
    for (int i = 0; i < msg_len; i++) {
        char c = msg[i];
        for (int j = 0; j < 8; j++) {
            msg_binary[i * 8 + j] = (c >> (7 - j)) & 1 ? '1' : '0';
        }
    }
    msg_binary[bits_required] = '\0';

    // Check if image has enough pixels to hide message
    if (bits_required > num_pixels * 3) {
        printf("Error: message too large to hide in image\n");
        return 1;
    }

    // Hide message in image
    int msg_index = 0;
    for (int i = 0; i < num_pixels; i++) {
        Pixel p = image.pixels[i];
        if (msg_index < bits_required) {
            p.red &= ~1;
            p.green &= ~1;
            p.blue &= ~1;
            if (msg_binary[msg_index] == '1') {
                p.red |= 1;
            }
            msg_index++;
            if (msg_binary[msg_index] == '1') {
                p.green |= 1;
            }
            msg_index++;
            if (msg_binary[msg_index] == '1') {
                p.blue |= 1;
            }
            msg_index++;
        }
        image.pixels[i] = p;
    }

    // Save stego image
    f = fopen("stego_image.bmp", "wb");
    fwrite(&image, sizeof(Image), 1, f);
    fclose(f);

    // Read stego image and extract message
    f = fopen("stego_image.bmp", "rb");
    fread(&image, sizeof(Image), 1, f);
    fclose(f);

    char *extracted_msg_binary = malloc(bits_required + 1);
    msg_index = 0;
    for (int i = 0; i < num_pixels; i++) {
        Pixel p = image.pixels[i];
        if (msg_index < bits_required) {
            if (p.red & 1) {
                extracted_msg_binary[msg_index] = '1';
            } else {
                extracted_msg_binary[msg_index] = '0';
            }
            msg_index++;
            if (p.green & 1) {
                extracted_msg_binary[msg_index] = '1';
            } else {
                extracted_msg_binary[msg_index] = '0';
            }
            msg_index++;
            if (p.blue & 1) {
                extracted_msg_binary[msg_index] = '1';
            } else {
                extracted_msg_binary[msg_index] = '0';
            }
            msg_index++;
        }
    }
    extracted_msg_binary[bits_required] = '\0';

    // Convert extracted message to ASCII
    char *extracted_msg = malloc(msg_len + 1);
    for (int i = 0; i < msg_len; i++) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= (extracted_msg_binary[i * 8 + j] - '0') << (7 - j);
        }
        extracted_msg[i] = byte;
    }
    extracted_msg[msg_len] = '\0';

    printf("Extracted message: %s\n", extracted_msg);

    return 0;
}