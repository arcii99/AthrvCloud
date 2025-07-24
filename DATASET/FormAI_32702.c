//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: statistical
/* Statistical Pac-Man Game Clone */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 20
#define COL 30

/* Define the different characters used in the game */
#define PACMAN 'C'
#define WALL '+'
#define EMPTY ' '
#define DOT '.'
#define GHOST 'G'

/* Define the different colors used in the game */
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

/* Define the game board, and global variables for Pac-Man's location, the score, and the number of dots collected */
char board[ROW][COL];
int pacmanX, pacmanY, score, dots;

/* Function prototypes */
void initializeBoard();
void printBoard();
void spawnPacMan();
void spawnGhosts();
void movePacMan(char);
void moveGhosts();

/* Main function */
int main() {

    // Seed the random number generator for spawning ghosts
    srand(time(NULL));

    // Initialize the board, spawn Pac-Man and the ghosts, and print the board
    initializeBoard();
    spawnPacMan();
    spawnGhosts();
    printBoard();

    // Game loop
    char direction;
    while (true) {
        // Get user input for Pac-Man's direction
        printf("Score: %d\n", score);
        printf("Enter a direction (wasd): ");
        scanf(" %c", &direction);

        // Move Pac-Man and the ghosts accordingly
        movePacMan(direction);
        moveGhosts();

        // Print the updated board
        printBoard();

        // Check if Pac-Man has collected all the dots
        if (dots == 0) {
            printf("Congratulations! You collected all the dots and won the game!\n");
            break;
        }
    }

    return 0;
}

/* Function to initialize the game board */
void initializeBoard() {

    // Define the layout of the board
    char layout[ROW][COL] = {
      "+_______________________________+",
      "| .........................   ..|",
      "|._________________________. ...|",
      "|.......................... . ..|",
      "|._________________________. ...|",
      "| ................................|",
      "| .________.....___________.. ..|",
      "| ........................... ...|",
      "| ...............__.......... ...|",
      "|.___.._.................... ...|",
      "| ................................|",
      "| .____________________________.|",
      "|..................................|",
      "|._____________________________.|",
      "| ................................|",
      "|._____________________________.|",
      "| .........................       |",
      "|._________________________. ...|",
      "|.......................... . ..|",
      "+------------------------------+",
    };

    // Initialize the board using the layout
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = layout[i][j];

            // Count the number of dots on the board
            if (board[i][j] == DOT) {
                dots++;
            }
        }
    }
}

/* Function to print the game board */
void printBoard() {

    // Clear the console
    system("clear");

    // Print each character on the board with its corresponding color
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == PACMAN) {
                printf(YELLOW "%c" RESET, board[i][j]);
            } else if (board[i][j] == WALL) {
                printf(BLUE "%c" RESET, board[i][j]);
            } else if (board[i][j] == DOT) {
                printf(GREEN "%c" RESET, board[i][j]);
            } else if (board[i][j] == GHOST) {
                printf(MAGENTA "%c" RESET, board[i][j]);
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

/* Function to spawn Pac-Man on the board */
void spawnPacMan() {
    pacmanX = 1;
    pacmanY = 1;
    board[pacmanX][pacmanY] = PACMAN;
}

/* Function to spawn the ghosts on the board */
void spawnGhosts() {

    // Spawn four ghosts randomly on the board
    for (int k = 0; k < 4; k++) {
        int ghostX, ghostY;
        do {
            ghostX = rand() % ROW;
            ghostY = rand() % COL;
        } while (board[ghostX][ghostY] != EMPTY);
        board[ghostX][ghostY] = GHOST;
    }
}

/* Function to move Pac-Man */
void movePacMan(char direction) {

    // Calculate Pac-Man's new position based on the input direction
    int newX, newY;
    if (direction == 'w') {
        newX = pacmanX - 1;
        newY = pacmanY;
    } else if (direction == 's') {
        newX = pacmanX + 1;
        newY = pacmanY;
    } else if (direction == 'a') {
        newX = pacmanX;
        newY = pacmanY - 1;
    } else if (direction == 'd') {
        newX = pacmanX;
        newY = pacmanY + 1;
    }

    // Check if the new position is valid (not a wall or out of bounds)
    if (board[newX][newY] != WALL && newX >= 0 && newY >= 0 && newX < ROW && newY < COL) {

        // If the new position is a dot, collect it and add to the score
        if (board[newX][newY] == DOT) {
            dots--;
            score++;
        }

        // Update Pac-Man's position on the board
        board[pacmanX][pacmanY] = EMPTY;
        pacmanX = newX;
        pacmanY = newY;
        board[pacmanX][pacmanY] = PACMAN;
    }
}

/* Function to move the ghosts */
void moveGhosts() {

    // Move each ghost randomly
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == GHOST) {

                // Determine a random direction for the ghost to move in
                int direction = rand() % 4;
                int ghostX, ghostY;
                if (direction == 0) {
                    ghostX = i - 1;
                    ghostY = j;
                } else if (direction == 1) {
                    ghostX = i + 1;
                    ghostY = j;
                } else if (direction == 2) {
                    ghostX = i;
                    ghostY = j - 1;
                } else {
                    ghostX = i;
                    ghostY = j + 1;
                }

                // Check if the new position is valid (not a wall or out of bounds)
                if (board[ghostX][ghostY] != WALL && ghostX >= 0 && ghostY >= 0 && ghostX < ROW && ghostY < COL) {

                    // Update the ghost's position on the board
                    board[i][j] = EMPTY;
                    board[ghostX][ghostY] = GHOST;
                }
            }
        }
    }
}