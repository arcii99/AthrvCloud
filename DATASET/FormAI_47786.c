//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 20

// ASCII characters arranged from darkest to lightest
char ascii_chars[] = {'@', '8', 'o', ':', '.', ' '};

// Custom color struct to store RGB values
typedef struct {
    int r;
    int g;
    int b;
} rgb_color;

// Custom pixel struct to store color and brightness
typedef struct {
    rgb_color color;
    int brightness;
} pixel;

// Function to convert a pixel to ASCII
char pixel_to_ascii(pixel p) {
    int num_chars = strlen(ascii_chars);
    int brightness_range = (255 * 3) / num_chars;
    int brightness_value = (p.color.r + p.color.g + p.color.b) / 3;

    for (int i = 0; i < num_chars; i++) {
        if (brightness_value <= (i+1) * brightness_range) {
            return ascii_chars[i];
        }
    }

    return ' ';
}

// Function to print an ASCII art image
void print_ascii(pixel image[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", pixel_to_ascii(image[y][x]));
        }
        printf("\n");
    }
}

int main() {
    // Create sample image with random color values
    pixel image[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            image[y][x].color.r = rand() % 256;
            image[y][x].color.g = rand() % 256;
            image[y][x].color.b = rand() % 256;
            image[y][x].brightness = 0;
        }
    }

    // Apply brightness filter to image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int brightness_sum = 0;
            int num_neighbors = 0;

            // Find brightness value for current pixel
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (x+j >= 0 && x+j < WIDTH && y+i >= 0 && y+i < HEIGHT) {
                        brightness_sum += image[y+i][x+j].brightness;
                        num_neighbors++;
                    }
                }
            }
            image[y][x].brightness = brightness_sum / num_neighbors;
        }
    }

    // Print ASCII art representation of image
    print_ascii(image);

    return 0;
}