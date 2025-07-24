//FormAI DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void initialize_board(int[], int);
void display_board(int[], int);
void play_game(int[], int);

int main() {
    int board[BOARD_SIZE];
    initialize_board(board, BOARD_SIZE);
    display_board(board, BOARD_SIZE);
    play_game(board, BOARD_SIZE);
    return 0;
}

void initialize_board(int board[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i += 2) {
        int value = rand() % (size / 2) + 1;
        board[i] = value;
        board[i+1] = value;
    }
    for (int i = 0; i < size; i++) {
        int random_index = rand() % size;
        int temp = board[i];
        board[i] = board[random_index];
        board[random_index] = temp;
    }
}

void display_board(int board[], int size) {
    printf("\nMemory Game!\n");
    printf("-----------------\n");
    for (int i = 0; i < size; i++) {
        if (i % 4 == 0) {
            printf("\n");
        }
        printf("%5d", board[i]);
    }
    printf("\n-----------------\n");
}

void play_game(int board[], int size) {
    int revealed_board[size];
    for (int i = 0; i < size; i++) {
        revealed_board[i] = 0; 
    }
    int num_revealed = 0;
    while (num_revealed < size) {
        printf("Enter first card to flip: ");
        int first_card;
        scanf("%d", &first_card);
        while (first_card < 0 || first_card >= size || revealed_board[first_card] == 1) {
            printf("Invalid card, please enter again: ");
            scanf("%d", &first_card);
        }
        revealed_board[first_card] = 1;
        num_revealed++;
        display_board(revealed_board, size);
        printf("Enter second card to flip: ");
        int second_card;
        scanf("%d", &second_card);
        while (second_card < 0 || second_card >= size || revealed_board[second_card] == 1) {
            printf("Invalid card, please enter again: ");
            scanf("%d", &second_card);
        }
        revealed_board[second_card] = 1;
        num_revealed++;
        display_board(revealed_board, size);
        if (board[first_card] != board[second_card]) {
            printf("Not a match! Try again!\n");
            revealed_board[first_card] = 0;
            revealed_board[second_card] = 0;
            num_revealed -= 2;
            display_board(revealed_board, size);
        } else {
            printf("Match!\n");
        }
    }
    printf("\nCongratulations! You matched all the cards!\n");
}