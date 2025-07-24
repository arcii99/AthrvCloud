//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE];
int backup_board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

void generate_board();
void reset_board();
void print_board();
int select_card();
int is_game_over();

int main() {
    srand(time(NULL));
    generate_board();
    int card1_pos, card2_pos, card1_value, card2_value, score = 0;
    while (!is_game_over()) {
        reset_board();
        print_board();
        printf("Score: %d\n", score);
        printf("Select first card: ");
        card1_pos = select_card();
        card1_value = board[card1_pos / BOARD_SIZE][card1_pos % BOARD_SIZE];
        revealed[card1_pos / BOARD_SIZE][card1_pos % BOARD_SIZE] = 1;
        reset_board();
        print_board();
        printf("Score: %d\n", score);
        printf("Select second card: ");
        card2_pos = select_card();
        card2_value = board[card2_pos / BOARD_SIZE][card2_pos % BOARD_SIZE];
        revealed[card2_pos / BOARD_SIZE][card2_pos % BOARD_SIZE] = 1;
        reset_board();
        print_board();
        if (card1_value == card2_value) {
            printf("Match found!\n");
            score++;
            board[card1_pos / BOARD_SIZE][card1_pos % BOARD_SIZE] = 0;
            board[card2_pos / BOARD_SIZE][card2_pos % BOARD_SIZE] = 0;
            revealed[card1_pos / BOARD_SIZE][card1_pos % BOARD_SIZE] = 2;
            revealed[card2_pos / BOARD_SIZE][card2_pos % BOARD_SIZE] = 2;
        } else {
            printf("No match\n");
        }
    }
    printf("Game over! Your final score is %d\n", score);
    return 0;
}

void generate_board() {
    int values[BOARD_SIZE*BOARD_SIZE/2];
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE/2; i++) {
        values[i] = i+1;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int random_index = rand() % (BOARD_SIZE*BOARD_SIZE/2);
            board[i][j] = values[random_index];
            backup_board[i][j] = values[random_index];
            values[random_index] = values[BOARD_SIZE*BOARD_SIZE/2-1];
            BOARD_SIZE*BOARD_SIZE/2-1;
        }
    }
}

void reset_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = revealed[i][j] == 2 ? backup_board[i][j] : 0;
        }
    }
}

void print_board() {
    printf("    1   2   3   4  \n");
    printf("  +---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j] == 2) {
                printf(" %d |", backup_board[i][j]);
            } else if (revealed[i][j] == 1) {
                printf(" * |");
            } else {
                printf("   |");
            }
        }
        printf("\n  +---+---+---+---+\n");
    }
}

int select_card() {
    int row, column;
    do {
        scanf("%d %d", &row, &column);
        row--;
        column--;
        if (row >= BOARD_SIZE || column >= BOARD_SIZE) {
            printf("Invalid position\n");
            continue;
        } else if (revealed[row][column]) {
            printf("Card already revealed\n");
            continue;
        }
        break;
    } while (1);
    return row * BOARD_SIZE + column;
}

int is_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}