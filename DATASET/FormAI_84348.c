//FormAI DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seeds random number generator
    
    int memoryBoard[4][4] = {0}; // initialize memory board to all zeros
    int numPairs = 8; // number of pairs of matching tiles
    int unpairedTiles = numPairs * 2; // initialize unpaired tiles to total number of tiles
    
    // randomly place pairs of numbers on board
    for (int i = 1; i <= numPairs; i++) {
        int row1, col1, row2, col2;
        do {
            // generate two random coordinates
            row1 = rand() % 4;
            col1 = rand() % 4;
            row2 = rand() % 4;
            col2 = rand() % 4;
        } while (memoryBoard[row1][col1] != 0 || memoryBoard[row2][col2] != 0 || (row1 == row2 && col1 == col2));
        // repeat until two unique and empty locations found
        
        memoryBoard[row1][col1] = i;
        memoryBoard[row2][col2] = i;
    }
    
    printf("\n\tWelcome to the Memory Game!\n");
    printf("\n\tFind all %d pairs to win!\n", numPairs);
    printf("\n\tTo uncover a tile, enter its row and column number (separated by a space).\n");
    
    while (unpairedTiles > 0) { // continue playing until all tiles are paired
        printf("\n\tCurrent Board:\n\n");
        printf("\t 1\t 2\t 3\t 4\t\n");
        printf("\t---\t---\t---\t---\t\n");
        for (int row = 0; row < 4; row++) {
            printf("%d|\t", row + 1);
            for (int col = 0; col < 4; col++) {
                if (memoryBoard[row][col] == -1) { // already paired tile
                    printf("X\t");
                } else if (memoryBoard[row][col] == 0) { // unselected tile
                    printf("*\t");
                } else { // selected tile
                    printf("%d\t", memoryBoard[row][col]);
                }
            }
            printf("\n");
        }
        
        int row1, col1, row2, col2;
        do {
            printf("\n\tEnter row and column for first tile: ");
            scanf("%d %d", &row1, &col1);
        } while (memoryBoard[row1 - 1][col1 - 1] == -1 || memoryBoard[row1 - 1][col1 - 1] == 1); // already paired or selected tile
        printf("\tTile selected: %d\n", memoryBoard[row1 - 1][col1 - 1]);
        
        do {
            printf("\n\tEnter row and column for second tile: ");
            scanf("%d %d", &row2, &col2);
        } while (memoryBoard[row2 - 1][col2 - 1] == -1 || memoryBoard[row2 - 1][col2 - 1] == 1 || (row1 == row2 && col1 == col2)); // already paired, selected, or same tile
        
        printf("\tTile selected: %d\n", memoryBoard[row2 - 1][col2 - 1]);
        
        if (memoryBoard[row1 - 1][col1 - 1] == memoryBoard[row2 - 1][col2 - 1]) { // tiles match
            memoryBoard[row1 - 1][col1 - 1] = -1; // mark tiles as paired
            memoryBoard[row2 - 1][col2 - 1] = -1;
            unpairedTiles -= 2; // decrement unpaired tiles by 2
        } else { // tiles don't match
            memoryBoard[row1 - 1][col1 - 1] = 0; // reset selected tiles to unselected
            memoryBoard[row2 - 1][col2 - 1] = 0;
        }
    }
    
    printf("\n\tCongratulations! You found all %d pairs!\n", numPairs);
    
    return 0;
}