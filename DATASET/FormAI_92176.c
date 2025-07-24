//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

// Define game constants
#define SCREEN_HEIGHT 20
#define SCREEN_WIDTH 40
#define SHIP_SPEED 2
#define BULLET_SPEED 2
#define BULLET_COOLDOWN 5

// Initialize variables
int score = 0;
int shipX = SCREEN_WIDTH / 2;
int bulletX = 0;
int bulletY = 0;
int bulletCooldown = 0;
char screenBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

// Function declarations
void updateScreen();
void moveShipLeft();
void moveShipRight();
void shootBullet();
void moveBullet();

int main() {
    // Set up terminal
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &term);
    fcntl(0, F_SETFL, O_NONBLOCK);

    // Set up initial screen buffer
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screenBuffer[i][j] = ' ';
        }
    }
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        screenBuffer[0][i] = '-';
    }
    for (int i = 1; i < SCREEN_HEIGHT; i++) {
        screenBuffer[i][0] = '|';
        screenBuffer[i][SCREEN_WIDTH - 1] = '|';
    }
    screenBuffer[0][0] = '+';
    screenBuffer[0][SCREEN_WIDTH - 1] = '+';
    for (int i = 0; i < 10; i++) {
        screenBuffer[2][5 + i] = 'O';
    }

    // Main game loop
    while (1) {
        // Update screen
        updateScreen();

        // Check for input
        char input = getchar();
        if (input == 'q') {
            break;
        } else if (input == 'a') {
            moveShipLeft();
        } else if (input == 'd') {
            moveShipRight();
        } else if (input == ' ') {
            shootBullet();
        }

        // Move bullet
        if (bulletCooldown == 0) {
            moveBullet();
        } else {
            bulletCooldown--;
        }

        // Pause to reduce CPU usage
        usleep(20000);
    }

    // Reset terminal
    term.c_lflag |= ECHO | ICANON;
    tcsetattr(0, TCSANOW, &term);

    // Exit cleanly
    printf("\nFinal score: %d\n", score);
    return 0;
}

void updateScreen() {
    // Clear screen
    printf("\033[2J");

    // Print score
    printf("Score: %d\n", score);

    // Print screen buffer
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", screenBuffer[i][j]);
        }
        printf("\n");
    }
}

void moveShipLeft() {
    if (shipX > 1) {
        screenBuffer[2][shipX + 8] = ' ';
        shipX -= SHIP_SPEED;
        for (int i = 0; i < 10; i++) {
            screenBuffer[2][shipX + i] = 'O';
        }
    }
}

void moveShipRight() {
    if (shipX < SCREEN_WIDTH - 12) {
        screenBuffer[2][shipX + 1] = ' ';
        shipX += SHIP_SPEED;
        for (int i = 0; i < 10; i++) {
            screenBuffer[2][shipX + i] = 'O';
        }
    }
}

void shootBullet() {
    if (bulletCooldown == 0) {
        bulletX = shipX + 4;
        bulletY = 1;
        screenBuffer[bulletY][bulletX] = '*';
        bulletCooldown = BULLET_COOLDOWN;
    }
}

void moveBullet() {
    if (bulletY > 0) {
        screenBuffer[bulletY][bulletX] = ' ';
        bulletY -= BULLET_SPEED;
        if (bulletY > 0) {
            screenBuffer[bulletY][bulletX] = '*';
        }
        if (bulletY == 2) {
            for (int i = 0; i < 10; i++) {
                if (bulletX >= shipX + i && bulletX <= shipX + i + 1) {
                    score++;
                    printf("\a"); // Beep to signal score increase
                    bulletY = 0;
                    break;
                }
            }
        }
    } else if (bulletY == 0) {
        screenBuffer[bulletY][bulletX] = ' ';
        bulletCooldown = 0;
    }
}