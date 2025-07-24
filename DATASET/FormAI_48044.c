//FormAI DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(int board[], int n) {
    for (int i = 0; i < n; i++) {
        if (board[i] == -1) {
            printf(" _ ");
        } else {
            printf("%2d ", board[i]);
        }
    }
    printf("\n");
}

void game(int board[], int n) {
    int score = 0;

    while (1) {
        printf("Score: %d\n", score);
        printBoard(board, n);

        int f, s;
        printf("Enter two indices: ");
        scanf("%d %d", &f, &s);

        if (board[f] == -1 || board[s] == -1) {
            printf("Invalid index!\n");
            continue;
        } 

        if (board[f] == board[s]) {
            score += 10;
            board[f] = -1;
            board[s] = -1;

            int gameOver = 1;
            for (int i = 0; i < n; i++) {
                if (board[i] != -1) {
                    gameOver = 0;
                    break;
                }
            }

            if (gameOver) {
                printf("You win! Final score: %d\n", score);
                return;
            }

        } else {
            score -= 5;
        }
    }
}

int main() {
    int board[16] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
    shuffle(board, 16);

    printf("Welcome to Memory Game!\n");
    printf("Try to match the numbers.\n");
    printf("You get 10 points for a match and -5 points for a miss.\n");
    printf("When all matches are found, you win!\n");
    game(board, 16);

    return 0;
}