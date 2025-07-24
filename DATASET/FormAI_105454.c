//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

/* This is a recursive implementation of the C Table Game. 
  Here, the opponent and user take turns to select a number (x) between 1 and 3, 
  and subtract it from a running total 'n', starting at 21. 
  Whoever reduces 'n' to zero (or less) loses the game. */

int playerTurn(int n);

int opponentTurn(int n);

int game(int n, int player);

int main() {
    printf("Welcome to the C Table Game!\n");
    printf("Rules: You start with a number (n) = 21\n");
    printf("Each player can subtract a number (x) = 1, 2, or 3. The player who reduces (n) to 0 or lesser, loses.\n\n");
    game(21, 1);
    return 0;
}

int playerTurn(int n) {
    int x;
    printf("Your turn!\n");
    printf("Enter a number between 1 and 3: ");
    scanf("%d", &x);
    if (x < 1 || x > 3) {
        printf("Invalid input, try again.\n\n");
        return playerTurn(n);
    } else if (n - x <= 0) {
        printf("Congratulations, you have won!\n");
        return 1;
    } else {
        printf("Remaining number: %d\n\n", n - x);
        return game(n - x, 0);
    }
}

int opponentTurn(int n) {
    int x;
    printf("My turn!\n");
    if (n % 4 == 0) {
        x = 3;
    } else {
        x = n % 4;
    }
    printf("I choose: %d\n", x);
    if (n - x <= 0) {
        printf("Oops, you have won!\n");
        return 1;
    } else {
        printf("Remaining number: %d\n\n", n - x);
        return game(n - x, 1);
    }
}

int game(int n, int player) {
    if (player) {
        return opponentTurn(n);
    } else {
        return playerTurn(n);
    }
}