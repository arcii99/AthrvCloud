//FormAI DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX 8

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(void) {
    int game_board[ROWS][COLS] = {0};
    int selection_board[ROWS][COLS] = {0};
    int max[MAX] = {0,1,1,2,2,3,3,4}; // Values to be matched
    shuffle(max, MAX);
    int count = 0;
    int row1, row2, col1, col2;
    int guess1, guess2;

    srand(time(NULL));
    
    // Print game header
    printf("*********WELCOME TO MEMORY CARD GAME*********\n\n");

    // Fill the game board with random numbers
    for(int i=0; i<MAX; i++) {
        for(int j=0; j<2; j++) {
            int num_assigned = 0;
            while(num_assigned != 2) {
                int r = rand() % ROWS;
                int c = rand() % COLS;
                if(game_board[r][c] == 0) {
                    game_board[r][c] = max[i];
                    num_assigned++;
                }
            }
        }
    }

    // Loop to play the game
    while(count < MAX) {
        // Print game board
        printf("\n\t\t\t\t");
        for(int i=0;i<COLS;i++)
            printf("%d\t",i+1);
        printf("\n");
        printf("\t\t\t-------------------------\n");

        for(int i=0;i<ROWS;i++) {
            printf("\t\t\t%d |",i+1);
            for(int j=0;j<COLS;j++) {
                if(selection_board[i][j] == 0) {
                    printf(" \t|");
                } else {
                    printf(" %d\t|", game_board[i][j]);
                }
            }
            printf("\n");
            printf("\t\t\t-------------------------\n");
        }

        // Get user input
        printf("Enter row 1, col 1: ");
        scanf("%d %d",&row1,&col1);

        // Check if the input is correct
        if(row1 < 1 || row1 > ROWS || col1 < 1 || col1 > COLS || selection_board[row1-1][col1-1] == 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Flip the card over
        selection_board[row1-1][col1-1] = 1;
        guess1 = game_board[row1-1][col1-1];

        // Print game board
        printf("\n\t\t\t\t");
        for(int i=0;i<COLS;i++)
            printf("%d\t",i+1);
        printf("\n");
        printf("\t\t\t-------------------------\n");

        for(int i=0;i<ROWS;i++) {
            printf("\t\t\t%d |",i+1);
            for(int j=0;j<COLS;j++) {
                if(selection_board[i][j] == 0) {
                    printf(" \t|");
                } else {
                    printf(" %d\t|", game_board[i][j]);
                }
            }
            printf("\n");
            printf("\t\t\t-------------------------\n");
        }

        // Get user input for the second card
        printf("Enter row 2, col 2: ");
        scanf("%d %d",&row2,&col2);

        // Check if the input is correct
        if(row2 < 1 || row2 > ROWS || col2 < 1 || col2 > COLS || selection_board[row2-1][col2-1] == 1) {
            printf("Invalid input. Please try again.\n");
            selection_board[row1-1][col1-1] = 0;
            continue;
        }

        // Flip the card over
        selection_board[row2-1][col2-1] = 1;
        guess2 = game_board[row2-1][col2-1];

        // Check if the guesses match
        if(guess1 == guess2) {
            printf("Matched!\n");
            count++;
        } else {
            printf("Not matched.\n");
            selection_board[row1-1][col1-1] = 0;
            selection_board[row2-1][col2-1] = 0;
        }
    }

    // The game is over
    printf("Congratulations! You won the game!\n");

    return 0;
}