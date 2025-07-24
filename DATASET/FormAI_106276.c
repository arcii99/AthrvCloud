//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

/* function prototypes */
void print_board(int board[ROWS][COLS]);
int get_random_number(int min, int max);
int is_number_in_board(int board[ROWS][COLS], int number);
int check_bingo(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int numbers[75];
    int drawn_count = 0;
    int number;

    // initialize board with zeros
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // initialize array of numbers
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }

    // set random seed
    srand(time(NULL));

    // start game loop
    while (1) {
        // print board
        printf("\n");
        print_board(board);

        // check for bingo
        if (check_bingo(board)) {
            printf("\nBingo! You won!\n");
            break;
        }

        // get random number that has not been drawn yet
        do {
            number = get_random_number(1, 75);
        } while (is_number_in_board(board, number));

        printf("Next number: %d\n", number);

        // add number to board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 0 && numbers[number-1] == number) {
                    board[i][j] = number;
                    drawn_count++;
                }
            }
        }

        // check if all numbers have been drawn
        if (drawn_count >= 75) {
            printf("\nGame over! No more numbers left.\n");
            break;
        }

        // wait for user to press enter
        printf("\nPress enter to draw the next number...\n");
        while (getchar() != '\n');
    }

    return 0;
}

// print board function
void print_board(int board[ROWS][COLS]) {
    printf("Current Board:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("[__]");
            } else {
                printf("[%2d]", board[i][j]);
            }
        }

        printf("\n");
    }
}

// get random number function
int get_random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// check if number is already in board
int is_number_in_board(int board[ROWS][COLS], int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == number) {
                return 1;
            }
        }
    }

    return 0;
}

// check for bingo function
int check_bingo(int board[ROWS][COLS]) {
    int count;

    // check rows
    for (int i = 0; i < ROWS; i++) {
        count = 0;

        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != 0) {
                count++;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        count = 0;

        for (int j = 0; j < ROWS; j++) {
            if (board[j][i] != 0) {
                count++;
            }
        }

        if (count == 5) {
            return 1;
        }
    }

    // check diagonal from top left to bottom right
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] != 0) {
            count++;
        }
    }

    if (count == 5) {
        return 1;
    }

    // check diagonal from bottom left to top right
    count = 0;
    for (int i = ROWS-1, j = 0; i >= 0 && j < COLS; i--, j++) {
        if (board[i][j] != 0) {
            count++;
        }
    }

    if (count == 5) {
        return 1;
    }

    return 0;
}