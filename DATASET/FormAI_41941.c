//FormAI DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// function prototypes
void print_board(int board[][BOARD_SIZE]);
void shuffle_board(int board[][BOARD_SIZE]);
void clear_screen();

int main() {
    // initialize the board
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    // seed random number generator
    srand(time(NULL));

    // shuffle the board
    shuffle_board(board);

    // print the board
    print_board(board);

    // game loop
    int num_pairs = BOARD_SIZE * BOARD_SIZE / 2;
    int num_guesses = 0;
    int pairs_found = 0;
    int row1, col1, row2, col2;
    while (pairs_found < num_pairs) {
        // get user input
        printf("Enter the row and column of two cards to flip: ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
        printf("\n");

        // check if coordinates are valid
        if (row1 < 0 || row1 >= BOARD_SIZE || row2 < 0 || row2 >= BOARD_SIZE ||
            col1 < 0 || col1 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
            printf("Invalid coordinates. Please try again.\n");
            continue;
        }

        // check if cards are already flipped
        if (board[row1][col1] < 0 || board[row2][col2] < 0) {
            printf("One or both of these cards have already been flipped. Please try again.\n");
            continue;
        }

        // flip the cards
        int card1 = board[row1][col1];
        int card2 = board[row2][col2];
        board[row1][col1] = -card1;
        board[row2][col2] = -card2;

        // print the board with the flipped cards
        clear_screen();
        print_board(board);

        // check if cards match
        if (card1 == card2) {
            printf("You found a pair!\n");
            pairs_found++;
        } else {
            printf("Sorry, those cards do not match.\n");
            board[row1][col1] = card1;
            board[row2][col2] = card2;
        }

        // increment number of guesses
        num_guesses++;
    }

    // print game over message
    printf("Game over! You found all %d pairs in %d guesses.\n", num_pairs, num_guesses);

    return 0;
}

void print_board(int board[][BOARD_SIZE]) {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] < 0) {
                printf("%d ", -board[row][col]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void shuffle_board(int board[][BOARD_SIZE]) {
    int values[BOARD_SIZE * BOARD_SIZE / 2];
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        values[i] = i + 1;
    }

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row == 0 && col == 0) {
                board[row][col] = values[0];
                continue;
            }

            int random_index = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
            int value = values[random_index];

            int count = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == value) {
                        count++;
                    }
                }
            }
            for (int j = 0; j < col; j++) {
                if (board[row][j] == value) {
                    count++;
                }
            }

            if (count == 0) {
                board[row][col] = value;
                values[random_index] = values[BOARD_SIZE * BOARD_SIZE / 2 - 1];
                values[BOARD_SIZE * BOARD_SIZE / 2 - 1] = value;
            } else {
                col--;
            }
        }
    }
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[2J\033[1;1H");
    #endif
}