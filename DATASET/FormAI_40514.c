//FormAI DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_MOVES 30

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void shuffleBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int moves);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {

    char board[BOARD_SIZE][BOARD_SIZE];
    int moves = 0, win = 0;

    srand(time(NULL)); // setup random number generator
    initializeBoard(board); // initialize game board
    shuffleBoard(board); // shuffle board pieces

    printf("Welcome to the C Memory Game!\n\n");

    while(moves < MAX_MOVES && !win) {
        printBoard(board, moves); // print game board after each move
        printf("Select first piece: ");
        int x1, y1;
        scanf("%d %d", &x1, &y1);

        printf("Select second piece: ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);

        if(board[x1][y1] == board[x2][y2]) { // if a match is found
            board[x1][y1] = '*'; // mark as matched
            board[x2][y2] = '*';
            printf("Match found!\n");
            moves++;
            win = checkWin(board); // check if there are still pairs remaining
        } else {
            printf("No match found.\n");
        }
    }

    if(win) {
        printf("Congratulations, you matched all pairs in %d moves!\n", moves);
    } else {
        printf("Sorry, you lost.\n");
    }

    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    char pieces[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    int index = 0;

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = pieces[index];
            index++;
        }
    }
}

void shuffleBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            int randomX = rand() % BOARD_SIZE;
            int randomY = rand() % BOARD_SIZE;
            char temp = board[i][j];
            board[i][j] = board[randomX][randomY];
            board[randomX][randomY] = temp;
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int moves) {
    printf("\n\n\n----------------\n\n");
    printf("Moves: %d\n\n", moves);
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '*') {
                printf(" * ");
            } else {
                printf(" %c ", board[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
    printf("\n----------------\n\n\n");
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] != '*') {
                return 0; // if a pair is still unmatched, return 0
            }
        }
    }
    return 1; // all pairs matched, return 1
}