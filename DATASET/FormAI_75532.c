//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

char grid[HEIGHT][WIDTH];
int pacman_x, pacman_y;
int ghost_x, ghost_y;
int score = 0;

// Initialize the game board
void initialize() {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            if (i==0 || i==HEIGHT-1 || j==0 || j==WIDTH-1) {
                grid[i][j] = '#';
            } else if (i==pacman_y && j==pacman_x) {
                grid[i][j] = 'P';
            } else if (i==ghost_y && j==ghost_x) {
                grid[i][j] = 'G';
            } else if (rand()%4 == 0) { // 25% chance to spawn a dot
                grid[i][j] = '.';
            } else {
                grid[i][j] = ' ';
            }
        }
    }
}

// Render the game board
void render() {
    int i, j;
    printf("Score: %d\n", score);
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Move Pac-Man according to user input
void movePacman(char direction) {
    int x, y;
    switch (direction) {
        case 'w':
            x = pacman_x;
            y = pacman_y - 1;
            break;
        case 'a':
            x = pacman_x - 1;
            y = pacman_y;
            break;
        case 's':
            x = pacman_x;
            y = pacman_y + 1;
            break;
        case 'd':
            x = pacman_x + 1;
            y = pacman_y;
            break;
        default:
            x = pacman_x;
            y = pacman_y;
            break;
    }
    if (grid[y][x] == '#') { // Hit a wall
        x = pacman_x;
        y = pacman_y;
    } else if (grid[y][x] == '.') { // Collect a dot
        score++;
    }
    grid[pacman_y][pacman_x] = ' ';
    grid[y][x] = 'P';
    pacman_x = x;
    pacman_y = y;
}

// Move the ghost towards Pac-Man
void moveGhost() {
    int x_diff = ghost_x - pacman_x;
    int y_diff = ghost_y - pacman_y;
    int x, y;
    if (abs(x_diff) > abs(y_diff)) { // Move horizontally
        if (x_diff < 0) {
            x = ghost_x + 1;
            y = ghost_y;
        } else {
            x = ghost_x - 1;
            y = ghost_y;
        }
    } else { // Move vertically
        if (y_diff < 0) {
            x = ghost_x;
            y = ghost_y + 1;
        } else {
            x = ghost_x;
            y = ghost_y - 1;
        }
    }
    if (grid[y][x] == '#') {
        x = ghost_x;
        y = ghost_y;
    }
    grid[ghost_y][ghost_x] = ' ';
    grid[y][x] = 'G';
    ghost_x = x;
    ghost_y = y;
}

int main() {
    srand(time(NULL));
    pacman_x = WIDTH/2;
    pacman_y = HEIGHT/2;
    ghost_x = rand()%(WIDTH-2) + 1; // Randomly spawn the ghost
    ghost_y = rand()%(HEIGHT-2) + 1;
    initialize();
    render();
    char input;
    do {
        printf("Enter a direction (wasd): ");
        scanf("%c", &input);
        movePacman(input);
        moveGhost();
        render();
    } while (score < 10); // Game ends after collecting 10 dots
    printf("You won!\n");
    return 0;
}