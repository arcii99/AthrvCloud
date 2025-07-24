//FormAI DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    int i, j, num;
    srand(time(0));
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = -1;
            revealed[i][j] = 0;
        }
    }
    for(num=0; num<BOARD_SIZE*BOARD_SIZE/2; num++) {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        while(board[i][j] != -1) {
            i = rand() % BOARD_SIZE;
            j = rand() % BOARD_SIZE;
        }
        board[i][j] = num;
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        while(board[i][j] != -1) {
            i = rand() % BOARD_SIZE;
            j = rand() % BOARD_SIZE;
        }
        board[i][j] = num;
    }
}

void printBoard() {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int getChoice(char* message) {
    int choice = -1;
    while(choice < 0 || choice >= BOARD_SIZE) {
        printf(message);
        scanf("%d", &choice);
    }
    return choice;
}

int makeMove(int row1, int col1, int row2, int col2) {
    if(board[row1][col1] == board[row2][col2]) {
        revealed[row1][col1] = 1;
        revealed[row2][col2] = 1;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numMoves = 0;
    int row1, col1, row2, col2, success;
    initializeBoard();
    printf("Memory Game\n");
    while(1) {
        printf("Number of moves: %d\n", numMoves);
        printBoard();
        printf("Enter first card location (row column): \n");
        row1 = getChoice("Enter row (0-3): ");
        col1 = getChoice("Enter column (0-3): ");
        revealed[row1][col1] = 1;
        printBoard();
        printf("Enter second card location (row column): \n");
        row2 = getChoice("Enter row (0-3): ");
        col2 = getChoice("Enter column (0-3): ");
        success = makeMove(row1, col1, row2, col2);
        numMoves++;
        if(success == 0) {
            printf("No match. Try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
        if(numMoves == BOARD_SIZE*BOARD_SIZE/2) {
            printf("Congratulations! You won in %d moves.\n", numMoves);
            break;
        }
    }
    return 0;
}