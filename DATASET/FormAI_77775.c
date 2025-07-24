//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 80
#define HEIGHT 30
#define BALL_RADIUS 3
#define GRAVITY 9.81

int main() {
    double x = WIDTH / 2, y = 0, vx = 5, vy = 0;
    int i, j, t = 0;
    char scene[HEIGHT][WIDTH + 1];

    while (1) {
        // calculate new position and velocity
        x += vx;
        y += vy;
        vy += GRAVITY;

        // check for collision with ground
        if (y >= HEIGHT - BALL_RADIUS) {
            y = 2 * (HEIGHT - BALL_RADIUS) - y;
            vy *= -0.9;
            vx *= 0.9;
        }

        // check for collision with walls
        if (x <= BALL_RADIUS || x >= WIDTH - BALL_RADIUS) {
            x = x <= BALL_RADIUS ? 2 * BALL_RADIUS - x : 2 * (WIDTH - BALL_RADIUS) - x;
            vx *= -0.9;
            vy *= 0.9;
        }

        // clear scene and draw ball
        for (i = 0; i < HEIGHT; ++i) {
            for (j = 0; j < WIDTH; ++j) {
                scene[i][j] = ' ';
            }
            scene[i][WIDTH] = '\0';
        }
        for (i = 0; i < 2 * BALL_RADIUS + 1; ++i) {
            for (j = 0; j < 2 * BALL_RADIUS + 1; ++j) {
                if (i * i + j * j <= BALL_RADIUS * BALL_RADIUS) {
                    scene[(int) round(y - BALL_RADIUS + i)][(int) round(x - BALL_RADIUS + j)] = '*';
                }
            }
        }

        // print scene and sleep for a bit
        system("clear");
        printf("Simulation time: %d seconds\n", t);
        for (i = 0; i < HEIGHT; ++i) {
            puts(scene[i]);
        }
        usleep(100000);
        ++t;
    }

    return 0;
}