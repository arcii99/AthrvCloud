//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10 //board is 10 x 10
#define NUM_MINES 10 //10 mines on the board

int mines[BOARD_SIZE][BOARD_SIZE] = {0}; //0 represents no mine, 1 represents mine
int playerBoard[BOARD_SIZE][BOARD_SIZE] = {0}; //0 represents unrevealed, 1 represents revealed
int numMinesLeft = NUM_MINES; //number of mines that have not been flagged yet

//function to initialize the board with random mines
void initBoard() {
    int i, j, count;
    srand(time(NULL));
    
    for(count = 1; count <= NUM_MINES; count++) {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        
        if(mines[i][j] == 0) {
            mines[i][j] = 1;
        }
        else {
            count--;
        }
    }
}

//function to print the board to the console
void printBoard() {
    int i, j;
    
    printf("   ");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(j = 0; j < BOARD_SIZE; j++) {
            if(playerBoard[i][j] == 0) {
                printf(". ");
            }
            else {
                printf("%d ", mines[i][j]);
            }
        }
        printf("\n");
    }
}

//function to recursively reveal empty squares
void revealEmptySquares(int i, int j) {
    int x, y;
    playerBoard[i][j] = 1;
    
    if(mines[i][j] == 0) {
        for(x = -1; x <= 1; x++) {
            for(y = -1; y <= 1; y++) {
                if(i+x >= 0 && i+x < BOARD_SIZE && j+y >= 0 && j+y < BOARD_SIZE && !playerBoard[i+x][j+y]) {
                    revealEmptySquares(i+x, j+y);
                }
            }
        }
    }
}

//function to handle player turn
void playerTurn() {
    int i, j, choice, flag;
    char input[10];
    printf("\nEnter row and column (0-9): ");
    fgets(input, 10, stdin);
    sscanf(input, "%d %d", &i, &j);
    printf("\n1) Reveal square\n2) Toggle flag");
    printf("\nEnter choice (1-2): ");
    fgets(input, 5, stdin);
    sscanf(input, "%d", &choice);
    
    if(choice == 1) {
        if(mines[i][j] == 1) {
            printf("You hit a mine! Game over.");
            exit(0);
        }
        else {
            revealEmptySquares(i, j);
        }
    }
    else if(choice == 2) {
        if(playerBoard[i][j] == 1) {
            printf("\nCannot flag a revealed square.");
        }
        else {
            if(mines[i][j] == 1) {
                printf("\nCorrectly flagged a mine!");
                numMinesLeft--;
            }
            else {
                printf("\nIncorrectly flagged.");
            }
        }
    }
}

//function to check if player has won
int playerWon() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(mines[i][j] == 0 && playerBoard[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

//main function
int main() {
    int i, j;
    char input[10];
    printf("Welcome to Minesweeper!\n");
    initBoard();
    
    while(1) {
        printf("\nMines left: %d\n", numMinesLeft);
        printBoard();
        playerTurn();
        
        if(playerWon()) {
            printf("Congratulations, you win!");
            exit(0);
        }
    }
    
    return 0;
}