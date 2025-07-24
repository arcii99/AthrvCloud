//FormAI DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize_board(char board[ROWS][COLS]) {
    int i, j, count = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '0' + (count % 8) + 1;
            count++;
        }
    }
}

void shuffle_board(char board[ROWS][COLS]) {
    srand(time(NULL));
    int i, j, k;
    char temp;
    for (k = 0; k < 20; k++) { // shuffle 20 times
        i = rand() % ROWS;
        j = rand() % COLS;
        int dir = rand() % 4;
        switch(dir) {
            case 0: // up
                if (i > 0) {
                    temp = board[i][j];
                    board[i][j] = board[i-1][j];
                    board[i-1][j] = temp;
                }
                break;
            case 1: // down
                if (i < ROWS-1) {
                    temp = board[i][j];
                    board[i][j] = board[i+1][j];
                    board[i+1][j] = temp;
                }
                break;
            case 2: // left
                if (j > 0) {
                    temp = board[i][j];
                    board[i][j] = board[i][j-1];
                    board[i][j-1] = temp;
                }
                break;
            case 3: // right
                if (j < COLS-1) {
                    temp = board[i][j];
                    board[i][j] = board[i][j+1];
                    board[i][j+1] = temp;
                }
                break;
        }
    }
}

void print_board(char board[ROWS][COLS], char revealed[ROWS][COLS]) {
    int i, j;
    printf("\t1\t2\t3\t4\n\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d\t", i+1);
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%c\t", board[i][j]);
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }
}

int play_game(char board[ROWS][COLS]) {
    char revealed[ROWS][COLS] = {{0}};
    int i, j, count = 0;
    while (1) {
        system("clear");
        print_board(board, revealed);
        int r1, c1, r2, c2;
        do {
            printf("Enter the row and column of the first card to reveal (ex. 1 2): ");
            scanf("%d %d", &r1, &c1);
        } while (r1 < 1 || r1 > ROWS || c1 < 1 || c1 > COLS || revealed[r1-1][c1-1]);
        revealed[r1-1][c1-1] = 1;
        system("clear");
        print_board(board, revealed);
        do {
            printf("Enter the row and column of the second card to reveal (ex. 3 4): ");
            scanf("%d %d", &r2, &c2);
        } while (r2 < 1 || r2 > ROWS || c2 < 1 || c2 > COLS || revealed[r2-1][c2-1]);
        revealed[r2-1][c2-1] = 1;
        system("clear");
        print_board(board, revealed);
        if (board[r1-1][c1-1] != board[r2-1][c2-1]) {
            printf("Sorry, not a match. Press enter to continue.\n");
            getchar();
            getchar(); // pause to allow player to see the cards before they are covered
            revealed[r1-1][c1-1] = 0;
            revealed[r2-1][c2-1] = 0;
        } else {
            printf("Match found! Press enter to continue.\n");
            getchar();
            getchar();
            count++;
            if (count == 8) {
                return 1;
            }
        }
    }
}

int main() {
    char board[ROWS][COLS];
    initialize_board(board);
    shuffle_board(board);
    int result = play_game(board);
    system("clear");
    printf("You won with %d matches!\n", result);
    return 0;
}