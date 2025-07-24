//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 10
#define MAX_MINE_NUM 10

void printBoard(int board[][BOARD_SIZE], int reveal[][BOARD_SIZE]);
int isMine(int board[][BOARD_SIZE], int row, int col);
int countMines(int board[][BOARD_SIZE], int row, int col);
void revealCell(int board[][BOARD_SIZE], int reveal[][BOARD_SIZE], int row, int col);
void setMines(int board[][BOARD_SIZE]);
int isLegal(int row, int col);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int reveal[BOARD_SIZE][BOARD_SIZE];
    int i, j, row, col, mine, winner = 0;

    // set the board
    setMines(board);
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            reveal[i][j] = 0;

    // game loop
    while (!winner) {
        // print the board
        system("clear");
        printBoard(board, reveal);

        // get user's input
        printf("\nEnter row and column: ");
        scanf("%d %d", &row, &col);

        // check if cell is legal
        if (!isLegal(row, col)) {
            printf("\nIllegal move. Please try again.");
            continue;
        }

        // check if the cell is a mine
        if (isMine(board, row, col)) {
            printf("\nYou hit a mine! Game over!");
            break;
        }

        // reveal the cell
        revealCell(board, reveal, row, col);

        // check if the player has won
        winner = 1;
        for (i = 0; i < BOARD_SIZE; i++)
            for (j = 0; j < BOARD_SIZE; j++)
                if (board[i][j] != -1 && reveal[i][j] == 0)
                    winner = 0;
    }

    // print the result
    if (winner)
        printf("\nCongratulations! You won!");
    else
        printf("\nGame over! You lost!");

    return 0;
}

// prints the board using ASCII characters
void printBoard(int board[][BOARD_SIZE], int reveal[][BOARD_SIZE]) {
    int i, j;

    printf("    ");
    for (j = 0; j < BOARD_SIZE; j++)
        printf("%d ", j);
    printf("\n");

    printf("    ");
    for (j = 0; j < BOARD_SIZE; j++)
        printf("_ ");
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d |", i);
        for (j = 0; j < BOARD_SIZE; j++)
            if (reveal[i][j])
                if (board[i][j] == -1)
                    printf("* ");
                else
                    printf("%d ", countMines(board, i, j));
            else
                printf("  ");
        printf("|\n");
    }

    printf("    ");
    for (j = 0; j < BOARD_SIZE; j++)
        printf("_ ");
    printf("\n");
}

// checks if the cell is a mine
int isMine(int board[][BOARD_SIZE], int row, int col) {
    if (board[row][col] == -1)
        return 1;
    else
        return 0;
}

// counts the number of mines around a cell
int countMines(int board[][BOARD_SIZE], int row, int col) {
    int i, j, count = 0;

    for (i = row - 1; i <= row + 1; i++)
        for (j = col - 1; j <= col + 1; j++)
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && board[i][j] == -1)
                count++;

    return count;
}

// reveals the cell and its neighbors if necessary
void revealCell(int board[][BOARD_SIZE], int reveal[][BOARD_SIZE], int row, int col) {
    reveal[row][col] = 1;

    if (countMines(board, row, col) == 0)
        for (int i = row - 1; i <= row + 1; i++)
            for (int j = col - 1; j <= col + 1; j++)
                if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && reveal[i][j] == 0)
                    revealCell(board, reveal, i, j);
}

// sets the mines randomly
void setMines(int board[][BOARD_SIZE]) {
    int i, j, mine_row, mine_col, count = 0;

    srand(time(NULL));

    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;

    while (count < MAX_MINE_NUM) {
        mine_row = rand() % BOARD_SIZE;
        mine_col = rand() % BOARD_SIZE;

        if (board[mine_row][mine_col] == 0) {
            board[mine_row][mine_col] = -1;
            count++;
        }
    }
}

// checks if the cell is legal
int isLegal(int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE)
        return 1;
    else
        return 0;
}