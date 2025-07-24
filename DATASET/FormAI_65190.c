//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

#define WIDTH 50 // Width of the game screen
#define HEIGHT 30 // Height of the game screen

// Defining the player and the alien's positions
int player_x, player_y;
int alien_x, alien_y;

// Defining the player and the alien's health
int player_health = 5;
int alien_health = 10;

// Defining the player and the alien's score
int player_score = 0;
int alien_score = 0;

// Function to set the screen mode to raw mode
void set_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to reset the screen mode to cooked mode
void reset_screen_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Function to draw the game screen
void draw_screen() {
    system("clear");
    printf("Player Score: %d\t\t\tAlien Score: %d\n", player_score, alien_score);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                printf("#");
            } else if (x == player_x && y == player_y) {
                printf("P");
            } else if (x == alien_x && y == alien_y) {
                printf("A");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Player Health: %d\t\t\tAlien Health: %d\n", player_health, alien_health);
}

// Function to move the player
void move_player(int direction) {
    if (player_x + direction >= 1 && player_x + direction < WIDTH - 1) {
        player_x += direction;
    }
}

// Function to move the alien
void move_alien() {
    if (alien_x < player_x) {
        alien_x++;
    } else if (alien_x > player_x) {
        alien_x--;
    }
    if (alien_y < player_y) {
        alien_y++;
    } else if (alien_y > player_y) {
        alien_y--;
    }
}

// Function to shoot the laser
void shoot_laser() {
    if (player_y > 1) {
        for (int y = player_y - 1; y > 0; y--) {
            if (alien_x == player_x && alien_y == y) {
                alien_health--;
                if (alien_health == 0) {
                    printf("Congratulations! You have defeated the alien.\n");
                    player_score++;
                    alien_health = 10;
                    alien_x = rand() % (WIDTH - 2) + 1;
                    alien_y = rand() % (HEIGHT - 6) + 2;
                }
                break;
            }
            if (y == 1) {
                printf("You missed the alien.\n");
            }
        }
    } else {
        printf("You cannot shoot while you are at the top.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    player_x = WIDTH / 2;
    player_y = HEIGHT - 2;
    alien_x = rand() % (WIDTH - 2) + 1;
    alien_y = rand() % (HEIGHT - 6) + 2;
    set_raw_mode();
    while (player_health > 0 && alien_score < 10) {
        draw_screen();
        move_alien();
        int c = getchar();
        if (c == 'q') {
            break;
        } else if (c == 'a') {
            move_player(-1);
        } else if (c == 'd') {
            move_player(1);
        } else if (c == ' ') {
            shoot_laser();
            sleep(1);
        }
        if (alien_y == player_y) {
            player_health--;
            if (player_health == 0) {
                printf("Game Over! The alien has conquered the earth.\n");
                break;
            } else {
                printf("The alien has hit you. You have %d health left.\n", player_health);
                alien_score++;
                alien_health = 10;
                alien_x = rand() % (WIDTH - 2) + 1;
                alien_y = rand() % (HEIGHT - 6) + 2;
            }
        }
    }
    reset_screen_mode();
    return 0;
}