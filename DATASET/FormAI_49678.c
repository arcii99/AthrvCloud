//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: artistic
// A Pong Game with AI Opponent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 70
#define HEIGHT 40
#define PADDLE_HEIGHT 5
#define BALL_MAX_SPEED 2
#define BALL_SPAWN_DELAY 3

// Global Variables
char screen[WIDTH][HEIGHT];
int ball_x, ball_y, ball_speed_x, ball_speed_y, player_score, ai_score;

// Set up terminal and get input
int kbhit(void) {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
}

// Initialise the game
void init_game() {
    // Clear screen
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            screen[i][j] = ' ';
        }
    }

    // Set up ball
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    ball_speed_x = rand() % BALL_MAX_SPEED * 2 - BALL_MAX_SPEED;
    ball_speed_y = rand() % BALL_MAX_SPEED * 2 - BALL_MAX_SPEED;

    // Set up player paddle
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        screen[0][HEIGHT / 2 - PADDLE_HEIGHT / 2 + i] = '|';
        screen[1][HEIGHT / 2 - PADDLE_HEIGHT / 2 + i] = '|';
    }

    // Set up ai paddle
    for (int i = 0; i < PADDLE_HEIGHT; i++) {
        screen[WIDTH - 1][HEIGHT / 2 - PADDLE_HEIGHT / 2 + i] = '|';
        screen[WIDTH - 2][HEIGHT / 2 - PADDLE_HEIGHT / 2 + i] = '|';
    }

    // Set up scores
    player_score = 0;
    ai_score = 0;
}

// Draw the screen
void draw_screen() {
    // Clear screen
    system("clear");

    // Draw screen
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }

    // Draw scores
    printf("\nPlayer: %d\t\tAI: %d\n", player_score, ai_score);
}

// Move the ball
void move_ball() {
    // Update ball position
    ball_x += ball_speed_x;
    ball_y += ball_speed_y;

    // Check for ball collision with walls
    if (ball_x <= 2 || ball_x >= WIDTH - 3) {
        ball_speed_x *= -1;
    }

    if (ball_y <= 0 || ball_y >= HEIGHT - 1) {
        ball_speed_y *= -1;
    }
}

// Move the paddle
void move_paddle(int up, int down, int row) {
    // Check for key input
    if (kbhit()) {
        char input = getchar();
        if (input == up && row > 1) {
            screen[0][row - 1] = '|';
            screen[1][row - 1] = '|';
            screen[0][row + PADDLE_HEIGHT - 1] = ' ';
            screen[1][row + PADDLE_HEIGHT - 1] = ' ';
        } else if (input == down && row < HEIGHT - PADDLE_HEIGHT - 1) {
            screen[0][row + PADDLE_HEIGHT + 1] = '|';
            screen[1][row + PADDLE_HEIGHT + 1] = '|';
            screen[0][row] = ' ';
            screen[1][row] = ' ';
        }
    }
}

// Move the ai paddle
void move_ai_paddle() {
    // Determine ball position relative to paddle
    int paddle_y = ball_y - PADDLE_HEIGHT / 2;
    int ball_direction = ball_speed_x < 0 ? -1 : 1;

    // Move paddle towards ball
    if (paddle_y < 1) {
        paddle_y = 1;
    } else if (paddle_y > HEIGHT - PADDLE_HEIGHT - 1) {
        paddle_y = HEIGHT - PADDLE_HEIGHT - 1;
    }

    if (ball_x < WIDTH / 2 && ball_direction < 0) {
        if (paddle_y < ball_y) {
            move_paddle('A', 'Z', paddle_y + 1);
        } else if (paddle_y > ball_y) {
            move_paddle('A', 'Z', paddle_y - 1);
        }
    } else {
        if (paddle_y < HEIGHT / 2) {
            move_paddle('A', 'Z', paddle_y + 1);
        } else if (paddle_y > HEIGHT / 2) {
            move_paddle('A', 'Z', paddle_y - 1);
        }
    }
}

// Check for paddle collision with ball
int check_collision(int x, int y) {
    if (x == 1 && ball_x == 2 && y - PADDLE_HEIGHT / 2 <= ball_y && y + PADDLE_HEIGHT / 2 >= ball_y) {
        return -1;
    }

    if (x == WIDTH - 2 && ball_x == WIDTH - 3 && y - PADDLE_HEIGHT / 2 <= ball_y && y + PADDLE_HEIGHT / 2 >= ball_y) {
        return 1;
    }

    return 0;
}

// Update game
void update() {
    // Check for ball collision with paddles
    int paddle_hit = check_collision(ball_x, ball_y);

    if (paddle_hit != 0) {
        ball_speed_x = -ball_speed_x;

        if (paddle_hit == -1) {
            ball_speed_y -= (ball_y - screen[1][ball_y]) / (PADDLE_HEIGHT / 2);
            player_score++;
        } else {
            ball_speed_y += (ball_y - screen[WIDTH - 2][ball_y]) / (PADDLE_HEIGHT / 2);
            ai_score++;
        }

        if (ball_speed_y > BALL_MAX_SPEED) {
            ball_speed_y = BALL_MAX_SPEED;
        } else if (ball_speed_y < -BALL_MAX_SPEED) {
            ball_speed_y = -BALL_MAX_SPEED;
        }
    }

    // Move paddles
    move_paddle('A', 'Z', ball_y - PADDLE_HEIGHT / 2);
    move_ai_paddle();

    // Move ball
    move_ball();

    // Check for game over
    if (ball_x < 0) {
        printf("You win!\n");
        exit(0);
    }

    if (ball_x > WIDTH) {
        printf("You lose!\n");
        exit(0);
    }
}

// Main loop
int main() {
    srand(time(NULL));

    init_game();
    draw_screen();

    sleep(BALL_SPAWN_DELAY);

    while (1) {
        update();
        draw_screen();
        usleep(100000);
    }

    return 0;
}