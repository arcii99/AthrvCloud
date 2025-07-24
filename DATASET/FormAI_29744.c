//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Shape-shifting C Space Invaders game clone

// define screen size constants
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

// define player character constants
#define PLAYER_CHAR '+'
#define PLAYER_LEFT '<'
#define PLAYER_RIGHT '>'

// define enemy character constants
#define ENEMY_CHAR 'X'
#define ENEMY_SPEED 5
#define ENEMY_RESPAWN_TIME 1000000

// declare function to get user input from terminal
char getInput();

// declare function to move player character left
void movePlayerLeft(char *player);

// declare function to move player character right
void movePlayerRight(char *player);

// declare function to spawn enemy character
void spawnEnemy(char *enemy);

// declare function to move enemy character
void moveEnemy(char *enemy);

int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize variables
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    char player[3] = { PLAYER_LEFT, PLAYER_CHAR, PLAYER_RIGHT };
    char enemy[2] = { ENEMY_CHAR, ' ' };
    int enemyPos = -1;
    int enemyTimer = 0;
    int score = 0;

    // set up screen buffer with starting values
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == SCREEN_HEIGHT - 1) {
                screen[i][j] = '_';
            } else if (j == 0 || j == SCREEN_WIDTH - 1) {
                screen[i][j] = '|';
            } else {
                screen[i][j] = ' ';
            }
        }
    }

    while (1) {
        // clear screen
        system("clear");

        // print screen buffer to terminal
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < SCREEN_WIDTH; j++) {
                printf("%c", screen[i][j]);
            }
            printf("\n");
        }

        // get user input
        char input = getInput();

        // move player left or right depending on user input
        if (input == 'a' || input == 'A') {
            movePlayerLeft(player);
        } else if (input == 'd' || input == 'D') {
            movePlayerRight(player);
        }

        // spawn enemy if it is time
        enemyTimer++;
        if (enemyTimer > ENEMY_RESPAWN_TIME) {
            spawnEnemy(enemy);
            enemyTimer = 0;
        }

        // move enemy if it exists
        if (enemyPos != -1) {
            moveEnemy(enemy);
            // if enemy collides with player, end game
            if (screen[SCREEN_HEIGHT - 2][enemyPos] == PLAYER_LEFT || screen[SCREEN_HEIGHT - 2][enemyPos] == PLAYER_CHAR || screen[SCREEN_HEIGHT - 2][enemyPos] == PLAYER_RIGHT) {
                printf("You lost! Final score: %d\n", score);
                return 0;
            }
            // if enemy reaches bottom of screen, add to score and remove enemy
            if (enemyPos == SCREEN_HEIGHT - 2) {
                score++;
                enemyPos = -1;
            }
        }

        // update screen buffer with player and enemy positions
        for (int i = 0; i < 3; i++) {
            screen[SCREEN_HEIGHT - 2][i + (SCREEN_WIDTH / 2) - 1] = player[i];
        }
        if (enemyPos != -1) {
            screen[enemyPos][SCREEN_WIDTH / 2] = enemy[0];
            screen[enemyPos - 1][SCREEN_WIDTH / 2] = enemy[1];
        }
    }

    return 0;
}

char getInput() {
    // disable terminal buffering and echoing
    system("stty -icanon -echo");

    // get input character
    char input = getchar();

    // re-enable terminal buffering and echoing
    system("stty icanon echo");

    return input;
}

void movePlayerLeft(char *player) {
    for (int i = 0; i < 2; i++) {
        player[i] = PLAYER_LEFT;
        player[i + 1] = PLAYER_CHAR;
        sleep(0.1);
    }
}

void movePlayerRight(char *player) {
    for (int i = 0; i < 2; i++) {
        player[i] = PLAYER_CHAR;
        player[i + 1] = PLAYER_RIGHT;
        sleep(0.1);
    }
}

void spawnEnemy(char *enemy) {
    enemy[0] = ENEMY_CHAR;
    enemy[1] = ' ';
}

void moveEnemy(char *enemy) {
    // randomly move enemy left or right
    if (rand() % 2 == 0) {
        enemy[0] = ' ';
        enemy[1] = ENEMY_CHAR;
    } else {
        enemy[0] = ENEMY_CHAR;
        enemy[1] = ' ';
    }
}