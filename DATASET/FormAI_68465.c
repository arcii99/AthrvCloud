//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board dimensions
#define ROWS 20
#define COLS 40

char board[ROWS][COLS];  // Initialize the board array
int score = 0;  // Initialize the player score

// Define structure for ghosts
typedef struct {
    int row;
    int col;
} Ghost;

// Define structure for player
typedef struct {
    int row;
    int col;
} Player;

Player player;  // Declare player instance
Ghost ghosts[4];  // Declare array of four ghosts

// Initialize the board with walls, pellets, and player
void initBoard() {
    int i, j;

    // Fill board with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Add pellets to board
    for (i = 2; i < ROWS-2; i++) {
        for (j = 2; j < COLS-2; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                board[i][j] = '.';
            }
        }
    }

    // Add player to board
    player.row = ROWS/2;
    player.col = COLS/2;
    board[player.row][player.col] = 'P';
}

// Print the board
void printBoard() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);  // Display player score
}

// Set the ghost positions randomly
void setGhosts() {
    int i;

    srand(time(NULL));  // Seed the random number generator

    for (i = 0; i < 4; i++) {
        ghosts[i].row = rand() % ROWS;
        ghosts[i].col = rand() % COLS;
        board[ghosts[i].row][ghosts[i].col] = 'G';  // Add ghosts to board
    }
}

// Move the player
void movePlayer(char direction) {
    int newRow = player.row, newCol = player.col;

    switch (direction) {
        case 'w':
            newRow--;
            break;
        case 'a':
            newCol--;
            break;
        case 's':
            newRow++;
            break;
        case 'd':
            newCol++;
            break;
    }

    if (board[newRow][newCol] != '#') {  // Check if new position is a wall
        if (board[newRow][newCol] == '.') {  // Check if pellet is eaten
            score++;
        }
        board[player.row][player.col] ='.';  // Set previous position to pellet
        player.row = newRow;  // Update player position
        player.col = newCol;
        board[player.row][player.col] = 'P';  // Set new position to player
    }
}

// Move the ghosts
void moveGhosts() {
    int i;

    for (i = 0; i < 4; i++) {
        int newRow = ghosts[i].row, newCol = ghosts[i].col;

        int direction = rand() % 4;  // Randomly select direction to move

        switch (direction) {
            case 0:
                newRow--;
                break;
            case 1:
                newCol--;
                break;
            case 2:
                newRow++;
                break;
            case 3:
                newCol++;
                break;
        }

        if (board[newRow][newCol] != '#') {  // Check if new position is a wall
            board[ghosts[i].row][ghosts[i].col] = '.';  // Set previous position to pellet
            ghosts[i].row = newRow;  // Update ghost position
            ghosts[i].col = newCol;
            board[ghosts[i].row][ghosts[i].col] = 'G';  // Set new position to ghost
        }
    }
}

int main() {
    int running = 1;
    char input;

    initBoard();  // Initialize the board
    setGhosts();  // Initialize the ghosts

    while (running) {
        system("clear");  // Clear the console
        printBoard();  // Print the board
        printf("Enter movement (w/a/s/d): ");
        scanf("%c", &input);
        movePlayer(input);  // Move the player
        moveGhosts();  // Move the ghosts
    }

    return 0;
}