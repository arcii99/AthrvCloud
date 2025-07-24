//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Define the width and height of the game board
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20

// Define the number of pellets on the board
#define NUM_PELLETS 180

// Define the game board and player variables
char game_board[BOARD_HEIGHT][BOARD_WIDTH];
int player_x, player_y;
int score = 0;

// Define the pellet structure
struct Pellet {
    int x, y;
    bool exists;
};

// Define the array of pellets
struct Pellet pellets[NUM_PELLETS];

// Initialize the game board
void init_board() {
    // Initialize all cells to empty
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            game_board[row][col] = ' ';
        }
    }
    
    // Add walls around the edges
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        game_board[row][0] = '#';
        game_board[row][BOARD_WIDTH-1] = '#';
    }
    for (int col = 0; col < BOARD_WIDTH; col++) {
        game_board[0][col] = '#';
        game_board[BOARD_HEIGHT-1][col] = '#';
    }
    
    // Add the player to the board
    player_x = BOARD_WIDTH / 2;
    player_y = BOARD_HEIGHT / 2;
    game_board[player_y][player_x] = 'P';
    
    // Add pellets to the board
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < NUM_PELLETS; i++) {
        bool placed = false;
        while (!placed) {
            // Choose a random location for the pellet
            int pellet_x = rand() % (BOARD_WIDTH-2) + 1;
            int pellet_y = rand() % (BOARD_HEIGHT-2) + 1;
            
            // If the cell is empty, place the pellet there
            if (game_board[pellet_y][pellet_x] == ' ') {
                game_board[pellet_y][pellet_x] = '.';
                pellets[i].x = pellet_x;
                pellets[i].y = pellet_y;
                pellets[i].exists = true;
                placed = true;
            }
        }
    }
}

// Print the game board to the console
void print_board() {
    // Clear the console
    system("cls");
    
    // Print the board
    for (int row = 0; row < BOARD_HEIGHT; row++) {
        for (int col = 0; col < BOARD_WIDTH; col++) {
            printf("%c", game_board[row][col]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// Move the player in the specified direction
void move_player(char direction) {
    // Calculate the new player position
    int new_x = player_x;
    int new_y = player_y;
    switch (direction) {
        case 'w':
            new_y--;
            break;
        case 's':
            new_y++;
            break;
        case 'a':
            new_x--;
            break;
        case 'd':
            new_x++;
            break;
    }
    
    // If the new position is empty, move the player there
    if (game_board[new_y][new_x] == ' ') {
        game_board[player_y][player_x] = ' ';
        game_board[new_y][new_x] = 'P';
        player_x = new_x;
        player_y = new_y;
    }
    
    // If the new position contains a pellet, collect it
    if (game_board[new_y][new_x] == '.') {
        for (int i = 0; i < NUM_PELLETS; i++) {
            if (pellets[i].x == new_x && pellets[i].y == new_y && pellets[i].exists) {
                pellets[i].exists = false;
                score++;
            }
        }
        game_board[player_y][player_x] = ' ';
        game_board[new_y][new_x] = 'P';
        player_x = new_x;
        player_y = new_y;
    }
}

int main() {
    // Initialize the game board
    init_board();
    
    // Play the game
    bool game_over = false;
    while (!game_over) {
        // Print the current game board
        print_board();
        
        // Get the user's input
        char input;
        printf("Enter a direction (w, a, s, d): ");
        scanf(" %c", &input);
        
        // Move the player in the specified direction
        move_player(input);
        
        // Check for game over conditions
        if (score == NUM_PELLETS) {
            game_over = true;
            printf("You win!\n");
        }
    }
    
    return 0;
}