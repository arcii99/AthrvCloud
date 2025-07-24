//FormAI DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROWS 4
#define COLS 4

int main()
{
    char mem_board[ROWS][COLS] = {{'*', '*', '*', '*'},
								  {'*', '*', '*', '*'},
								  {'*', '*', '*', '*'},
								  {'*', '*', '*', '*'}};
    char display_board[ROWS][COLS] = {{'1', '2', '3', '4'},
									  {'5', '6', '7', '8'},
									  {'9', 'a', 'b', 'c'},
									  {'d', 'e', 'f', 'g'}};
    char prev_choice = ' ';
    int row1, col1, row2, col2, count = 0;

    srand(time(NULL));

    // initialize random shuffle of display board
    for (int i = 0; i < ROWS * COLS; i++)
    {
        int rand_row1 = rand() % ROWS;
        int rand_col1 = rand() % COLS;
        int rand_row2 = rand() % ROWS;
        int rand_col2 = rand() % COLS;

        char temp = display_board[rand_row1][rand_col1];
        display_board[rand_row1][rand_col1] = display_board[rand_row2][rand_col2];
        display_board[rand_row2][rand_col2] = temp;
    }

    printf("\nWelcome to the Memory Game!\n\n");
    printf("Rules: \n");
    printf("Try to match every character with its pair.\n");
    printf("If two characters match, they will remain uncovered.\n");
    printf("The game ends when all characters are uncovered.\n\n");

    while (1)
    {
        // display memory board
        printf("Memory Board: \n\n");
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%c ", mem_board[i][j]);
            }
            printf("\n");
        }

        // get input from user
        printf("\nChoose a character to uncover (ex: a1): ");
        char choice_str[3];
        scanf("%s", choice_str);

        // convert row and col strings to ints
        char row_str = tolower(choice_str[0]);
        char col_str = choice_str[1];
        row1 = row_str - 'a';
        col1 = col_str - '1';

        // check if row and column are valid
        if (row1 < 0 || row1 > ROWS || col1 < 0 || col1 > COLS)
        {
            printf("Invalid row and/or column input.\n");
            continue;
        }

        // check if already uncovered
        if (mem_board[row1][col1] != '*')
        {
            printf("That spot has already been uncovered.\n");
            continue;
        }

        // uncover character and show display board
        mem_board[row1][col1] = display_board[row1][col1];
        printf("\nDisplay Board: \n\n");
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%c ", display_board[i][j]);
            }
            printf("\n");
        }
		
        // check if this is first or second choice
        if (prev_choice == ' ')
        {
            prev_choice = display_board[row1][col1];
            row2 = row1;
            col2 = col1;
        }
        else if (display_board[row1][col1] == prev_choice)
        {
            // match found!
            printf("\nMatch found!\n");
            prev_choice = ' ';
            count++;
        }
        else
        {
            // no match, cover both back up
            printf("\nNo match found.\n");
            mem_board[row1][col1] = '*';
            mem_board[row2][col2] = '*';
            prev_choice = ' ';
        }

        // check if game is over
        if (count == ROWS * COLS / 2)
        {
            printf("\nCongratulations! You uncovered all pairs!\n");
            break;
        }
    }

    return 0;
}