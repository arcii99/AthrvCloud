//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_MOVES 50

// Structure representing the player's position on the board
typedef struct {
    int x;
    int y;
} Player;

int main() {
    srand(time(NULL)); // Initialize random number generator

    char board[BOARD_SIZE][BOARD_SIZE]; // Initialize game board

    // Set all board values to be empty spaces initially
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    Player player; // Initialize player's starting position
    player.x = rand() % BOARD_SIZE;
    player.y = rand() % BOARD_SIZE;

    int moves = 0; // Initialize move counter

    // Main game loop - continue until user runs out of moves or finds the treasure
    while(moves < MAX_MOVES) {
        printf("You have %d moves left.\n", MAX_MOVES - moves);
        printf("You are at position (%d,%d)\n", player.x, player.y);
        printf("Enter your move (u = up, d = down, l = left, r = right): ");

        char move;
        scanf(" %c", &move);

        // Update player's position based on user's move
        switch(move) {
            case 'u':
                if(player.y > 0) {
                    player.y--;
                }
                break;
            case 'd':
                if(player.y < BOARD_SIZE - 1) {
                    player.y++;
                }
                break;
            case 'l':
                if(player.x > 0) {
                    player.x--;
                }
                break;
            case 'r':
                if(player.x < BOARD_SIZE - 1) {
                    player.x++;
                }
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        // Check if player has found the treasure
        if(board[player.y][player.x] == 'X') {
            printf("Congratulations! You have found the treasure!\n");
            return 0;
        }

        // If player has not found the treasure, update board with player's new position
        board[player.y][player.x] = '+';

        // Randomly place treasure on board if it hasn't already been placed
        int treasure_placed = 0;
        if(moves == 0) {
            while(!treasure_placed) {
                int treasure_x = rand() % BOARD_SIZE;
                int treasure_y = rand() % BOARD_SIZE;
                if(board[treasure_y][treasure_x] != '+') {
                    board[treasure_y][treasure_x] = 'X';
                    treasure_placed = 1;
                }
            }
        }

        // Print out the current state of the board
        for(int i = 0; i < BOARD_SIZE; i++) {
            printf("|");
            for(int j = 0; j < BOARD_SIZE; j++) {
                printf(" %c |", board[i][j]);
            }
            printf("\n");
        }

        moves++; // Increment move counter
    }

    printf("Sorry, you have run out of moves. Game over.\n");

    return 0;
}