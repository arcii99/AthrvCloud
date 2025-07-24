//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Constants for color values
#define BLACK 0
#define WHITE 255

// Constants for pixel matrix dimensions
#define ROWS 10
#define COLS 10

// Struct for storing pixel information
typedef struct {
    int color;
} Pixel;

// Function to randomly generate pixel color value
int getPixelColor() {
    return rand() % 2 == 0 ? BLACK : WHITE;
}

// Function to print the pixel matrix to console
void printPixelMatrix(Pixel matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j].color == BLACK) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Thread function to asynchronously generate pixel colors in a row
void* generatePixelRow(void* arg) {
    Pixel (*matrix)[COLS] = arg; // Cast argument back into 2D pixel matrix
    time_t t;
    srand((unsigned) time(&t)); // Seed random number generator

    int row = rand() % ROWS; // Pick a random row to generate
    for (int j = 0; j < COLS; j++) {
        matrix[row][j].color = getPixelColor(); // Set pixel color
    }

    return NULL;
}

int main(void) {
    pthread_t thread;
    Pixel matrix[ROWS][COLS];

    // Initialize the pixel matrix with random colors
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j].color = getPixelColor();
        }
    }

    printPixelMatrix(matrix);

    // Start asynchronous thread to generate new row of pixels
    pthread_create(&thread, NULL, generatePixelRow, (void*) matrix);
    pthread_join(thread, NULL); // Wait for thread to finish

    printf("\n");

    printPixelMatrix(matrix);

    return 0;
}