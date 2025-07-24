//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 100
#define MAX_ASCII_SIZE 70

typedef struct {
    int width, height;
    char pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

int getAsciiChar(int grayValue, char asciiChars[]);
void generateAsciiChars(char asciiChars[]);

int main() {
    Image image;
    char asciiChars[MAX_ASCII_SIZE];

    generateAsciiChars(asciiChars);

    FILE *fp = fopen("example_image.pgm", "r");
    if (!fp) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the header
    char header[256];
    fgets(header, sizeof(header), fp);
    if (strcmp(header, "P2\n") != 0) {
        printf("Error: Invalid file format\n");
        return EXIT_FAILURE;
    }

    // Read the width, height and maximum gray value
    fscanf(fp, "%d %d\n255\n", &image.width, &image.height);
    if (image.width > MAX_WIDTH || image.height > MAX_HEIGHT) {
        printf("Error: Image too large\n");
        return EXIT_FAILURE;
    }

    // Read the pixel values
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            fscanf(fp, "%hhu ", &image.pixels[i][j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);

    // Convert image to ASCII art and print to console
    for (int i = 0; i < image.height; i += 2) {
        for (int j = 0; j < image.width; j++) {
            int grayValue = ((int)image.pixels[i][j] + (int)image.pixels[i + 1][j]) / 2;
            putchar(getAsciiChar(grayValue, asciiChars));
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

int getAsciiChar(int grayValue, char asciiChars[]) {
    // Map the gray value to an index in the ASCII character array
    int asciiIndex = grayValue / (255 / (strlen(asciiChars) - 1));
    return asciiChars[asciiIndex];
}

void generateAsciiChars(char asciiChars[]) {
    // Add additional ASCII characters to the array to create a shape-shifting effect
    strcpy(asciiChars, " .':,\"/\\|(){}[]?-_+=*^%$#@");
    strcat(asciiChars, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strcat(asciiChars, "abcdefghijklmnopqrstuvwxyz");
    strcat(asciiChars, "0123456789");
    strcat(asciiChars, "\n");
}