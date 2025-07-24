//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void printBoard(char board[BOARD_SIZE])
{
    printf("\nCurrent Board:\n\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%c ", board[i]);

        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int checkValidChoice(int choice1, int choice2, char board[BOARD_SIZE], char boardCopy[BOARD_SIZE])
{
    if (choice1 < 1 || choice2 < 1 || choice1 > BOARD_SIZE || choice2 > BOARD_SIZE)
    {
        printf("Invalid choice, please try again.\n");
        return 0;
    }

    if (board[choice1 - 1] == '*' || board[choice2 - 1] == '*' || choice1 == choice2)
    {
        printf("Invalid choice, please try again.\n");
        return 0;
    }

    if (board[choice1 - 1] != board[choice2 - 1])
    {
        printf("Sorry, those are not a match.\n");
        boardCopy[choice1 - 1] = '*';
        boardCopy[choice2 - 1] = '*';
        printBoard(boardCopy);
        return 1;
    }
    else
    {
        printf("Match found!\n");
        boardCopy[choice1 - 1] = board[choice1 - 1];
        boardCopy[choice2 - 1] = board[choice2 - 1];
        printBoard(boardCopy);
        return 1;
    }
}

int checkIfFinished(char boardCopy[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (boardCopy[i] != boardCopy[0])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    srand(time(NULL));

    char symbols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char board[BOARD_SIZE];
    char boardCopy[BOARD_SIZE];

    for (int i = 0; i < 8; i++)
    {
        board[i] = symbols[i];
        board[i + 8] = symbols[i];
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        boardCopy[i] = '*';
    }

    int choice1, choice2;
    int turns = 0;

    while (!checkIfFinished(boardCopy))
    {
        printf("\nEnter two numbers between 1 and 16 to reveal symbols.\n");
        printBoard(boardCopy);

        printf("\nTurn %d. Enter first choice: ", turns + 1);
        scanf("%d", &choice1);

        printf("Enter second choice: ");
        scanf("%d", &choice2);

        if (checkValidChoice(choice1, choice2, board, boardCopy))
        {
            turns++;
        }
    }

    printf("\nCongratulations! You Finished the Memory Game in %d turns!\n", turns);

    return 0;
}