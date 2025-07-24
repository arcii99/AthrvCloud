//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>

int main()
{
    FILE *image_fp, *output_fp;
    unsigned char pixel[3], message_byte;
    int bit_pos, i;

    // Open the image file for reading
    image_fp = fopen("image.bmp", "rb");

    // Open a new file for writing the output image
    output_fp = fopen("output.bmp", "wb");

    // Read the header bytes of the input image and write them to the output image
    for (i = 0; i < 54; i++)
    {
        int c = fgetc(image_fp);
        fputc(c, output_fp);
    }

    // Read the message byte by byte and encode it into the least significant bits of the image pixels
    while ((message_byte = getchar()) != EOF)
    {
        for (bit_pos = 0; bit_pos < 8; bit_pos++)
        {
            // Read the next pixel from the image
            fread(pixel, sizeof(pixel), 1, image_fp);

            // Write the pixel with the current bit of the message byte encoded into its least significant bit
            pixel[2] = (pixel[2] & 0xFE) | ((message_byte >> bit_pos) & 0x01);
            fwrite(pixel, sizeof(pixel), 1, output_fp);
        }
    }

    // If the message was less than 256 bytes long, add an end-of-message byte to the output
    for (bit_pos = 0; bit_pos < 8; bit_pos++)
    {
        fread(pixel, sizeof(pixel), 1, image_fp);
        pixel[2] &= 0xFE;
        fwrite(pixel, sizeof(pixel), 1, output_fp);
    }

    // Close the input and output files
    fclose(image_fp);
    fclose(output_fp);

    return 0;
}