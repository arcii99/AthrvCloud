//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4
#define SIZE (ROW * COL)

void fill_board(int *board, int size);
void print_board(int *board, int size);
void shuffle_board(int *board, int size);
void play_game(int *board, int size);

int main() {
    int board[SIZE];

    srand(time(NULL)); // seed the random number generator

    fill_board(board, SIZE); // initialize the board with values
    shuffle_board(board, SIZE); // shuffle the board
    print_board(board, SIZE); // print the board

    play_game(board, SIZE); // start the game

    return 0;
}

void fill_board(int *board, int size) {
    int i, j, num;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            num = i * COL + j + 1;
            if (num == size) {
                board[i * COL + j] = 0; // set last element to zero
            } else {
                board[i * COL + j] = num; // assign other numbers
            }
        }
    }
}

void print_board(int *board, int size) {
    int i, j;

    printf("\nMemory Game\n");

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (board[i * COL + j] == 0) {
                printf("XX ");
                continue;
            }
            printf("%2d ", board[i * COL + j]);
        }
        printf("\n");
    }
}

void shuffle_board(int *board, int size) {
    int i, j, temp;

    for (i = 0; i < size; i++) {
        j = rand() % size;
        temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}

void play_game(int *board, int size) {
    int i1, j1, i2, j2;
    int count = 0;
    int matches = 0;
    int selection[SIZE];

    printf("\nStart Game!\n");

    while (matches < SIZE - 1) {
        printf("\nSelect two cards (row1 col1 row2 col2): ");
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);

        if (board[i1 * COL + j1] == board[i2 * COL + j2]) {
            matches++;
            printf("Match found!\n");
            selection[matches * 2 - 2] = i1;
            selection[matches * 2 - 1] = j1;
            selection[matches * 2] = i2;
            selection[matches * 2 + 1] = j2;
            printf("%d Matches so far.\n", matches);
        } else {
            printf("No match found!\n");
        }
        count++;
        print_board(board, SIZE);
    }

    printf("\nCongratulations, You won the game in %d tries!\n", count);

    printf("\nHere is your final board:\n");
    for (i1 = 0; i1 < ROW; i1++) {
        for (j1 = 0; j1 < COL; j1++) {
            for (i2 = 0; i2 < matches * 2; i2 += 2) {
                if (i1 == selection[i2] && j1 == selection[i2 + 1]) {
                    printf("%2d ", board[i1 * COL + j1]);
                    goto found_match;
                }
            }
            printf("XX ");
            found_match:;
        }
        printf("\n");
    }
}