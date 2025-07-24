//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define WIN_TILE 2048

int board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int i, j;
    srand((unsigned)time(NULL));
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    int random_num1 = rand() % BOARD_SIZE;
    int random_num2 = rand() % BOARD_SIZE;
    board[random_num1][random_num2] = (rand()%2 + 1)*2;
}

void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("     ");
            }
            else {
                printf("%-5d", board[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
}

int check_game_over() {
    int i, j, count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
            if (j == BOARD_SIZE-1 && i != BOARD_SIZE-1) {
                if (board[i][j] == board[i+1][0]) {
                    count++;
                }
            }
            else if (j != BOARD_SIZE-1) {
                if (board[i][j] == board[i][j+1]) {
                    count++;
                }
                if (board[i][j] == board[i+1][j]) {
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void add_new_tile() {
    int i, j;
    int random_num1 = rand() % BOARD_SIZE;
    int random_num2 = rand() % BOARD_SIZE;
    while(board[random_num1][random_num2] != 0) {
        random_num1 = rand() % BOARD_SIZE;
        random_num2 = rand() % BOARD_SIZE;
    }
    int value = (rand()%2 + 1)*2;
    board[random_num1][random_num2] = value;
}

void shift_tiles_left() {
    int i, j, k;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                for (k = j+1; k < BOARD_SIZE; k++) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void merge_tiles_left() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE-1; j++) {
            if (board[i][j] == board[i][j+1] && board[i][j] != 0) {
                board[i][j] *= 2;
                board[i][j+1] = 0;
            }
        }
    }
}

void transpose() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = i; j < BOARD_SIZE; j++) {
            int temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
    }
}

void swap_rows() {
    int i, j;
    for (j = 0; j < BOARD_SIZE; j++) {
        for (i = 0; i < BOARD_SIZE/2; i++) {
            int temp = board[i][j];
            board[i][j] = board[BOARD_SIZE-1-i][j];
            board[BOARD_SIZE-1-i][j] = temp;
        }
    }
}

void shift_tiles_up() {
    transpose();
    shift_tiles_left();
    transpose();
}

void shift_tiles_down() {
    transpose();
    swap_rows();
    shift_tiles_left();
    swap_rows();
    transpose();
}

void merge_tiles_up() {
    transpose();
    merge_tiles_left();
    transpose();
}

void merge_tiles_down() {
    transpose();
    swap_rows();
    merge_tiles_left();
    swap_rows();
    transpose();
}

void move_left() {
    shift_tiles_left();
    merge_tiles_left();
    shift_tiles_left();
}

void move_right() {
    transpose();
    shift_tiles_left();
    merge_tiles_left();
    shift_tiles_left();
    transpose();
}

void move_up() {
    shift_tiles_up();
    merge_tiles_up();
    shift_tiles_up();
}

void move_down() {
    shift_tiles_down();
    merge_tiles_down();
    shift_tiles_down();
}

void play_game() {
    int game_over = 0;
    int score = 0;
    initialize_board();
    printf("\nWelcome to 2048!\n");
    printf("How to play: Use the arrow keys to move the tiles. Combine tiles with the same number to create new numbers.\n");
    while (!game_over) {
        printf("\nScore: %d", score);
        print_board();
        printf("\nUse arrow keys to move the tiles. Press 'q' to quit.\n");
        char move = getchar();
        while (move == '\n') {
            move = getchar();
        }
        if (move == 'q') {
            break;
        }
        if (move == 'a') {
            move_left();
        }
        else if (move == 'd') {
            move_right();
        }
        else if (move == 'w') {
            move_up();
        }
        else if (move == 's') {
            move_down();
        }
        else {
            printf("\nInvalid move! Use arrow keys to move.\n");
            continue;
        }
        add_new_tile();
        if (check_game_over()) {
            game_over = 1;
            printf("\nGame over! Your score: %d\n", score);
            break;
        }
        int i, j;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == WIN_TILE) {
                    printf("\nCongratulations! You have reached %d!\n", WIN_TILE);
                    game_over = 1;
                    break;
                }
                if (board[i][j] != 0) {
                    score += board[i][j];
                }
            }
        }
    }
}

int main() {
    play_game();
    return 0;
}