//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define ROW 9
#define COLUMN 77
#define ALIEN_ROWS 3
#define ALIEN_COLUMNS 8

int rows[ALIEN_ROWS] = { 2, 4, 6 };
int columns[ALIEN_COLUMNS] = { 1, 10, 19, 28, 37, 46, 55, 64 };
int shipPosition = 39;
int lives = 3;
int score = 0;

char space[ROW][COLUMN];
char ship = '<';
char alien = 'o';
char bullet = '|';

// Function to change terminal settings
void initTermios() {
    struct termios old, new;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

// Function to change terminal settings back to default
void resetTermios(void) {
    struct termios old;
    tcgetattr(0, &old);
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    tcsetattr(0, TCSANOW, &old);
}

// Function to generate random number
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Function to move the ship left
void moveShipLeft() {
    if (shipPosition > 0) {
        space[ROW - 1][shipPosition] = ' ';
        space[ROW - 1][--shipPosition] = ship;
    }
}

// Function to move the ship right
void moveShipRight() {
    if (shipPosition < COLUMN - 1) {
        space[ROW - 1][shipPosition] = ' ';
        space[ROW - 1][++shipPosition] = ship;
    }
}

// Function to move the bullet up
void moveBullet() {
    int i, j, flag = 0;
    for (i = ROW - 2; i >= 0; i--) {
        for (j = 0; j < COLUMN; j++) {
            if (space[i][j] == bullet) {
                space[i][j] = ' ';
                if (i == 0) {
                    flag = 1;
                }
                else if (i == rows[0] || i == rows[1] || i == rows[2]) {
                    int k;
                    for (k = 0; k < ALIEN_COLUMNS; k++) {
                        if (j == columns[k]) {
                            score += 10;
                            space[i][j] = ' ';
                            rows[(rows[0] == i) ? 0 : (rows[1] == i) ? 1 : 2] -= 1;
                            columns[(columns[0] == j) ? 0 : (columns[1] == j) ? 1 : (columns[2] == j) ? 2 : (columns[3] == j) ? 3 : (columns[4] == j) ? 4 : (columns[5] == j) ? 5 : (columns[6] == j) ? 6 : 7] = -1;
                        }
                    }
                }
                else {
                    space[i - 1][j] = bullet;
                }
            }
        }
    }
    if (flag == 1) {
        space[0][shipPosition] = ship;
    }
}

// Function to move aliens
void moveAliens() {
    int i, j, flag = 0;
    for (i = 0; i < ALIEN_ROWS; i++) {
        for (j = 0; j < ALIEN_COLUMNS; j++) {
            if (columns[j] != -1) {
                space[rows[i]][columns[j]] = ' ';
                if (rows[i] == ROW - 2) {
                    flag = 1;
                    break;
                }
                rows[i]++;
                space[rows[i]][columns[j]] = alien;
            }
        }
    }
    if (flag == 1) {
        lives--;
        space[ROW - 1][shipPosition] = ship;
        int i, j;
        for (i = 0; i < ALIEN_ROWS; i++) {
            for (j = 0; j < ALIEN_COLUMNS; j++) {
                rows[i] = 2;
                columns[j] = (j * 9) + 1;
                space[rows[i]][columns[j]] = alien;
            }
        }
        sleep(1);
    }
}

// Function to fire bullet
void fireBullet() {
    int i, j;
    for (i = ROW - 2; i >= 0; i--) {
        if (space[i][shipPosition] == alien) {
            space[i][shipPosition] = ' ';
            rows[(rows[0] == i) ? 0 : (rows[1] == i) ? 1 : 2] -= 1;
            columns[(columns[0] == shipPosition) ? 0 : (columns[1] == shipPosition) ? 1 : (columns[2] == shipPosition) ? 2 : (columns[3] == shipPosition) ? 3 : (columns[4] == shipPosition) ? 4 : (columns[5] == shipPosition) ? 5 : (columns[6] == shipPosition) ? 6 : 7] = -1;
            score += 10;
            return;
        }
        else if (space[i][shipPosition] == ' ') {
            space[i][shipPosition] = bullet;
            return;
        }
    }
    space[ROW - 1][shipPosition] = ship;
}

// Function to draw the space
void drawSpace() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN - 1; j++) {
            if (i == ROW - 1) {
                space[i][j] = ' ';
            }
            else if (i == 0 || j == 0 || j == COLUMN - 2) {
                space[i][j] = '#';
            }
            else if (j == COLUMN - 3 && i == 1) {
                space[i][j] = '-';
            }
            else if (j == shipPosition && i == ROW - 1) {
                space[i][j] = ship;
            }
            else {
                space[i][j] = ' ';
            }
            int k;
            for (k = 0; k < ALIEN_ROWS; k++) {
                if (i == rows[k] && j == columns[0] || j == columns[1] || j == columns[2] || j == columns[3] || j == columns[4] || j == columns[5] || j == columns[6] || j == columns[7]) {
                    space[i][j] = alien;
                }
            }
        }
        space[0][shipPosition] = '-';
    }
}

// Function to print the space
void printSpace() {
    int i, j;
    system("clear");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            printf("%c", space[i][j]);
        }
        printf("\n");
    }
    printf("Lives: %d\nScore: %d\n", lives, score);
}

int main() {
    initTermios();
    drawSpace();
    printSpace();
    char key = '\0';
    while (lives > 0) {
        if (key != '\0') {
            if (key == 'a') {
                moveShipLeft();
                printSpace();
            }
            else if (key == 'd') {
                moveShipRight();
                printSpace();
            }
            else if (key == ' ') {
                fireBullet();
                printSpace();
            }
            key = '\0';
        }
        int x = getRandomNumber(1, 2000000);
        usleep(x);
        moveBullet();
        if (lives > 0) {
            moveAliens();
        }
        printSpace();
        if (rows[ALIEN_ROWS - 1] >= ROW - 2) {
            lives = 0;
        }
        if (score == 240) {
            printf("\nCongratulations! You have saved the Earth!\n");
            break;
        }
        if (lives == 0) {
            printf("\nGame Over! You scored %d points!\n", score);
            break;
        }
        if (lives == 1) {
            printf("Warning! Only one life remaining!\n");
        }
        key = getchar();
    }
    resetTermios();
    return 0;
}