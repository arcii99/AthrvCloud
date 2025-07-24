//FormAI DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define PLAYER_1 1
#define PLAYER_2 2
#define BLANK {-1,-1}

typedef struct {
    int row;
    int col;
} position;

void surpriseDance() {
    printf("Wow, you didn't see that coming, did you?\n");
    printf("Let's celebrate with a surprise dance!\n");
    
    // Randomly generate dance steps
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int step = rand() % 3;
        if (step == 0) {
            printf("Left foot step\n");
        } else if (step == 1) {
            printf("Right foot step\n");
        } else {
            printf("Twirl around\n");
        }
    }
}

void displayBoard(int board[SIZE][SIZE]) {
    printf("  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == PLAYER_1) {
                printf("O ");
            } else if (board[i][j] == PLAYER_2) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int canMove(int board[SIZE][SIZE], position curr, position next, int player) {
    if (board[curr.row][curr.col] != player) {
        return 0;
    }

    int dx = abs(curr.row - next.row);
    int dy = abs(curr.col - next.col);

    if (dx != 1 || dy != 1) {
        return 0;
    }

    if (board[next.row][next.col] != 0) {
        return 0;
    }

    return 1;
}

int isJump(int board[SIZE][SIZE], position curr, position next, int player) {
    if (board[curr.row][curr.col] != player) {
        return 0;
    }

    int dx = abs(curr.row - next.row);
    int dy = abs(curr.col - next.col);

    if (dx != 2 || dy != 2) {
        return 0;
    }

    if (board[next.row][next.col] != 0) {
        return 0;
    }

    int midRow = (curr.row + next.row) / 2;
    int midCol = (curr.col + next.col) / 2;

    if (board[midRow][midCol] != (3 - player)) {
        return 0;
    }

    return 1;
}

void jump(int board[SIZE][SIZE], position curr, position next) {
    int midRow = (curr.row + next.row) / 2;
    int midCol = (curr.col + next.col) / 2;
    board[curr.row][curr.col] = 0;
    board[midRow][midCol] = 0;
    board[next.row][next.col] = 2;
}

int checkWinner(int board[SIZE][SIZE]) {
    int player1Count = 0;
    int player2Count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == PLAYER_1 || board[i][j] == 3) {
                player1Count++;
            } else if (board[i][j] == PLAYER_2 || board[i][j] == 4) {
                player2Count++;
            }
        }
    }

    if (player1Count == 0) {
        return PLAYER_2;
    } else if (player2Count == 0) {
        return PLAYER_1;
    } else {
        return 0;
    }
}

int main() {
    printf("Welcome to the Amazing Checkers game!\n");
    printf("May the odds be in your favor\n");

    int board[SIZE][SIZE] = {0};
    board[0][1] = PLAYER_1;
    board[0][3] = PLAYER_1;
    board[0][5] = PLAYER_1;
    board[0][7] = PLAYER_1;
    board[1][0] = PLAYER_1;
    board[1][2] = PLAYER_1;
    board[1][4] = PLAYER_1;
    board[1][6] = PLAYER_1;
    board[2][1] = PLAYER_1;
    board[2][3] = PLAYER_1;
    board[2][5] = PLAYER_1;
    board[2][7] = PLAYER_1;
    board[5][0] = PLAYER_2;
    board[5][2] = PLAYER_2;
    board[5][4] = PLAYER_2;
    board[5][6] = PLAYER_2;
    board[6][1] = PLAYER_2;
    board[6][3] = PLAYER_2;
    board[6][5] = PLAYER_2;
    board[6][7] = PLAYER_2;
    board[7][0] = PLAYER_2;
    board[7][2] = PLAYER_2;
    board[7][4] = PLAYER_2;
    board[7][6] = PLAYER_2;

    int turn = PLAYER_1;

    while (1) {
        displayBoard(board);

        if (turn == PLAYER_1) {
            printf("PLAYER 1's turn!\n");
        } else {
            printf("PLAYER 2's turn!\n");
        }

        position curr = BLANK;
        position next = BLANK;

        printf("Enter current position (row, col): ");
        scanf("%d,%d", &curr.row, &curr.col);

        printf("Enter next position (row, col): ");
        scanf("%d,%d", &next.row, &next.col);

        if (canMove(board, curr, next, turn)) {
            board[curr.row][curr.col] = 0;
            board[next.row][next.col] = turn;
            if (turn == PLAYER_1 && next.row == 7) {
                board[next.row][next.col] = 3;
            } else if (turn == PLAYER_2 && next.row == 0) {
                board[next.row][next.col] = 4;
            }
        } else if (isJump(board, curr, next, turn)) {
            jump(board, curr, next);
            if (turn == PLAYER_1 && next.row == 7) {
                board[next.row][next.col] = 3;
            } else if (turn == PLAYER_2 && next.row == 0) {
                board[next.row][next.col] = 4;
            }
        } else {
            printf("Invalid move, try again!\n");
            surpriseDance();
            continue;
        }

        int winner = checkWinner(board);
        if (winner != 0) {
            displayBoard(board);
            printf("Congratulations Player %d, you have won the game!\n", winner);
            break;
        }

        if (turn == PLAYER_1) {
            turn = PLAYER_2;
        } else {
            turn = PLAYER_1;
        }
    }

    return 0;
}