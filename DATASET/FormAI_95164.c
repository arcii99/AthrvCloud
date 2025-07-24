//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: enthusiastic
// Welcome to the C Pixel Art Generator!
// This program generates a custom pixel art design based on user input
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 // width of the art
#define HEIGHT 10 // height of the art

// function to randomly generate a color
char randomColor() {
    char colors[6] = "RGBYOP"; // Red, Green, Blue, Yellow, Orange, Purple
    return colors[rand() % 6]; // return a random color from the array
}

// main function
int main() {
    // set random seed based on current time
    srand(time(NULL));
    
    // create 2D array for the pixel art
    char pixels[HEIGHT][WIDTH];
    
    // loop through the array and generate each pixel
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = randomColor(); // assign a random color to each pixel
        }
    }
    
    // print the pixel art
    printf("Here's your custom pixel art:\n\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixels[i][j]); // print each pixel with a space between them
        }
        printf("\n"); // move to the next row
    }
    
    // end of program
    printf("\nThanks for using the C Pixel Art Generator! Have a colorful day!\n");
    return 0;
}