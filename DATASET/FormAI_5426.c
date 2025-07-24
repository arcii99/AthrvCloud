//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

// Function to generate unique random numbers from 1 to MAX_NUM
void generateUniqueRandomNumbers(int *arr, int n) {
    int i, j, temp;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate numbers from 1 to MAX_NUM in array
    for (i = 0; i < MAX_NUM; i++)
        arr[i] = i + 1;

    // Shuffle the array
    for (i = 0; i < n; i++) {
        j = rand() % (MAX_NUM - i) + i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int i, j, n, num_drawn = 0, found, count = 0;
    int bingo_card[ROWS][COLS];
    int drawn_numbers[MAX_NUM];
    char bingo_letter[5] = {'B', 'I', 'N', 'G', 'O'};

    // Generate unique random numbers to fill the bingo card
    generateUniqueRandomNumbers(drawn_numbers, MAX_NUM);

    // Fill the bingo card with numbers from shuffled array
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            bingo_card[i][j] = drawn_numbers[count++];
        }
    }

    // Welcome message
    printf("Welcome to the Bingo Simulator\n");
    printf("--------------------------------\n");
    printf("Press enter to start!\n");
    getchar(); // Wait for user input

    // Draw numbers until someone wins
    while (1) {
        // Clear screen and print bingo card
        system("clear"); // For Linux/Mac
        //system("cls"); // For Windows
        printf("       B   I   N   G   O\n");
        for (i = 0; i < ROWS; i++) {
            printf("\n    ");
            for (j = 0; j < COLS; j++) {
                if (i == 2 && j == 2) // Free space
                    printf("   ");
                else
                    printf("%2d ", bingo_card[i][j]);
            }
        }

        // Get input from user and search for number in bingo card
        printf("\n\nEnter a number (1-%d): ", MAX_NUM);
        scanf("%d", &n);
        getchar(); // Consume newline character

        // Check if number is already drawn
        found = 0;
        for (i = 0; i < num_drawn; i++) {
            if (drawn_numbers[i] == n) {
                printf("Number is already drawn.\n");
                found = 1;
                break;
            }
        }
        if (found) {
            getchar(); // Wait for user input
            continue;
        }

        // Search for number in bingo card
        found = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (bingo_card[i][j] == n) {
                    bingo_card[i][j] = 0; // Replace drawn number with 0
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }

        // Check if number is present in bingo card
        if (!found) {
            printf("Number is not present in bingo card.\n");
            getchar(); // Wait for user input
            continue;
        }

        // Print letter and number of drawn number
        printf("%c%d\n", bingo_letter[j], n);
        drawn_numbers[num_drawn++] = n;

        // Check rows, columns and diagonals for bingo
        for (i = 0; i < ROWS; i++) {
            // Check row i
            found = 1;
            for (j = 0; j < COLS; j++) {
                if (bingo_card[i][j] != 0) {
                    found = 0;
                    break;
                }
            }
            if (found)
                break;

            // Check column i
            found = 1;
            for (j = 0; j < ROWS; j++) {
                if (bingo_card[j][i] != 0) {
                    found = 0;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found)
            break;

        // Check diagonal from top left to bottom right
        found = 1;
        for (i = 0; i < ROWS; i++) {
            if (bingo_card[i][i] != 0) {
                found = 0;
                break;
            }
        }
        if (found)
            break;

        // Check diagonal from bottom left to top right
        found = 1;
        for (i = 0; i < ROWS; i++) {
            if (bingo_card[i][ROWS - 1 - i] != 0) {
                found = 0;
                break;
            }
        }
        if (found)
            break;
    }

    // Game over message
    system("clear"); // For Linux/Mac
    //system("cls"); // For Windows
    printf("B   I   N   G   O\n");
    for (i = 0; i < ROWS; i++) {
        printf("\n");
        for (j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) // Free space
                printf("   ");
            else if (bingo_card[i][j] == 0)
                printf(" X ");
            else
                printf("%2d ", bingo_card[i][j]);
        }
    }
    printf("\n\nBINGO!!\n");
    printf("Congratulations, you won in %d draws!\n", num_drawn);

    return 0;
}