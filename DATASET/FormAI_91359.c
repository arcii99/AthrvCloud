//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void displayBoard(char board[SIZE][SIZE], int positions[2][2]) {
    int i, j;
    printf("    ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d   ", i + 1);
        for (j = 0; j < SIZE; j++) {
            if (positions[0][0] == i && positions[0][1] == j) {
                printf("X ");
            } else if (positions[1][0] == i && positions[1][1] == j) {
                printf("X ");
            } else if (board[i][j] == '*') {
                printf("  ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void resetBoard(char board[SIZE][SIZE], int positions[2][2]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }
    srand(time(NULL));
    int x1 = rand() % SIZE;
    int y1 = rand() % SIZE;
    int x2 = rand() % SIZE;
    int y2 = rand() % SIZE;
    while (x1 == x2 && y1 == y2) {
        x2 = rand() % SIZE;
        y2 = rand() % SIZE;
    }
    positions[0][0] = x1;
    positions[0][1] = y1;
    positions[1][0] = x2;
    positions[1][1] = y2;
}

void checkGameOver(char board[SIZE][SIZE], int positions[2][2], int* score) {
    if (board[positions[0][0]][positions[0][1]] == board[positions[1][0]][positions[1][1]]) {
        printf("You found a match!\n");
        *score += 5;
        board[positions[0][0]][positions[0][1]] = '*';
        board[positions[1][0]][positions[1][1]] = '*';
    } else {
        printf("Sorry, no match. Try again.\n");
        *score -= 1;
    }
}

int main() {
    char board[SIZE][SIZE];
    int positions[2][2];
    int score = 0;
    resetBoard(board, positions);
    printf("Welcome to Memory Game!\n");
    printf("Find all matches to win.\n");
    printf("Scoring: +5 for a match, -1 for a miss.\n");
    while (1) {
        displayBoard(board, positions);
        printf("Score: %d\n", score);
        int r1, c1, r2, c2;
        printf("Enter row and column for the first selection: ");
        scanf("%d %d", &r1, &c1);
        positions[0][0] = r1 - 1;
        positions[0][1] = c1 - 1;
        if (board[positions[0][0]][positions[0][1]] == '*') {
            board[positions[0][0]][positions[0][1]] = rand() % 26 + 65;
        }
        displayBoard(board, positions);
        printf("Score: %d\n", score);
        printf("Enter row and column for the second selection: ");
        scanf("%d %d", &r2, &c2);
        positions[1][0] = r2 - 1;
        positions[1][1] = c2 - 1;
        if (board[positions[1][0]][positions[1][1]] == '*') {
            board[positions[1][0]][positions[1][1]] = rand() % 26 + 65;
        }
        displayBoard(board, positions);
        printf("Score: %d\n", score);
        checkGameOver(board, positions, &score);
        if (score >= 40) {
            printf("Congratulations! You won!\n");
            break;
        }
    }
    return 0;
}