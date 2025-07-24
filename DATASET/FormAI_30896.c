//FormAI DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

int main()
{
    int memoryBoard[ROWS][COLUMNS] = {0};
    int userBoard[ROWS][COLUMNS] = {0};
    int numberOfPairs = ROWS*COLUMNS/2;
    int pairsFound = 0;
    
    srand(time(0));
    
    //filling the memory board with pairs of random numbers
    for (int i = 1; i <= numberOfPairs; i++) {
        int firstRow, firstColumn, secondRow, secondColumn;
        
        do {
            firstRow = rand()%ROWS;
            firstColumn = rand()%COLUMNS;
        } while (memoryBoard[firstRow][firstColumn] != 0);
        
        do {
            secondRow = rand()%ROWS;
            secondColumn = rand()%COLUMNS;
        } while (memoryBoard[secondRow][secondColumn] != 0 || (firstRow == secondRow && firstColumn == secondColumn));
        
        memoryBoard[firstRow][firstColumn] = i;
        memoryBoard[secondRow][secondColumn] = i;
    }
    
    //game loop
    while (pairsFound < numberOfPairs) {
        //print user board
        printf("Current Board:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                printf("%d ", userBoard[i][j]);
            }
            printf("\n");
        }
        
        //ask user for a move
        int row1, column1, row2, column2;
        printf("Enter the row and column of the first tile to flip (separated by a space):\n");
        scanf("%d %d", &row1, &column1);
        printf("Enter the row and column of the second tile to flip (separated by a space):\n");
        scanf("%d %d", &row2, &column2);
        
        if (memoryBoard[row1][column1] != memoryBoard[row2][column2]) {
            printf("Sorry, those tiles don't match. Try again.\n");
        } else {
            userBoard[row1][column1] = memoryBoard[row1][column1];
            userBoard[row2][column2] = memoryBoard[row2][column2];
            pairsFound++;
            printf("You found a pair!\n");
        }
    }
    
    printf("Congratulations, you won the game!\n");
    
    return 0;
}