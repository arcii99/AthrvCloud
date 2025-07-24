//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void print_board(char board[]) {
    printf("       MEMORY GAME        \n");
    printf("--------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 4 == 0) printf("|");
        if (board[i] == 'x') {
            printf("  ?");
        } else {
            printf("  %c", board[i]);
        }
        if (i % 4 == 3) printf("  |\n");
    }
    printf("--------------------------\n");
}

int main() {
    char board[BOARD_SIZE] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
                              'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    int num_pairs = BOARD_SIZE / 2;
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        int j = rand() % BOARD_SIZE;
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
    // Start the game
    int score = 0;
    while (score < num_pairs) {
        print_board(board);
        int choice1, choice2;
        do {
            printf("Enter two distinct numbers [0-15] to reveal their values.\n");
            scanf("%d %d", &choice1, &choice2);
            if (choice1 < 0 || choice1 >= BOARD_SIZE || choice2 < 0 || choice2 >= BOARD_SIZE) {
                printf("Invalid choice. Try again.\n");
                continue;
            }
            if (choice1 == choice2) {
                printf("You cannot choose the same number twice. Try again.\n");
                continue;
            }
            if (board[choice1] == 'x' || board[choice2] == 'x') {
                break;
            }
            printf("Both numbers have already been revealed. Try again.\n");
        } while (1);

        if (board[choice1] == board[choice2]) {
            printf("You found a pair!\n");
            board[choice1] = board[choice2] = 'x';
            score++;
        } else {
            printf("Sorry, those numbers do not match.\n");
        }
    }
    printf("Congratulations! You found all the pairs.\n");
    return 0;
}