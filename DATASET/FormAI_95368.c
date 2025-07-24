//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 50
#define HEIGHT 30

// Alien structure
typedef struct {
    int x;
    int y;
    int active;
} Alien;

Alien aliens[3][10]; // 3 rows of 10 aliens
int score = 0; // Game score
int lives = 3; // Player lives
int playerX = WIDTH/2; // Player starting position
int playerY = HEIGHT-3;
int missileX = -1; // Missile coordinates
int missileY = -1;
int missileActive = 0; // Is missile active
int direction = 1; // Alien direction
int movingDown = 0;

int kbhit(void) // Function to check if a key is pressed
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void clearScreen() // Function to clear the screen
{
    printf("\033[2J");
}

void cursorPosition(int x, int y) // Function to move the cursor to a specific position
{
    printf("\033[%d;%dH", y, x);
}

void updateScore() // Function to update the score on the screen
{
    cursorPosition(1, 1);
    printf("Score: %d", score);
}

void updateLives() // Function to update the lives on the screen
{
    cursorPosition(WIDTH-10, 1);
    printf("Lives: %d", lives);
}

void drawBorder() // Function to draw the border of the game
{
    int i, j;

    for (i = 0; i < WIDTH+2; i++) {
        cursorPosition(i, 0);
        printf("#");
        cursorPosition(i, HEIGHT+1);
        printf("#");
    }

    for (j = 0; j < HEIGHT+2; j++) {
        cursorPosition(0, j);
        printf("#");
        cursorPosition(WIDTH+1, j);
        printf("#");
    }
}

void drawPlayer() // Function to draw the player
{
    cursorPosition(playerX, playerY);
    printf("|");
    cursorPosition(playerX, playerY-1);
    printf("|");
    cursorPosition(playerX-1, playerY);
    printf("\\");
    cursorPosition(playerX+1, playerY);
    printf("/");
}

void erasePlayer() // Function to erase the player
{
    cursorPosition(playerX, playerY);
    printf(" ");
    cursorPosition(playerX, playerY-1);
    printf(" ");
    cursorPosition(playerX-1, playerY);
    printf(" ");
    cursorPosition(playerX+1, playerY);
    printf(" ");
}

void drawMissile() // Function to draw the missile
{
    cursorPosition(missileX, missileY);
    printf("|");
}

void eraseMissile() // Function to erase the missile
{
    cursorPosition(missileX, missileY);
    printf(" ");
}

void drawAliens() // Function to draw the aliens
{
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            if (aliens[i][j].active) {
                cursorPosition(aliens[i][j].x, aliens[i][j].y);
                printf("o");
            }
        }
    }
}

void eraseAliens() // Function to erase the aliens
{
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            if (aliens[i][j].active) {
                cursorPosition(aliens[i][j].x, aliens[i][j].y);
                printf(" ");
            }
        }
    }
}

void updateAliens() // Function to update the aliens
{
    int i, j;
    int minX = WIDTH;
    int maxX = 0;
    int activeAliens = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            if (aliens[i][j].active) {
                activeAliens++;

                if (movingDown) {
                    aliens[i][j].y++;
                } else {
                    aliens[i][j].x += direction;
                }

                if (aliens[i][j].x < minX) {
                    minX = aliens[i][j].x;
                }

                if (aliens[i][j].x > maxX) {
                    maxX = aliens[i][j].x;
                }

                if (aliens[i][j].y == playerY) { // Alien has reached the player
                    lives--;
                    updateLives();

                    if (lives == 0) { // Game over
                        clearScreen();
                        cursorPosition(WIDTH/2-5, HEIGHT/2);
                        printf("GAME OVER!");
                        cursorPosition(WIDTH/2-10, HEIGHT/2+1);
                        printf("Final score: %d", score);
                        exit(0);
                    }

                    // Reset missile and player position
                    missileActive = 0;
                    missileX = -1;
                    missileY = -1;
                    eraseMissile();
                    erasePlayer();
                    playerX = WIDTH/2;
                    playerY = HEIGHT-3;
                    drawPlayer();
                }
            }
        }
    }

    if (minX == 1 || maxX == WIDTH) { // Aliens have reached the edge of the screen, change direction
        direction *= -1;
        movingDown = 1;
    }

    if (movingDown) { // Aliens are moving down, check if they've reached the bottom
        movingDown = 0;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 10; j++) {
                if (aliens[i][j].active && aliens[i][j].y == HEIGHT-2) { // Alien has reached the bottom
                    clearScreen();
                    cursorPosition(WIDTH/2-5, HEIGHT/2);
                    printf("GAME OVER!");
                    cursorPosition(WIDTH/2-10, HEIGHT/2+1);
                    printf("Final score: %d", score);
                    exit(0);
                }
            }
        }
    }

    if (activeAliens == 0) { // Player has won
        clearScreen();
        cursorPosition(WIDTH/2-5, HEIGHT/2);
        printf("YOU WIN!");
        cursorPosition(WIDTH/2-10, HEIGHT/2+1);
        printf("Final score: %d", score);
        exit(0);
    }

    drawAliens();
}

void fire() // Function to fire the missile
{
    if (missileActive) {
        return;
    }

    missileX = playerX;
    missileY = playerY - 1;
    missileActive = 1;
    drawMissile();
}

int main() // Main function
{
    srand(time(NULL));

    // Set up the aliens
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            aliens[i][j].x = 4+j*4;
            aliens[i][j].y = 2+i*2;
            aliens[i][j].active = 1;
        }
    }

    // Draw the game
    clearScreen();
    drawBorder();
    drawPlayer();
    drawAliens();
    updateScore();
    updateLives();

    // Loop while player has lives
    while (lives > 0) {
        usleep(100000);

        if (kbhit()) { // Handle keyboard input
            char c = getchar();

            if (c == 'a' && playerX > 2) { // Move player left
                erasePlayer();
                playerX--;
                drawPlayer();
            } else if (c == 'd' && playerX < WIDTH-2) { // Move player right
                erasePlayer();
                playerX++;
                drawPlayer();
            } else if (c == ' ' && !missileActive) { // Fire missile
                fire();
            }
        }

        if (missileActive) { // Update missile position
            eraseMissile();
            missileY--;

            if (missileY < 1) { // Missile has gone off the screen
                missileActive = 0;
                missileX = -1;
                missileY = -1;
            } else {
                drawMissile();
            }
        }

        updateAliens();
    }

    return 0; // Game over
}