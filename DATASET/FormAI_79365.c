//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void initializeCard(int card[ROWS][COLS]);
void generateNumbers(int ball[], int n);
void printCard(int card[ROWS][COLS], int show);
int checkForBingo(int card[ROWS][COLS]);

int main() {
    int card[ROWS][COLS];
    int ballCount = 75;
    int ball[ballCount], i = 0;

    // Seed random number generator
    srand(time(NULL));

    // Initialize card and print
    initializeCard(card);
    printf("Welcome to Bingo!\n");
    printf("Here is your card:\n");
    printCard(card, 1);

    // Generate and display the first ball
    generateNumbers(ball, ballCount);
    printf("First Ball: %d\n", ball[i]);

    while (1) {
        // Prompt user to mark ball or end game
        printf("Type 'm' to mark ball or 'e' to end the game: ");
        char input;
        scanf("%c", &input);

        if (input == 'm') {
            // Mark number on card if present
            int j;
            for (j = 0; j < ROWS; j++) {
                int k;
                for (k = 0; k < COLS; k++) {
                    if (card[j][k] == ball[i]) {
                        card[j][k] = -1;
                        break;
                    }
                }
            }
            // Display updated card
            printCard(card, 1);

            // Check for bingo
            if (checkForBingo(card)) {
                printf("BINGO!\n");
                break;
            }
        } else if (input == 'e') {
            // End game if user chooses to
            printf("Thanks for playing!\n");
            break;
        }

        // Generate and display next ball
        i++;
        printf("Next Ball: %d\n", ball[i]);
    }

    return 0;
}

/*
* Initializes the bingo card with random numbers between 1 - 75
*/
void initializeCard(int card[ROWS][COLS]) {
    printf("Generating your card...\n");
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % 75 + 1;
            } while (numIsDuplicate(num, card));
            card[i][j] = num;
        }
    }
}

/*
* Populates an array of ball numbers without duplicates
*/
void generateNumbers(int ball[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        int num;
        do {
            num = rand() % 75 + 1;
        } while (numIsDuplicate(num, ball));
        ball[i] = num;
    }
}

/*
* Checks if a number is a duplicate in an array
*/
int numIsDuplicate(int num, int arr[]) {
    int i;
    for (i = 0; i < COLS; i++) {
        if (arr[i] == num)
            return 1;
    }
    return 0;
}

/*
* Prints the card contents to the screen
*/
void printCard(int card[ROWS][COLS], int show) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == -1 || show == 0)
                printf("XX ");
            else
                printf("%02d ", card[i][j]);
        }
        printf("\n");
    }
}

/*
* Checks for bingo in rows, columns, and diagonals
*/
int checkForBingo(int card[ROWS][COLS]) {
    int i, j, diag1 = 0, diag2 = 0, flagRow, flagCol;
    for (i = 0; i < ROWS; i++) {
        flagRow = 1;
        flagCol = 1;
        for (j = 0; j < COLS; j++) {
            // Check rows
            if (card[i][j] != -1)
                flagRow = 0;
            // Check columns
            if (card[j][i] != -1)
                flagCol = 0;
            // Check diagonal 1
            if (i == j && card[i][j] != -1)
                diag1++;
            // Check diagonal 2
            if ((i+j) == (ROWS-1) && card[i][j] != -1)
                diag2++;
        }
        if (flagRow || flagCol)
            return 1;
    }
    if (diag1 == ROWS || diag2 == ROWS)
        return 1;
    return 0;
}