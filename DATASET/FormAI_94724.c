//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

int player_position[2] = {0, 0}; // initial position of the player
int ghost_position[2] = {0, 0}; // initial position of the ghost
int score = 0; // initial score is 0
bool is_ghost_alive = true; // flag to check if the ghost is alive

void display_board(char board[][COLS+1]) {
    printf("\nScore: %d\n\n", score);
    for(int i = 0; i < ROWS; i++) {
        printf("%s\n", board[i]);
    }
}

void update_board(char board[][COLS+1]) {
    // update the board with current player and ghost positions
    board[player_position[0]][player_position[1]] = 'P';
    if(is_ghost_alive) {
        board[ghost_position[0]][ghost_position[1]] = 'G';
    }
    display_board(board);
}
 
int main() {
    srand(time(NULL)); // seed the random number generator
    char board[ROWS][COLS+1];
    // initialize the board with empty spaces
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
        board[i][COLS] = '\0'; // add the null terminator at the end of the row
    }
    int treasure_row = rand() % ROWS; // generate a random row for the treasure
    int treasure_col = rand() % COLS; // generate a random column for the treasure
    board[treasure_row][treasure_col] = 'T'; // place the treasure on the board
    ghost_position[0] = rand() % ROWS; // generate a random row for the ghost
    ghost_position[1] = rand() % COLS; // generate a random column for the ghost
    player_position[0] = ROWS-1; // player starts at the bottom row
    player_position[1] = COLS/2; // player starts at the middle column

    // main game loop
    while(true) {
        system("clear"); // clear the screen before displaying the updated board
        update_board(board);
        if(player_position[0] == treasure_row && player_position[1] == treasure_col) {
            printf("\nYou found the treasure! Congrats!\n");
            break;
        }
        if(is_ghost_alive && player_position[0] == ghost_position[0] && player_position[1] == ghost_position[1]) {
            printf("\nYou got caught by the ghost! Game over.\n");
            break;
        }
        char input;
        printf("Enter your next move ('w' for up, 'a' for left, 's' for down, 'd' for right): ");
        scanf(" %c", &input);
        if(input == 'w') {
            player_position[0]--;
        } else if(input == 'a') {
            player_position[1]--;
        } else if(input == 's') {
            player_position[0]++;
        } else if(input == 'd') {
            player_position[1]++;
        }
        if(player_position[0] < 0) {
            player_position[0] = 0;
        } else if(player_position[0] >= ROWS) {
            player_position[0] = ROWS-1;
        }
        if(player_position[1] < 0) {
            player_position[1] = 0;
        } else if(player_position[1] >= COLS) {
            player_position[1] = COLS-1;
        }
        if(is_ghost_alive) {
            // update the ghost position
            int ghost_move = rand() % 4;
            if(ghost_move == 0) {
                ghost_position[0]--;
            } else if(ghost_move == 1) {
                ghost_position[1]--;
            } else if(ghost_move == 2) {
                ghost_position[0]++;
            } else if(ghost_move == 3) {
                ghost_position[1]++;
            }
            if(ghost_position[0] < 0) {
                ghost_position[0] = 0;
            } else if(ghost_position[0] >= ROWS) {
                ghost_position[0] = ROWS-1;
            }
            if(ghost_position[1] < 0) {
                ghost_position[1] = 0;
            } else if(ghost_position[1] >= COLS) {
                ghost_position[1] = COLS-1;
            }
        } else {
            // if the ghost is dead, revive it with a 20% chance
            if(rand() % 5 == 0) {
                is_ghost_alive = true;
            }
        }
        score++; // increment the score with each move
    }
    return 0;
}