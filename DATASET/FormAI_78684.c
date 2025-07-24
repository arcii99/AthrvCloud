//FormAI DATASET v1.0 Category: Robot movement control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_MOVES 50

int board[BOARD_SIZE][BOARD_SIZE];

struct Position {
    int x;
    int y;
};

struct Move {
    int x;
    int y;
};

struct Robot {
    struct Position position;
    struct Move moves[MAX_MOVES];
    int num_moves;
};

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void generate_moves(struct Robot *robot) {
    robot->num_moves = 0;
    srand(time(NULL));
    for (int i = 0; i < MAX_MOVES; i++) {
        struct Move move;
        move.x = rand() % 3 - 1;
        move.y = rand() % 3 - 1;
        robot->moves[i] = move;
        robot->num_moves++;
    }
}

void move_robot(struct Robot *robot) {
    for (int i = 0; i < robot->num_moves; i++) {
        struct Move move = robot->moves[i];
        int new_x = robot->position.x + move.x;
        int new_y = robot->position.y + move.y;
        if (new_x >= 0 && new_x < BOARD_SIZE && new_y >= 0 && new_y < BOARD_SIZE) {
            board[robot->position.x][robot->position.y] = 0;
            board[new_x][new_y] = 1;
            robot->position.x = new_x;
            robot->position.y = new_y;
        }
        printf("Robot is at: (%d,%d)\n", robot->position.x, robot->position.y);
        print_board();
    }
}

int main() {
    struct Robot robot;
    robot.position.x = rand() % BOARD_SIZE;
    robot.position.y = rand() % BOARD_SIZE;
    board[robot.position.x][robot.position.y] = 1;
    printf("Robot is at: (%d,%d)\nInitial board:\n", robot.position.x, robot.position.y);
    print_board();
    generate_moves(&robot);
    move_robot(&robot);
}