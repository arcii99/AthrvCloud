//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // This is the size of your art canvas

// This function generates a random pixel character 
char randomPixel() {
    char pixels[] = {' ', '#', '*', '@', 'O', 'o', '+'}; // ASCII characters for pixels
    int index = rand() % 7;
    return pixels[index];
}

int main() {
    srand(time(NULL)); // Set the seed for the random function
    
    char canvas[SIZE][SIZE]; // This is your art canvas
    
    // Fill the canvas with random pixels
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            canvas[i][j] = randomPixel();
        }
    }
    
    // Print the canvas
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n"); // End the line after each row of pixels
    }
    
    return 0; // End the program
}