//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include <termios.h>

#define NUM_ROWS 6
#define NUM_COLS 10
#define INVADER_SYMBOL "\u25CF"
#define PLAYER_SYMBOL "\u25A0"
#define BULLET_SYMBOL "\u25B2"

int score = 0; // Global variable to keep score

// Define structure to hold the player's position
struct Position {
    int row;
    int col;
};

// Define structure to hold the invader's position
struct Invader {
    int row;
    int col;
    int alive;
};

// Define arrays to hold player and invader positions
struct Position player;
struct Invader invaders[NUM_ROWS][NUM_COLS];

// Define function to print the game board
void printBoard() {
    system("clear"); // Clear the console

    // Print the top border
    for(int i = 0; i < NUM_COLS + 2; i++) {
        printf("\u2500");
    }
    printf("\n");

    // Print each row of the game board
    for(int i = 0; i < NUM_ROWS; i++) {
        printf("\u2502 "); // Print left border

        for(int j = 0; j < NUM_COLS; j++) {
            if(player.row == i && player.col == j) { // Print player symbol at player position
                printf("%s ", PLAYER_SYMBOL);
            } else if(invaders[i][j].row == i && invaders[i][j].col == j && invaders[i][j].alive) { // Print invader symbol at invader position if invader is alive
                printf("%s ", INVADER_SYMBOL); 
            } else {
                printf("  "); // Print empty space
            }
        }

        printf("\u2502\n"); // Print right border
    }

    // Print the bottom border
    for(int i = 0; i < NUM_COLS + 2; i++) {
        printf("\u2500");
    }
    printf("\n");

    printf("Score: %d\n", score);
}

// Define function to handle user input
void getInput() {
    struct termios oldt, newt; // Declare termios structs for handling input mode changes
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt; // Set new terminal settings to current settings
    newt.c_lflag &= ~(ICANON | ECHO); // Set new terminal settings to raw mode
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new terminal settings

    char c = getchar(); // Get character from user input

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Reapply old terminal settings
    
    switch(c) { // Move player position according to user input
        case 'a':
            if(player.col > 0) {
                player.col--;
            }
            break;
        case 'd':
            if(player.col < NUM_COLS - 1) {
                player.col++;
            }
            break;
        case ' ': // Create a bullet at player's position when space bar is pressed
            for(int i = NUM_ROWS - 1; i >= 0; i--) { // Search for the lowest available space in the column and create a bullet there
                if(!invaders[i][player.col].alive) {
                    invaders[i][player.col].alive = 1;
                    invaders[i][player.col].row = i;
                    invaders[i][player.col].col = player.col;
                    break;
                }
            }
            break;
        default:
            break;
    }
}

// Define function to move invaders down by one row
void moveInvadersDown() {
    for(int i = NUM_ROWS - 1; i >= 0; i--) { // Traverse through rows bottom up
        for(int j = 0; j < NUM_COLS; j++) { // Traverse through columns left to right
            if(invaders[i][j].alive) { // Move the invader down if it's alive
                invaders[i][j].row++;
            }
        }
    }
}

// Define function to move invaders side to side
void moveInvaders() {
    static int moveDirection = 1; // Static variable to keep track of current direction of movement

    for(int i = 0; i < NUM_ROWS; i++) { // Traverse through rows left to right
        if(moveDirection == 1) { // Move invaders right
            for(int j = NUM_COLS - 1; j >= 0; j--) { // Traverse through columns right to left
                if(invaders[i][j].alive) { // Move the invader right if it's alive
                    if(j == NUM_COLS - 1) { // If the invader is on the right edge of the screen, move it down instead
                        moveDirection = -1;
                        moveInvadersDown();
                    } else {
                        invaders[i][j+1] = invaders[i][j];
                        invaders[i][j].alive = 0;
                    }
                }
            }
        } else { // Move invaders left
            for(int j = 0; j < NUM_COLS; j++) { // Traverse through columns left to right
                if(invaders[i][j].alive) { // Move the invader left if it's alive
                    if(j == 0) { // If the invader is on the left edge of the screen, move it down instead
                        moveDirection = 1;
                        moveInvadersDown();
                    } else {
                        invaders[i][j-1] = invaders[i][j];
                        invaders[i][j].alive = 0;
                    }
                }
            }
        }
    }
}

// Define function to move bullets up and check for collisions
void moveBullets() {
    for(int i = 0; i < NUM_ROWS; i++) { // Traverse through rows top to bottom
        for(int j = 0; j < NUM_COLS; j++) { // Traverse through columns left to right
            if(invaders[i][j].alive && i < NUM_ROWS - 1) { // Move invader bullets up if the invader is alive and the bullet isn't at the top of the screen
                invaders[i+1][j] = invaders[i][j];
                invaders[i][j].alive = 0;
            } else if(i == 0 && invaders[i][j].alive && invaders[i][j].col == player.col) { // If a bullet hits the player, end the game
                printf("Game Over!\nFinal Score: %d\n", score);
                exit(0);
            } else if(i > 0 && invaders[i][j].alive && invaders[i-1][j].alive && invaders[i][j].col == player.col) { // If a bullet hits a bullet, destroy both bullets
                invaders[i][j].alive = 0;
                invaders[i-1][j].alive = 0;
            }
        }
    }
}

// Define function to handle game loop and timers
void loop(int signum) {
    printBoard();
    getInput();
    moveInvaders();
    moveBullets();
    score++;
    alarm(1); // Set timer for 1 second
}

int main() {
    // Initialize player position
    player.row = NUM_ROWS - 1;
    player.col = NUM_COLS / 2;

    // Initialize invader positions and states
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLS; j++) {
            invaders[i][j].alive = 1;
            invaders[i][j].row = i;
            invaders[i][j].col = j;
        }
    }

    signal(SIGALRM, loop); // Set signal handler for alarm timer
    alarm(1); // Set timer for 1 second

    while(1); // Run game loop indefinitely
}