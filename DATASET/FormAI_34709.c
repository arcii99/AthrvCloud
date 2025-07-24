//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define SCREEN_HEIGHT 20
#define SCREEN_WIDTH 40
#define BALL_INITIAL_X SCREEN_WIDTH/2
#define BALL_INITIAL_Y SCREEN_HEIGHT/2
#define PADDLE_INITIAL_X 1
#define PADDLE_INITIAL_Y SCREEN_HEIGHT/2
#define PADDLE_SIZE 5

pthread_t input_thread;
pthread_t ball_thread;
pthread_t opponent_thread;

int paddle_y = PADDLE_INITIAL_Y;

struct Ball {
    int x;
    int y;
    int dx;
    int dy;
} ball = {BALL_INITIAL_X, BALL_INITIAL_Y, 1, 1};

bool opp_move_up = false;
bool opp_move_down = false;

void set_input_mode(void) 
{   
    struct termios tty_attr;

    tcgetattr(0, &tty_attr);
    tty_attr.c_lflag &= ~(ICANON|ECHO);
    tty_attr.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &tty_attr);
}

void reset_input_mode(void) 
{
    struct termios tty_attr;

    tcgetattr(0, &tty_attr);
    tty_attr.c_lflag |= ICANON|ECHO;
    tcsetattr(0, TCSANOW, &tty_attr);
}

void move_ball(int dx, int dy) 
{
    ball.x += dx;
    ball.y += dy;
}

void move_paddle(int dy) 
{
    if ((paddle_y + dy > 0) && (paddle_y + dy < SCREEN_HEIGHT - PADDLE_SIZE))
        paddle_y += dy;
}

void draw_board() 
{
    int i, j;

    system("clear");

    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if ((i == ball.y) && (j == ball.x)) {
                printf("o");
            } else if ((j == PADDLE_INITIAL_X) && (i >= paddle_y) && (i <= paddle_y + PADDLE_SIZE)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update_opponent() 
{
    int target = ball.y;

    if (paddle_y < target) {
        opp_move_down = true;
        opp_move_up = false;
    } else {
        opp_move_up = true;
        opp_move_down = false;
    }
}

void *read_input(void *arg) 
{
    while (1) {
        char c;
        int nbytes;

        nbytes = read(0, &c, 1);

        if (nbytes > 0) {
            switch (c) {
                case 'k':
                    move_paddle(-1);
                    break;
                case 'j':
                    move_paddle(1);
                    break;
            }
        }
    }
}

void *move_opponent(void *arg) 
{
    while (1) {
        if (opp_move_up) {
            move_paddle(-1);
        } else if (opp_move_down) {
            move_paddle(1);
        }
        update_opponent();
        sleep(1);
    }
}

void *move_ball_thread(void *arg) 
{
    while (1) {
        move_ball(ball.dx, ball.dy);

        if ((ball.x == SCREEN_WIDTH - 1) || (ball.x == 0)) {
            ball.dx = -ball.dx;
            update_opponent();
        } else if ((ball.y == SCREEN_HEIGHT - 1) || (ball.y == 0)) {
            ball.dy = -ball.dy;
            update_opponent();
        } else if ((ball.x == PADDLE_INITIAL_X) && ((ball.y >= paddle_y) && (ball.y <= paddle_y + PADDLE_SIZE))) {
            ball.dx = -ball.dx;
            update_opponent();
        } else if (ball.x == SCREEN_WIDTH - 2) {
            printf("You won!");
            exit(0);
        } else if (ball.x == 1) {
            printf("You lost!");
            exit(0);
        }

        usleep(40000);
    }
}

int main(void) 
{
    int i, result;
    set_input_mode();
    draw_board();

    result = pthread_create(&input_thread, NULL, read_input, NULL);
    if (result != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    result = pthread_create(&ball_thread, NULL, move_ball_thread, NULL);
    if (result != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    result = pthread_create(&opponent_thread, NULL, move_opponent, NULL);
    if (result != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    pthread_join(input_thread, NULL);
    pthread_join(ball_thread, NULL);
    pthread_join(opponent_thread, NULL);

    reset_input_mode();

    return EXIT_SUCCESS;
}