//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_FRUITS 5

typedef enum {EMPTY, APPLE, BANANA, ORANGE, PEAR, STRAWBERRY} fruit_type;
typedef enum {LEFT, RIGHT, UP, DOWN} direction;

fruit_type fruits[] = {APPLE, BANANA, ORANGE, PEAR, STRAWBERRY};

int fruits_remaining[MAX_FRUITS] = {0};

int board[ROWS][COLS] = {EMPTY};

int score = 0;

void initialize_board() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
    for (i = 0; i < MAX_FRUITS; i++) {
        int fruit = fruits[rand() % 5];
        int qty = (rand() % 3) + 1;
        fruits_remaining[i] = qty;
        while (qty > 0) {
            int row = rand() % ROWS;
            int col = rand() % COLS;
            if (board[row][col] == EMPTY) {
                board[row][col] = fruit;
                qty--;
            }
        }
    }
}

void print_board() {
    int i, j;
    printf("\n\nScore: %d\n\n", score);
    printf("   ");
    for (j = 0; j < COLS; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < COLS; j++) {
            switch(board[i][j]) {
                case EMPTY: printf(". "); break;
                case APPLE: printf("A "); break;
                case BANANA: printf("B "); break;
                case ORANGE: printf("O "); break;
                case PEAR: printf("P "); break;
                case STRAWBERRY: printf("S "); break;
            }
        }
        printf("\n");
    }
}

void move_fruit(int row, int col, direction dir) {
    int new_row = row, new_col = col;
    switch (dir) {
        case LEFT: new_col--; break;
        case RIGHT: new_col++; break;
        case UP: new_row--; break;
        case DOWN: new_row++; break;
    }
    if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS && board[new_row][new_col] == EMPTY) {
        board[new_row][new_col] = board[row][col];
        board[row][col] = EMPTY;
    }
}

void move_all_fruits(direction dir) {
    int i, j;
    switch (dir) {
        case LEFT:
            for (i = 0; i < ROWS; i++) {
                for (j = 1; j < COLS; j++) {
                    if (board[i][j] != EMPTY) {
                        move_fruit(i, j, LEFT);
                    }
                }
            }
            break;
        case RIGHT:
            for (i = 0; i < ROWS; i++) {
                for (j = COLS - 2; j >= 0; j--) {
                    if (board[i][j] != EMPTY) {
                        move_fruit(i, j, RIGHT);
                    }
                }
            }
            break;
        case UP:
            for (i = 1; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    if (board[i][j] != EMPTY) {
                        move_fruit(i, j, UP);
                    }
                }
            }
            break;
        case DOWN:
            for (i = ROWS - 2; i >= 0; i--) {
                for (j = 0; j < COLS; j++) {
                    if (board[i][j] != EMPTY) {
                        move_fruit(i, j, DOWN);
                    }
                }
            }
            break;
    }
}

int count_fruits(int fruit) {
    int i, j, count = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == fruit) {
                count++;
            }
        }
    }
    return count;
}

void process_move(int row, int col) {
    int fruit = board[row][col];
    int qty = fruits_remaining[fruit];
    if (qty > 0) {
        board[row][col] = EMPTY;
        fruits_remaining[fruit]--;
        score += 10;
    }
    if (fruits_remaining[fruit] == 0) {
        int i, j;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == fruit) {
                    board[i][j] = EMPTY;
                }
            }
        }
    }
}

int main() {
    int quit = 0;
    char command;
    initialize_board();
    while (!quit) {
        print_board();
        printf("\n");
        printf("Enter command (m <row> <col> <dir>, q): ");
        scanf("%c", &command);
        if (command == 'q') {
            printf("Final score: %d\n", score);
            quit = 1;
        } else if (command == 'm') {
            int row, col;
            direction dir;
            scanf("%d %d %d", &row, &col, &dir);
            row--; col--;
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                process_move(row, col);
                move_all_fruits(dir);
            }
        }
        fflush(stdin);
        usleep(500000);
    }
    return 0;
}