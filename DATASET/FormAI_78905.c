//FormAI DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define TOTAL_CARDS BOARD_SIZE * BOARD_SIZE / 2

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(char board[][BOARD_SIZE]) {
    printf("\n+-----+-----+-----+-----+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|  %c  ", board[i][j]);
        }
        printf("|\n+-----+-----+-----+-----+\n");
    }
}

void revealCards(int x1, int y1, int x2, int y2, char board[][BOARD_SIZE], char solution[][BOARD_SIZE]) {
    board[x1][y1] = solution[x1][y1];
    board[x2][y2] = solution[x2][y2];
    printBoard(board);
}

int isMatch(int x1, int y1, int x2, int y2, char solution[][BOARD_SIZE]) {
    if (solution[x1][y1] == solution[x2][y2]) {
        return 1;
    }
    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE], solution[BOARD_SIZE][BOARD_SIZE];
    int cards[TOTAL_CARDS * 2], cardIndex = 0;

    //initialize cards array
    for (int i = 0; i < TOTAL_CARDS; i++) {
        cards[cardIndex++] = i + 'A';
        cards[cardIndex++] = i + 'A';
    }
    
    //shuffle cards array
    srand(time(NULL));
    shuffle(cards, TOTAL_CARDS * 2);

    //initialize solution and board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            solution[i][j] = cards[i * BOARD_SIZE + j];
            board[i][j] = '_';
        }
    }

    //start game
    int x1, y1, x2, y2;
    do {
        printBoard(board);
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &x2, &y2);

        if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
            x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
            printf("Invalid input.\n");
            continue;
        }

        if (board[x1][y1] != '_' || board[x2][y2] != '_') {
            printf("Cards already revealed.\n");
            continue;
        }

        revealCards(x1, y1, x2, y2, board, solution);

        if (isMatch(x1, y1, x2, y2, solution)) {
            printf("Match found!\n");
        } else {
            printf("No match. Try again.\n");
        }

    } while (1);

    return 0;
}