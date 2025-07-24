//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

#define ROW_SIZE 21
#define COL_SIZE 31 

char grid[ROW_SIZE][COL_SIZE] = {
    "+~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
    "|#################|########|",
    "|#################|########|",
    "|#################|########|",
    "|#################|########|",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|##########|################",
    "|################|########|",
    "|################|########|",
    "|################|########|",
    "|################|########|",
    "+~~~~~~~~~~~~~~~~~~~~~~~~~~~+"
};

struct Pacman {
    int x;
    int y;
    int score;
    bool alive;
};

struct Ghost {
    int x;
    int y;
    bool alive;
};

struct Pacman pacman = { 14, 14, 0, true };
struct Ghost ghost = { 10, 10, true };

// Get non-blocking input from user
int non_blocking_input() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Draw the grid with Pacman and Ghost
void draw_grid() {
    system("clear");
    for (int i = 0; i < ROW_SIZE; i++) {
        printf("%s\n", grid[i]);
    }
    printf("\nScore: %d\n", pacman.score);
    printf("\nUse Arrow Keys to Move Pac-Man\n");
}

// Move the Pacman
void move_pacman(int key) {
    int current_x = pacman.x;
    int current_y = pacman.y;
    int new_x = pacman.x;
    int new_y = pacman.y;
    
    // Change direction based on user input
    switch (key) {
        case 'A':
        case 'a':
            pacman.y--;
            break;
        case 'D':
        case 'd':
            pacman.y++;
            break;
        case 'W':
        case 'w':
            pacman.x--;
            break;
        case 'S':
        case 's':
            pacman.x++;
            break;
    }
    
    // Check if new position is within bounds
    if (pacman.x < 0 || pacman.x >= ROW_SIZE || pacman.y < 0 || pacman.y >= COL_SIZE) {
        pacman.x = current_x;
        pacman.y = current_y;
        return;
    }
    
    // Determine what's in the new position
    char c = grid[pacman.x][pacman.y];
    if (c == '#') {
        pacman.x = current_x;
        pacman.y = current_y;
    } else if (c == 'o') {
        pacman.score++;
        grid[pacman.x][pacman.y] = ' ';
    }
}

// Move the Ghost
void move_ghost() {
    int current_x = ghost.x;
    int current_y = ghost.y;
    int new_x = ghost.x;
    int new_y = ghost.y;
    
    // Determine where the Pacman is
    int dx = pacman.x - ghost.x;
    int dy = pacman.y - ghost.y;
    if (abs(dx) < abs(dy)) {
        if (dy < 0) {
            new_y--;
        } else {
            new_y++;
        }
    } else {
        if (dx < 0) {
            new_x--;
        } else {
            new_x++;
        }
    }
    
    // Check if new position is within bounds
    if (new_x < 0 || new_x >= ROW_SIZE || new_y < 0 || new_y >= COL_SIZE) {
        return;
    }
    
    // Determine what's in the new position
    char c = grid[new_x][new_y];
    if (c == '#') {
        return;
    } else if (c == 'P') {
        pacman.alive = false;
        return;
    }
    
    // Update the Ghost position
    ghost.x = new_x;
    ghost.y = new_y;
}

int main() {
    // Draw the initial grid
    draw_grid();
    
    // Loop until Pacman dies or eats all dots
    while (pacman.alive && pacman.score < 174) {
        // Get user input
        int key = non_blocking_input();
        
        // Move the Pacman
        move_pacman(key);
        
        // Move the Ghost
        move_ghost();
        
        // Redraw the grid
        draw_grid();
        
        // Slow down the game to make it playable
        usleep(100000);
    }
    
    // Game over
    printf("\nGame Over!\n");
    if (!pacman.alive) {
        printf("You were caught by the ghost!\n");
    } else {
        printf("Congratulations! You won!\n");
    }
    
    return 0;
}