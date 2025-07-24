//FormAI DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_CARDS (BOARD_SIZE * BOARD_SIZE) / 2

typedef struct {
    int row;
    int col;
} coordinates;

typedef struct {
    int val;
    int matched;
} card;

int check_board(card board[][BOARD_SIZE]) {
    int num_matched = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col].matched) {
                num_matched++;
            }
        }
    }
    return num_matched == NUM_CARDS * 2;
}

void print_board(card board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col].matched) {
                printf("  ");
            } else {
                printf("%d ", board[row][col].val);
            }
        }
        printf("\n");
    }
}

void play_game() {
    int num_moves = 0;
    card board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 1; i <= NUM_CARDS; i++) {
        int card1_row, card1_col, card2_row, card2_col;
        do {
            card1_row = rand() % BOARD_SIZE;
            card1_col = rand() % BOARD_SIZE;
        } while (board[card1_row][card1_col].val != 0);
        board[card1_row][card1_col].val = i;
        do {
            card2_row = rand() % BOARD_SIZE;
            card2_col = rand() % BOARD_SIZE;
        } while (board[card2_row][card2_col].val != 0 || (card2_row == card1_row && card2_col == card1_col));
        board[card2_row][card2_col].val = i;
    }
    while (!check_board(board)) {
        system("clear");
        printf("Moves: %d\n", num_moves);
        print_board(board);
        printf("Enter first card coordinates (row column): ");
        coordinates card1_coords = {0};
        scanf("%d %d", &card1_coords.row, &card1_coords.col);
        while (card1_coords.row < 1 || card1_coords.row > BOARD_SIZE || card1_coords.col < 1 || card1_coords.col > BOARD_SIZE || board[card1_coords.row - 1][card1_coords.col - 1].matched) {
            printf("Invalid coordinates, please enter again: ");
            scanf("%d %d", &card1_coords.row, &card1_coords.col);
        }
        printf("Enter second card coordinates (row column): ");
        coordinates card2_coords = {0};
        scanf("%d %d", &card2_coords.row, &card2_coords.col);
        while (card2_coords.row < 1 || card2_coords.row > BOARD_SIZE || card2_coords.col < 1 || card2_coords.col > BOARD_SIZE || board[card2_coords.row - 1][card2_coords.col - 1].matched || (card1_coords.row == card2_coords.row && card1_coords.col == card2_coords.col)) {
            printf("Invalid coordinates, please enter again: ");
            scanf("%d %d", &card2_coords.row, &card2_coords.col);
        }
        system("clear");
        num_moves++;
        if (board[card1_coords.row - 1][card1_coords.col - 1].val == board[card2_coords.row - 1][card2_coords.col - 1].val) {
            printf("Match! %d moves.", num_moves);
            board[card1_coords.row - 1][card1_coords.col - 1].matched = 1;
            board[card2_coords.row - 1][card2_coords.col - 1].matched = 1;
        } else {
            printf("No match.\n");
        }
    }
    printf("Congratulations! You won in %d moves.\n", num_moves);
}

int main() {
    srand(time(NULL));
    printf("Welcome to Memory Game!\n");
    char play_again = 'y';
    while (play_again == 'y' || play_again == 'Y') {
        play_game();
        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &play_again);
        while (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N') {
            printf("Invalid response, please enter again: ");
            scanf(" %c", &play_again);
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}