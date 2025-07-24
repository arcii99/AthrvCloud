//FormAI DATASET v1.0 Category: Image Steganography ; Style: random
#include<stdio.h>
#include<stdlib.h>

#define IMG_HEIGHT  480
#define IMG_WIDTH   640
#define IMG_SIZE    IMG_HEIGHT * IMG_WIDTH * 3
#define BITS_TO_READ 4

int main()
{
    FILE *image, *new_image, *message;
    unsigned char img_data[IMG_SIZE], msg_data;
    unsigned char bit_shift[] = {128, 64, 32, 16, 8, 4, 2, 1};
    unsigned char read_bits[BITS_TO_READ], new_bit;
    int i, j, img_index, msg_index, bit_index, bits_read, msg_bits, new_pix;
    long unsigned int img_size;
    image = fopen("image.jpg", "rb");
    fread(img_data, 1, IMG_SIZE, image);
    fclose(image);
    msg_data = fgetc(message);
    while(msg_data != EOF)
    {
        bits_read = 0;
        while(bits_read < BITS_TO_READ)
        {
            read_bits[bits_read] = msg_data & bit_shift[bits_read];
            bits_read++;
        }
        for(i = 0; i < IMG_SIZE; i++)
        {
            img_index = i * sizeof(unsigned char);
            msg_index = i % BITS_TO_READ;
            bit_index = (BITS_TO_READ - 1) - (i / BITS_TO_READ);
            new_pix = img_data[img_index];
            new_bit = (new_pix & ~1) | read_bits[msg_index];
            img_data[img_index] = new_bit;
        }
    }
    new_image = fopen("new_image.jpg", "wb");
    fwrite(img_data, 1, IMG_SIZE, new_image);
    fclose(new_image);
    return 0;
}