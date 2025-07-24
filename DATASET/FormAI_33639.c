//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define PADDLE_SIZE 4
#define BOARD_WIDTH 80
#define BOARD_HEIGHT 22
#define BALL_SIZE 1

// Define keycodes for arrow keys
#define KEY_UP 65
#define KEY_DOWN 66

// Define structure for game objects
typedef struct {
    int x;
    int y;
    int velocity_x;
    int velocity_y;
    int size;
} Ball;

typedef struct {
    int x;
    int y;
    int size;
    int score;
} Paddle;

typedef struct {
    Ball ball;
    Paddle player;
    Paddle opponent;
} GameState;

// Function to initialize game state
void init_game(GameState* game) {
    // Initialize ball position and velocity
    game->ball.x = BOARD_WIDTH / 2;
    game->ball.y = BOARD_HEIGHT / 2;
    srand(time(NULL));
    game->ball.velocity_x = (rand() % 2 == 0) ? 1 : -1;
    game->ball.velocity_y = (rand() % 2 == 0) ? 1 : -1;
    game->ball.size = BALL_SIZE;

    // Initialize player paddle position and score
    game->player.x = 1;
    game->player.y = (BOARD_HEIGHT - PADDLE_SIZE) / 2;
    game->player.size = PADDLE_SIZE;
    game->player.score = 0;

    // Initialize opponent paddle position and score
    game->opponent.x = BOARD_WIDTH - 2;
    game->opponent.y = (BOARD_HEIGHT - PADDLE_SIZE) / 2;
    game->opponent.size = PADDLE_SIZE;
    game->opponent.score = 0;

}

// Function to update game state each frame
void update_game(GameState* game) {
    // Move ball
    game->ball.x += game->ball.velocity_x;
    game->ball.y += game->ball.velocity_y;

    // Bounce ball off top and bottom walls
    if (game->ball.y == 0 || game->ball.y == BOARD_HEIGHT - 1) {
        game->ball.velocity_y *= -1;
    }

    // Handle ball colliding with player paddle
    if (game->ball.x == game->player.x + 1 && game->ball.y >= game->player.y 
            && game->ball.y < game->player.y + game->player.size) {
        game->ball.velocity_x *= -1;
    }

    // Handle ball colliding with opponent paddle
    if (game->ball.x == game->opponent.x - 1 && game->ball.y >= game->opponent.y 
            && game->ball.y < game->opponent.y + game->opponent.size) {
        game->ball.velocity_x *= -1;
    }

    // Check if player scored
    if (game->ball.x == 0) {
        game->player.score++;
        init_game(game);
    }

    // Check if opponent scored
    if (game->ball.x == BOARD_WIDTH - 1) {
        game->opponent.score++;
        init_game(game);
    }

    // Update opponent paddle position to try to hit ball
    if (game->opponent.y + game->opponent.size / 2 < game->ball.y) {
        game->opponent.y++;
    } else if (game->opponent.y + game->opponent.size / 2 > game->ball.y) {
        game->opponent.y--;
    }
}

// Function to get user input
int get_input() {
    struct termios old_term, new_term;
    tcgetattr(STDIN_FILENO, &old_term);
    new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

    int input = 0;
    if (read(STDIN_FILENO, &input, 1) != 1) input = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &old_term);

    return input;
}

// Function to draw game objects to screen
void draw_screen(GameState* game) {
    // Clear screen
    system("clear");

    // Draw top and bottom walls
    for (int i = 0; i < BOARD_WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 1; i < BOARD_HEIGHT - 1; i++) {
        // Draw player paddle
        if (i >= game->player.y && i < game->player.y + game->player.size) {
            for (int j = 0; j < game->player.size; j++) {
                printf("#");
            }
        } else {
            printf("|");
        }

        // Draw ball or empty space
        if (i == game->ball.y) {
            printf("O");
        } else {
            printf(" ");
        }

        // Draw opponent paddle
        if (i >= game->opponent.y && i < game->opponent.y + game->opponent.size) {
            for (int j = 0; j < game->opponent.size; j++) {
                printf("#");
            }
        } else {
            printf("|");
        }

        printf("\n");
    }

    // Draw top and bottom walls
    for (int i = 0; i < BOARD_WIDTH; i++) {
        printf("-");
    }
    printf("\n");

    // Draw player score
    printf("Score: %d %*s %d\n", game->player.score, BOARD_WIDTH - 14, "Opponent: ", game->opponent.score);
}

int main() {
    // Initialize game state
    GameState game;
    init_game(&game);

    // Run game loop
    while (true) {
        // Get user input
        int input = get_input();

        // Update game state
        update_game(&game);

        // Draw screen
        draw_screen(&game);

        // Check for game over
        if (game.player.score == 3 || game.opponent.score == 3) {
            printf("Game Over!\n");
            break;
        }

        // Wait for 16ms to simulate 60fps
        usleep(16667);
    }

    return 0;
}