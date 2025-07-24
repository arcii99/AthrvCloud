//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void shuffle(int *array, int size) {
    int i, j, temp;
    for (i = size - 1; i >= 0; i--) {
        // generate random index
        j = rand() % (i + 1);
        // swap elements
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void display_board(int board[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (i % 4 == 0) {
            printf("\n-----------------\n");
        }
        for (j = 0; j < size; j++) {
            if (j % 4 == 0) {
                printf("| ");
            }
            printf("%d ", board[i * size + j]);
        }
        printf("|");
    }
    printf("\n-----------------\n");
}

int main() {
    int board[BOARD_SIZE];
    int i, guess1, guess2;
    int matches = 0;
    int attempts = 0;
    
    // initialize board with pairs of numbers
    for (i = 0; i < BOARD_SIZE; i += 2) {
        board[i] = board[i + 1] = i / 2 + 1;
    }
    
    // shuffle board
    srand(time(0));
    shuffle(board, BOARD_SIZE);
    
    // game loop
    printf("Welcome to the Memory Game!\n");
    printf("Pairs of numbers are hidden in a 4x4 board.\n");
    printf("Try to find all pairs with the least attempts!\n");
    while (matches < BOARD_SIZE / 2) {
        display_board(board, 4);
        printf("Enter the coordinates of the first card: ");
        scanf("%d", &guess1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d", &guess2);
        
        if (board[guess1] == board[guess2]) {
            printf("You found a pair!\n");
            board[guess1] = board[guess2] = -1;
            matches++;
        } else {
            printf("Sorry, the numbers do not match.\n");
        }
        attempts++;
    }
    printf("Congratulations! You found all pairs in %d attempts!\n", attempts);
    return 0;
}