//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 5
#define MAX_MOVES 10
#define SCORE_INCREMENT 10

int score = 0;
bool game_over = false;

typedef struct {
    int x, y;
} Point;

void clear_screen() {
    system("cls||clear");
}

void print_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[][BOARD_SIZE], Point *player_pos, Point *goal_pos) {
    srand(time(NULL));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    player_pos->x = rand() % BOARD_SIZE;
    player_pos->y = rand() % BOARD_SIZE;
    board[player_pos->x][player_pos->y] = 'P';

    do {
        goal_pos->x = rand() % BOARD_SIZE;
        goal_pos->y = rand() % BOARD_SIZE;
    } while (goal_pos->x == player_pos->x && goal_pos->y == player_pos->y);
    board[goal_pos->x][goal_pos->y] = 'G';
}

void move_player(char board[][BOARD_SIZE], Point *player_pos, Point *new_pos) {
    board[player_pos->x][player_pos->y] = '-';
    player_pos->x = new_pos->x;
    player_pos->y = new_pos->y;
    board[player_pos->x][player_pos->y] = 'P';
}

bool is_valid_move(Point *cur_pos, Point *new_pos) {
    if (new_pos->x < 0 || new_pos->x >= BOARD_SIZE || new_pos->y < 0 || new_pos->y >= BOARD_SIZE) {
        return false;
    }

    int x_diff = abs(cur_pos->x - new_pos->x);
    int y_diff = abs(cur_pos->y - new_pos->y);

    if (x_diff > 1 || y_diff > 1 || (x_diff == 0 && y_diff == 0)) {
        return false;
    }

    return true;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    Point player_pos, goal_pos, new_pos;
    int moves_left = MAX_MOVES;

    initialize_board(board, &player_pos, &goal_pos);

    printf("Find the Goal! You have %d moves. Press w/a/s/d to move.\n", moves_left);
    print_board(board);

    while (!game_over) {
        printf("Moves Left: %d\tScore: %d\n", moves_left, score);
        printf("Enter your move: ");
        char move = getchar();
        getchar();

        switch (move) {
            case 'w':
                new_pos.x = player_pos.x - 1;
                new_pos.y = player_pos.y;
                break;
            case 'a':
                new_pos.x = player_pos.x;
                new_pos.y = player_pos.y - 1;
                break;
            case 's':
                new_pos.x = player_pos.x + 1;
                new_pos.y = player_pos.y;
                break;
            case 'd':
                new_pos.x = player_pos.x;
                new_pos.y = player_pos.y + 1;
                break;
            default:
                continue;
        }

        if (!is_valid_move(&player_pos, &new_pos)) {
            printf("INVALID MOVE\n");
            continue;
        }

        moves_left--;
        move_player(board, &player_pos, &new_pos);

        if (player_pos.x == goal_pos.x && player_pos.y == goal_pos.y) {
            score += SCORE_INCREMENT;
            printf("CONGRATULATIONS! You found the goal. Score: %d\n", score);
            game_over = true;
            continue;
        }

        if (moves_left == 0) {
            printf("GAME OVER! Moves left: 0\tScore: %d\n", score);
            game_over = true;
            continue;
        }

        clear_screen();
        print_board(board);
    }

    return 0;
}