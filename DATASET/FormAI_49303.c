//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16 // board size of 16
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// function prototypes
void print_board(int board[], int guesses[], int size);
int get_choice();
void swap(int *a, int *b);
void shuffle(int board[], int size);
int get_direction();
void move(int board[], int guesses[], int size, int direction);
int check_win(int guesses[], int size);

// main function
int main() {
    int board[BOARD_SIZE]; // array to hold the numbers on the board
    int guesses[BOARD_SIZE] = {0}; // array to hold the guesses
    int size = BOARD_SIZE; // size of the board
    int moves = 0; // number of moves made
    int direction; // direction to move in

    srand(time(0)); // seed random number generator

    // initialize board array
    for (int i = 0; i < size; i++) {
        board[i] = i / 2 + 1;
    }

    // shuffle board array
    shuffle(board, size);

    // print board
    print_board(board, guesses, size);

    // game loop
    while (!check_win(guesses, size)) {
        // get direction from user
        direction = get_direction();

        // move board in chosen direction
        move(board, guesses, size, direction);
        moves += 1;

        // print board after move
        print_board(board, guesses, size);

        // print number of moves made
        printf("Moves: %d\n", moves);
    }

    // print win message
    printf("Congratulations, you win!\n");
    printf("Number of moves: %d\n", moves);

    return 0;
}

// function to print the board
void print_board(int board[], int guesses[], int size) {
    printf("\n");

    for (int i = 0; i < size; i++) {
        if (guesses[i]) {
            printf("%3d", board[i]);
        } else {
            printf("%3c", '?');
        }

        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

// function to get the user's choice of direction
int get_direction() {
    int choice;

    do {
        printf("Choose a direction to move (1 - up, 2 - down, 3 - left, 4 - right): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);

    return choice;
}

// function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to shuffle the board
void shuffle(int board[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(&board[i], &board[j]);
    }
}

// function to move the board
void move(int board[], int guesses[], int size, int direction) {
    int row, col;

    // find empty slot (0)
    for (int i = 0; i < size; i++) {
        if (board[i] == 0) {
            row = i / 4;
            col = i % 4;
            break;
        }
    }

    // move board in chosen direction
    switch (direction) {
        case UP:
            if (row != 0) {
                swap(&board[row * 4 + col], &board[(row - 1) * 4 + col]);
            }
            break;
        case DOWN:
            if (row != 3) {
                swap(&board[row * 4 + col], &board[(row + 1) * 4 + col]);
            }
            break;
        case LEFT:
            if (col != 0) {
                swap(&board[row * 4 + col], &board[row * 4 + col - 1]);
            }
            break;
        case RIGHT:
            if (col != 3) {
                swap(&board[row * 4 + col], &board[row * 4 + col + 1]);
            }
            break;
    }

    // mark guessed tiles
    for (int i = 0; i < size; i++) {
        if (board[i] == 0 || guesses[i]) {
            continue;
        }

        if (board[i] == board[row * 4 + col]) {
            guesses[i] = 1;
        }
    }
}

// function to check if the game has been won
int check_win(int guesses[], int size) {
    for (int i = 0; i < size; i++) {
        if (!guesses[i]) {
            return 0;
        }
    }

    return 1;
}