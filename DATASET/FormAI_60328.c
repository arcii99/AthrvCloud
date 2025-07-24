//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 32  // Size of the pixel art
#define COLORS 8  // Number of colors available for the pixel art

// Function to randomly select a color
int select_color(){
    return (rand() % COLORS) + 1;
}

// Function to generate the pixel art
void generate_pixel_art(int art[SIZE][SIZE], int colors){
    // Seed the random number generator
    srand(time(NULL));

    // Generate the pixel art
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            art[i][j] = select_color();
        }
    }
}

// Function to print the pixel art
void print_pixel_art(int art[SIZE][SIZE]){
    // Print the pixel art
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%d ", art[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Declare the pixel art array
    int pixel_art[SIZE][SIZE];

    // Generate the pixel art
    generate_pixel_art(pixel_art, COLORS);

    // Print the pixel art
    print_pixel_art(pixel_art);

    return 0;
}