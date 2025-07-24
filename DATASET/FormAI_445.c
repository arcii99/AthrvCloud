//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>

//Initialize the pixel art array
char pixels[8][8] = {
    {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
    {'X', 'X', ' ', ' ', ' ', 'X', 'X', ' '},
    {'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X'},
    {'X', 'X', ' ', ' ', ' ', 'X', 'X', ' '},
    {'X', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
    {'X', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
    {'X', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
    {'X', ' ', ' ', ' ', ' ', ' ', 'X', ' '}
};

//Create a function to print the pixel art
void printPixels(char pixels[][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //Print the original pixel art
    printf("Original Pixel Art:\n");
    printPixels(pixels);
    
    //Edit the pixel art by changing some pixels
    pixels[2][3] = ' ';
    pixels[3][3] = 'X';
    pixels[4][3] = 'X';
    pixels[5][3] = 'X';
    pixels[4][4] = 'X';
    pixels[5][4] = 'X';
    pixels[6][4] = 'X';
    
    //Print the edited pixel art
    printf("\nEdited Pixel Art:\n");
    printPixels(pixels);
    
    return 0;
}