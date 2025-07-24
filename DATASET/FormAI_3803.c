//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16 // The size of the board
#define NUM_PAIRS SIZE / 2 // The number of pairs in the game

int board[SIZE];
int revealed[SIZE];
int first_card = -1;
int second_card = -1;

void init_game()
{
    int pair_count = 0;
    while (pair_count < NUM_PAIRS) {
        int value = rand() % 100 + 1;
        int pos1 = rand() % SIZE;
        int pos2 = rand() % SIZE;

        if (board[pos1] == 0 && board[pos2] == 0 && pos1 != pos2) {
            board[pos1] = value;
            board[pos2] = value;
            pair_count++;
        }
    }
}

void print_board()
{
    printf("\n\n");
    printf("Memory Game\n\n");
    for (int i = 0; i < SIZE; i++) {
        if (revealed[i]) {
            printf(" %2d ", board[i]);
        } else {
            printf(" ???");
        }

        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

void reveal_card(int pos)
{
    revealed[pos] = 1;
}

void hide_cards()
{
    revealed[first_card] = 0;
    revealed[second_card] = 0;
}

int check_match()
{
    return board[first_card] == board[second_card];
}

int check_win()
{
    for (int i = 0; i < SIZE; i++) {
        if (revealed[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    srand(time(NULL)); // Seed random number generator
    init_game();

    while (1) {
        print_board();

        printf("Enter position of first card (0-15): ");
        scanf("%d", &first_card);
        reveal_card(first_card);
        print_board();

        printf("Enter position of second card (0-15): ");
        scanf("%d", &second_card);
        reveal_card(second_card);
        print_board();

        // Check for match
        if (check_match()) {
            printf("\nMatch found!\n");
        } else {
            printf("\nNo match found.\n");
            hide_cards();
        }

        // Check for win
        if (check_win()) {
            printf("\nCongratulations! You have won!\n");
            break;
        }
    }

    return 0;
}