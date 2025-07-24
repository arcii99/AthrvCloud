//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
// Maximum number of characters per line

#define HEIGHT 80
// Maximum number of lines

#define SCALE 4
// Number of pixels per ASCII character

const char ASCII_CHARS[] = " .:-=+*#%@";
// Characters in order of darkness, from lightest to darkest

void convert_to_ascii(unsigned char img[HEIGHT][WIDTH], char ascii[HEIGHT * SCALE][WIDTH * SCALE + 1]) {
    // Convert image to ASCII art

    int i, j, k, l;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            // Calculate darkness of current pixel

            int pixel_value = img[i][j];
            int darkness = (int)(10.0 * (255 - pixel_value) / 255.0);

            // Map darkness to character

            char c = ASCII_CHARS[darkness];

            // Assign character to corresponding positions in ASCII art

            for(k = 0; k < SCALE; k++) {
                for(l = 0; l < SCALE; l++) {
                    ascii[i * SCALE + k][j * SCALE + l] = c;
                }
            }
        }
    }

    // Add null character to end of each line of ASCII art

    for(i = 0; i < HEIGHT * SCALE; i++) {
        ascii[i][WIDTH * SCALE] = '\0';
    }
}

int main(int argc, char *argv[]) {
    // Read image from file

    unsigned char img[HEIGHT][WIDTH];
    FILE *fp = fopen("image.raw", "r");
    fread(img, 1, HEIGHT * WIDTH, fp);
    fclose(fp);

    // Convert image to ASCII art

    char ascii[HEIGHT * SCALE][WIDTH * SCALE + 1];
    convert_to_ascii(img, ascii);

    // Print ASCII art to console

    int i;
    for(i = 0; i < HEIGHT * SCALE; i++) {
        printf("%s\n", ascii[i]);
    }

    return 0;
}