//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define NUM_PAIRS 8

int board[BOARD_SIZE];
int revealed[BOARD_SIZE];
int num_revealed;

void init_board() {
    for (int i = 0; i < NUM_PAIRS; i++) {
        int pair_val = i + 1;
        board[2*i] = pair_val;
        board[2*i + 1] = pair_val;
    }
    num_revealed = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        revealed[i] = 0;
    }
}

void shuffle_board() {
    srand(time(NULL));
    for (int i = 0; i < 5*BOARD_SIZE; i++) {
        int index1 = rand() % BOARD_SIZE;
        int index2 = rand() % BOARD_SIZE;
        int temp = board[index1];
        board[index1] = board[index2];
        board[index2] = temp;
    }
}

void display_board() {
    printf("   1 2 3 4\n");
    printf("  -------\n");
    for (int i = 0; i < 4; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 4; j++) {
            int index = i*4 + j;
            if (revealed[index]) {
                printf("%d ", board[index]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int get_index(char row, int col) {
    int irow = row - 'A';
    int icol = col - 1;
    if (irow < 0 || irow >= 4 || icol < 0 || icol >= 4) {
        return -1;
    }
    return irow*4 + icol;
}

void display_instructions() {
    printf("Welcome to Memory Game!\n");
    printf("To make a guess, enter a row letter and column number (e.g. A3).\n");
    printf("You must find all the matching pairs in as few guesses as possible.\n");
}

void make_guess() {
    while(1) {
        char input[10];
        printf("Enter your guess: ");
        fgets(input, 10, stdin);
        char row = input[0];
        int col = atoi(&input[1]);
        if (get_index(row, col) < 0) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        int index = get_index(row, col);
        if (revealed[index]) {
            printf("That location is already revealed. Try again.\n");
            continue;
        }
        revealed[index] = 1;
        num_revealed++;
        break;
    }
}

int check_gameover() {
    if (num_revealed == BOARD_SIZE) {
        return 1;
    }
    return 0;
}

void main() {
    init_board();
    shuffle_board();
    display_instructions();
    while(1) {
        display_board();
        make_guess();
        if (check_gameover()) {
            display_board();
            printf("Congratulations, you won!\n");
            break;
        }
    }
}