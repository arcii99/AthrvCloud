//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random pixel art
void generatePixelArt(int size, int numColors) {
    char colorCode[numColors]; // array to hold color codes
    int i, j;
    
    srand(time(NULL)); // seed random number generator
    
    // generate color codes
    for (i = 0; i < numColors; i++) {
        colorCode[i] = 'A' + rand() % 16; // assign a letter from A-F randomly
    }
    
    // generate pixel art
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c ", colorCode[rand() % numColors]); // randomly select a color code and print
        }
        printf("\n"); // print new line after each row
    }
}

// main function
int main() {
    int size, numColors;
    
    printf("Enter the size of the pixel art: ");
    scanf("%d", &size); // get size of pixel art
    
    printf("Enter the number of colors to use (maximum 16): ");
    scanf("%d", &numColors); // get number of colors
    
    generatePixelArt(size, numColors); // call function to generate pixel art
    
    return 0;
}