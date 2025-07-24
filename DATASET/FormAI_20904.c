//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ROW 20
#define COL 30

// Pacman directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Pacman status
#define ALIVE 1
#define DEAD 0

// Board elements
#define EMPTY_SPACE ' '
#define WALL '|'
#define PELLET '.'
#define POWER_PELLET 'o'
#define PACMAN 'C'
#define GHOST 'G'

// Pellet values
#define PELLET_PTS 10
#define POWER_PELLET_PTS 50

// Number of ghosts
#define NUM_GHOSTS 4

char board[ROW][COL];
bool visited[ROW][COL];
int score, pellets_left;
bool power_pellet_active;
int pacman_status = ALIVE;
int pacman_row, pacman_col;
int ghost_row[NUM_GHOSTS], ghost_col[NUM_GHOSTS];
int ghost_dir[NUM_GHOSTS];

// Draw the board
void draw_board() {
    // Clear screen and print score
    system("clear");
    printf("Score: %d\n\n", score);
    
    // Print board
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Initialize board
void init_board() {
    // Load empty spaces
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }
    
    // Load walls
    for(int i = 0; i < ROW; i++) {
        board[i][0] = WALL;
        board[i][COL-1] = WALL;
    }
    
    for(int j = 0; j < COL; j++) {
        board[0][j] = WALL;
        board[ROW-1][j] = WALL;
    }
    
    // Load pacman
    pacman_row = ROW/2;
    pacman_col = COL/2;
    board[pacman_row][pacman_col] = PACMAN;
    
    // Load ghosts
    srand(time(NULL)); // Seed random number generator
    for(int i = 0; i < NUM_GHOSTS; i++) {
        ghost_row[i] = rand() % (ROW-2) + 1;
        ghost_col[i] = rand() % (COL-2) + 1;
        ghost_dir[i] = rand() % 4 + 1;
        board[ghost_row[i]][ghost_col[i]] = GHOST;
    }
    
    // Load pellets and power pellets
    memset(visited, false, sizeof(visited));
    pellets_left = 0;
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(board[i][j] == EMPTY_SPACE && !visited[i][j]) {
                // Generate pellet
                board[i][j] = PELLET;
                pellets_left++;
                
                // Generate power pellet
                if(i > 0 && i < ROW-1 && j > 0 && j < COL-1 && !visited[i-1][j] && !visited[i+1][j] && !visited[i][j-1] && !visited[i][j+1]) {
                    board[i][j] = POWER_PELLET;
                }
                
                // Mark surrounding blocks as visited
                visited[i][j] = true;
                visited[i-1][j] = true;
                visited[i+1][j] = true;
                visited[i][j-1] = true;
                visited[i][j+1] = true;
            }
        }
    }
}

// Move pacman
void move_pacman(int direction) {
    int new_row = pacman_row;
    int new_col = pacman_col;
    switch(direction) {
        case UP:
            new_row--;
            break;
        case DOWN:
            new_row++;
            break;
        case LEFT:
            new_col--;
            break;
        case RIGHT:
            new_col++;
            break;
    }
    
    // Check if move is valid
    if(board[new_row][new_col] != WALL) {
        // Handle eating pellets
        if(board[new_row][new_col] == PELLET) {
            score += PELLET_PTS;
            pellets_left--;
        }
        else if(board[new_row][new_col] == POWER_PELLET) {
            score += POWER_PELLET_PTS;
            power_pellet_active = true;
            pellets_left--;
        }
        
        // Move pacman
        board[pacman_row][pacman_col] = EMPTY_SPACE;
        pacman_row = new_row;
        pacman_col = new_col;
        board[pacman_row][pacman_col] = PACMAN;
    }
}

// Move ghosts
void move_ghosts() {
    for(int i = 0; i < NUM_GHOSTS; i++) {
        int new_row = ghost_row[i];
        int new_col = ghost_col[i];
        
        // Determine direction
        switch(ghost_dir[i]) {
            case UP:
                new_row--;
                break;
            case DOWN:
                new_row++;
                break;
            case LEFT:
                new_col--;
                break;
            case RIGHT:
                new_col++;
                break;
        }
        
        // Check if move is valid
        if(board[new_row][new_col] != WALL) {
            // Check if ghost ran into pacman
            if(new_row == pacman_row && new_col == pacman_col) {
                if(power_pellet_active) {
                    score += POWER_PELLET_PTS;
                    ghost_row[i] = rand() % (ROW-2) + 1;
                    ghost_col[i] = rand() % (COL-2) + 1;
                }
                else {
                    pacman_status = DEAD;
                }
            }
            else {
                // Move ghost
                board[ghost_row[i]][ghost_col[i]] = EMPTY_SPACE;
                ghost_row[i] = new_row;
                ghost_col[i] = new_col;
                board[ghost_row[i]][ghost_col[i]] = GHOST;
            }
        }
        else {
            // Change direction
            ghost_dir[i] = rand() % 4 + 1;
        }
    }
}

int main() {
    // Initialize board
    init_board();
    
    // Game loop
    while(pellets_left > 0 && pacman_status == ALIVE) {
        // Draw board
        draw_board();
        
        // Get user input
        int input;
        printf("Enter direction (1-4): ");
        scanf("%d", &input);
        
        // Make move
        move_pacman(input);
        move_ghosts();
        
        // Check if power pellet expired
        if(power_pellet_active) {
            power_pellet_active = false;
        }
        
        // Wait for user to press enter
        char enter;
        printf("Press enter to continue...");
        scanf("%c", &enter);
    }
    
    // Print game over message
    draw_board();
    if(pacman_status == DEAD) {
        printf("GAME OVER - You Lose!\n");
    }
    else {
        printf("GAME OVER - You Win!\n");
    }
    
    return 0;
}