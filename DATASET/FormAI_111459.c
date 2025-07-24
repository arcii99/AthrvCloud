//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 10
#define CANVAS_SIZE 100
#define MAX_COLOR 255

int main() {
    srand(time(NULL));
    int canvas[CANVAS_SIZE][CANVAS_SIZE];

    // Initialize canvas to white
    for(int i=0; i<CANVAS_SIZE; i++) {
        for(int j=0; j<CANVAS_SIZE; j++) {
            canvas[i][j] = MAX_COLOR;
        }
    }

    // Draw the pixel art
    for(int i=0; i<CANVAS_SIZE/PIXEL_SIZE; i++) {
        for(int j=0; j<CANVAS_SIZE/PIXEL_SIZE; j++) {
            int r = rand() % MAX_COLOR; // Random red value
            int g = rand() % MAX_COLOR; // Random green value
            int b = rand() % MAX_COLOR; // Random blue value

            // Draw the pixel
            for(int k=0; k<PIXEL_SIZE; k++) {
                for(int l=0; l<PIXEL_SIZE; l++) {
                    canvas[i*PIXEL_SIZE+k][j*PIXEL_SIZE+l] = r << 16 | g << 8 | b; // Store the RGB values in the pixel
                }
            }
        }
    }

    // Output the pixel art
    FILE* f = fopen("pixel_art.ppm", "wb"); // Open a file to write the pixel art to
    fprintf(f, "P6 %d %d %d\n", CANVAS_SIZE, CANVAS_SIZE, MAX_COLOR); // Write the PPM header
    for(int i=0; i<CANVAS_SIZE; i++) {
        for(int j=0; j<CANVAS_SIZE; j++) {
            fwrite(&canvas[i][j], 3, 1, f); // Write the pixel data to the file
        }
    }
    fclose(f);

    return 0;
}