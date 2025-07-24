//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 17
#define HEIGHT 17

// Function to print the board
void print_board(char board[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char board[HEIGHT][WIDTH]; // The board
    int score = 0; // The score
    int pacman_x = 8; // X position of Pac-Man
    int pacman_y = 8; // Y position of Pac-Man
    
    // Initialize the board with dots, Pac-Man and ghosts
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(i == pacman_y && j == pacman_x) {
                board[i][j] = 'P'; // Pac-Man
            } else {
                board[i][j] = '.'; // Dot
            }
        }
    }
    board[7][7] = 'G'; // Ghost
    board[7][9] = 'G'; // Ghost
    board[9][7] = 'G'; // Ghost
    board[9][9] = 'G'; // Ghost
    
    // Print the board
    print_board(board);
    
    // Game loop
    while(1) {
        // Get user input
        char input;
        printf("Enter a direction (WASD): ");
        scanf("%c", &input);
        
        // Update Pac-Man's position based on the user input
        switch(input) {
            case 'W':
                pacman_y--;
                break;
            case 'A':
                pacman_x--;
                break;
            case 'S':
                pacman_y++;
                break;
            case 'D':
                pacman_x++;
                break;
            default:
                printf("Invalid input!\n");
        }
        
        // Update the board based on Pac-Man's new position and collect any dots
        if(board[pacman_y][pacman_x] == '.') {
            board[pacman_y][pacman_x] = 'P'; // Pac-Man moves to the new position
            score++; // Increase the score
        } else if(board[pacman_y][pacman_x] == 'G') {
            printf("Game over! You were eaten by a ghost.\n");
            printf("Final score: %d\n", score);
            exit(0);
        } else {
            printf("Invalid move!\n");
        }
        
        // Clear the screen and print the updated board and score
        system("clear");
        printf("Score: %d\n", score);
        print_board(board);
        
        // Add a new dot to the board randomly
        srand(time(0));
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        if(board[y][x] == '.') {
            board[y][x] = '.';
        }
    }
    
    return 0;
}