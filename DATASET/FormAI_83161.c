//FormAI DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // size of the board, change this to adjust the difficulty level

int board[BOARD_SIZE][BOARD_SIZE]; // 2D array to store the game board

/* function to initialize the board with random values */
void init_board() {
    int num_pairs = BOARD_SIZE * BOARD_SIZE / 2;
    int nums[num_pairs];
    for (int i = 0; i < num_pairs; i++) {
        nums[i] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % num_pairs;
            int num = nums[index];
            board[i][j] = num;
            board[BOARD_SIZE - 1 - i][BOARD_SIZE - 1 - j] = num;
            // set the same number at the symmetric position
            num_pairs--;
            nums[index] = nums[num_pairs]; // remove the used number from the array
        }
    }
}

/* function to print the board */
void print_board() {
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] >= 0) {
                printf("# ");
            } else {
                printf("%d ", -board[i][j]);
            }
        }
        printf("\n");
    }
}

/* function to reveal the card at (x, y) */
void reveal_card(int x, int y) {
    board[x][y] = -board[x][y];
}

/* function to hide all revealed cards */
void hide_cards() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] < 0) {
                board[i][j] = -board[i][j];
            }
        }
    }
}

/* function to check if the game is over */
int is_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] >= 0) {
                return 0; // there is still a card that is not matched
            }
        }
    }
    return 1; // all cards are matched
}

int main() {
    init_board();
    int num_attempts = 0;
    while (1) {
        printf("Attempt #%d:\n", num_attempts+1);
        print_board();
        int x1, y1, x2, y2;
        printf("Enter the coordinates of the first card to reveal: ");
        scanf("%d%d", &x1, &y1);
        reveal_card(x1, y1);
        printf("Enter the coordinates of the second card to reveal: ");
        scanf("%d%d", &x2, &y2);
        reveal_card(x2, y2);
        printf("\n");
        print_board();
        if (board[x1][y1] != board[x2][y2]) { // not a match
            printf("Sorry, the cards do not match.\n");
            hide_cards();
        } else { // a match
            printf("Congratulations, the cards match!\n");
            board[x1][y1] = -board[x1][y1]; // mark the cards as matched
            board[x2][y2] = -board[x2][y2];
        }
        if (is_game_over()) { // check if the game is over
            printf("Congratulations, you have won the game!\n");
            break;
        }
        num_attempts++;
    }
    return 0;
}