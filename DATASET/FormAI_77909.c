//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random number
int generate_random_num(int min, int max) {
    srand(time(0)); // Seed the random number generator with the current time
    return (rand() % (max - min + 1)) + min;
}

// Function to initialize the game board
void initialize_board(char board[][30], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = '.';
        }
    }
}

// Function to print the game board
void print_board(char board[][30], int rows, int columns) {
    printf("\n"); // Add some spacing
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n"); // Add new line after each row
    }
    printf("\n"); // Add some spacing
}

// Function to move the player
void move_player(char board[][30], int rows, int columns, int* player_pos, int move) {
    int current_pos = *player_pos;
    board[rows - 1][current_pos] = '.'; // Remove the player from current position
    if (move == 1) { // Move left
        if (current_pos > 0) {
            *player_pos = current_pos - 1;
            board[rows - 1][*player_pos] = 'P'; // Add the player to new position
        }
    }
    else if (move == 2) { // Move right
        if (current_pos < columns - 1) {
            *player_pos = current_pos + 1;
            board[rows - 1][*player_pos] = 'P'; // Add the player to new position
        }
    }
}

// Function to move the aliens and check for collision with player or bottom row
void move_aliens(char board[][30], int rows, int columns, int* alien_pos, int* num_aliens) {
    for (int i = 0; i < *num_aliens; i++) {
        int current_pos = alien_pos[i];
        board[i][current_pos] = '.'; // Remove the alien from current position
        if (i == rows - 2 && board[i + 1][current_pos] == 'P') { // Check for collision with player at bottom row
            printf("\nGame Over!\n");
            exit(0);
        }
        if (current_pos == 0) { // Alien hit left boundary, move right
            alien_pos[i] = current_pos + 1;
        }
        else if (current_pos == columns - 1) { // Alien hit right boundary, move left
            alien_pos[i] = current_pos - 1;
        }
        else { // Move the alien randomly left or right
            int random_move = generate_random_num(1, 2);
            if (random_move == 1) {
                alien_pos[i] = current_pos - 1;
            }
            else {
                alien_pos[i] = current_pos + 1;
            }
        }
        board[i][alien_pos[i]] = 'A'; // Add the alien to new position
    }
}

int main() {
    int rows = 10;
    int columns = 30;
    char board[rows][columns];
    int player_pos = columns / 2; // Initial position of the player
    int alien_pos[rows - 1]; // Array to store the positions of the aliens
    int num_aliens = rows - 1; // Number of aliens equal to number of rows - 1
    
    initialize_board(board, rows, columns); // Initialize the game board
    
    // Add the player to the board
    board[rows - 1][player_pos] = 'P';
    
    // Add the aliens to the board and store their positions
    for (int i = 0; i < num_aliens; i++) {
        int random_pos = generate_random_num(0, columns - 1);
        board[i][random_pos] = 'A';
        alien_pos[i] = random_pos;
    }
    
    print_board(board, rows, columns); // Print the initial game board
    
    bool playing = true;
    while (playing) {
        // Get player move input
        int move;
        printf("Enter 1 to move left, enter 2 to move right: ");
        scanf("%d", &move);
        
        // Move the player
        move_player(board, rows, columns, &player_pos, move);
        
        // Move the aliens and check for collision
        move_aliens(board, rows, columns, alien_pos, &num_aliens);
        
        print_board(board, rows, columns); // Print the updated game board
    }
    
    return 0;
}