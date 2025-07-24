//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 8
#define MAX_COLORS 3
#define PARANOID_MODE

#ifdef PARANOID_MODE
#define SECURITY_LIMIT 500
#endif

void generate_pixels(int pixels[WIDTH][HEIGHT]);

int main() {
    int pixels[WIDTH][HEIGHT];
    srand(time(NULL));

#ifdef PARANOID_MODE
    int security_counter = 0;
#endif

    generate_pixels(pixels);

#ifdef PARANOID_MODE
    while (security_counter < SECURITY_LIMIT) {
#endif
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int pixel = pixels[x][y];
                if (pixel == 0) {
                    printf(" ");
                } else if (pixel == 1) {
                    printf("*");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }

#ifdef PARANOID_MODE
        // Check if the pixels were tampered with
        int tampered_pixels = 0;
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int pixel = pixels[x][y];
                if (pixel != 0 && pixel != 1 && pixel != 2) {
                    tampered_pixels++;
                    // Reset the pixel to a safe value
                    pixels[x][y] = rand() % MAX_COLORS;
                }
            }
        }

        if (tampered_pixels > 0) {
            printf("WARNING: %d tampered pixels detected and reset\n", tampered_pixels);
        }

        security_counter++;
    }

    printf("SECURITY LIMIT REACHED. SHUTTING DOWN\n");
    // Erase all pixel data
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[x][y] = 0;
        }
    }
#endif

    return 0;
}

void generate_pixels(int pixels[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[x][y] = rand() % MAX_COLORS;
        }
    }
}