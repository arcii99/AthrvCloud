//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <termios.h>

#define WIDTH 80
#define HEIGHT 25
#define BULLET_SPEED 5

// Function to get keyboard input without waiting for '\n'
int get_input() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to generate random number
int random_num(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int player_x = WIDTH / 2;
    int player_y = HEIGHT - 2;
    int bullet_x, bullet_y, bullet_flag = 0;
    int score = 0;
    int enemy_x[WIDTH], enemy_y[HEIGHT];
    int enemy_speed[HEIGHT], enemy_alive[HEIGHT];
    char screen[HEIGHT][WIDTH+1];
    int key, i, j;

    // Initialize screen and enemies
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
        screen[i][WIDTH] = '\0';
    }
    for (i = 0; i < WIDTH; i++) {
        enemy_x[i] = i;
        enemy_y[i] = 0;
        enemy_speed[i] = random_num(1,3);
        enemy_alive[i] = 1;
    }

    // Main game loop
    while(1) {
        // Clear screen and redraw player
        system("clear");
        for (i = 0; i < HEIGHT-1; i++) {
            printf("%s\n", screen[i]);
        }
        for (i = 0; i < WIDTH; i++) {
            screen[player_y][i] = ' ';
        }
        screen[player_y][player_x] = 'A';

        // Move and draw enemies
        for (i = 0; i < WIDTH; i++) {
            if (enemy_alive[i]) {
                screen[enemy_y[i]][enemy_x[i]] = '*';
                enemy_y[i] += enemy_speed[i];
                if (enemy_y[i] >= player_y) {
                    printf("Game over! Your score is %d\n", score);
                    exit(0);
                }
                if (enemy_y[i] < HEIGHT-1) {
                    screen[enemy_y[i]][enemy_x[i]] = ' ';
                }
            }
        }

        // Shoot bullet
        if (bullet_flag) {
            screen[bullet_y][bullet_x] = ' ';
            bullet_y--;
            if (bullet_y <= 0) {
                bullet_flag = 0;
            }
            else {
                screen[bullet_y][bullet_x] = '|';
                for (i = 0; i < WIDTH; i++) {
                    if (enemy_alive[i] && bullet_x == enemy_x[i] && bullet_y == enemy_y[i]) {
                        enemy_alive[i] = 0;
                        bullet_flag = 0;
                        score++;
                        break;
                    }
                }
            }
        }

        // Get keyboard input and move player or shoot bullet
        key = get_input();
        switch (key) {
            case 'a':
                if (player_x > 0) {
                    player_x--;
                }
                break;
            case 'd':
                if (player_x < WIDTH-1) {
                    player_x++;
                }
                break;
            case ' ':
                if (!bullet_flag) {
                    bullet_x = player_x;
                    bullet_y = player_y - 1;
                    bullet_flag = 1;
                }
                break;
            case 'q':
                exit(0);
                break;
        }
        usleep(10000);
    }

    return 0;
}