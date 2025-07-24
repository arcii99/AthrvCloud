//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 11
#define MAX_BOMB_COUNT 15

int board[BOARD_SIZE][BOARD_SIZE];

void print_board(bool show_bombs) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (show_bombs && board[y][x] == -1) {
                printf("B ");
            } else if (board[y][x] == 0) {
                printf(". ");
            } else {
                printf("%d ", board[y][x]);
            }
        }
        printf("\n");
    }
}

void generate_bombs() {
    int bombs_placed = 0;
    while (bombs_placed < MAX_BOMB_COUNT) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[y][x] == 0) {
            board[y][x] = -1;
            bombs_placed++;
        }
    }
}

void update_numbers() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (board[y][x] != -1) {
                int nearby_bombs = 0;
                for (int y2 = y - 1; y2 <= y + 1; y2++) {
                    for (int x2 = x - 1; x2 <= x + 1; x2++) {
                        if (y2 >= 0 && y2 < BOARD_SIZE && x2 >= 0 && x2 < BOARD_SIZE) {
                            if (board[y2][x2] == -1) {
                                nearby_bombs++;
                            }
                        }
                    }
                }
                board[y][x] = nearby_bombs;
            }
        }
    }
}

int main() {
    srand(time(0));
    printf("Welcome to Minefield!\n\n");
    printf("Rules:\n");
    printf(" - You're in a minefield, you have to find all the bombs to win\n");
    printf(" - The number in each square tells you how many bombs are adjacent to it\n");
    printf(" - To uncover a square, enter its coordinates (line, column)\n");
    printf(" - If you uncover a bomb, you lose!\n\n");
    printf("Let's play!\n\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = 0;
        }
    }
    generate_bombs();
    update_numbers();
    print_board(false);
    while (true) {
        int x, y;
        printf("\nEnter the coordinates of the square you want to uncover (x y): ");
        scanf("%d %d", &x, &y);
        if (board[y][x] == -1) {
            printf("\nGame over!\n");
            print_board(true);
            break;
        } else {
            board[y][x] = -2;
            print_board(false);
            bool all_uncovered = true;
            for (int y2 = 0; y2 < BOARD_SIZE; y2++) {
                for (int x2 = 0; x2 < BOARD_SIZE; x2++) {
                    if (board[y2][x2] != -1 && board[y2][x2] != -2) {
                        all_uncovered = false;
                        break;
                    }
                }
                if (!all_uncovered) {
                    break;
                }
            }
            if (all_uncovered) {
                printf("\nYou win!\n");
                print_board(true);
                break;
            }
        }
    }
    return 0;
}