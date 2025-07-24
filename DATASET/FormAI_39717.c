//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_bingo_card(int card[5][5]);
int check_bingo(int card[5][5]);
int call_number(int called[], int last_num);

int main()
{
    // Initialize variables and arrays
    int card[5][5] = {0};
    int called[75] = {0};
    int last_num = 0;
    int bingo = 0;
    srand(time(NULL));

    // Generate random BINGO card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                card[i][j] = 0;
            } else {
                int num;
                do {
                    num = rand() % 15 + 1 + 15 * j;
                } while (num == card[0][j] || num == card[1][j] || num == card[2][j] || num == card[3][j] || num == card[4][j]);
                card[i][j] = num;
            }
        }
    }

    // Print BINGO card
    printf("Welcome to BINGO Simulator!\n\n");
    printf("Here is your BINGO Card:\n\n");
    print_bingo_card(card);
    printf("\n");

    // Start game loop
    while (!bingo) {
        // Call number
        int num = call_number(called, last_num);
        last_num = num;
        printf("The next number is: %d\n", num);

        // Mark number on card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] == num) {
                    card[i][j] = -1;
                }
            }
        }

        // Check for bingo
        bingo = check_bingo(card);
        if (bingo) {
            printf("\nBINGO! You won!\n");
        }

        // Pause game for user input
        printf("\nPress ENTER for next number.");
        getchar();
    }

    // End game
    return 0;
}

// Function to print BINGO card
void print_bingo_card(int card[5][5])
{
    printf("B   I   N   G   O\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card[i][j] == -1) {
                printf("X   ");
            } else {
                printf("%-3d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check for bingo
int check_bingo(int card[5][5])
{
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card[i][0] == -1 && card[i][1] == -1 && card[i][2] == -1 && card[i][3] == -1 && card[i][4] == -1) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card[0][j] == -1 && card[1][j] == -1 && card[2][j] == -1 && card[3][j] == -1 && card[4][j] == -1) {
            return 1;
        }
    }

    // Check diagonals
    if (card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) {
        return 1;
    }
    if (card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1) {
        return 1;
    }

    // No bingo found
    return 0;
}

// Function to call number
int call_number(int called[], int last_num)
{
    int num;
    do {
        num = rand() % 75 + 1;
    } while (num == last_num || called[num] != 0);
    called[num] = 1;
    return num;
}