//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define MAX_TIME 60000000 // Maximum game time in microseconds
#define BOARD_WIDTH 50 // Width of the game board
#define BOARD_HEIGHT 25 // Height of the game board
#define PADDLE_HEIGHT 5 // Height of the paddle
#define BALL_DELAY 500000 // Delay between ball movements in microseconds

pthread_mutex_t lock; // Mutex lock to synchronize access to the game board

int ball_x, ball_y; // Coordinates of the ball
int paddle_left, paddle_right; // Y-coordinates of the left and right paddles
int player_left, player_right; // Scores of the left and right players
int game_time; // Time remaining in the game

char board[BOARD_HEIGHT][BOARD_WIDTH]; // Game board

enum { STOPPED, UP, DOWN } paddle_left_dir, paddle_right_dir; // Direction of the paddles
enum { LEFT_PLAYER, RIGHT_PLAYER } ball_direction; // Direction of the ball

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    for (i = 0; i < BOARD_HEIGHT; i++) {
        board[i][0] = '|';
        board[i][BOARD_WIDTH-1] = '|';
    }

    for (i = 0; i < BOARD_WIDTH; i++) {
        board[0][i] = '-';
        board[BOARD_HEIGHT-1][i] = '-';
    }

    for (i = 0; i < PADDLE_HEIGHT; i++) {
        board[paddle_left + i][1] = '|';
        board[paddle_right + i][BOARD_WIDTH-2] = '|';
    }

    board[ball_y][ball_x] = 'O';
}

void draw_board() {
    int i, j;
    system("clear"); // Clear the console screen

    printf("Time: %d  Left player score: %d  Right player score: %d\n\n", game_time/1000000, player_left, player_right);

    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void init_ball() {
    srand(time(NULL));
    ball_x = rand() % (BOARD_WIDTH - 3) + 2; // Random x-coordinate
    ball_y = rand() % (BOARD_HEIGHT - 3) + 2; // Random y-coordinate
    ball_direction = rand() % 2 ? LEFT_PLAYER : RIGHT_PLAYER; // Random direction
}

void* move_ball(void* arg) {
    while (game_time > 0) {
        usleep(BALL_DELAY);

        pthread_mutex_lock(&lock); // Lock the mutex

        board[ball_y][ball_x] = ' ';

        if (ball_direction == LEFT_PLAYER) {
            if (ball_x == 2) { // Left paddle collision
                if (ball_y >= paddle_left && ball_y < (paddle_left + PADDLE_HEIGHT)) {
                    ball_direction = RIGHT_PLAYER;
                } else {
                    player_right++;
                    init_ball();
                }
            } else {
                ball_x--;
            }
        } else {
            if (ball_x == BOARD_WIDTH - 3) { // Right paddle collision
                if (ball_y >= paddle_right && ball_y < (paddle_right + PADDLE_HEIGHT)) {
                    ball_direction = LEFT_PLAYER;
                } else {
                    player_left++;
                    init_ball();
                }
            } else {
                ball_x++;
            }
        }

        if (ball_y == 1 || ball_y == BOARD_HEIGHT - 2) { // Top/bottom wall collision
            ball_direction = ball_direction == LEFT_PLAYER ? RIGHT_PLAYER : LEFT_PLAYER;
        } else {
            ball_y += ball_direction == LEFT_PLAYER ? -1 : 1;
        }

        board[ball_y][ball_x] = 'O';

        pthread_mutex_unlock(&lock); // Unlock the mutex
    }
    return NULL;
}

void move_paddle_up(int* paddle_y) {
    if (*paddle_y > 2) {
        (*paddle_y)--;
    }
}

void move_paddle_down(int* paddle_y) {
    if (*paddle_y < BOARD_HEIGHT - PADDLE_HEIGHT - 1) {
        (*paddle_y)++;
    }
}

void* move_paddle_left(void* arg) {
    int* paddle_y = (int*) arg;
    char c;

    while (game_time > 0) {
        c = getchar();
        if (c == 'w' || c == 'W') {
            move_paddle_up(paddle_y);
        } else if (c == 's' || c == 'S') {
            move_paddle_down(paddle_y);
        }
    }
    return NULL;
}

void* move_paddle_right(void* arg) {
    int* paddle_y = (int*) arg;

    while (game_time > 0) {
        if (ball_y < *paddle_y + PADDLE_HEIGHT/2) {
            move_paddle_up(paddle_y);
        } else if (ball_y > *paddle_y + PADDLE_HEIGHT/2) {
            move_paddle_down(paddle_y);
        }
    }
    return NULL;
}

int main() {
    struct termios oldt, newt;
    pthread_t ball_thread, paddle_left_thread, paddle_right_thread;
    
    pthread_mutex_init(&lock, NULL); // Initialize the mutex lock

    tcgetattr(0, &oldt); // Get console input attributes
    newt = oldt;
    newt.c_lflag &= ~ICANON; // Disable canonical mode (line buffering)
    newt.c_lflag &= ~ECHO; // Disable echoing of input characters
    tcsetattr(0, TCSANOW, &newt); // Set new console input attributes

    paddle_left = paddle_right = (BOARD_HEIGHT - PADDLE_HEIGHT)/2; // Center the paddles
    player_left = player_right = 0;
    game_time = MAX_TIME;

    init_ball();
    init_board();

    pthread_create(&ball_thread, NULL, move_ball, NULL); // Create the ball movement thread
    pthread_create(&paddle_left_thread, NULL, move_paddle_left, (void*) &paddle_left); // Create the left paddle movement thread
    pthread_create(&paddle_right_thread, NULL, move_paddle_right, (void*) &paddle_right); // Create the right paddle movement thread

    while (game_time > 0) {
        usleep(1000);
        game_time -= 1000;
        draw_board();
    }

    pthread_join(ball_thread, NULL); // Wait for the ball movement thread to finish
    pthread_cancel(paddle_left_thread); // Terminate the left paddle movement thread
    pthread_cancel(paddle_right_thread); // Terminate the right paddle movement thread

    pthread_mutex_destroy(&lock); // Destroy the mutex lock

    tcsetattr(0, TCSANOW, &oldt); // Restore the console input attributes

    return 0;
}