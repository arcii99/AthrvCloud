//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 15
#define MAX_PELLETS 100

int board[HEIGHT][WIDTH]; // 0 = empty space, 1 = wall, 2 = pellet
int pacman_x, pacman_y; // Pac-Man's current position
int pellets_remaining = MAX_PELLETS; // Number of pellets left on the board

// Updates the Pac-Man's position based on user input
void update_pacman_position(int direction) {
    int new_x = pacman_x;
    int new_y = pacman_y;

    if (direction == 'w') {
        new_y--;
    } else if (direction == 'a') {
        new_x--;
    } else if (direction == 's') {
        new_y++;
    } else if (direction == 'd') {
        new_x++;
    }

    // Check if new position is inside the board and is not a wall
    if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT && board[new_y][new_x] != 1) {
        pacman_x = new_x;
        pacman_y = new_y;

        // Check if Pac-Man ate a pellet
        if (board[pacman_y][pacman_x] == 2) {
            board[pacman_y][pacman_x] = 0; // Remove the pellet from the board
            pellets_remaining--;
        }
    }
}

// Initializes the board with walls and pellets
void initialize_board() {
    int i, j;
    int num_pellets = 0;
    srand(time(NULL)); // Initialize random seed

    // Fill the board with walls on borders and random walls inside
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1 || rand() % 100 < 30) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    // Place pellets randomly on the board
    while (num_pellets < MAX_PELLETS) {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
        if (board[i][j] == 0) {
            board[i][j] = 2;
            num_pellets++;
        }
    }

    // Place Pac-Man's initial position
    for (i = 1; i < HEIGHT - 1; i++) { // Start from 1 to avoid borders
        for (j = 1; j < WIDTH - 1; j++) {
            if (board[i][j] == 0) {
                pacman_x = j;
                pacman_y = i;
                return;
            }
        }
    }
}

// Draws the board with ASCII characters
void draw_board() {
    int i, j;
    system("clear"); // Clear console before drawing
    printf("Pellets Remaining: %d\n", pellets_remaining);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == pacman_y && j == pacman_x) {
                printf("@"); // Pac-Man's character
            } else if (board[i][j] == 1) {
                printf("#"); // Wall character
            } else if (board[i][j] == 2) {
                printf("."); // Pellet character
            } else {
                printf(" "); // Empty space character
            }
        }
        printf("\n");
    }
}

int main() {
    char direction;
    initialize_board();

    while (pellets_remaining > 0) {
        draw_board();

        printf("Enter WASD to move: ");
        scanf("%c", &direction);
        update_pacman_position(direction);
        getchar(); // Remove newline from input buffer on some systems
    }

    draw_board();
    printf("You won!\n");
    return 0;
}