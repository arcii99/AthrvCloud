//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Defining constants for the game board dimensions
#define ROWS 20
#define COLS 30

// Defining constants for the symbols representing the game objects
#define BLANK ' '
#define WALL '#'
#define PACMAN 'C'
#define DOT '\u2022'
#define POWER_PELLET '\u25C9'
#define GHOST 'G'

// Defining constants for the game object values
#define PACMAN_VALUE 1
#define DOT_VALUE 2
#define POWER_PELLET_VALUE 3
#define GHOST_VALUE 4

// Defining constants for the game's control keys
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define QUIT 'q'

// Defining the game object structure
typedef struct object {
    char symbol;
    int value;
    bool active;
    int x;
    int y;
} Object;

// Function for initializing a game object
void initObject(Object *obj, char symbol, int value, bool active, int x, int y) {
    obj->symbol = symbol;
    obj->value = value;
    obj->active = active;
    obj->x = x;
    obj->y = y;
}

// Function for updating the position of a game object
void updateObject(Object *obj, int x, int y) {
    obj->x = x;
    obj->y = y;
}

// Function for drawing the game board
void drawBoard(Object board[ROWS][COLS]) {
    system("clear"); // Clearing the console screen

    printf("PAC-MAN CLONE GAME\n\n");

    // Drawing the game board row by row
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j].symbol);
        }
        printf("\n");
    }
    printf("\n");
}

// Function for checking if a given position is within the game board's bounds
bool isValidMove(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Function for checking if a given game object can move to a target position
bool canMove(Object board[ROWS][COLS], Object *obj, int x, int y) {
    if (!isValidMove(x, y)) {
        return false; // Target position is out of the game board's bounds
    }
    if (board[x][y].symbol == WALL) {
        return false; // Target position contains a wall
    }
    if (obj->symbol == GHOST && board[x][y].symbol == GHOST) {
        return false; // Two ghosts cannot occupy the same position
    }
    return true;
}

// Function for moving a game object to a target position
void moveObject(Object board[ROWS][COLS], Object *obj, int x, int y) {
    if (canMove(board, obj, x, y)) {
        board[obj->x][obj->y].symbol = BLANK;
        updateObject(obj, x, y);
        board[obj->x][obj->y] = *obj;
    }
}

// Function for updating the game state after a move has been made
void updateGameState(Object board[ROWS][COLS], Object *pacman, Object ghosts[], int numGhosts, int *remainingDots, int *remainingPellets, int *score) {
    // Updating the position of the ghosts randomly
    for (int i = 0; i < numGhosts; i++) {
        int x = ghosts[i].x;
        int y = ghosts[i].y;
        int r = rand() % 4; // Generating a random number between 0 and 3

        switch (r) {
            case 0: // Moving up
                x -= 1;
                break;
            case 1: // Moving down
                x += 1;
                break;
            case 2: // Moving left
                y -= 1;
                break;
            case 3: // Moving right
                y += 1;
                break;
            default:
                break;
        }

        moveObject(board, &ghosts[i], x, y);
    }

    // Checking if Pac-Man collides with a ghost
    for (int i = 0; i < numGhosts; i++) {
        if (pacman->x == ghosts[i].x && pacman->y == ghosts[i].y && ghosts[i].active) { // Checking only active ghosts
            if (*score == 0) {
                printf("\n\nGAME OVER\n\n");
                exit(0); // End the game
            }
            else {
                *score -= 10; // Decrease score
                ghosts[i].active = false; // Deactivate ghost
            }
            break; // Only one ghost at a time can collide with Pac-Man
        }
    }

    // Updating the score and number of remaining dots/pellets
    switch (board[pacman->x][pacman->y].value) {
        case DOT_VALUE:
            *score += 10;
            *remainingDots -= 1;
            break;
        case POWER_PELLET_VALUE:
            *score += 50;
            *remainingPellets -= 1;
            // Activating all ghosts
            for (int i = 0; i < numGhosts; i++) {
                ghosts[i].active = true;
            }
            break;
        default:
            break;
    }

    board[pacman->x][pacman->y].value = PACMAN_VALUE;
}

int main() {
    // Initializing the random number generator with a seed value
    srand(time(NULL));

    // Initializing the game objects
    Object board[ROWS][COLS];
    Object pacman;
    Object ghosts[4];
    int remainingDots = 0;
    int remainingPellets = 0;
    int score = 0;

    // Reading the game board from a file
    FILE *f = fopen("board.txt", "r");
    if (f == NULL) {
        printf("Error: Cannot open board.txt\n");
        return 1;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char c = fgetc(f);
            switch (c) {
                case BLANK:
                case WALL:
                    initObject(&board[i][j], c, 0, true, i, j);
                    break;
                case PACMAN:
                    initObject(&pacman, c, PACMAN_VALUE, true, i, j);
                    initObject(&board[i][j], c, PACMAN_VALUE, true, i, j);
                    break;
                case DOT:
                    initObject(&board[i][j], c, DOT_VALUE, true, i, j);
                    remainingDots += 1;
                    break;
                case POWER_PELLET:
                    initObject(&board[i][j], c, POWER_PELLET_VALUE, true, i, j);
                    remainingPellets += 1;
                    break;
                case GHOST:
                    initObject(&ghosts[j], c, GHOST_VALUE, true, i, j);
                    initObject(&board[i][j], c, GHOST_VALUE, true, i, j);
                    break;
                default:
                    break;
            }
        }
        fgetc(f); // Reading the newline character at the end of the row
    }
    fclose(f);

    // Running the game loop
    char input;
    bool running = true;
    while (running) {
        drawBoard(board);
        printf("SCORE: %d\n", score);
        printf("DOTS: %d     ", remainingDots);
        printf("POWER PELLETS: %d\n", remainingPellets);
        printf("Use WASD to move, Q to quit\n");

        input = tolower(getchar());
        while (getchar() != '\n'); // Clearing the input buffer

        switch (input) {
            case UP:
                moveObject(board, &pacman, pacman.x - 1, pacman.y);
                break;
            case DOWN:
                moveObject(board, &pacman, pacman.x + 1, pacman.y);
                break;
            case LEFT:
                moveObject(board, &pacman, pacman.x, pacman.y - 1);
                break;
            case RIGHT:
                moveObject(board, &pacman, pacman.x, pacman.y + 1);
                break;
            case QUIT:
                running = false;
                break;
            default:
                break;
        }

        updateGameState(board, &pacman, ghosts, 4, &remainingDots, &remainingPellets, &score);

        if (remainingDots == 0 && remainingPellets == 0) {
            printf("\n\nYOU WIN!\n\n");
            running = false; // End the game
        }
    }

    return 0;
}