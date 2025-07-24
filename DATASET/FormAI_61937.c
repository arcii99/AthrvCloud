//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void displayBoard(int board[][COLS], int rows) {
    printf("    ");
    for(int i = 0; i < COLS; i++) {
        printf("%02d  ", i + 1);
    }
    printf("\n");
    printf("  ╔═╦═╦═╦═╦═╗\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%02d║", i + 1);
        for(int j = 0; j < COLS; j++) {
            printf(" %2d", board[i][j]);
            if(j != COLS - 1) {
                printf(" │");
            }
        }
        printf(" ║\n");
        if(i != ROWS - 1) {
            printf("  ╠═╬═╬═╬═╬═╣\n");
        }
    }
    printf("  ╚═╩═╩═╩═╩═╝\n");
}

int isBingo(int board[][COLS], int rows) {
    int bingo = 0, fullLines = 0;

    // Check Rows
    for(int i = 0; i < ROWS; i++) {
        int fullRow = 1;
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] != -1) {
                fullRow = 0;
            }
        }
        if(fullRow) {
            bingo = 1;
        }
    }

    // Check Columns
    for(int i = 0; i < COLS; i++) {
        int fullCol = 1;
        for(int j = 0; j < ROWS; j++) {
            if(board[j][i] != -1) {
                fullCol = 0;
            }
        }
        if(fullCol) {
            bingo = 1;
        }
    }

    // Check Diagonals
    int diagonal1 = 1, diagonal2 = 1;
    for(int i = 0; i < ROWS; i++) {
        if(board[i][i] != -1) {
            diagonal1 = 0;
        }
        if(board[i][ROWS - i - 1] != -1) {
            diagonal2 = 0;
        }
    }
    if(diagonal1 || diagonal2) {
        bingo = 1;
    }

    return bingo;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];

    // Initialize Board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    int bingoNumbers[75];
    for(int i = 0; i < 75; i++) {
        bingoNumbers[i] = i + 1;
    }

    int currNumber = 1, currRow = 0, currCol = 0;
    while(currNumber <= 75) {
        // Display Board
        system("clear");
        printf("BINGO BOARD\n");
        displayBoard(board, ROWS);

        // Display Current Number
        printf("\nCurrent Number: %d", currNumber);

        // Prompt User
        printf("\nEnter 1 for New Number, 0 to Quit: ");
        int choice;
        scanf("%d", &choice);

        if(choice) {
            int found = 0;
            while(!found) {
                int randIndex = rand() % 75;
                if(bingoNumbers[randIndex] != -1) {
                    currNumber = bingoNumbers[randIndex];
                    bingoNumbers[randIndex] = -1;
                    found = 1;
                }
            }

            // Update Board
            int rowFound = 0;
            for(int i = 0; i < ROWS; i++) {
                for(int j = 0; j < COLS; j++) {
                    if(board[i][j] == currNumber) {
                        board[i][j] = -1;
                    }
                    if(!rowFound && board[i][j] == -1) {
                        board[i][j] = currNumber;
                        currRow = i;
                        currCol = j;
                        rowFound = 1;
                    }
                }
            }
        } else {
            printf("\nGoodbye! Hope you enjoyed the game!\n");
            return 0;
        }

        // Check if Bingo
        if(isBingo(board, ROWS)) {
            printf("\nBINGO!\n");
            displayBoard(board, ROWS);
            printf("\nCongratulations! You have won!\n");
            return 0;
        }
    }

    printf("\nIt's a Tie!\n");
    return 0;
}