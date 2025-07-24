//FormAI DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_PLAYERS 4

bool gameOver = false;
int currentPlayer = 0;
int currentRow, currentCol;
char players[MAX_PLAYERS] = {'A', 'B', 'C', 'D'};
int playerPositions[MAX_PLAYERS] = {1, 1, 1, 1};
char board[ROWS][COLS] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

void displayBoard() {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c", board[i][j]);
            if(j != COLS-1) {
                printf("|");
            }
        }
        printf("\n");
        if(i != ROWS-1) {
            printf("-----\n");
        }
    }
}

void updateBoard() {
    int i;
    for(i=0; i<MAX_PLAYERS; i++) {
        board[0][playerPositions[i]] = players[i];
    }
}

void resetGame() {
    gameOver = false;
    currentPlayer = 0;
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
    }
    playerPositions[0] = 1;
    playerPositions[1] = 1;
    playerPositions[2] = 1;
    playerPositions[3] = 1;
    updateBoard();
}

void rollDie() {
    srand(time(0));
    int roll = rand() % 6 + 1;
    printf("\nPlayer %c rolled a %d!\n\n", players[currentPlayer], roll);
    playerPositions[currentPlayer] += roll;
    if(playerPositions[currentPlayer] >= COLS-1) {
        playerPositions[currentPlayer] = COLS-1;
        gameOver = true;
        printf("Player %c won!\n", players[currentPlayer]);
    }
    currentRow = 0;
    currentCol = playerPositions[currentPlayer];
    updateBoard();
}

void playGame() {
    printf("Welcome to the Surrealist C Table Game!\n\n");
    resetGame();
    while(!gameOver) {
        printf("Player %c's turn. Press enter to roll the die.", players[currentPlayer]);
        getchar();
        system("clear");
        rollDie();
        displayBoard();
        currentPlayer = (currentPlayer + 1) % MAX_PLAYERS;
    }
}

int main() {
    playGame();
    return 0;
}