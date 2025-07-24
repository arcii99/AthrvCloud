//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
    int height = 5; // change the value of height to modify the pattern's size
    int width = height * 2; // width is always double the height in our pattern
    
    // iterate over each row in the pattern
    for (int row = 0; row < height; row++) {
        // check if we are in the top or bottom half of the pattern
        int half = row < height / 2 ? 0 : 1;
        
        // iterate over each character in the row
        for (int col = 0; col < width; col++) {
            // check if we are in one of the two diagonal lines
            if (half == 0 && col == row || half == 1 && col == width - 1 - row) {
                printf("O");
            }
            // check if we are in the center column
            else if (col == height) {
                printf("|");
            }
            // check if we are above or below the diagonal lines
            else if (half == 0 && col < row || half == 1 && col < width - 1 - row) {
                printf("\\");
            }
            // otherwise, we must be below or above the diagonal lines
            else {
                printf("/");
            }
        }
        
        printf("\n"); // move to the next row
    }
    
    return 0;
}