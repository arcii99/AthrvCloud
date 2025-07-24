//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 20

// Paddle struct representing player and AI paddles
typedef struct {
    int x, y;  // Position of top-left corner of paddle
    int height; // Height of paddle
} Paddle;

// Ball struct representing the game ball
typedef struct {
    int x, y;  // Position of the ball
    int x_direction, y_direction; // Direction the ball is moving
} Ball;

// Function to draw the game screen
void draw_screen(Paddle player, Paddle ai, Ball ball) {
    // Clear the screen
    system("clear");

    // Draw the top border of the game screen
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    // Draw the game screen row by row
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            // Draw the left and right borders of the screen
            if (j == 0 || j == SCREEN_WIDTH-1) {
                printf("|");
            } else {
                // Check if the current coordinate is the position of the ball or paddle
                if (ball.x == j && ball.y == i) {
                    printf("O");
                } else if ((player.x <= j && j <= player.x + 2) && (player.y <= i && i <= player.y + player.height)) {
                    printf("=");
                } else if ((ai.x <= j && j <= ai.x + 2) && (ai.y <= i && i <= ai.y + ai.height)) {
                    printf("=");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    // Draw the bottom border of the game screen
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}

// Function to move the player paddle based on user input
void move_player(Paddle *player, char input) {
    switch(input) {
        case 'w':
            // Move up
            if (player->y > 0) {player->y--;}
            break;
        case 's':
            // Move down
            if (player->y + player->height < SCREEN_HEIGHT - 1) {player->y++;}
            break;
    }
}

// Function to move the AI paddle
void move_ai(Paddle *ai, Ball ball) {
    // If the ball is above the AI paddle, move up; if it's below, move down
    if (ball.y < ai->y) {
        if (ai->y > 0) {ai->y--;}
    } else if (ball.y > ai->y + ai->height) {
        if (ai->y + ai->height < SCREEN_HEIGHT - 1) {ai->y++;}
    }
}

// Function to move the ball
void move_ball(Ball *ball, Paddle player, Paddle ai) {
    // Move the ball in its current direction
    ball->x += ball->x_direction;
    ball->y += ball->y_direction;

    // If the ball hits the top or bottom of the screen, reverse its y direction
    if (ball->y == 0 || ball->y == SCREEN_HEIGHT - 1) {
        ball->y_direction *= -1;
    }

    // If the ball hits the player paddle, reverse its x direction and adjust y direction
    if ((player.x <= ball->x && ball->x <= player.x + 2) && (player.y <= ball->y && ball->y <= player.y + player.height)) {
        ball->x_direction *= -1;
        ball->y_direction = -1;
    }

    // If the ball hits the AI paddle, reverse its x direction and adjust y direction
    if ((ai.x <= ball->x && ball->x <= ai.x + 2) && (ai.y <= ball->y && ball->y <= ai.y + ai.height)) {
        ball->x_direction *= -1;
        ball->y_direction = 1;
    }

    // If the ball goes past the player, the AI scores a point and reset the ball position
    if (ball->x < player.x) {
        ball->x = ai.x + 2;
        ball->y = ai.y + ai.height / 2;
        ball->x_direction = -1;
        ball->y_direction = 1;
    }

    // If the ball goes past the AI, the player scores a point and reset the ball position
    if (ball->x > ai.x) {
        ball->x = player.x;
        ball->y = player.y + player.height / 2;
        ball->x_direction = 1;
        ball->y_direction = -1;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize player paddle
    Paddle player = {2, SCREEN_HEIGHT / 2 - 2, 4};

    // Initialize AI paddle
    Paddle ai = {SCREEN_WIDTH - 5, SCREEN_HEIGHT / 2 - 2, 4};

    // Initialize ball
    Ball ball = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, (rand() % 2 == 0) ? 1 : -1, (rand() % 2 == 0) ? 1 : -1};

    // Game loop
    while(1) {
        // Check for user input
        char input;
        if ((input = getchar()) != EOF && input != '\n') {
            move_player(&player, input);
        }

        // Move the AI paddle based on the ball position
        move_ai(&ai, ball);

        // Move the ball
        move_ball(&ball, player, ai);

        // Draw the game screen
        draw_screen(player, ai, ball);

        // Sleep for a short period to control game speed
        usleep(25000);
    }

    return 0;
}