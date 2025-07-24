//FormAI DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void grayscale(char* input, char* output, int width, int height) {
    FILE* input_file = fopen(input, "rb");
    FILE* output_file = fopen(output, "wb");

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);
    fwrite(header, sizeof(unsigned char), 54, output_file);

    unsigned char pixel[3];
    int padding = (4 - (width * sizeof(pixel)) % 4) % 4;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(pixel, sizeof(unsigned char), 3, input_file);

            int gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;

            fwrite(pixel, sizeof(unsigned char), 3, output_file);
        }

        fseek(input_file, padding, SEEK_CUR);

        for (int i = 0; i < padding; i++) {
            fputc(0, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input[] = "input.bmp";
    char output[] = "output.bmp";
    int width = 300;
    int height = 300;

    grayscale(input, output, width, height);

    printf("Grayscale conversion complete\n");

    return 0;
}