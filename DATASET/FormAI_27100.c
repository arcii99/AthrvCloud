//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define ROWS 21
#define COLS 21
#define MAX_GHOSTS 4
#define TICK_INTERVAL 150

// Define variables
char maze[ROWS][COLS];
int score = 0;
int pelletsLeft = 0;
bool gameOver = false;

// Define struct for Pac-Man
typedef struct PacMan {
    int row;
    int col;
    int direction; // 0 = up, 1 = right, 2 = down, 3 = left
} PacMan;

// Define struct for ghosts
typedef struct Ghost {
    int row;
    int col;
    int direction; // 0 = up, 1 = right, 2 = down, 3 = left
} Ghost;

// Declare functions
void initializeMaze();
void initializePacMan(PacMan *pacman);
void initializeGhosts(Ghost *ghosts);
void printMaze(PacMan pacman, Ghost ghosts[]);
void movePacMan(char input, PacMan *pacman);
void moveGhost(Ghost *ghost, PacMan pacman);
void checkCollisions(PacMan pacman, Ghost ghosts[]);
void gameOverMessage();
void updateScore(int value);
void displayScore();

int main() {
    srand(time(NULL)); // Seed random number generator

    // Initialize maze, Pac-Man, and ghosts
    initializeMaze();
    PacMan pacman;
    initializePacMan(&pacman);
    Ghost ghosts[MAX_GHOSTS];
    initializeGhosts(ghosts);

    // Game loop
    while (!gameOver) {
        // Print maze and score
        printMaze(pacman, ghosts);
        displayScore();

        // Move Pac-Man and ghosts
        char input;
        printf("Move Pac-Man (WASD): ");
        scanf(" %c", &input);
        movePacMan(input, &pacman);
        for (int i = 0; i < MAX_GHOSTS; i++) {
            moveGhost(&ghosts[i], pacman);
        }

        // Check collisions and update score
        checkCollisions(pacman, ghosts);
        pelletsLeft--; // Decrement pellets left

        // Check if game is over
        if (pelletsLeft == 0) {
            gameOver = true;
            printf("Congratulations, you won!\n");
        }
        else if (pacman.row == -1) {
            gameOver = true;
            printf("Game over!\n");
        }

        // Wait for tick interval
        usleep(TICK_INTERVAL * 1000);
    }

    return 0;
}

// Initialize maze
void initializeMaze() {
    // Define maze walls and pellets
    char mazeString[] =
        "+-----------------+\n"
        "|. . . . . . . . .|\n"
        "|+-.--+-+ +-+-+ .-+\n"
        "| .....| | | | |..|\n"
        "|+-+| .--.-.-. |.+|\n"
        "|..|+-+ . | . +-+ |\n"
        "|. | ....| |.| .  |\n"
        "|. +-+. .-+-+ +-+.|\n"
        "|. .|.| | . . .|. |\n"
        "|--+-+. .+-+-+|+>+|\n"
        "|  .|. | |    |+-+|\n"
        "|-+.|++-+-+-+. . .|\n"
        "|.. | . . . .|-+.|\n"
        "|.+++-+. . |-+--.|\n"
        "|.....|.| | .....|\n"
        "|+--+.+-+ +.-+--+.|\n"
        "|...|. . . . .|...|\n"
        "|+--|+-+ +-+ +-+. |\n"
        "|.. | .........|..|\n"
        "| . | +-+-+ +-+ |.|\n"
        "|. .|.|.....|.|.. |\n"
        "+-----------------+";

    // Copy mazeString into maze array
    char *p = mazeString;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = *p++;
        }
    }

    // Count number of pellets
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == '.') {
                pelletsLeft++;
            }
        }
    }
}

// Initialize Pac-Man
void initializePacMan(PacMan *pacman) {
    pacman->row = 10;
    pacman->col = 10;
    pacman->direction = 0;
}

// Initialize ghosts
void initializeGhosts(Ghost *ghosts) {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].row = 10;
        ghosts[i].col = 11 + i;
        ghosts[i].direction = rand() % 4; // Random direction
    }
}

// Print maze
void printMaze(PacMan pacman, Ghost ghosts[]) {
    system("clear"); // Clear console

    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Print Pac-Man
            if (i == pacman.row && j == pacman.col) {
                switch (pacman.direction) {
                    case 0:
                        printf("v");
                        break;
                    case 1: 
                        printf("<");
                        break;
                    case 2:
                        printf("^");
                        break;
                    case 3:
                        printf(">");
                        break;
                }
            }
            // Print ghosts
            else {
                bool isGhost = false;
                for (int k = 0; k < MAX_GHOSTS; k++) {
                    if (i == ghosts[k].row && j == ghosts[k].col) {
                        printf("G");
                        isGhost = true;
                    }
                }
                // Print maze cell
                if (!isGhost) {
                    printf("%c", maze[i][j]);
                }
            }
        }
        printf("\n");
    }
}

// Move Pac-Man
void movePacMan(char input, PacMan *pacman) {
    int row = pacman->row;
    int col = pacman->col;
    int direction = pacman->direction;

    switch (input) {
        case 'w':
        case 'W':
            row--;
            direction = 0;
            break;
        case 'd':
        case 'D': 
            col++;
            direction = 1;
            break;
        case 's':
        case 'S':
            row++;
            direction = 2;
            break;
        case 'a':
        case 'A':
            col--;
            direction = 3;
            break;
    }

    // Check if move is valid
    if (maze[row][col] != '+' && maze[row][col] != '-') {
        pacman->row = row;
        pacman->col = col;
        pacman->direction = direction;
    }
}

// Move ghost
void moveGhost(Ghost *ghost, PacMan pacman) {
    int row = ghost->row;
    int col = ghost->col;
    int direction = ghost->direction;

    // Choose one of two strategies, depending on Pac-Man's distance
    int rowDiff = pacman.row - row;
    int colDiff = pacman.col - col;
    if (abs(rowDiff) > abs(colDiff)) {
        // Move vertically
        if (rowDiff > 0) {
            row++;
            direction = 2;
        }
        else if (rowDiff < 0) {
            row--;
            direction = 0;
        }
    }
    else {
        // Move horizontally
        if (colDiff > 0) {
            col++;
            direction = 1;
        }
        else if (colDiff < 0) {
            col--;
            direction = 3;
        }
    }

    // Check if move is valid
    if (maze[row][col] != '+' && maze[row][col] != '-') {
        ghost->row = row;
        ghost->col = col;
        ghost->direction = direction;
    }
    else {
        // If move is not valid, choose a random direction
        ghost->direction = rand() % 4;
    }
}

// Check for collisions
void checkCollisions(PacMan pacman, Ghost ghosts[]) {
    // Check Pac-Man collisions
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (pacman.row == ghosts[i].row && pacman.col == ghosts[i].col) {
            gameOver = true;
            printf("Game over!\n");
            return;
        }
    }

    // Check pellet collisions
    if (maze[pacman.row][pacman.col] == '.') {
        maze[pacman.row][pacman.col] = ' '; // Remove pellet
        updateScore(10); // Increment score
    }
}

// Display game over message
void gameOverMessage() {
    printf("Game over!\n");
    displayScore();
    gameOver = true;
}

// Update score
void updateScore(int value) {
    score += value;
}

// Display score
void displayScore() {
    printf("Score: %d\n", score);
}