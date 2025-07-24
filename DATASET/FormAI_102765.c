//FormAI DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linus Torvalds-style C Memory Game
int main() {
    printf("Welcome to the Linux Memory Game!\n");
    printf("You need to match all pairs of the same letters.\n");
    printf("To select a card, enter its row and column numbers (e.g. 1 2).\n");
    printf("Let's start! Here's your board:\n\n");

    // setting up game board
    char board[4][4] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'A', 'B'},
        {'C', 'D', 'E', 'F'},
        {'G', 'H', 'G', 'H'}
    };
    int revealed[4][4] = {0};
    int pairsFound = 0;

    // randomizing the board
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        int x1 = rand() % 4;
        int y1 = rand() % 4;
        int x2 = rand() % 4;
        int y2 = rand() % 4;
        char temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }

    // main game loop
    while (pairsFound < 8) {
        // print current state of board
        printf("  1 2 3 4\n");
        printf(" +-+-+-+-+\n");
        for (int i = 0; i < 4; i++) {
            printf("%d|", i+1);
            for (int j = 0; j < 4; j++) {
                if (revealed[i][j]) {
                    printf("%c|", board[i][j]);
                } else {
                    printf(" |");
                }
            }
            printf("\n");
            printf(" +-+-+-+-+\n");
        }

        // get user input
        int x1, y1, x2, y2;
        printf("Enter first card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter second card: ");
        scanf("%d %d", &x2, &y2);

        // check if cards match
        if (board[x1-1][y1-1] == board[x2-1][y2-1]) {
            printf("You found a pair!\n");
            revealed[x1-1][y1-1] = 1;
            revealed[x2-1][y2-1] = 1;
            pairsFound++;
        } else {
            printf("Sorry, those cards don't match.\n");
        }
    }

    printf("Congratulations! You found all pairs!\n");
    return 0;
}