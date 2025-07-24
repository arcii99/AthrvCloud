//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TURN_LIMIT 10

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
void initialize_board(int board[ROWS][COLS], int revealed[ROWS][COLS]);
void generate_pairs(int pairs[ROWS*COLS/2][2]);
void shuffle_pairs(int pairs[ROWS*COLS/2][2]);
int is_valid_choice(int choice_row, int choice_col, int revealed[ROWS][COLS]);
void reveal_card(int choice_row, int choice_col, int board[ROWS][COLS], int revealed[ROWS][COLS]);

int main() {
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int pairs[ROWS*COLS/2][2];
    int num_turns = 0, num_pairs_found = 0;

    srand(time(NULL));
    generate_pairs(pairs);
    shuffle_pairs(pairs);
    initialize_board(board, revealed);

    printf("Welcome to the Memory Game!\n");
    printf("Find all the matching pairs in %d turns or less.\n\n", TURN_LIMIT);

    while (num_pairs_found < ROWS*COLS/2 && num_turns < TURN_LIMIT) {
        print_board(board, revealed);

        int choice1_row, choice1_col, choice2_row, choice2_col;

        do {
            printf("Enter row and column (ex. 1 2): ");
            scanf("%d %d", &choice1_row, &choice1_col);
        } while (!is_valid_choice(choice1_row, choice1_col, revealed));
        reveal_card(choice1_row, choice1_col, board, revealed);

        print_board(board, revealed);

        do {
            printf("Enter row and column (ex. 1 2): ");
            scanf("%d %d", &choice2_row, &choice2_col);
        } while (!is_valid_choice(choice2_row, choice2_col, revealed));
        reveal_card(choice2_row, choice2_col, board, revealed);

        if (board[choice1_row][choice1_col] == board[choice2_row][choice2_col]) {
            printf("Match found!\n");
            num_pairs_found++;
        } else {
            printf("No match found.\n");
            revealed[choice1_row][choice1_col] = 0;
            revealed[choice2_row][choice2_col] = 0;
        }

        num_turns++;
    }

    if (num_pairs_found == ROWS*COLS/2) {
        printf("Congratulations! You found all the matching pairs.\n");
    } else {
        printf("Sorry, you ran out of turns. Game over.\n");
    }

    return 0;
}

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    printf("\n  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void initialize_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    int values[ROWS*COLS/2];

    for (int i = 0; i < ROWS*COLS/2; i++) {
        values[i] = i+1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;
        }
    }

    for (int pair = 0; pair < ROWS*COLS/2; pair++) {
        int row1, col1, row2, col2;
        do {
            row1 = rand() % ROWS;
            col1 = rand() % COLS;
        } while (board[row1][col1] != 0);

        do {
            row2 = rand() % ROWS;
            col2 = rand() % COLS;
        } while (board[row2][col2] != 0 || (row1 == row2 && col1 == col2));

        board[row1][col1] = values[pair];
        board[row2][col2] = values[pair];
    }
}

void generate_pairs(int pairs[ROWS*COLS/2][2]) {
    for (int i = 0; i < ROWS*COLS/2; i++) {
        pairs[i][0] = i+1;
        pairs[i][1] = i+1;
    }
}

void shuffle_pairs(int pairs[ROWS*COLS/2][2]) {
    for (int i = 0; i < ROWS*COLS/2-1; i++) {
        int j = rand() % (ROWS*COLS/2-i-1) + i+1;
        int temp1 = pairs[i][0];
        int temp2 = pairs[i][1];
        pairs[i][0] = pairs[j][0];
        pairs[i][1] = pairs[j][1];
        pairs[j][0] = temp1;
        pairs[j][1] = temp2;
    }
}

int is_valid_choice(int choice_row, int choice_col, int revealed[ROWS][COLS]) {
    if (choice_row < 0 || choice_row >= ROWS || choice_col < 0 || choice_col >= COLS) {
        printf("Choice out of bounds. Try again.\n");
        return 0;
    } else if (revealed[choice_row][choice_col]) {
        printf("Card already revealed. Try again.\n");
        return 0;
    } else {
        return 1;
    }
}

void reveal_card(int choice_row, int choice_col, int board[ROWS][COLS], int revealed[ROWS][COLS]) {
    revealed[choice_row][choice_col] = 1;
    printf("Card revealed: %d\n", board[choice_row][choice_col]);
}