//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constant values
#define ROW 10
#define COL 10
#define NUM_GHOSTS 3

// Define structure for ghost
struct Ghost {
    int row;
    int col;
};

// Function to wait for user to press enter
void waitForEnter() {
    char c;
    do {
        c = getchar();
    } while (c != '\n');
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create initial game board
    char board[ROW][COL];
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '.';
        }
    }

    // Initialize player in middle of board
    int player_row = ROW / 2;
    int player_col = COL / 2;
    board[player_row][player_col] = 'P';

    // Initialize ghosts randomly on board
    struct Ghost ghosts[NUM_GHOSTS];
    for (i = 0; i < NUM_GHOSTS; i++) {
        ghosts[i].row = rand() % ROW;
        ghosts[i].col = rand() % COL;
        board[ghosts[i].row][ghosts[i].col] = 'G';
    }

    // Print initial game board
    printf("HAUNTED HOUSE SIMULATOR\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Main loop
    int game_over = 0;
    char move;
    while (!game_over) {
        // Get player move
        printf("Enter move (w/s/a/d): ");
        move = getchar();
        waitForEnter();

        // Move player
        int new_row = player_row;
        int new_col = player_col;
        switch (move) {
            case 'w': new_row--; break;
            case 's': new_row++; break;
            case 'a': new_col--; break;
            case 'd': new_col++; break;
        }
        if (new_row < 0 || new_row >= ROW || new_col < 0 || new_col >= COL) {
            // Player moved off edge of board, game over
            printf("GAME OVER\n");
            game_over = 1;
            break;
        } else if (board[new_row][new_col] == 'G') {
            // Player collided with ghost, game over
            printf("GAME OVER\n");
            game_over = 1;
            break;
        } else {
            // Update player position on board
            board[player_row][player_col] = '.';
            player_row = new_row;
            player_col = new_col;
            board[player_row][player_col] = 'P';
        }

        // Move ghosts
        for (i = 0; i < NUM_GHOSTS; i++) {
            // Choose random direction to move ghost
            int dir = rand() % 4;
            int ghost_row = ghosts[i].row;
            int ghost_col = ghosts[i].col;
            switch (dir) {
                case 0: ghost_row--; break;
                case 1: ghost_row++; break;
                case 2: ghost_col--; break;
                case 3: ghost_col++; break;
            }
            if (ghost_row >= 0 && ghost_row < ROW && ghost_col >= 0 && ghost_col < COL) {
                // Update ghost position on board
                if (board[ghost_row][ghost_col] != 'P') {
                    board[ghosts[i].row][ghosts[i].col] = '.';
                    ghosts[i].row = ghost_row;
                    ghosts[i].col = ghost_col;
                    board[ghosts[i].row][ghosts[i].col] = 'G';
                }
            }
        }

        // Print updated game board
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}