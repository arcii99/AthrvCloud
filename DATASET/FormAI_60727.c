//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int board[][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0}; // initialize board to all zeros
    int num_spaces = BOARD_SIZE * BOARD_SIZE;
    int row, col, num;

    srand(time(NULL)); // initialize random number generator

    // randomly place two numbers on board
    row = rand() % BOARD_SIZE;
    col = rand() % BOARD_SIZE;
    num = (rand() % 2 + 1) * 2;
    board[row][col] = num;

    num_spaces--;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while(board[row][col] != 0);

    num = (rand() % 2 + 1) * 2;
    board[row][col] = num;

    num_spaces--;

    // game loop
    while(num_spaces > 0) {
        // print board
        print_board(board);

        // get move from player
        char move;
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &move);

        int i, j;
        switch(move) {
            case 'w': // move up
                // slide numbers up
                for(j = 0; j < BOARD_SIZE; j++) { // for each column
                    for(i = 1; i < BOARD_SIZE; i++) { // for each row (starting from second row)
                        if(board[i][j] == 0) { // if this cell is empty
                            continue; // skip to next row
                        }
                        // slide this number up until it hits the edge or another number
                        int k;
                        for(k = i - 1; k >= 0; k--) {
                            if(board[k][j] == 0) { // if this cell is empty
                                board[k][j] = board[k+1][j];
                                board[k+1][j] = 0;
                            }
                            else if(board[k][j] == board[k+1][j]) { // if this cell has same value as current cell
                                board[k][j] *= 2;
                                board[k+1][j] = 0;
                                break;
                            }
                            else { // if this cell has different value as current cell
                                break;
                            }
                        }
                    }
                }
                break;

            case 'a': // move left
                // slide numbers left
                for(i = 0; i < BOARD_SIZE; i++) { // for each row
                    for(j = 1; j < BOARD_SIZE; j++) { // for each column (starting from second column)
                        if(board[i][j] == 0) { // if this cell is empty
                            continue; // skip to next column
                        }
                        // slide this number left until it hits the edge or another number
                        int k;
                        for(k = j - 1; k >= 0; k--) {
                            if(board[i][k] == 0) { // if this cell is empty
                                board[i][k] = board[i][k+1];
                                board[i][k+1] = 0;
                            }
                            else if(board[i][k] == board[i][k+1]) { // if this cell has same value as current cell
                                board[i][k] *= 2;
                                board[i][k+1] = 0;
                                break;
                            }
                            else { // if this cell has different value as current cell
                                break;
                            }
                        }
                    }
                }
                break;

            case 's': // move down
                // slide numbers down
                for(j = 0; j < BOARD_SIZE; j++) { // for each column
                    for(i = BOARD_SIZE - 2; i >= 0; i--) { // for each row (starting from second to last row)
                        if(board[i][j] == 0) { // if this cell is empty
                            continue; // skip to next row
                        }
                        // slide this number down until it hits the edge or another number
                        int k;
                        for(k = i + 1; k < BOARD_SIZE; k++) {
                            if(board[k][j] == 0) { // if this cell is empty
                                board[k][j] = board[k-1][j];
                                board[k-1][j] = 0;
                            }
                            else if(board[k][j] == board[k-1][j]) { // if this cell has same value as current cell
                                board[k][j] *= 2;
                                board[k-1][j] = 0;
                                break;
                            }
                            else { // if this cell has different value as current cell
                                break;
                            }
                        }
                    }
                }
                break;

            case 'd': // move right
                // slide numbers right
                for(i = 0; i < BOARD_SIZE; i++) { // for each row
                    for(j = BOARD_SIZE - 2; j >= 0; j--) { // for each column (starting from second to last column)
                        if(board[i][j] == 0) { // if this cell is empty
                            continue; // skip to next column
                        }
                        // slide this number right until it hits the edge or another number
                        int k;
                        for(k = j + 1; k < BOARD_SIZE; k++) {
                            if(board[i][k] == 0) { // if this cell is empty
                                board[i][k] = board[i][k-1];
                                board[i][k-1] = 0;
                            }
                            else if(board[i][k] == board[i][k-1]) { // if this cell has same value as current cell
                                board[i][k] *= 2;
                                board[i][k-1] = 0;
                                break;
                            }
                            else { // if this cell has different value as current cell
                                break;
                            }
                        }
                    }
                }
                break;

            default:
                printf("Invalid move. Please enter w/a/s/d.\n");
                continue; // go back to beginning of loop
        }

        // randomly place another number on board
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while(board[row][col] != 0);

        num = (rand() % 2 + 1) * 2;
        board[row][col] = num;

        num_spaces--;
    }

    // print final board
    print_board(board);
    printf("Game over!\n");

    return 0;
}