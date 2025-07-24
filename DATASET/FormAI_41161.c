//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROW 10
#define COL 10
#define GHOSTS 3
#define TRAPS 4

// Define character struct
typedef struct Character {
    int row;
    int col;
} Character;

// Define function prototypes
void printBoard(char board[][COL], Character player);
void initializeBoard(char board[][COL], Character* player);
void initializeGhosts(char board[][COL], Character ghosts[]);
void initializeTraps(char board[][COL], Character traps[]);
void movePlayer(char board[][COL], Character* player);
void moveGhosts(char board[][COL], Character ghosts[]);
void checkCollision(Character player, Character ghosts[], Character traps[]);

// Define main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize board and characters
    char board[ROW][COL];
    Character player;
    initializeBoard(board, &player);
    Character ghosts[GHOSTS];
    initializeGhosts(board, ghosts);
    Character traps[TRAPS];
    initializeTraps(board, traps);

    // Loop until game is over
    while (1) {
        // Clear console and print board
        system("clear");
        printBoard(board, player);

        // Move player and ghosts
        movePlayer(board, &player);
        moveGhosts(board, ghosts);

        // Check for collision
        checkCollision(player, ghosts, traps);
    }

    return 0;
}

// Define function to print board and characters
void printBoard(char board[][COL], Character player) {
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (row == player.row && col == player.col) {
                printf("P ");
            } else {
                printf("%c ", board[row][col]);
            }
        }
        printf("\n");
    }
}

// Define function to initialize board and characters
void initializeBoard(char board[][COL], Character* player) {
    // Initialize board with walls and floor
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (row == 0 || row == ROW - 1 || col == 0 || col == COL - 1) {
                board[row][col] = '#';
            } else {
                board[row][col] = '-';
            }
        }
    }

    // Initialize player position
    player->row = 1;
    player->col = 1;
    board[player->row][player->col] = 'P';
}

// Define function to initialize ghosts
void initializeGhosts(char board[][COL], Character ghosts[]) {
    for (int i = 0; i < GHOSTS; i++) {
        ghosts[i].row = rand() % (ROW - 2) + 1;
        ghosts[i].col = rand() % (COL - 2) + 1;
        board[ghosts[i].row][ghosts[i].col] = 'G';
    }
}

// Define function to initialize traps
void initializeTraps(char board[][COL], Character traps[]) {
    for (int i = 0; i < TRAPS; i++) {
        traps[i].row = rand() % (ROW - 2) + 1;
        traps[i].col = rand() % (COL - 2) + 1;
        board[traps[i].row][traps[i].col] = 'T';
    }
}

// Define function to move player
void movePlayer(char board[][COL], Character* player) {
    // Get user input
    char input;
    printf("Enter w, a, s, or d to move: ");
    scanf(" %c", &input);

    // Move player
    switch (input) {
        case 'w':
            if (board[player->row - 1][player->col] != '#') {
                board[player->row][player->col] = '-';
                player->row--;
                board[player->row][player->col] = 'P';
            }
            break;
        case 'a':
            if (board[player->row][player->col - 1] != '#') {
                board[player->row][player->col] = '-';
                player->col--;
                board[player->row][player->col] = 'P';
            }
            break;
        case 's':
            if (board[player->row + 1][player->col] != '#') {
                board[player->row][player->col] = '-';
                player->row++;
                board[player->row][player->col] = 'P';
            }
            break;
        case 'd':
            if (board[player->row][player->col + 1] != '#') {
                board[player->row][player->col] = '-';
                player->col++;
                board[player->row][player->col] = 'P';
            }
            break;
    }
}

// Define function to move ghosts
void moveGhosts(char board[][COL], Character ghosts[]) {
    for (int i = 0; i < GHOSTS; i++) {
        // Get random direction
        int dir = rand() % 4;

        // Move ghost
        switch (dir) {
            case 0:
                if (board[ghosts[i].row - 1][ghosts[i].col] != '#') {
                    board[ghosts[i].row][ghosts[i].col] = '-';
                    ghosts[i].row--;
                    board[ghosts[i].row][ghosts[i].col] = 'G';
                }
                break;
            case 1:
                if (board[ghosts[i].row][ghosts[i].col - 1] != '#') {
                    board[ghosts[i].row][ghosts[i].col] = '-';
                    ghosts[i].col--;
                    board[ghosts[i].row][ghosts[i].col] = 'G';
                }
                break;
            case 2:
                if (board[ghosts[i].row + 1][ghosts[i].col] != '#') {
                    board[ghosts[i].row][ghosts[i].col] = '-';
                    ghosts[i].row++;
                    board[ghosts[i].row][ghosts[i].col] = 'G';
                }
                break;
            case 3:
                if (board[ghosts[i].row][ghosts[i].col + 1] != '#') {
                    board[ghosts[i].row][ghosts[i].col] = '-';
                    ghosts[i].col++;
                    board[ghosts[i].row][ghosts[i].col] = 'G';
                }
                break;
        }
    }
}

// Define function to check for collision
void checkCollision(Character player, Character ghosts[], Character traps[]) {
    // Check for collision with ghosts
    for (int i = 0; i < GHOSTS; i++) {
        if (player.row == ghosts[i].row && player.col == ghosts[i].col) {
            printf("You were caught by a ghost!\n");
            exit(0);
        }
    }

    // Check for collision with traps
    for (int i = 0; i < TRAPS; i++) {
        if (player.row == traps[i].row && player.col == traps[i].col) {
            printf("You fell into a trap!\n");
            exit(0);
        }
    }

    // Check for win condition
    if (player.row == ROW - 2 && player.col == COL - 2) {
        printf("You escaped the haunted house!\n");
        exit(0);
    }
}