//FormAI DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define TOTAL_CELLS (BOARD_SIZE * BOARD_SIZE)

void init_board(int board[]);
void print_board(int board[], int revealed[]);
int flip_cell(int board[], int revealed[], int cell_index);

int main() {
    int board[TOTAL_CELLS];
    int revealed[TOTAL_CELLS] = {0};
    int flipped_cell_count = 0;

    srand(time(NULL));
    init_board(board);

    while (flipped_cell_count < TOTAL_CELLS) {
        print_board(board, revealed);

        int cell_index;
        do {
            printf("Choose a cell to flip (0-15): ");
            scanf("%d", &cell_index);
        } while (cell_index < 0 || cell_index >= TOTAL_CELLS);

        if (flip_cell(board, revealed, cell_index)) {
            flipped_cell_count += 2;
            printf("Match found!\n");
        } else {
            printf("No match found...\n");
        }
    }

    printf("Congratulations, you win!\n");
    return 0;
}

void init_board(int board[]) {
    int shuffled[TOTAL_CELLS];

    for (int i = 0; i < TOTAL_CELLS; i++) {
        board[i] = i / 2;
        shuffled[i] = i / 2;
    }

    for (int i = TOTAL_CELLS - 1; i >= 0; i--) {
        int j = rand() % (i + 1);

        int temp = shuffled[i];
        shuffled[i] = shuffled[j];
        shuffled[j] = temp;
    }

    for (int i = 0; i < TOTAL_CELLS; i++) {
        board[i] = shuffled[i];
    }
}

void print_board(int board[], int revealed[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = i * BOARD_SIZE + j;

            if (revealed[index]) {
                printf("%2d ", board[index]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int flip_cell(int board[], int revealed[], int cell_index) {
    if (revealed[cell_index]) {
        printf("Cell already flipped!\n");
        return 0;
    }

    revealed[cell_index] = 1;

    for (int i = 0; i < TOTAL_CELLS; i++) {
        if (i == cell_index || !revealed[i]) {
            continue;
        }

        if (board[i] == board[cell_index]) {
            revealed[i] = 2;
            return 1;
        }
    }

    return 0;
}