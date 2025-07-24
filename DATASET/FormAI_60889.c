//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COLUMN 5

void print_board(int board[ROW][COLUMN]) {
    printf("B\tI\tN\tG\tO\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[ROW][COLUMN]) {
    // check for horizontal win
    for (int i = 0; i < ROW; i++) {
        if (board[i][0] && board[i][1] && board[i][2] && board[i][3] && board[i][4]) {
            return 1;
        }
    }

    // check for vertical win
    for (int i = 0; i < COLUMN; i++) {
        if (board[0][i] && board[1][i] && board[2][i] && board[3][i] && board[4][i]) {
            return 1;
        }
    }

    // check for diagonal win
    if (board[0][0] && board[1][1] && board[2][2] && board[3][3] && board[4][4]) {
        return 1;
    }

    if (board[0][4] && board[1][3] && board[2][2] && board[3][1] && board[4][0]) {
        return 1;
    }

    return 0;
}

int main() {
    int board[ROW][COLUMN] = {0};
    int numbers[ROW * COLUMN] = {0};

    // fill numbers array with 1-25
    for (int i = 0; i < ROW * COLUMN; i++) {
        numbers[i] = i + 1;
    }

    // shuffle numbers array
    srand(time(NULL));
    for (int i = 0; i < ROW * COLUMN; i++) {
        int j = rand() % (ROW * COLUMN);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // fill board with shuffled numbers
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            board[i][j] = numbers[i * ROW + j];
        }
    }

    print_board(board);

    printf("Press ENTER to start playing...\n");
    getchar();

    int num_count = 0;
    int num;

    while (!check_win(board)) {
        system("clear");
        print_board(board);

        printf("Enter a number (1-25): ");
        scanf("%d", &num);

        if (num < 1 || num > 25) {
            printf("Invalid number! Enter a number between 1-25.\n");
            continue;
        }

        // check if number has already been called
        int found = 0;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0;
                    num_count++;
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (!found) {
            printf("%d has already been called! Choose a different number.\n", num);
            continue;
        }
    }

    printf("BINGO! You called %d numbers to win the game.\n", num_count);

    return 0;
}