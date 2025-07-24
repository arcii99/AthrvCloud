//FormAI DATASET v1.0 Category: Checkers Game ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#define BOARD_SIZE 8

// Function to display the board
void displayBoard(char board[][BOARD_SIZE]) 
{
    printf("\n   ");
    for(int i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i+1);
    printf("\n\n");

    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf("%d  ",i+1);
        for(int j=0;j<BOARD_SIZE;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Function to initialize the board
void initializeBoard(char board[][BOARD_SIZE])
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(i%2 == 0)
            {
                if(j%2 == 0)
                    board[i][j]='_';
                else if(i<3)
                    board[i][j]='B';
                else if(i>4)
                    board[i][j]='W';
                else
                    board[i][j]='_';
            }
            else
            {
                if(j%2 == 0)
                    board[i][j]='_';
                else if(i<3)
                    board[i][j]='B';
                else if(i>4)
                    board[i][j]='W';
                else
                    board[i][j]='_';
            }
        }
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn=0;

    //initialize the board
    initializeBoard(board);

    //display the board
    displayBoard(board);

    // Game loop
    while(1)
    {
        int x1, y1, x2, y2, captured=0, i;

        if(turn%2 == 0)
            printf("Player 1 (Black turn):\n");
        else
            printf("Player 2 (White turn):\n");

        printf("Enter initial and final coordinates(x1 y1 x2 y2): ");
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        // check for valid move
        if(board[x1-1][y1-1] == 'B' || board[x1-1][y1-1] == 'W' || board[x2-1][y2-1] == 'B' || board[x2-1][y2-1] == 'W')
        {
            printf("Invalid move. Try again!\n");
            continue;
        }

        //check if piece is moving diagonally
        if(abs(x2-x1) != abs(y2-y1))
        {
            printf("Invalid move. Piece must move diagonally. Try again!\n");
            continue;
        }

        // check for valid move distance
        if(abs(x2-x1) > 2)
        {
            printf("Invalid move. Try again!\n");
            continue;
        }

        // check for capturing
        if(abs(x2-x1) == 2)
        {
            if(board[(x1+x2)/2-1][(y1+y2)/2-1] == '_')
            {
                printf("Invalid move. You must capture. Try again!\n");
                continue;
            }

            if(board[x1-1][y1-1] == 'B')
            {
                if(board[(x1+x2)/2-1][(y1+y2)/2-1] == 'W' || board[(x1+x2)/2-1][(y1+y2)/2-1] == 'w')
                {
                    board[(x1+x2)/2-1][(y1+y2)/2-1] = '_';
                    captured=1;
                }

                if(x2 == 1)
                {
                    board[x2-1][y2-1] = 'w';
                    board[x1-1][y1-1] = '_';
                }
                else
                {
                    board[x2-1][y2-1] = board[x1-1][y1-1];
                    board[x1-1][y1-1] = '_';
                }

                if(!captured)
                    turn++;
            }

            if(board[x1-1][y1-1] == 'W')
            {
                if(board[(x1+x2)/2-1][(y1+y2)/2-1] == 'B' || board[(x1+x2)/2-1][(y1+y2)/2-1] == 'b')
                {
                    board[(x1+x2)/2-1][(y1+y2)/2-1] = '_';
                    captured=1;
                }

                if(x2 == 8)
                {
                    board[x2-1][y2-1] = 'b';
                    board[x1-1][y1-1] = '_';
                }
                else
                {
                    board[x2-1][y2-1] = board[x1-1][y1-1];
                    board[x1-1][y1-1] = '_';
                }

                if(!captured)
                    turn++;
            }
        }
        else
        {
            if(board[x1-1][y1-1] == 'B')
            {
                if(x2 == 1)
                    board[x2-1][y2-1] = 'w';
                else
                    board[x2-1][y2-1] = board[x1-1][y1-1];

                board[x1-1][y1-1] = '_';
                turn++;
            }

            if(board[x1-1][y1-1] == 'W')
            {
                if(x2 == 8)
                    board[x2-1][y2-1] = 'b';
                else
                    board[x2-1][y2-1] = board[x1-1][y1-1];

                board[x1-1][y1-1] = '_';
                turn++;
            }
        }

        // check for end of game
        int bcount=0, wcount=0;
        for(i=0;i<BOARD_SIZE;i++)
        {
            for(int j=0;j<BOARD_SIZE;j++)
            {
                if(board[i][j] == 'B' || board[i][j] == 'b')
                    bcount++;
                if(board[i][j] == 'W' || board[i][j] == 'w')
                    wcount++;
            }
        }

        if(bcount == 0 || wcount == 0)
        {
            printf("\nGame over!\n");
            printf("Player %d won!\n", (turn+1)%2+1);
            break;
        }

        //display the board
        displayBoard(board);
    }

    return 0;
}