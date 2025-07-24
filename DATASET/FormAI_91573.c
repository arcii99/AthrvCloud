//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define ROWS 20
#define COLS 50
#define BOARD_SIZE ROWS * COLS
#define UPS 5
#define DOWNS 6
#define LEFTS 7
#define RIGHTS 8

enum Object {
    EMPTY,
    SNAKE,
    FOOD,
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum Status {
    RUNNING,
    GAMEOVER,
};

// Global variables
int board[BOARD_SIZE] = {EMPTY};
int snake[BOARD_SIZE] = {EMPTY};
int head_position = 0;
int tail_position = 0;
int dir = RIGHT;
int score = 0;
int food_position = -1;
int status = RUNNING;
int speed = 100000;

// Function prototypes
void print_board();
void move_snake();
void insert_food();
void set_direction();
void game_over_handler();
void set_up_input();
void stop_input();

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (board[i * COLS + j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case SNAKE:
                    printf("O");
                    break;
                case FOOD:
                    printf("X");
                    break;
            }
        }
        printf("\n");
    }
}

void move_snake() {
    int next_position = -1;

    switch (dir) {
        case UP:
            next_position = head_position - COLS;
            break;
        case DOWN:
            next_position = head_position + COLS;
            break;
        case LEFT:
            next_position = head_position - 1;
            break;
        case RIGHT:
            next_position = head_position + 1;
            break;
    }

    if (board[next_position] == SNAKE) {
        status = GAMEOVER;
        return;
    }

    if (board[next_position] == FOOD) {
        score++;
        speed -= score * 5000;
        snake[head_position] = dir;
        head_position = next_position;
        board[head_position] = SNAKE;
        insert_food();
        return;
    }

    snake[head_position] = dir;
    board[head_position] = SNAKE;
    head_position = next_position;
    board[head_position] = SNAKE;
    dir = snake[tail_position];
    board[tail_position] = EMPTY;
    tail_position++;
}

void insert_food() {
    while (true) {
        int position = rand() % BOARD_SIZE;

        if (board[position] == EMPTY) {
            board[position] = FOOD;
            food_position = position;
            return;
        }
    }
}

void set_direction() {
    char input;

    while (status == RUNNING) {
        input = getchar();

        switch (input) {
            case 'w':
                if (snake[head_position] != UP && snake[head_position] != DOWN) {
                    dir = UP;
                }
                break;
            case 's':
                if (snake[head_position] != UP && snake[head_position] != DOWN) {
                    dir = DOWN;
                }
                break;
            case 'a':
                if (snake[head_position] != LEFT && snake[head_position] != RIGHT) {
                    dir = LEFT;
                }
                break;
            case 'd':
                if (snake[head_position] != LEFT && snake[head_position] != RIGHT) {
                    dir = RIGHT;
                }
                break;
        }
    }
}

void game_over_handler() {
    system("clear");
    printf("Game over! You scored %d points!\n", score);
    printf("Press any key to exit.\n");
    stop_input();
}

void set_up_input() {
    // Set terminal to non-blocking
    system("stty -icanon -echo");
}

void stop_input() {
    // Reset terminal settings
    system("stty icanon echo");
}

int main() {
    srand(time(NULL));

    // Initialize variables
    snake[0] = RIGHT;
    head_position = ROWS * COLS / 2 + ROWS / 2;
    tail_position = head_position;

    for (int i = 0; i < 5; i++) {
        board[head_position - i] = SNAKE;
    }

    insert_food();

    // Set up input
    set_up_input();

    // Set up signal handler
    signal(SIGINT, game_over_handler);

    while (status == RUNNING) {
        // Clear console
        system("clear");

        // Move snake and print board
        move_snake();
        print_board();

        // Sleep for a certain amount of time
        usleep(speed);
    }

    // Stop input
    stop_input();

    return 0;
}