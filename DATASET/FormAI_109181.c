//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 8
#define HEIGHT 8

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    // Open input file
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Error: could not open file %s\n", input_filename);
        return 1;
    }

    // Open output file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: could not create file %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Read input file and store in 2D array
    char pixel_array[WIDTH][HEIGHT];
    size_t bytes_read;
    bytes_read = fread(pixel_array, 1, WIDTH * HEIGHT, input_file);
    if (bytes_read != WIDTH * HEIGHT) {
        printf("Error: could not read %d bytes from file %s\n", WIDTH * HEIGHT, input_filename);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    // Define watermark as 2D array
    char watermark[2][2] = {
        {1, 1},
        {1, -1}
    };

    // Embed the watermark in the least significant bit of each pixel
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            char pixel = pixel_array[i][j];
            int bit_index = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    char watermark_value = watermark[k][l];
                    char new_pixel = pixel;
                    int shift_amount = bit_index % 8;
                    if (watermark_value == 1) {
                        new_pixel |= (1 << shift_amount);
                    } else {
                        new_pixel &= ~(1 << shift_amount);
                    }
                    pixel_array[i + k][j + l] = new_pixel;
                    bit_index++;
                }
            }
        }
    }

    // Write the modified pixel array to output file
    fwrite(pixel_array, 1, WIDTH * HEIGHT, output_file);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Watermark generated and embedded in file %s\n", output_filename);

    return 0;
}