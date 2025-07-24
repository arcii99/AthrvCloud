//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

char shades[] = " .,:;irsXA253hMHGS#9B&@";

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    FILE *in = fopen(input_filename, "rb");
    if (!in) {
        printf("Error: unable to open file %s\n", input_filename);
        return 1;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    int width = 0, height = 0;
    while (!feof(in) && height < MAX_HEIGHT) {
        int i = 0;
        for (; i < MAX_WIDTH && !feof(in); ++i) {
            image[height][i] = fgetc(in);
        }
        if (i > width) width = i;
        ++height;
    }

    fclose(in);

    char ascii_image[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int index = (int)(image[i][j] / 11);
            ascii_image[i][j] = shades[index];
        }
    }

    FILE *out = fopen(output_filename, "w");
    if (!out) {
        printf("Error: unable to open file %s\n", output_filename);
        return 1;
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fputc(ascii_image[i][j], out);
        }
        fputc('\n', out);
    }

    fclose(out);

    printf("File saved to %s\n", output_filename);

    return 0;
}