//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_board(char board[][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS];
    int i, j;
    srand(time(NULL)); // seed random number generator

    // initialize board with blank spaces
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // randomly place ghost and player on board
    int ghost_row = rand() % ROWS;
    int ghost_col = rand() % COLS;
    int player_row = rand() % ROWS;
    int player_col = rand() % COLS;

    board[ghost_row][ghost_col] = 'G';
    board[player_row][player_col] = 'P';

    printf("Welcome to the Haunted House Simulator!\n\n");
    print_board(board);

    // main game loop
    while(1) {
        char input;
        printf("\nMove (up, down, left, right): ");
        scanf(" %c", &input);

        // move the player
        switch(input) {
            case 'u':
                if(player_row > 0) {
                    board[player_row][player_col] = ' ';
                    player_row--;
                }
                break;
            case 'd':
                if(player_row < ROWS-1) {
                    board[player_row][player_col] = ' ';
                    player_row++;
                }
                break;
            case 'l':
                if(player_col > 0) {
                    board[player_row][player_col] = ' ';
                    player_col--;
                }
                break;
            case 'r':
                if(player_col < COLS-1) {
                    board[player_row][player_col] = ' ';
                    player_col++;
                }
                break;
            default:
                printf("Invalid input!\n");
                continue;;
        }

        // check if player found the ghost
        if(player_row == ghost_row && player_col == ghost_col) {
            printf("\nYou found the ghost!\n");
            board[ghost_row][ghost_col] = 'X';
            print_board(board);
            break;
        }

        // randomly move the ghost
        int ghost_move = rand() % 4;
        switch(ghost_move) {
            case 0: // move up
                if(ghost_row > 0) {
                    board[ghost_row][ghost_col] = ' ';
                    ghost_row--;
                }
                break;
            case 1: // move down
                if(ghost_row < ROWS-1) {
                    board[ghost_row][ghost_col] = ' ';
                    ghost_row++;
                }
                break;
            case 2: // move left
                if(ghost_col > 0) {
                    board[ghost_row][ghost_col] = ' ';
                    ghost_col--;
                }
                break;
            case 3: // move right
                if(ghost_col < COLS-1) {
                    board[ghost_row][ghost_col] = ' ';
                    ghost_col++;
                }
                break;
        }

        // check if ghost found the player
        if(player_row == ghost_row && player_col == ghost_col) {
            printf("\nYou were caught by the ghost!\n");
            board[player_row][player_col] = 'X';
            print_board(board);
            break;
        }

        board[ghost_row][ghost_col] = 'G';
        board[player_row][player_col] = 'P';

        // print updated board
        printf("\n");
        print_board(board);
    }

    return 0;
}