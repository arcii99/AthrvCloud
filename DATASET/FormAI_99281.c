//FormAI DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // change board size here

// function prototypes
void create_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE], int hide_numbers[]);
int check_valid_move(int board[][BOARD_SIZE], int choice1, int choice2);
void make_move(int board[][BOARD_SIZE], int choice1, int choice2, int hide_numbers[]);
int check_game_over(int hide_numbers[]);

int main() {
    srand(time(NULL)); // seed random number generator

    int board[BOARD_SIZE][BOARD_SIZE];
    int hide_numbers[BOARD_SIZE * BOARD_SIZE]; // array to keep track of hidden numbers
    create_board(board); // populate board with random numbers
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        hide_numbers[i] = 1; // initialize all numbers as hidden
    }

    int choice1, choice2, valid_move;
    int moves = 0;
    while (check_game_over(hide_numbers)) { // check if all numbers are uncovered
        print_board(board, hide_numbers); 
        printf("Enter two coordinates (ex: 1 2): ");
        scanf("%d %d", &choice1, &choice2);

        valid_move = check_valid_move(board, choice1, choice2);
        if (valid_move == 1) {
            printf("This number has already been uncovered. Please choose another.\n");
        } else if (valid_move == 2) {
            printf("Invalid coordinates. Please choose two numbers between 1 and %d.\n", BOARD_SIZE);
        } else {
            make_move(board, choice1, choice2, hide_numbers);
            moves++;
        }
    }
    print_board(board, hide_numbers); // print final board
    printf("Game over! You won in %d moves.\n", moves);

    return 0;
}

// function to create the random board
void create_board(int board[][BOARD_SIZE]) {
    int numbers[BOARD_SIZE * BOARD_SIZE / 2];
    int count = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        numbers[i] = count++ % (BOARD_SIZE * BOARD_SIZE / 2) + 1; // create numbers in pairs
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
            while (numbers[index] == 0) { // make sure number hasn't already been placed
                index = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
            }
            board[i][j] = numbers[index];
            numbers[index] = 0; // mark number as placed
        }
    }
}

// function to print the board
void print_board(int board[][BOARD_SIZE], int hide_numbers[]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (hide_numbers[i * BOARD_SIZE + j] == 0) { // if number is not hidden, print it
                printf("%d ", board[i][j]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

// function to check if move is valid
int check_valid_move(int board[][BOARD_SIZE], int choice1, int choice2) {
    choice1--;
    choice2--;

    if (choice1 < 0 || choice1 >= BOARD_SIZE || choice2 < 0 || choice2 >= BOARD_SIZE) {
        return 2; // invalid coordinates
    }

    if (board[choice1][choice2] == -1) {
        return 1; // number has already been uncovered
    }

    return 0;
}

// function to uncover the chosen numbers
void make_move(int board[][BOARD_SIZE], int choice1, int choice2, int hide_numbers[]) {
    choice1--;
    choice2--;

    if (board[choice1][choice2] == -1) {
        printf("This number has already been uncovered. Please choose another.\n");
    } else {
        int val = board[choice1][choice2];
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == val) {
                    hide_numbers[i * BOARD_SIZE + j] = 0; // mark both numbers as uncovered
                }
            }
        }
        board[choice1][choice2] = -1; // mark number as uncovered
    }
}

// function to check if game is over
int check_game_over(int hide_numbers[]) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (hide_numbers[i] == 1) {
            return 1; // there are still hidden numbers
        }
    }
    return 0; // all numbers have been uncovered
}