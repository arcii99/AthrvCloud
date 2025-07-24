//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Seed the random generator with current time
    char pixels[8][8]; // Array to hold pixel art
    int i, j; // Loop counters

    // Loop through each row of pixels
    for(i = 0; i < 8; i++){
        // Loop through each column of pixels
        for(j = 0; j < 8; j++){
            int rand_num = rand() % 3; // Generate a random number between 0 and 2
            // Assign a character based on the random number
            if(rand_num == 0)
                pixels[i][j] = ' ';
            else if(rand_num == 1)
                pixels[i][j] = '+';
            else
                pixels[i][j] = 'X';
        }
    }

    // Print out the pixel art
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%c ", pixels[i][j]); // Print each pixel with a space after it
        }
        printf("\n"); // Move to the next row of pixels
    }
    return 0;
}