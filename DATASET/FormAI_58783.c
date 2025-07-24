//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];
int allowed_moves[BOARD_SIZE * BOARD_SIZE];
int num_allowed_moves;

void init_board() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }
}

void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void generate_random_number(int *i, int *j) {
    *i = rand() % BOARD_SIZE;
    *j = rand() % BOARD_SIZE;
}

void place_number_on_board(int number) {
    int i, j;
    do {
        generate_random_number(&i, &j);
    } while (board[i][j] != -1);
    board[i][j] = number;
}

void initialize_allowed_moves() {
    int i;
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        allowed_moves[i] = i;
    }
}

void shuffle_allowed_moves() {
    int i, temp, index;
    for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        index = rand() % (BOARD_SIZE * BOARD_SIZE);
        temp = allowed_moves[index];
        allowed_moves[index] = allowed_moves[i];
        allowed_moves[i] = temp;
    }
    num_allowed_moves = BOARD_SIZE * BOARD_SIZE;
}

int get_input() {
    int input;
    printf("Enter a number between 1 and %d: ", BOARD_SIZE * BOARD_SIZE);
    scanf("%d", &input);
    return input;
}

int is_allowed_move(int input) {
    int i;
    for (i = 0; i < num_allowed_moves; i++) {
        if (input == allowed_moves[i]) {
            return 1;
        }
    }
    return 0;
}

void remove_allowed_move(int input) {
    int i, index;
    for (i = 0; i < num_allowed_moves; i++) {
        if (allowed_moves[i] == input) {
            index = i;
            break;
        }
    }
    for (i = index; i < num_allowed_moves - 1; i++) {
        allowed_moves[i] = allowed_moves[i + 1];
    }
    num_allowed_moves--;
}

int check_horizontal_win() {
    int i, j, win;
    for (i = 0; i < BOARD_SIZE; i++) {
        win = 1;
        for (j = 0; j < BOARD_SIZE - 1; j++) {
            if (board[i][j] == -1 || board[i][j + 1] == -1 || board[i][j] > board[i][j + 1]) {
                win = 0;
                break;
            }
        }
        if (win) {
            return 1;
        }
    }
    return 0;
}

int check_vertical_win() {
    int i, j, win;
    for (j = 0; j < BOARD_SIZE; j++) {
        win = 1;
        for (i = 0; i < BOARD_SIZE - 1; i++) {
            if (board[i][j] == -1 || board[i + 1][j] == -1 || board[i][j] > board[i + 1][j]) {
                win = 0;
                break;
            }
        }
        if (win) {
            return 1;
        }
    }
    return 0;
}

void play_game() {
    int i, j, input, move_number = 0;
    initialize_allowed_moves();
    shuffle_allowed_moves();
    for (i = 1; i <= BOARD_SIZE * BOARD_SIZE; i++) {
        place_number_on_board(allowed_moves[num_allowed_moves - 1]);
        remove_allowed_move(allowed_moves[num_allowed_moves - 1]);
    }
    print_board();
    while (1) {
        input = get_input();
        if (is_allowed_move(input)) {
            for (i = 0; i < BOARD_SIZE; i++) {
                for (j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == -1 || board[i][j] == input) {
                        board[i][j] = input;
                    } else {
                        printf("%d ", board[i][j]);
                    }
                }
                printf("\n");
            }
            if (check_horizontal_win() || check_vertical_win()) {
                printf("Congratulations! You have won in %d moves.\n", move_number);
                break;
            }
            move_number++;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the C Memory Game!\n");
    printf("The goal of the game is to remember the board positions and place numbers in the correct order.\n");
    init_board();
    play_game();

    return 0;
}