//FormAI DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(char board[][MAX], int n) {
    printf("     ");
    for (int i = 0; i < n; i++) {
        printf("%d%c  ", i + 1, i == n - 1 ? '\n' : ' ');
    }
    printf("    ┌");
    for (int i = 0; i < 2 * n - 1; i++) {
        printf(i % 2 == 0 ? "─" : "┬");
    }
    printf("┐\n");

    for (int i = 0; i < n; i++) {
        printf(" %2d ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("│ %c ", board[i][j]);
        }
        printf("│\n");
        printf("    ├");
        for (int j = 0; j < 2 * n - 1; j++) {
            printf(j % 2 == 0 ? "─" : "┼");
        }
        printf("┤\n");
    }

    printf("\n");
}

int selectCard(char board[][MAX], int row, int col) {
    if (board[row][col] == '*') {
        return -1;
    } else {
        return board[row][col];
    }
}

int main() {
    int n = 4; // board size
    int numCards = n * n / 2;
    char board[MAX][MAX] = {'*'};
    int choice1Col, choice1Row, choice2Col, choice2Row;

    // initialize cards
    int cards[numCards * 2];
    for (int i = 0; i < numCards * 2; i += 2) {
        cards[i] = i / 2 + 1;
        cards[i + 1] = i / 2 + 1;
    }

    // shuffle cards
    shuffle(cards, numCards * 2);

    // arrange cards on board
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = cards[k++];
        }
    }

    // play game
    printf("Memory Game\n\n");
    printBoard(board, n);

    for (int i = 0; i < numCards; i++) {
        printf("Player 1's turn\n");
        printf("Choose your first card (row, col): ");
        scanf("%d %d", &choice1Row, &choice1Col);
        while (selectCard(board, choice1Row-1, choice1Col-1) == -1) {
            printf("That card has already been selected. Try again.\n");
            printf("Choose your first card (row, col): ");
            scanf("%d %d", &choice1Row, &choice1Col);
        }

        board[choice1Row-1][choice1Col-1] = '*';
        printBoard(board, n);

        printf("Choose your second card (row, col): ");
        scanf("%d %d", &choice2Row, &choice2Col);
        while (selectCard(board, choice2Row-1, choice2Col-1) == -1) {
            printf("That card has already been selected. Try again.\n");
            printf("Choose your second card (row, col): ");
            scanf("%d %d", &choice2Row, &choice2Col);
        }

        board[choice2Row-1][choice2Col-1] = '*';
        printBoard(board, n);

        // check if cards match
        if (cards[(choice1Row-1) * n + choice1Col-1] != cards[(choice2Row-1) * n + choice2Col-1]) {
            printf("Player 1: Sorry, those cards do not match.\n");
        } else {
            printf("Player 1: Congratulations, you found a match!\n");
            i--;
        }
    }

    return 0;
}