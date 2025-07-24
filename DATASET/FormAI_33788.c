//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PIXELS 1000000

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR: No input file provided. Usage: ./asciiart input_file");
        return 1;
    }

    char *input_file = argv[1];
    FILE *fp = fopen(input_file, "rb");
    if (!fp) {
        printf("ERROR: Could not open input file");
        return 1;
    }

    char output_file[100];
    printf("Enter output filename: ");
    scanf("%s", output_file);

    int width, height, depth;
    char magic_number[10];
    fscanf(fp, "%s %d %d %d", magic_number, &width, &height, &depth);
    int max_gray = pow(2, depth) - 1;

    unsigned char pixels[width][height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char pixel;
            fscanf(fp, "%hhu", &pixel);
            pixels[i][j] = pixel;
        }
    }

    fclose(fp);

    char ascii_chars[] = "$@B%8&WM#*oahkbdpwmZO0QCJYXzcvnxrjft/\|()1{}[]?_+-~<>i!lI;:,\"^`\'. ";
    int num_chars = strlen(ascii_chars);

    char ascii_art[MAX_PIXELS];
    int index = 0;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int pixel_val = pixels[i][j];
            int char_index = (int)(pixel_val / (max_gray / num_chars)) - 1;
            if (char_index < 0) char_index = 0;
            ascii_art[index++] = ascii_chars[char_index];
        }
        ascii_art[index++] = '\n';
    }
    ascii_art[index] = '\0';

    fp = fopen(output_file, "w");
    if (!fp) {
        printf("ERROR: Could not open output file");
        return 1;
    }

    fprintf(fp, "%s", ascii_art);
    fclose(fp);

    printf("Conversion successful. Output file: %s", output_file);

    return 0;
}