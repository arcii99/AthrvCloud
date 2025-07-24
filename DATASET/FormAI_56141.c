//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    const int ROWS = 5;
    const int COLS = 5;
    const int RANGE = 25;
    int used[RANGE];
    int card[ROWS][COLS];
    int num;
    int turn_count = 0;
    int gameover = 0;

    srand(time(NULL));

    // Creating the unique Romeo and Juliet style bingo game card
    for (int i = 0; i < RANGE; i++) {
        used[i] = 0;
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            num = rand() % RANGE + 1;
            while (used[num - 1] != 0) {
                num = rand() % RANGE + 1;
            }
            used[num - 1] = 1;
            card[row][col] = num;
        }
    }

    // Displaying the Romeo and Juliet style bingo game card
    printf("Welcome to the unique Romeo and Juliet style Bingo Simulator!\n");
    printf("You will be playing with a card that includes numbers from 1 to 25 in a unique order.\n");
    printf("\n");
    printf("Here is your Romeo and Juliet style bingo card:\n");
    printf("\n");

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == 2 && col == 2) {
                printf(" * ");
            } else {
                printf("%2d ", card[row][col]);
            }
        }
        printf("\n");
    }

    // Starting the gameplay
    printf("\n");
    printf("Let's start playing! Type in the number that was called out or type -1 to quit the game.\n");
    printf("\n");

    while (gameover == 0) {
        int input;
        scanf("%d", &input);

        if (input == -1) {
            printf("You have quit the game. Better luck next time!\n");
            break;
        }

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (card[row][col] == input) {
                    card[row][col] = 0;
                    turn_count++;
                }
            }
        }

        // Checking if the game is over
        if (card[0][0] == 0 && card[1][1] == 0 && card[3][3] == 0 && card[4][4] == 0) {
            printf("Congratulations! You have completed the unique Romeo and Juliet style bingo card in %d turns!\n", turn_count);
            gameover = 1;
        } else if (card[0][4] == 0 && card[1][3] == 0 && card[3][1] == 0 && card[4][0] == 0) {
            printf("Congratulations! You have completed the unique Romeo and Juliet style bingo card in %d turns!\n", turn_count);
            gameover = 1;
        }

        if (gameover == 1) {
            break;
        }

        // Displaying the updated card
        printf("\n");
        printf("Here is your new Romeo and Juliet style bingo card:\n");
        printf("\n");

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (row == 2 && col == 2) {
                    printf(" * ");
                } else {
                    printf("%2d ", card[row][col]);
                }
            }
            printf("\n");
        }

        printf("\n");
        printf("Type in the number that was called out or type -1 to quit the game.\n");
        printf("\n");
    }

    return 0;
}