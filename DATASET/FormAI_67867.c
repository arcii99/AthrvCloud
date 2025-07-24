//FormAI DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 1000000
#define MAX_MSG_SIZE 1000
#define BITS_IN_BYTE 8

bool is_bit_set(unsigned char c, int i) {
    return (c & (1 << i)) != 0;
}

void set_bit(unsigned char* c, int i, bool val) {
    if (val)
        *c |= (1 << i);
    else
        *c &= ~(1 << i);
}

void write_bit(unsigned char* data, int bit_pos, bool bit_val) {
    int byte_pos = bit_pos / BITS_IN_BYTE;
    int bit_in_byte = bit_pos % BITS_IN_BYTE;
    set_bit(&data[byte_pos], bit_in_byte, bit_val);
}

bool read_bit(unsigned char* data, int bit_pos) {
    int byte_pos = bit_pos / BITS_IN_BYTE;
    int bit_in_byte = bit_pos % BITS_IN_BYTE;
    return is_bit_set(data[byte_pos], bit_in_byte);
}

void hide_msg(unsigned char* image, int image_size, char* msg, int msg_size) {
    if (image_size * BITS_IN_BYTE < msg_size) {
        printf("Unable to hide message in image, not enough space.\n");
        return;
    }

    int bit_pos = 0;
    for (int i = 0; i < msg_size; i++) {
        unsigned char c = msg[i];
        for (int j = 0; j < BITS_IN_BYTE; j++) {
            bool bit_val = is_bit_set(c, j);
            write_bit(image, bit_pos, bit_val);
            bit_pos++;
        }
    }
}

void extract_msg(unsigned char* image, int image_size, char* msg, int msg_size) {
    int bit_pos = 0;
    for (int i = 0; i < msg_size; i++) {
        unsigned char c = 0;
        for (int j = 0; j < BITS_IN_BYTE; j++) {
            bool bit_val = read_bit(image, bit_pos);
            set_bit(&c, j, bit_val);
            bit_pos++;
        }
        msg[i] = c;
    }
}

int main() {
    FILE *fp = fopen("image.bmp", "rb");
    if (!fp) {
        printf("Unable to open image file.\n");
        return 1;
    }

    unsigned char image[MAX_IMAGE_SIZE];
    int image_size = fread(image, sizeof(char), MAX_IMAGE_SIZE, fp);
    fclose(fp);

    char msg[MAX_MSG_SIZE] = "Steganography is awesome!";
    hide_msg(image, image_size, msg, strlen(msg));

    fp = fopen("stego_image.bmp", "wb");
    if (!fp) {
        printf("Unable to create stego image file.\n");
        return 1;
    }
    fwrite(image, sizeof(char), image_size, fp);
    fclose(fp);

    char extracted_msg[MAX_MSG_SIZE];
    extract_msg(image, image_size, extracted_msg, strlen(msg));
    extracted_msg[strlen(msg)] = '\0';
    printf("Extracted message: %s\n", extracted_msg);

    return 0;
}