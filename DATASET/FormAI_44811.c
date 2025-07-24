//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // seed the RNG
    int numbers[75]; // array for holding the numbers
    int currentNumber = 1; // counter for current number
    int card[5][5]; // bingo card
    int i, j, n; // loop indexes and RNG value
    int bingo = 0; // flag for checking bingo status

    // fill the bingo card with random numbers
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i][j] = (j * 15) + (rand() % 15) + 1;
        }
    }

    // display the bingo card
    printf("Welcome to the Sherlock Holmes Bingo Simulator!\n\n");
    printf("Your bingo card:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }

    while (!bingo) {
        printf("\n\nPress Enter to reveal the next number...\n\n");
        getchar(); // wait for user input

        // generate a random number and check if it's already been called
        do {
            n = rand() % 75 + 1;
        } while (numbers[n-1] != 0);

        // mark the number as called and display it
        numbers[n-1] = 1;
        printf("The next number is: %d\n", n);

        // check for matches on the bingo card
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (card[i][j] == n) {
                    card[i][j] = 0; // mark the number as matched
                }
            }
        }

        // check for bingo
        for (i = 0; i < 5; i++) {
            int rowSum = 0;
            int colSum = 0;
            for (j = 0; j < 5; j++) {
                rowSum += card[i][j];
                colSum += card[j][i];
            }
            if (rowSum == 0 || colSum == 0) {
                bingo = 1;
                break;
            }
        }

        // display the updated bingo card
        printf("\nYour updated bingo card:\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                printf("%d\t", card[i][j]);
            }
            printf("\n");
        }

        currentNumber++;
    }

    // display the winning message
    printf("\nBingo! You won in %d calls!\n", currentNumber);
    printf("Congratulations, you have solved the mystery!\n");

    return 0;
}