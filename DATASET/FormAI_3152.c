//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6
#define MAX_MOVES 20

void print_board(int board[][BOARD_SIZE], int num_moves);
void init_board(int board[][BOARD_SIZE]);
void shuffle(int array[], int size);
void create_moves(int array[], int size);

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    int moves[MAX_MOVES];
    int row, col, move_num, num_moves, match_found;

    init_board(board);
    print_board(board, 0);

    create_moves(moves, MAX_MOVES);
    shuffle(moves, MAX_MOVES);

    for (move_num = 0, num_moves = 0; num_moves < MAX_MOVES; move_num = (move_num + 1) % MAX_MOVES) {
        printf("\nEnter row and column: ");
        scanf("%d %d", &row, &col);

        if (row >= BOARD_SIZE || col >= BOARD_SIZE || row < 0 || col < 0) {
            printf("Invalid move! Must be within board range.\n");
            continue;
        }

        if (board[row][col] != -1) {
            printf("Invalid move! Square has already been revealed.\n");
            continue;
        }
        
        board[row][col] = moves[move_num];
        print_board(board, ++num_moves);

        if (num_moves % 2 == 0) {
            match_found = 0;

            for (int r = 0; r < BOARD_SIZE; r++) {
                for (int c = 0; c < BOARD_SIZE; c++) {
                    if (board[r][c] == board[row][col] && !(r == row && c == col)) {
                        printf("Match found!\n");
                        board[r][c] = moves[move_num] = -2;
                        match_found = 1;
                        break;
                    }
                }
                if (match_found) {
                    break;
                }
            }
            if(!match_found){
              printf("No match found.\n");
            }
        }

        if (num_moves == MAX_MOVES) {
            printf("No moves left! Game over.\n");
            return 0;
        }
    }

    return 0;
}

// Initialize board with -1 to indicate unrevealed squares
void init_board(int board[][BOARD_SIZE]) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c] = -1;
        }
    }
}

// Print current board state
void print_board(int board[][BOARD_SIZE], int num_moves) {
    printf("\n\n");

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == -1) {
                printf(" - ");
            }
            else {
                printf(" %d ", board[r][c]);
            }
        }
        printf("\n");
    }

    printf("\n\nNumber of moves: %d", num_moves);
}

// Shuffle an array of integers using Fisher-Yates algorithm
void shuffle(int array[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Create array of moves (pairs of matching integers)
void create_moves(int array[], int size) {
    for (int i = 0; i < size; i += 2) {
        array[i] = array[i + 1] = i / 2 + 1;
    }
}