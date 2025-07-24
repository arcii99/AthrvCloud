//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define pixel size
#define PIXEL_SIZE 8

// define color codes for pixels
#define BLACK "\u2588\u2588"
#define RED "\u2588\u2588"
#define GREEN "\u2588\u2588"
#define YELLOW "\u2588\u2588"
#define BLUE "\u2588\u2588"
#define MAGENTA "\u2588\u2588"
#define CYAN "\u2588\u2588"
#define WHITE "\u2588\u2588"

void printRandomPixel() {
    // array of color codes
    char* colors[] = {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

    // get random color code from array
    int randomIndex = rand() % 8;
    char* color = colors[randomIndex];

    // print pixel with random color
    printf("%s", color);
}

int main() {

    // set seed for random number generator
    srand(time(NULL));

    // generate 50x50 pixel art
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            // print random pixel
            printRandomPixel();

            // add spacing for readability
            printf(" ");
        }

        // move to next line
        printf("\n");
    }

    return 0;
}