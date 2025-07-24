//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define ROWS 10
#define COLS 10

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the player structure
typedef struct {
    char name[20];
    int x;
    int y;
} Player;

// Define the grid, players array and exit position
char grid[ROWS][COLS];
Player players[MAX_PLAYERS];
int exit_x, exit_y;

// Function to generate random integer between min and max
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if the given position is valid and empty
int isValidPosition(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] == ' ');
}

// Function to move the player to the new position
void movePlayer(Player* player, int new_x, int new_y) {
    // Check if the new position is valid
    if (isValidPosition(new_x, new_y)) {
        // Update the grid
        grid[player->x][player->y] = ' ';
        grid[new_x][new_y] = player->name[0];
        // Update the player position
        player->x = new_x;
        player->y = new_y;
    }
}

// Function to print the grid and players
void printGrid() {
    // Print the grid
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf("%d", i % 10);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d", i % 10);
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    // Print the players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s (%d,%d)\n", players[i].name, players[i].x, players[i].y);
    }
}

// Function to check if any player has reached the exit
int checkExit() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].x == exit_x && players[i].y == exit_y) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Initialize the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
    
    // Initialize the players
    players[0] = (Player){"Player 1", 0, 0};
    players[1] = (Player){"Player 2", 0, 9};
    players[2] = (Player){"Player 3", 9, 0};
    players[3] = (Player){"Player 4", 9, 9};
    for (int i = 0; i < MAX_PLAYERS; i++) {
        grid[players[i].x][players[i].y] = players[i].name[0];
    }
    
    // Generate the exit position
    exit_x = randomInt(0, ROWS-1);
    exit_y = randomInt(0, COLS-1);
    grid[exit_x][exit_y] = 'E';
    
    // Print the initial game state
    printGrid();
    
    // Start the game loop
    int winner = 0;
    while (!winner) {
        // Get the player input
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s's turn\n", players[i].name);
            int new_x = players[i].x, new_y = players[i].y;
            char direction;
            printf("Enter direction (w/a/s/d): ");
            scanf(" %c", &direction);
            switch (direction) {
                case 'w':
                    new_x--;
                    break;
                case 'a':
                    new_y--;
                    break;
                case 's':
                    new_x++;
                    break;
                case 'd':
                    new_y++;
                    break;
                default:
                    printf("Invalid direction\n");
            }
            movePlayer(&players[i], new_x, new_y);
            printGrid();
            if (checkExit()) {
                winner = i+1;
                break;
            }
        }
    }
    
    // Print the winner
    printf("Congratulations, %s won the game!\n", players[winner-1].name);
    
    return 0;
}