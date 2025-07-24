//FormAI DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

/* Function to print game board */
void print_board(int board[ROWS][COLS]) {
    printf("\n    1  2  3  4 \n");
    printf("  +------------+\n");
    for(int i=0; i<ROWS; i++) {
        printf("%d |", i+1);
        for(int j=0; j<COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  +------------+\n\n");
}

/* Function to shuffle array */
void shuffle(int* array, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        int j = rand() % (size - i) + i;
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

int main() {
    int board[ROWS][COLS] = {{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12},
                             {13,14,15,16}}; // initial game board
    int moves[100]; // moves made by player
    int num_moves = 0; // count of number of moves made by player
    char input[10]; // buffer for user input

    // shuffle board
    int temp[16];
    for(int i=0; i<16; i++) {
        temp[i] = board[i/4][i%4];
    }
    shuffle(temp, 16);
    for(int i=0; i<16; i++) {
        board[i/4][i%4] = temp[i];
    }

    printf("Welcome to C Memory Game!\n");
    printf("The objective of this game is to match the pairs of numbers on the board.\n");
    printf("You will need to remember the position of the numbers to make a match.\n");
    printf("Enter 'quit' at anytime to exit the game.\n");

    // main game loop
    while(1) {
        print_board(board);
        printf("Enter the coordinates of the first number (row, col): ");
        fgets(input, 10, stdin);
        if(strncmp(input, "quit", 4) == 0) {
            printf("Thank you for playing!\n");
            break;
        }
        int row1 = input[0] - '0' - 1;
        int col1 = input[2] - '0' - 1;
        while(row1 < 0 || row1 > 3 || col1 < 0 || col1 > 3) {
            printf("Invalid input. Enter the coordinates of the first number (row, col): ");
            fgets(input, 10, stdin);
            if(strncmp(input, "quit", 4) == 0) {
                printf("Thank you for playing!\n");
                exit(0);
            }
            row1 = input[0] - '0' - 1;
            col1 = input[2] - '0' - 1;
        }
        printf("Select a second number to match.\n");
        printf("Enter the coordinates of the second number (row, col): ");
        fgets(input, 10, stdin);
        if(strncmp(input, "quit", 4) == 0) {
            printf("Thank you for playing!\n");
            break;
        }
        int row2 = input[0] - '0' - 1;
        int col2 = input[2] - '0' - 1;
        while(row2 < 0 || row2 > 3 || col2 < 0 || col2 > 3) {
            printf("Invalid input. Enter the coordinates of the second number (row, col): ");
            fgets(input, 10, stdin);
            if(strncmp(input, "quit", 4) == 0) {
                printf("Thank you for playing!\n");
                exit(0);
            }
            row2 = input[0] - '0' - 1;
            col2 = input[2] - '0' - 1;
        }

        // check if two chosen numbers match
        if(board[row1][col1] == board[row2][col2]) {
            printf("Match found! Well done.\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            // add moves to moves array
            moves[num_moves++] = row1;
            moves[num_moves++] = col1;
            moves[num_moves++] = row2;
            moves[num_moves++] = col2;
        }
        else {
            printf("No match found. Try again.\n");
        }

        // check if game is over
        int count = 0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] != 0) {
                    count++;
                }
            }
        }
        if(count == 0) {
            printf("Congratulations! You have completed the game in %d moves.\n", num_moves/4);
            printf("Your moves: ");
            for(int i=0; i<num_moves; i+=4) {
                printf("(%d,%d) and (%d,%d) ", moves[i]+1, moves[i+1]+1, moves[i+2]+1, moves[i+3]+1);
            }
            printf("\n");
            printf("Thank you for playing!\n");
            break;
        }
    }
    return 0;
}