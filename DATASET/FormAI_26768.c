//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>

// Define the height and width of the art
#define ART_HEIGHT 5
#define ART_WIDTH 10

// Define the ASCII characters used to draw the art
#define ART_BLANK ' '
#define ART_FILL '-'
#define ART_BORDER '|'

int main() {
    // Declare and initialize the art character array
    char art[ART_HEIGHT][ART_WIDTH] = { { ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL },
                                         { ART_FILL, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_FILL },
                                         { ART_FILL, ART_BORDER, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BORDER, ART_FILL },
                                         { ART_FILL, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_BLANK, ART_FILL },
                                         { ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL, ART_FILL } };

    // Draw the art
    for (int row = 0; row < ART_HEIGHT; row++) {
        for (int col = 0; col < ART_WIDTH; col++) {
            printf("%c", art[row][col]);
        }
        printf("\n");
    }

    return 0;
}