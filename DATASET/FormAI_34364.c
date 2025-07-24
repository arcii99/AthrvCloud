//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

// create the game board with numbers from 0 to 7 appearing twice
void create_board(int board[]) {
    int i, j, count = 0;

    for (i = 0; i < BOARD_SIZE; i += 2) {
        board[i] = board[i + 1] = count;
        count++;
    }
}

// randomize the order of numbers in the board array
void shuffle_board(int board[]) {
    int i, temp, rand_index;

    srand(time(NULL));

    for (i = 0; i < BOARD_SIZE; i++) {
        rand_index = rand() % BOARD_SIZE;

        // swap the values at index i and rand_index
        temp = board[i];
        board[i] = board[rand_index];
        board[rand_index] = temp;
    }
}

// print the game board
void print_board(int board[], int reveal[]) {
    int i;

    printf("\n   MEMORY GAME\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        if (reveal[i])
            printf(" %d ", board[i]);
        else
            printf(" - ");
        
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
}

// determine if the game is complete
int is_complete(int reveal[]) {
    int i;

    for (i = 0; i < BOARD_SIZE; i++) {
        if (!reveal[i])
            return 0;
    }

    return 1;
}

// main function
int main() {
    int board[BOARD_SIZE], reveal[BOARD_SIZE] = {0};
    int first_guess, second_guess, guesses = 0;

    create_board(board);
    shuffle_board(board);

    while (!is_complete(reveal)) {
        print_board(board, reveal);

        // get the user's first guess
        printf("\nEnter the index of your first guess (0-15): ");
        scanf("%d", &first_guess);

        while (reveal[first_guess]) {
            printf("\nThat index has already been revealed. Try again: ");
            scanf("%d", &first_guess);
        }

        reveal[first_guess] = 1;
        print_board(board, reveal);

        // get the user's second guess
        printf("\nEnter the index of your second guess (0-15): ");
        scanf("%d", &second_guess);

        while (reveal[second_guess] || second_guess == first_guess) {
            if (second_guess == first_guess)
                printf("\nYou cannot choose the same index twice. Try again: ");
            else
                printf("\nThat index has already been revealed. Try again: ");

            scanf("%d", &second_guess);
        }

        reveal[second_guess] = 1;
        print_board(board, reveal);

        // check if the user made a match
        if (board[first_guess] == board[second_guess])
            printf("\nMatch found!\n");
        else {
            printf("\nNo match. Try again.\n");

            // hide the un-matched guesses
            reveal[first_guess] = reveal[second_guess] = 0;
        }

        guesses++;
    }

    printf("\nCongratulations! You completed the Memory Game in %d guesses!\n", guesses);

    return 0;
}