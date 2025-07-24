//FormAI DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_REVEALS 20

int board[BOARD_SIZE];
int revealed[BOARD_SIZE];
int num_reveals;

void init_board() {
    // Initialize board with pairs of random numbers
    int nums[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 8; i++) {
        int val = nums[i];
        int idx1, idx2;
        do {
            idx1 = rand() % BOARD_SIZE;
        } while (board[idx1] != -1);
        do {
            idx2 = rand() % BOARD_SIZE;
        } while (board[idx2] != -1 || idx2 == idx1);
        board[idx1] = val;
        board[idx2] = val;
    }
}

void print_board() {
    // Display the board with revealed numbers
    int row = 0;
    printf("   0 1 2 3\n");
    printf("  ---------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 4 == 0) {
            printf("%d |", row++);
        }
        if (revealed[i]) {
            printf(" %d", board[i]);
        } else {
            printf(" *");
        }
        if (i % 4 == 3) {
            printf("\n");
        }
    }
    printf("\n");
}

void reveal(int idx) {
    // Reveal the number at the given index
    revealed[idx] = 1;
    num_reveals++;
}

int get_input() {
    // Get user input, verifying that it is within bounds
    int r, c;
    do {
        printf("Enter row and column (space-separated): ");
        scanf("%d %d", &r, &c);
        if (r < 0 || r > 3 || c < 0 || c > 3) {
            printf("Invalid input! Row and column must be within bounds.\n");
        } else {
            int idx = r * 4 + c;
            if (revealed[idx]) {
                printf("That square has already been revealed! Try again.\n");
            } else {
                return idx;
            }
        }
    } while (1);
}

void check_match(int idx1, int idx2) {
    // Check if the values at the given indices match
    if (board[idx1] == board[idx2]) {
        printf("Good match!\n");
    } else {
        printf("Sorry, those don't match.\n");
        revealed[idx1] = 0;
        revealed[idx2] = 0;
    }
}

int play_game() {
    // Main game loop
    init_board();
    num_reveals = 0;
    printf("Welcome to Memory Game! You have %d chances to reveal all the pairs.\n", MAX_REVEALS);

    while (num_reveals < MAX_REVEALS) {
        print_board();
        int idx1 = get_input();
        reveal(idx1);
        print_board();
        int idx2 = get_input();
        reveal(idx2);
        check_match(idx1, idx2);
        if (num_reveals == MAX_REVEALS) {
            printf("Sorry, you ran out of chances. Good luck next time!\n");
            return 0;
        }
        if (board[idx1] == board[idx2]) {
            if (num_reveals == BOARD_SIZE) {
                printf("Congratulations! You solved the game!\n");
                return 1;
            }
        }
    }
}

int main() {
    srand((unsigned) time(NULL));
    while (play_game());
    return 0;
}