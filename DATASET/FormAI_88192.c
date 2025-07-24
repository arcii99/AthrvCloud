//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height; // dimensions of the pixel art
    int colors[3]; // RGB values for colors
    srand(time(NULL)); // seed the random number generator with the current time

    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);

    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    printf("Enter the RGB values for the first color (e.g. 255 0 0 for red): ");
    scanf("%d %d %d", &colors[0], &colors[1], &colors[2]);

    for (int i = 0; i < height; i++) { // loop through all rows
        for (int j = 0; j < width; j++) { // loop through all columns
            int color = rand() % 2; // randomize color choice
            if (color == 0) {
                printf("\033[48;2;%d;%d;%dm ", colors[0], colors[1], colors[2]); // set color using ANSI escape code and print space
            } else {
                printf("\033[48;2;%d;%d;%dm#", colors[0], colors[1], colors[2]); // set color using ANSI escape code and print #
            }
        }
        printf("\n"); // move to a new line at the end of each row
    }

    printf("\033[0m"); // reset color to default using ANSI escape code
    return 0;
}