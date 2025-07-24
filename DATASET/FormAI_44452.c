//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 16 //size of the board
#define ROW_SIZE 4 //number of rows in the board

void generateBoard(char[]); //function to generate the board
void printBoard(char[]); //function to print the board
int openCard(int, char[]); //function to open a card

int main()
{
    char board[BOARD_SIZE]; //declare the board
    generateBoard(board); //generate the board
    printBoard(board); //print the board

    int open1 = -1, open2 = -1; //to keep track of open cards
    int move_count = 0; //to keep track of number of moves

    while (1) //keep looping until game is over
    {
        printf("\nEnter two card numbers (0 to quit): ");
        scanf("%d", &open1);
        scanf("%d", &open2);

        if(open1 == 0 || open2 == 0) //check if user wants to quit
        {
            printf("\nQuitting game...\n");
            break;
        }

        if(openCard(open1, board) == openCard(open2, board)) //check if the two selected cards are a match
        {
            printf("Match found!\n");
            board[open1-1] = '*';
            board[open2-1] = '*';
        }
        else
        {
            printf("No match. Try again.\n");
        }

        printBoard(board); //print the board
        move_count++; //increase move count
    }

    printf("\nTotal moves: %d\n", move_count); //print total moves
    return 0;
}

void generateBoard(char board[])
{
    srand(time(NULL)); //seed random number generator

    //initialize board
    for(int i=0; i<BOARD_SIZE; i++)
        board[i] = (i % 8) + 'A';

    //shuffle board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int j = rand() % BOARD_SIZE;
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}

void printBoard(char board[])
{
    printf("\nCurrent board:\n\n");

    for(int i=0; i<ROW_SIZE; i++)
    {
        for(int j=0; j<ROW_SIZE; j++)
            printf("%2c", board[i*ROW_SIZE + j]);

        printf("\n");
    }
}

int openCard(int card_num, char board[])
{
    return board[card_num-1]; //return the character at the selected card
}