//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("\n   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
    }
    printf("\n  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("___");
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("\n%d| ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c| ", board[i][j]);
        }
    }
    printf("\n  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("___");
    }
    printf("\n");
}

void init_board(char board[BOARD_SIZE][BOARD_SIZE], char letters[BOARD_SIZE*BOARD_SIZE/2]) {
    int i, j, k;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    srand(time(NULL));
    for (k = 0; k < BOARD_SIZE*BOARD_SIZE/2; k++) {
        char letter = letters[k];
        int x1, y1, x2, y2;
        do {
            x1 = rand() % BOARD_SIZE;
            y1 = rand() % BOARD_SIZE;
        } while (board[x1][y1] != '-');
        do {
            x2 = rand() % BOARD_SIZE;
            y2 = rand() % BOARD_SIZE;
        } while (board[x2][y2] != '-');
        board[x1][y1] = letter;
        board[x2][y2] = letter;
    }
}

int play_game() {
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board, letters);
    int i, j, x1, y1, x2, y2, num_turns = 0;
    while (1) {
        print_board(board);
        printf("Turn %d:\n", num_turns+1);
        printf("Enter a row for the first card: ");
        scanf("%d", &x1);
        printf("Enter a column for the first card: ");
        scanf("%d", &y1);
        printf("Enter a row for the second card: ");
        scanf("%d", &x2);
        printf("Enter a column for the second card: ");
        scanf("%d", &y2);
        if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (board[x1][y1] == '-' || board[x2][y2] == '-') {
            printf("That spot is already flipped or does not exist. Try again.\n");
            continue;
        }
        if (board[x1][y1] != board[x2][y2]) {
            printf("Cards do not match. Try again.\n");
            board[x1][y1] = '-';
            board[x2][y2] = '-';
        } else {
            printf("Cards match!\n");
            num_turns++;
            board[x1][y1] = '*';
            board[x2][y2] = '*';
        }
        int num_flipped = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != '-') {
                    num_flipped++;
                }
            }
        }
        if (num_flipped == BOARD_SIZE*BOARD_SIZE) {
            printf("You win! It took you %d turns.\n", num_turns);
            return 0;
        }
    }
}

int main() {
    printf("Welcome to the C Memory Game!\n");
    printf("Flip over all the cards in as few turns as possible to win.\n");
    printf("The letters on the cards will match in pairs.\n");
    return play_game();
}