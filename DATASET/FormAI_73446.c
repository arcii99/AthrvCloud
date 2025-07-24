//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
    int rows = 7;
    int cols = 7;
    char pattern[rows][cols]; // create a 2D array for the pattern
    
    // initialize the array with blank spaces
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            pattern[i][j] = ' ';
        }
    }
    
    // add the C pattern to the array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if((j == 1 && i != 0 && i != 6) || (i == 0 && j > 1 && j < 6) || (i == 6 && j > 1 && j < 5) || (j == 5 && i != 0 && i != 6)) {
                pattern[i][j] = '*';
            }
        }
    }
    
    // print the C pattern
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}