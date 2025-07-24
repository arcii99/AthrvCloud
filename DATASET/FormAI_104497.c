//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define our pixel art generator
void pixelArt(int rows, int cols, char pixels[rows][cols]) {

    //Iterate through rows and columns to give each pixel a random character
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            pixels[i][j] = (rand() % 2 == 0) ? '0' : '1';
        }
    }

    //Print out the resulting pixel art
    printf("\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}

//Main function to run our generator
int main() {
    //Seed the random number generator with the current time
    srand(time(NULL));

    //Get the number of rows and columns from the user
    int rows, cols;
    printf("Enter the number of rows for your pixel art: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for your pixel art: ");
    scanf("%d", &cols);

    //Create the character array to hold our pixel art
    char pixels[rows][cols];

    //Generate the pixel art
    pixelArt(rows, cols, pixels);

    //Exit the program
    return 0;
}