//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

int game_board[BOARD_SIZE];
int matched_board[BOARD_SIZE];
int first_card = -1;
int second_card = -1;

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        game_board[i] = matched_board[i] = -1;
    }

    for (int i = 0; i < BOARD_SIZE/2; i++) {
        int first_pos = -1;
        int second_pos = -1;

        do {
            first_pos = rand()%BOARD_SIZE;
        } while (game_board[first_pos] != -1);

        do {
            second_pos = rand()%BOARD_SIZE;
        } while ((game_board[second_pos] != -1) || (second_pos == first_pos));

        game_board[first_pos] = game_board[second_pos] = i;
    }
}

void display_board() {
    printf("\n\n----------Memory Game----------\n\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (matched_board[i] == 1) {
            printf(" %2d ", game_board[i]);
        } else {
            printf(" XX ");
        }

        if ((i+1) % 4 == 0) {
            printf("\n");
        }
    }

    printf("\n\n-------------------------\n\n");
}

int get_position() {
    int position = -1;

    do {
        printf("Enter a position (0-15): ");
        scanf("%d", &position);
    } while ((position < 0) || (position > 15) || (matched_board[position] == 1));

    return position;
}

void update_game(int position) {
    if (first_card == -1) {
        first_card = position;
    } else {
        second_card = position;

        if (game_board[first_card] == game_board[second_card]) {
            printf("Cards matched!\n");
            matched_board[first_card] = 1;
            matched_board[second_card] = 1;

            if (matched_board[0] == 1 && matched_board[1] == 1 && matched_board[2] == 1 && matched_board[3] == 1 && matched_board[4] == 1 && matched_board[5] == 1 && matched_board[6] == 1 && matched_board[7] == 1 &&
                matched_board[8] == 1 && matched_board[9] == 1 && matched_board[10] == 1 && matched_board[11] == 1 && matched_board[12] == 1 && matched_board[13] == 1 && matched_board[14] == 1 && matched_board[15] == 1) {
                printf("\n Congratulations! You Won!\n");
                exit(0);
            }

            first_card = -1;
            second_card = -1;
        } else {
            printf("Cards did not match!\n");
            first_card = second_card = -1;
        }
    }
}

int main() {
    srand(time(NULL));

    init_board();

    while (1) {
        display_board();

        int position = get_position();

        update_game(position);
    }

    return 0;
}