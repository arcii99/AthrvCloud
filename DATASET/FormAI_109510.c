//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20
#define PADDLE_WIDTH 3
#define PADDLE_HEIGHT 1
#define BALL_WIDTH 1
#define BALL_HEIGHT 1

typedef struct {
    int x, y;
} point;

typedef struct {
    point upper_left;
    int width, height;
} paddle;

typedef struct {
    point upper_left;
    int width, height;
    int dx, dy;
} ball;

// Function declarations
void clear_screen();
void draw_paddle(paddle p);
void draw_ball(ball b);
void draw_score(int score);
void move_paddle(paddle *p, int dx, int dy);
void move_ball(ball *b);
bool ball_hits_paddle(ball b, paddle p);
bool ball_hits_wall(ball b);
bool score(ball b, int *score);
int get_input();

int main() {
    // Set up game state
    paddle player_paddle = {{SCREEN_WIDTH/2-PADDLE_WIDTH/2, SCREEN_HEIGHT-1}, PADDLE_WIDTH, PADDLE_HEIGHT};
    paddle ai_paddle = {{SCREEN_WIDTH/2-PADDLE_WIDTH/2, 0}, PADDLE_WIDTH, PADDLE_HEIGHT};
    ball game_ball = {{SCREEN_WIDTH/2-BALL_WIDTH/2, SCREEN_HEIGHT/2-BALL_HEIGHT/2}, BALL_WIDTH, BALL_HEIGHT, 1, 1};
    int player_score = 0;
    int ai_score = 0;
    bool game_over = false;

    // Set up input handling
    int fd = fileno(stdin);
    struct termios old = {0};
    struct termios new = {0};
    tcgetattr(fd, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;
    tcsetattr(fd, TCSANOW, &new);

    while (!game_over) {
        // Move the player paddle based on input
        int input = get_input();
        switch (input) {
            case 'a':
                move_paddle(&player_paddle, -1, 0);
                break;
            case 'd':
                move_paddle(&player_paddle, 1, 0);
                break;
        }

        // Move the AI paddle to try to block the ball
        if (game_ball.upper_left.y < SCREEN_HEIGHT/2) {
            if (ai_paddle.upper_left.x + ai_paddle.width/2 < game_ball.upper_left.x + game_ball.width/2) {
                move_paddle(&ai_paddle, 1, 0);
            } else if (ai_paddle.upper_left.x + ai_paddle.width/2 > game_ball.upper_left.x + game_ball.width/2) {
                move_paddle(&ai_paddle, -1, 0);
            }
        }

        // Move the ball and check for collisions
        move_ball(&game_ball);
        if (ball_hits_wall(game_ball)) {
            game_ball.dx *= -1;
        }
        if (ball_hits_paddle(game_ball, player_paddle)) {
            game_ball.dy *= -1;
        }
        if (ball_hits_paddle(game_ball, ai_paddle)) {
            game_ball.dy *= -1;
        }
        if (score(game_ball, &player_score)) {
            game_over = true;
            printf("You win!\n");
            break;
        }
        if (score(game_ball, &ai_score)) {
            game_over = true;
            printf("You lose!\n");
            break;
        }

        // Draw the updated game state
        clear_screen();
        draw_paddle(player_paddle);
        draw_paddle(ai_paddle);
        draw_ball(game_ball);
        draw_score(player_score);
        usleep(50000);
    }

    // Clean up input handling
    tcsetattr(fd, TCSANOW, &old);

    return 0;
}

void clear_screen() {
    system("clear");
}

void draw_paddle(paddle p) {
    int x, y;
    for (y = p.upper_left.y; y < p.upper_left.y + p.height; y++) {
        for (x = p.upper_left.x; x < p.upper_left.x + p.width; x++) {
            printf("\033[%d;%dH=", y, x);
        }
    }
}

void draw_ball(ball b) {
    printf("\033[%d;%dH@", b.upper_left.y, b.upper_left.x);
}

void draw_score(int score) {
    printf("\033[%d;%dHScore: %d", SCREEN_HEIGHT+1, 0, score);
}

void move_paddle(paddle *p, int dx, int dy) {
    int new_x = p->upper_left.x + dx;
    if (new_x >= 0 && new_x + p->width <= SCREEN_WIDTH) {
        p->upper_left.x = new_x;
    }
}

void move_ball(ball *b) {
    b->upper_left.x += b->dx;
    b->upper_left.y += b->dy;
}

bool ball_hits_paddle(ball b, paddle p) {
    if (b.upper_left.y + b.height == p.upper_left.y &&
        b.upper_left.x + b.width > p.upper_left.x &&
        b.upper_left.x < p.upper_left.x + p.width) {
        return true;
    } else {
        return false;
    }
}

bool ball_hits_wall(ball b) {
    if (b.upper_left.x <= 0 || b.upper_left.x + b.width >= SCREEN_WIDTH) {
        return true;
    }
    if (b.upper_left.y <= 0) {
        return true;
    }
    return false;
}

bool score(ball b, int *score) {
    if (b.upper_left.y + b.height == SCREEN_HEIGHT) {
        *score += 1;
        return true;
    }
    if (b.upper_left.y == 0) {
        return true;
    }
    return false;
}

int get_input() {
    int c = getchar();
    return c;
}