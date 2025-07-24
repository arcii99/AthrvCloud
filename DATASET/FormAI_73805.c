//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Linus Torvalds
// This is a Pac-Man clone created by [Your Name] in the style of Linus Torvalds

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants for the game board size
#define BOARD_WIDTH 28
#define BOARD_HEIGHT 31

// Define constants for the game objects
#define EMPTY_SPACE ' '
#define WALL '#'
#define DOT '.'
#define POWER_PELLET 'o'
#define PACMAN 'C'
#define GHOST 'G'

// Define the game board array
char board[BOARD_HEIGHT][BOARD_WIDTH];

// Define the Pac-Man object
struct PacMan {
    int x, y;
    int direction;
    bool poweredUp;
};

// Define the Ghost object
struct Ghost {
    int x, y;
    int direction;
};

// Define the global variables
int score;
bool gameOver;
struct PacMan pacMan;
struct Ghost ghosts[4];

// Define the function prototypes
void initBoard();
void displayBoard();
void spawnPacMan();
void spawnGhosts();
void movePacMan();
void moveGhost(int ghostIndex);
bool isMoveValid(int x, int y);
bool checkCollision(int x, int y);
void handleCollision(int x, int y);
void endGame();
void clearScreen();

// Define the main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Initialize the game board
    initBoard();

    // Spawn the Pac-Man and the ghosts
    spawnPacMan();
    spawnGhosts();
    
    // Initialize the game status variables
    score = 0;
    gameOver = false;

    // Display the initial game board
    displayBoard();

    // Enter the game loop
    while (!gameOver) {
        // Move the Pac-Man and the ghosts
        movePacMan();
        for (int i = 0; i < 4; i++) {
            moveGhost(i);
        }

        // Display the updated game board
        displayBoard();

        // Check if the game should end
        if (score == 244) {
            endGame();
        }
    }

    // End the game and exit
    endGame();
    return 0;
}

// Initialize the game board with the wall and dot objects
void initBoard() {
    // Define the wall and dot pattern for the game board
    char boardPattern[BOARD_HEIGHT][BOARD_WIDTH] = {
        "#############################",
        "#............##............#",
        "#.####.#####.##.#####.####.#",
        "#.####.#####.##.#####.####.#",
        "#.####.#####.##.#####.####.#",
        "#...........................#",
        "#.####.#.##########.#.####.#",
        "#.####.#.##########.#.####.#",
        "#......#.##......##.#......#",
        "######.#.## #### ##.#.######",
        "     #.#.   ####   .#.     ",
        "     #.#.##      ##.#.     ",
        "######.#.#.######.#.#.######",
        "         .#.#GGGG.#.#.         ",
        "######.#.#.######.#.#.######",
        "     #.#.#........#.#.#     ",
        "     #.#.#.#.#  #.#.#.#     ",
        "######.#.#.#  #  #.#.#.######",
        "..........#.#GGGG.#..........",
        "######.#.#.#  #  #.#.#.######",
        "     #.#.#.#  .  #.#.#.#     ",
        "     #.#.#.#.####.#.#.#     ",
        "######.#.#.#      #.#.#.######",
        "#..........########..........#",
        "#.####.#.##########.#.####.#",
        "#.####.#.##########.#.####.#",
        "#...##.#....##..##....#.##...#",
        "###.##.#.#.##.##.##.#.#.##.###",
        "###.##.#.#.##.##.##.#.#.##.###",
        "#......#.##......##.#......#",
        "#.##########.#.#.##########.#",
        "#.##########.#.#.##########.#",
        "#...........................#",
        "#############################",
    };

    // Assign the wall and dot pattern to the game board
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            char c = boardPattern[y][x];
            if (c == WALL) {
                board[y][x] = WALL;
            } else if (c == DOT) {
                board[y][x] = DOT;
            } else {
                board[y][x] = EMPTY_SPACE;
            }
        }
    }
}

// Display the game board on the console
void displayBoard() {
    clearScreen();

    printf("Score: %d\n", score);

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }
}

// Spawn the Pac-Man object at a random location on the game board
void spawnPacMan() {
    while (true) {
        int x = rand() % BOARD_WIDTH;
        int y = rand() % BOARD_HEIGHT;
        if (board[y][x] == EMPTY_SPACE) {
            pacMan.x = x;
            pacMan.y = y;
            pacMan.direction = 0;
            pacMan.poweredUp = false;
            board[y][x] = PACMAN;
            break;
        }
    }
}

// Spawn the ghost objects at random locations on the game board
void spawnGhosts() {
    for (int i = 0; i < 4; i++) {
        while (true) {
            int x = rand() % BOARD_WIDTH;
            int y = rand() % BOARD_HEIGHT;
            if (board[y][x] == EMPTY_SPACE) {
                ghosts[i].x = x;
                ghosts[i].y = y;
                ghosts[i].direction = 0;
                board[y][x] = GHOST;
                break;
            }
        }
    }
}

// Move the Pac-Man object based on keyboard input
void movePacMan() {
    // Check for keyboard input
    char input = getchar();
    getchar();
    
    // Calculate the new position based on direction
    int newX = pacMan.x;
    int newY = pacMan.y;
    switch (input) {
        case 'w':
            pacMan.direction = 1;
            newY--;
            break;
        case 'a':
            pacMan.direction = 2;
            newX--;
            break;
        case 's':
            pacMan.direction = 3;
            newY++;
            break;
        case 'd':
            pacMan.direction = 4;
            newX++;
            break;
    }

    // Check if the move is valid
    if (isMoveValid(newX, newY)) {
        pacMan.x = newX;
        pacMan.y = newY;

        // Check for collision with a dot or power pellet
        if (board[newY][newX] == DOT) {
            score++;
            board[newY][newX] = EMPTY_SPACE;
        } else if (board[newY][newX] == POWER_PELLET) {
            score += 10;
            board[newY][newX] = EMPTY_SPACE;
            pacMan.poweredUp = true;
        }

        // Check for collision with a ghost
        if (checkCollision(pacMan.x, pacMan.y)) {
            handleCollision(pacMan.x, pacMan.y);
        }

        // Update the game board with the new position of the Pac-Man object
        board[pacMan.y][pacMan.x] = PACMAN;
        board[pacMan.y][pacMan.x - 1] = pacMan.poweredUp ? 'V' : EMPTY_SPACE;
        board[pacMan.y][pacMan.x + 1] = pacMan.poweredUp ? 'V' : EMPTY_SPACE;
    }
}

// Move a ghost object randomly
void moveGhost(int ghostIndex) {
    // Calculate the new position based on direction
    int newX = ghosts[ghostIndex].x;
    int newY = ghosts[ghostIndex].y;
    switch (ghosts[ghostIndex].direction) {
        case 1:
            newY--;
            break;
        case 2:
            newX--;
            break;
        case 3:
            newY++;
            break;
        case 4:
            newX++;
            break;
    }

    // Check if the move is valid
    if (isMoveValid(newX, newY)) {
        // Update the game board with the new position of the ghost object
        board[ghosts[ghostIndex].y][ghosts[ghostIndex].x] = EMPTY_SPACE;
        board[newY][newX] = GHOST;

        // Update the ghost object with the new position
        ghosts[ghostIndex].x = newX;
        ghosts[ghostIndex].y = newY;

        // Check for collision with the Pac-Man object
        if (checkCollision(pacMan.x, pacMan.y)) {
            handleCollision(pacMan.x, pacMan.y);
        }

        // Generate a random direction for the ghost object
        int randomDirection = rand() % 4 + 1;
        while (!isMoveValid(newX, newY)) {
            randomDirection = rand() % 4 + 1;
            switch (randomDirection) {
                case 1:
                    newY--;
                    break;
                case 2:
                    newX--;
                    break;
                case 3:
                    newY++;
                    break;
                case 4:
                    newX++;
                    break;
            }
        }

        // Update the ghost object with the new direction
        ghosts[ghostIndex].direction = randomDirection;
    }
}

// Check if a move is valid
bool isMoveValid(int x, int y) {
    if (board[y][x] == WALL) {
        return false;
    }
    return true;
}

// Check if there is a collision between the Pac-Man and Ghost objects
bool checkCollision(int x, int y) {
    if (board[y][x] == GHOST) {
        return true;
    }
    return false;
}

// Handle a collision between the Pac-Man and Ghost objects
void handleCollision(int x, int y) {
    // Check if the Pac-Man is powered up
    if (pacMan.poweredUp) {
        // Respawn the ghost object at a random location on the game board
        board[y][x] = EMPTY_SPACE;
        spawnGhosts();
    } else {
        // End the game
        endGame();
    }
}

// End the game and exit
void endGame() {
    gameOver = true;
    clearScreen();
    printf("Game over! Final score: %d \n", score);
}

// Clear the console
void clearScreen() {
    printf("\033[H\033[J");
}