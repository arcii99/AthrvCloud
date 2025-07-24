//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void initialize_board(int board[BOARD_SIZE]);
void shuffle_board(int board[BOARD_SIZE]);
void print_board(int board[BOARD_SIZE]);
int choose_card();
int valid_choice(int index);
int match(int board[BOARD_SIZE], int choice1, int choice2);
int game_over(int board[BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE];
    int choice1, choice2;
    int num_moves = 0;
    int matches = 0;

    initialize_board(board);
    shuffle_board(board);
    print_board(board);

    while (!game_over(board)) {
        choice1 = choose_card();
        while (!valid_choice(choice1)) {
            printf("Invalid choice. Try again.\n");
            choice1 = choose_card();
        }
        printf("You chose card %d.\n\n", choice1);

        choice2 = choose_card();
        while (!valid_choice(choice2)) {
            printf("Invalid choice. Try again.\n");
            choice2 = choose_card();
        }
        printf("You chose card %d.\n\n", choice2);

        if (match(board, choice1, choice2)) {
            printf("MATCH!\n");
            matches++;
        } else {
            printf("No match.\n");
        }

        num_moves++;
        printf("Number of moves: %d\n\n", num_moves);
    }

    printf("Congratulations! You completed the game in %d moves.\n", num_moves);

    return 0;
}

void initialize_board(int board[BOARD_SIZE]) {
    int i;

    for (i = 0; i < BOARD_SIZE / 2; i++) {
        board[i] = i;
        board[i + BOARD_SIZE / 2] = i;
    }
}

void shuffle_board(int board[BOARD_SIZE]) {
    int i, temp, random_index;

    srand(time(NULL));

    for (i = BOARD_SIZE - 1; i >= 0; i--) {
        random_index = rand() % (i + 1);
        temp = board[i];
        board[i] = board[random_index];
        board[random_index] = temp;
    }
}

void print_board(int board[BOARD_SIZE]) {
    int i;

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d\t", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("-\t");
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d\t", board[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

int choose_card() {
    int choice;

    printf("Choose a card: ");
    scanf("%d", &choice);

    return choice;
}

int valid_choice(int index) {
    if (index < 0 || index >= BOARD_SIZE) {
        return 0;
    }

    return 1;
}

int match(int board[BOARD_SIZE], int choice1, int choice2) {
    if (board[choice1] == board[choice2]) {
        board[choice1] = -1;
        board[choice2] = -1;
        return 1;
    }

    return 0;
}

int game_over(int board[BOARD_SIZE]) {
    int i;

    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != -1) {
            return 0;
        }
    }

    return 1;
}