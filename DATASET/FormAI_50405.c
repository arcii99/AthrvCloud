//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10
#define BOMB_LIMIT 20
#define FLAG 'F'
#define BOMB '*'

void drawBoard(char board[ROWS][COLUMNS], int reveal);
int getAdjacentBombs(char board[ROWS][COLUMNS], int row, int col);
void revealEmptySpaces(char board[ROWS][COLUMNS], int row, int col, int visited[ROWS][COLUMNS]);
void revealBombs(char board[ROWS][COLUMNS]);
int checkWin(char board[ROWS][COLUMNS]);

int main() {
    char board[ROWS][COLUMNS];
    int visited[ROWS][COLUMNS] = { 0 };
    int row, col, bombCount = 0, revealCount = 0;

    srand(time(NULL));

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            board[i][j] = '.';
        }
    }

    while(bombCount < BOMB_LIMIT) {
        row = rand() % ROWS;
        col = rand() % COLUMNS;

        if(board[row][col] != BOMB) {
            board[row][col] = BOMB;
            bombCount++;
        }
    }

    drawBoard(board, 0);

    while(1) {
        printf("Enter row and column (separated by a space, e.g. 3 4): ");
        scanf("%d %d", &row, &col);
        getchar();

        if(row < 0 || row >= ROWS || col < 0 || col >= COLUMNS) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if(visited[row][col] == 1) {
            printf("You've already visited that space. Please try again.\n");
            continue;
        }

        visited[row][col] = 1;

        if(board[row][col] == BOMB) {
            drawBoard(board, 1);
            printf("Game over! You hit a bomb!\n");
            break;
        } else if(getAdjacentBombs(board, row, col) > 0) {
            board[row][col] = getAdjacentBombs(board, row, col) + '0';
            drawBoard(board, 0);
            revealCount++;
        } else {
            revealEmptySpaces(board, row, col, visited);
            drawBoard(board, 0);
            revealCount++;
        }

        if(checkWin(board) == 1) {
            drawBoard(board, 1);
            printf("Congratulations! You won the game in %d moves!\n", revealCount);
            break;
        }
    }

    return 0;
}

void drawBoard(char board[ROWS][COLUMNS], int reveal) {
    printf("\n");
    printf("  ");

    for(int i = 0; i < COLUMNS; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        printf("%d ", i);

        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == BOMB && reveal == 0) {
                printf(". ");
            } else if(board[i][j] == BOMB && reveal == 1) {
                printf("%c ", BOMB);
            } else {
                printf("%c ", board[i][j]);
            }
        }

        printf("\n");
    }
}

int getAdjacentBombs(char board[ROWS][COLUMNS], int row, int col) {
    int count = 0;

    if(row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] == BOMB) {
        count++;
    }

    if(row - 1 >= 0 && board[row - 1][col] == BOMB) {
        count++;
    }

    if(row - 1 >= 0 && col + 1 < COLUMNS && board[row - 1][col + 1] == BOMB) {
        count++;
    }

    if(col - 1 >= 0 && board[row][col - 1] == BOMB) {
        count++;
    }

    if(col + 1 < COLUMNS && board[row][col + 1] == BOMB) {
        count++;
    }

    if(row + 1 < ROWS && col - 1 >= 0 && board[row + 1][col - 1] == BOMB) {
        count++;
    }

    if(row + 1 < ROWS && board[row + 1][col] == BOMB) {
        count++;
    }

    if(row + 1 < ROWS && col + 1 < COLUMNS && board[row + 1][col + 1] == BOMB) {
        count++;
    }

    return count;
}

void revealEmptySpaces(char board[ROWS][COLUMNS], int row, int col, int visited[ROWS][COLUMNS]) {
    visited[row][col] = 1;

    if(getAdjacentBombs(board, row, col) > 0) {
        board[row][col] = getAdjacentBombs(board, row, col) + '0';
    } else {
        board[row][col] = '0';

        if(row - 1 >= 0 && !visited[row - 1][col]) {
            revealEmptySpaces(board, row - 1, col, visited);
        }

        if(row + 1 < ROWS && !visited[row + 1][col]) {
            revealEmptySpaces(board, row + 1, col, visited);
        }

        if(col - 1 >= 0 && !visited[row][col - 1]) {
            revealEmptySpaces(board, row, col - 1, visited);
        }

        if(col + 1 < COLUMNS && !visited[row][col + 1]) {
            revealEmptySpaces(board, row, col + 1, visited);
        }

        if(row - 1 >= 0 && col - 1 >= 0 && !visited[row - 1][col - 1]) {
            revealEmptySpaces(board, row - 1, col - 1, visited);
        }

        if(row - 1 >= 0 && col + 1 < COLUMNS && !visited[row - 1][col + 1]) {
            revealEmptySpaces(board, row - 1, col + 1, visited);
        }

        if(row + 1 < ROWS && col - 1 >= 0 && !visited[row + 1][col - 1]) {
            revealEmptySpaces(board, row + 1, col - 1, visited);
        }

        if(row + 1 < ROWS && col + 1 < COLUMNS && !visited[row + 1][col + 1]) {
            revealEmptySpaces(board, row + 1, col + 1, visited);
        }
    }
}

void revealBombs(char board[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == BOMB) {
                board[i][j] = BOMB;
            }
        }
    }
}

int checkWin(char board[ROWS][COLUMNS]) {
    int count = 0;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] != BOMB && board[i][j] != FLAG) {
                count++;
            }
        }
    }

    if(count == ROWS * COLUMNS - BOMB_LIMIT) {
        return 1;
    } else {
        return 0;
    }
}