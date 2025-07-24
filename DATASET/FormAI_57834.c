//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum cell_type { UNOPENED, OPENED, MINE };

typedef struct {
    enum cell_type type;
    int adjacent_mines;
} cell_t;

void print_board(cell_t board[][10], int board_size) {
    printf("    ");
    for (int i = 0; i < board_size; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("   ");
    for (int i = 0; i < board_size; i++) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i < board_size; i++) {
        printf("%d| ", i);
        for (int j = 0; j < board_size; j++) {
            if (board[i][j].type == UNOPENED) {
                printf("# ");
            } else if (board[i][j].type == OPENED) {
                printf("%d ", board[i][j].adjacent_mines);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void place_mines(cell_t board[][10], int num_mines, int board_size) {
    int num_placed = 0;
    while (num_placed < num_mines) {
        int i = rand() % board_size;
        int j = rand() % board_size;
        if (board[i][j].type != MINE) {
            board[i][j].type = MINE;
            num_placed++;
        }
    }
}

void print_lose_message() {
    printf("Sorry, you hit a mine and lost the game.\n");
}

void print_win_message() {
    printf("Congratulations, you won the game!\n");
}

void open_cell(cell_t board[][10], int i, int j, int board_size) {
    if (i < 0 || i >= board_size || j < 0 || j >= board_size) {
        return;
    }
    if (board[i][j].type == MINE) {
        return;
    }
    if (board[i][j].type == OPENED) {
        return;
    }
    if (board[i][j].adjacent_mines > 0) {
        board[i][j].type = OPENED;
        return;
    }

    board[i][j].type = OPENED;
    open_cell(board, i - 1, j, board_size); // check north
    open_cell(board, i + 1, j, board_size); // check south
    open_cell(board, i, j - 1, board_size); // check west
    open_cell(board, i, j + 1, board_size); // check east
}

int main() {
    srand(time(NULL)); // seed RNG

    int board_size = 10;
    int num_mines = 10;
    cell_t board[board_size][board_size];
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            board[i][j].type = UNOPENED;
            board[i][j].adjacent_mines = 0;
        }
    }

    place_mines(board, num_mines, board_size);

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j].type == MINE) {
                continue;
            }
            if (i > 0 && board[i-1][j].type == MINE) {
                board[i][j].adjacent_mines++;
            }
            if (i < board_size - 1 && board[i+1][j].type == MINE) {
                board[i][j].adjacent_mines++;
            }
            if (j > 0 && board[i][j-1].type == MINE) {
                board[i][j].adjacent_mines++;
            }
            if (j < board_size - 1 && board[i][j+1].type == MINE) {
                board[i][j].adjacent_mines++;
            }
        }
    }

    printf("Welcome to Minesweeper!\n\n");
    int num_unopened = board_size * board_size - num_mines;
    while (num_unopened > 0) {
        print_board(board, board_size);

        int i, j;
        printf("Enter row and column (e.g. 1 2): ");
        scanf("%d %d", &i, &j);

        if (board[i][j].type == MINE) {
            print_board(board, board_size);
            print_lose_message();
            return 0;
        }

        open_cell(board, i, j, board_size);

        num_unopened = 0;
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                if (board[i][j].type == UNOPENED) {
                    num_unopened++;
                }
            }
        }
    }

    print_board(board, board_size);
    print_win_message();

    return 0;
}