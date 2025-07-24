//FormAI DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6

int board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void init_board();
void reveal(int, int);
void print_board();
int check_win();

int main() {
    init_board(); // create the game board
    print_board(); // print the board for the first time
 
    int first_choice_row, first_choice_column, second_choice_row, second_choice_column;

    while (check_win() == 0) { // repeat until all pairs are found
        printf("Enter coordinates of the first card: ");
        scanf("%d %d", &first_choice_row, &first_choice_column);
        printf("Enter coordinates of the second card: ");
        scanf("%d %d", &second_choice_row, &second_choice_column);

        reveal(first_choice_row, first_choice_column);
        reveal(second_choice_row, second_choice_column);

        print_board(); // print the board after revealing the chosen cards

        if (board[first_choice_row][first_choice_column] != board[second_choice_row][second_choice_column]) {
            // if the chosen cards don't match, clear them and continue
            printf("Cards do not match. Starting over.\n");
            revealed[first_choice_row][first_choice_column] = 0;
            revealed[second_choice_row][second_choice_column] = 0;
        }
    }

    printf("Congratulations! You won!\n");

    return 0;
}

void init_board() {
    srand(time(NULL)); // seed the random number generator

    int i, j, current_value = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = current_value;
            revealed[i][j] = 0; // hide all cards at the start
            if (current_value % 2 == 0) {
                current_value = 1; // start over when all pairs have been added
            } else {
                current_value++;
            }
        }
    }

    // shuffle the cards by swapping random pairs
    int k;
    for (k = 0; k < 100; k++) {
        int row1 = rand() % BOARD_SIZE;
        int column1 = rand() % BOARD_SIZE;
        int row2 = rand() % BOARD_SIZE;
        int column2 = rand() % BOARD_SIZE;

        int temp = board[row1][column1];
        board[row1][column1] = board[row2][column2];
        board[row2][column2] = temp;
    }
}

void reveal(int row, int column) {
    revealed[row][column] = 1; // mark the card as revealed
}

void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j] == 0) {
                return 0; // if any pair is still hidden, the game continues
            }
        }
    }
    return 1; // if all pairs are revealed, the game is won
}