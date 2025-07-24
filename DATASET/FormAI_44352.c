//FormAI DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define NUM_PAIRS 8

void print_board(int board[BOARD_SIZE], int revealed[BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (revealed[i]) {
            printf("%d ", board[i]);
        } else {
            printf("* ");
        }
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int board[BOARD_SIZE] = {0};
    int revealed[BOARD_SIZE] = {0};
    int num_revealed = 0;
    int pairs_found = 0;

    // Generate board with pairs of numbers
    for (int i = 1; i <= NUM_PAIRS; i++) {
        int first_pos, second_pos;
        do {
            first_pos = rand() % BOARD_SIZE;
        } while (board[first_pos] != 0);
        do {
            second_pos = rand() % BOARD_SIZE;
        } while (board[second_pos] != 0 || second_pos == first_pos);
        board[first_pos] = i;
        board[second_pos] = i;
    }

    // Shuffle board
    for (int i = 0; i < BOARD_SIZE; i++) {
        int temp = board[i];
        int new_pos = rand() % BOARD_SIZE;
        board[i] = board[new_pos];
        board[new_pos] = temp;
    }

    // Main game loop
    while (pairs_found < NUM_PAIRS) {
        print_board(board, revealed);

        // Get user input
        int first_choice, second_choice;
        do {
            printf("Enter two positions (0-15) to reveal two cards: ");
            scanf("%d %d", &first_choice, &second_choice);
        } while (first_choice < 0 || first_choice >= BOARD_SIZE ||
                 second_choice < 0 || second_choice >= BOARD_SIZE ||
                 first_choice == second_choice ||
                 revealed[first_choice] || revealed[second_choice]);

        // Reveal cards and check for match
        revealed[first_choice] = 1;
        revealed[second_choice] = 1;
        num_revealed += 2;
        if (board[first_choice] == board[second_choice]) {
            pairs_found++;
        } else {
            // Not a match, hide cards again after a short delay
            print_board(board, revealed);
            printf("Not a match. Next player's turn.\n");
            int delay = 1000000;
            for (int i = 0; i < delay; i++) {}
            revealed[first_choice] = 0;
            revealed[second_choice] = 0;
            num_revealed -= 2;
        }
    }

    print_board(board, revealed);
    printf("Congratulations, you found all the pairs!\n");
    printf("Total number of moves: %d\n", num_revealed / 2);
    return 0;
}