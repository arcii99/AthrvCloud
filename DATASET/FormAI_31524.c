//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void init_board(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("%c ", 'O');
            } else {
                printf("%c ", 'X');
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[SIZE][SIZE], int i, int j) {
    int cnt = 0, x, y;
    for (x = i - 1; x <= i + 1; x++) {
        if (x < 0 || x >= SIZE) continue;
        for (y = j - 1; y <= j + 1; y++) {
            if (y < 0 || y >= SIZE) continue;
            if (x == i && y == j) continue;
            cnt += board[x][y];
        }
    }
    return cnt;
}

void update_board(int board[SIZE][SIZE]) {
    int i, j;
    int new_board[SIZE][SIZE];
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            int cnt = count_neighbors(board, i, j);
            if (!board[i][j] && cnt == 3) {
                new_board[i][j] = 1;
            } else if (board[i][j] && (cnt == 2 || cnt == 3)) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[SIZE][SIZE];

    srand(time(NULL)); // Seed random number generator with current time
    init_board(board);

    while (1) {
        system("clear"); // Clear screen
        print_board(board);
        update_board(board);
        usleep(100000); // Wait for 100ms before updating again
    }

    return 0;
}