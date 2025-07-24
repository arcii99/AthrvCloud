//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 10

char space[ROW][COL];
int player_position = 4;
int level = 1;
int score = 0;
int lives = 3;
int aliens_left = 0;

void init_game();   // function to initialize the game
void draw_game();   // function to draw the game on the terminal
void move_player(int direction);    // function to move the player left or right
void move_aliens(); // function to move the aliens down the screen
void fire_missile();    // function to fire a missile from the player's position
bool is_game_over();    // function to check if the game is over (player has no lives left or all aliens are destroyed)

int main() {
    init_game();

    while (1) {
        draw_game();

        int input = getchar();

        if (input == 'q') {
            break;
        } else if (input == 'a') {
            move_player(-1);
        } else if (input == 'd') {
            move_player(1);
        } else if (input == ' ') {
            fire_missile();
        }

        move_aliens();

        if (is_game_over()) {
            break;
        }
    }

    printf("\n\nGame over! Your score is %d.\n", score);

    return 0;
}

void init_game() {
    // initialize the space array with '-' characters
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            space[i][j] = '-';
        }
    }

    // randomly place 30 aliens on the top row
    srand(time(NULL));
    for (int i = 0; i < 30; i++) {
        int x = rand() % COL;
        space[0][x] = 'X';
    }

    aliens_left = 30;
}

void draw_game() {
    system("clear");    // clear the terminal window

    printf("Level: %d   Score: %d   Lives: %d   Aliens left: %d\n", level, score, lives, aliens_left);
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", space[i][j]);
        }
        printf("\n");
    }
}

void move_player(int direction) {
    if (player_position + direction >= 0 && player_position + direction < COL) {
        space[ROW - 1][player_position] = '-';
        player_position += direction;
        space[ROW - 1][player_position] = 'P';
    }
}

void move_aliens() {
    for (int i = ROW - 1; i >= 0; i--) {
        for (int j = 0; j < COL; j++) {
            if (space[i][j] == 'X') {
                space[i][j] = '-';
                if (i == ROW - 1) {  // alien has reached the bottom row
                    lives--;
                    if (lives == 0) {
                        return;
                    }
                } else {
                    if (space[i + 1][j] == 'P') {    // alien has collided with player
                        lives--;
                        if (lives == 0) {
                            return;
                        }
                    } else {
                        space[i + 1][j] = 'X';
                    }
                }
            }
        }
    }
}

void fire_missile() {
    for (int i = ROW - 1; i >= 0; i--) {
        if (space[i][player_position] == 'X') {   // player has destroyed an alien
            score += 10;
            aliens_left--;
            space[i][player_position] = '-';
            break;
        } else if (i == 0) {    // player has fired and missed
            score--;
        } else {
            space[i][player_position] = '|';    // missile is still in the air
        }
    }
}

bool is_game_over() {
    if (aliens_left == 0) {
        level++;
        init_game();
    }

    return lives == 0;
}