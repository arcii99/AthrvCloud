//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_FOOD 20

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    Position position;
    bool is_super;
} Food;

typedef struct {
    Position position;
    int score;
    bool is_super;
} PacMan;

typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
} Direction;

void print_board(Food foods[], int num_foods, PacMan *pacman) {
    char board[ROWS][COLS] = {{' '}};
    for (int i = 0; i < num_foods; i++) {
        if (foods[i].is_super) {
            board[foods[i].position.row][foods[i].position.col] = 'O';
        } else {
            board[foods[i].position.row][foods[i].position.col] = '.';
        }
    }
    board[pacman->position.row][pacman->position.col] = 'P';
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool can_go_to(PacMan *pacman, Direction dir) {
    switch (dir) {
        case LEFT:
            return pacman->position.col > 0;
        case RIGHT:
            return pacman->position.col < COLS - 1;
        case UP:
            return pacman->position.row > 0;
        case DOWN:
            return pacman->position.row < ROWS - 1;
        default:
            return false;
    }
}

void move_pacman(PacMan *pacman, Direction dir) {
    switch (dir) {
        case LEFT:
            pacman->position.col--;
            break;
        case RIGHT:
            pacman->position.col++;
            break;
        case UP:
            pacman->position.row--;
            break;
        case DOWN:
            pacman->position.row++;
            break;
    }
}

bool is_same_position(Position p1, Position p2) {
    return p1.row == p2.row && p1.col == p2.col;
}

bool is_food_under_pacman(PacMan *pacman, Food foods[], int num_foods) {
    for (int i = 0; i < num_foods; i++) {
        if (is_same_position(pacman->position, foods[i].position)) {
            foods[i].is_super = false;
            pacman->score++;
            return true;
        }
    }
    return false;
}

void generate_foods(Food foods[], int num_foods) {
    for (int i = 0; i < num_foods; i++) {
        foods[i].position.row = rand() % ROWS;
        foods[i].position.col = rand() % COLS;
        foods[i].is_super = rand() % 2 == 0;
    }
}

bool is_game_over(Food foods[], int num_foods, PacMan *pacman) {
    for (int i = 0; i < num_foods; i++) {
        if (is_same_position(pacman->position, foods[i].position)) {
            if (foods[i].is_super) {
                return false;
            } else {
                return pacman->score < MAX_FOOD;
            }
        }
    }
    return pacman->score < MAX_FOOD;
}

void play_game() {
    srand(time(0)); // seed the random number generator
    Food foods[MAX_FOOD];
    generate_foods(foods, MAX_FOOD);
    PacMan pacman = {{0, 0}, 0, false};
    while (is_game_over(foods, MAX_FOOD, &pacman)) {
        print_board(foods, MAX_FOOD, &pacman);
        printf("Score: %d\n", pacman.score);
        printf("Where do you want to go (L/R/U/D)? ");
        char input;
        scanf(" %c", &input);
        Direction dir;
        switch (input) {
            case 'L':
                dir = LEFT;
                break;
            case 'R':
                dir = RIGHT;
                break;
            case 'U':
                dir = UP;
                break;
            case 'D':
                dir = DOWN;
                break;
            default:
                printf("Invalid input\n");
                continue;
        }
        if (can_go_to(&pacman, dir)) {
            move_pacman(&pacman, dir);
            if (!pacman.is_super) {
                pacman.is_super = is_food_under_pacman(&pacman, foods, MAX_FOOD);
            }
        } else {
            printf("Can't go there!\n");
        }
    }
    printf("Game over! Final score: %d\n", pacman.score);
}

int main() {
    play_game();
    return 0;
}