//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayBoard(int rows, int cols, char board[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int randomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

void movePlayer(int rows, int cols, char board[][cols], int* playerRow, int* playerCol) {
    char direction;
    while (1) {
        printf("Enter direction (U/D/L/R): ");
        scanf(" %c", &direction);
        if (direction == 'U' && *playerRow > 0 && board[*playerRow - 1][*playerCol] != '|') {
            board[*playerRow][*playerCol] = ' ';
            *playerRow -= 1;
            break;
        } else if (direction == 'D' && *playerRow < rows - 1 && board[*playerRow + 1][*playerCol] != '|') {
            board[*playerRow][*playerCol] = ' ';
            *playerRow += 1;
            break;
        } else if (direction == 'L' && *playerCol > 0 && board[*playerRow][*playerCol - 1] != '|') {
            board[*playerRow][*playerCol] = ' ';
            *playerCol -= 1;
            break;
        } else if (direction == 'R' && *playerCol < cols - 1 && board[*playerRow][*playerCol + 1] != '|') {
            board[*playerRow][*playerCol] = ' ';
            *playerCol += 1;
            break;
        }
        printf("Invalid move.\n");
    }
    board[*playerRow][*playerCol] = 'C';
}

int main() {
    int rows = 15;
    int cols = 15;
    char board[rows][cols];
    int dots = 0;
    int playerRow = 7;
    int playerCol = 7;

    //initialize board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                board[i][j] = '|';
            } else {
                board[i][j] = '.';
                if (i != playerRow || j != playerCol) {
                    if (randomNumber(0, 9) == 0) {
                        board[i][j] = 'o';
                        dots += 1;
                    }
                }
            }
        }
    }
    board[playerRow][playerCol] = 'C';

    displayBoard(rows, cols, board);

    while (1) {
        movePlayer(rows, cols, board, &playerRow, &playerCol);
        if (board[playerRow][playerCol] == 'o') {
            dots -= 1;
            board[playerRow][playerCol] = 'C';
            if (dots == 0) {
                printf("You win!\n");
                break;
            }
        }
        displayBoard(rows, cols, board);
    }

    return 0;
}