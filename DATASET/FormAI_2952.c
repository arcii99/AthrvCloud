//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 30
#define HEIGHT 20

// game variables
char board[HEIGHT][WIDTH];
int ball_x, ball_y;  // position of the ball
int dx, dy;          // velocity of the ball
int paddle_x;        // position of the paddle
int score;           // player's score

// terminal settings
struct termios orig_termios;

void disable_canonical_echo_mode() {
    // disable canonical mode and echoing
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void restore_terminal_settings() {
    // restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void setup() {
    // initialize game variables

    // clear the board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // set the ball's starting position and velocity
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    dx = 1;
    dy = 1;

    // set the paddle's starting position
    paddle_x = WIDTH / 2;

    // set the initial score
    score = 0;

    // draw the board
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("#");
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("#\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // move cursor to bottom of board
    printf("\033[%d;%dH", HEIGHT + 3, 0);
    printf("Score: %d", score);
}

bool is_game_over() {
    // check if the game is over
    if (ball_y == HEIGHT - 1) {
        return true;
    }
    return false;
}

void update() {
    // update ball position and velocity
    
    // check for collision with walls or ceiling
    if (ball_x == 0 || ball_x == WIDTH - 1) {
        dx = -dx;
    }
    if (ball_y == 0) {
        dy = -dy;
    }

    // check for collision with the paddle
    if (ball_y == HEIGHT - 2 && ball_x >= paddle_x - 3 && ball_x <= paddle_x + 3) {
        dy = -dy;
        score++;
    }

    // update ball position
    ball_x += dx;
    ball_y += dy;

    // clear board and redraw ball and paddle
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
    board[ball_y][ball_x] = 'O';
    board[HEIGHT - 1][paddle_x - 3] = '-';
    board[HEIGHT - 1][paddle_x - 2] = '-';
    board[HEIGHT - 1][paddle_x - 1] = '-';
    board[HEIGHT - 1][paddle_x] = '|';
    board[HEIGHT - 1][paddle_x + 1] = '-';
    board[HEIGHT - 1][paddle_x + 2] = '-';
    board[HEIGHT - 1][paddle_x + 3] = '-';

    // draw the board and score
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("#");
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("#\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // move cursor to bottom of board and update score
    printf("\033[%d;%dH", HEIGHT + 3, 0);
    printf("Score: %d", score);
}

void* input_thread(void* arg) {
    // thread for reading user input
    
    while (true) {
        int c = getchar();
        if (c == 'q') {
            restore_terminal_settings();
            exit(0);
        }
        else if (c == 'a') {
            // move paddle to the left
            if (paddle_x > 3) {
                paddle_x--;
            }
        }
        else if (c == 'd') {
            // move paddle to the right
            if (paddle_x < WIDTH - 4) {
                paddle_x++;
            }
        }
    }
}

int main() {
    // disable canonical mode and echoing
    disable_canonical_echo_mode();

    // set up game
    setup();

    // start input thread
    pthread_t input_tid;
    pthread_create(&input_tid, NULL, input_thread, NULL);

    // loop until game is over
    while (true) {
        usleep(100000);  // sleep for 0.1 seconds
        update();
        if (is_game_over()) {
            break;
        }
    }

    // game over
    printf("\033[%d;%dH", HEIGHT + 5, 0);
    printf("Game over! Your score was: %d\n", score);

    // restore original terminal settings and exit
    restore_terminal_settings();
    return 0;
}