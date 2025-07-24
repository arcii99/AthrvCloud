//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8 //Size of the checkerboard

void initializeGame(char board[][SIZE]); //Function to set up checkerboard
void printBoard(char board[][SIZE]); //Function to print current state of the checkerboard
bool moveIsValid(char board[][SIZE], int startX, int startY, int endX, int endY, int team); //Function to check if move is valid
bool canCapture(char board[][SIZE], int x, int y, int team); //Function to check if a given piece can capture an opponent's piece
bool continueCapture(char board[][SIZE], int currentX, int currentY, int team); //Function to check if a piece can continue capturing
void makeMove(char board[][SIZE], int startX, int startY, int endX, int endY, int team); //Function to make a valid move
bool gameFinished(char board[][SIZE]); //Function to check if the game has been won

int main()
{
    char board[SIZE][SIZE];
    int player = 1; //Keeps track of whose turn it is
    int startX, startY, endX, endY;

    initializeGame(board); //Set up checkerboard

    while(!gameFinished(board))
    {
        printBoard(board); //Print current state of checkerboard

        printf("Player %d: Enter your move (startX startY endX endY): ", player);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if(moveIsValid(board, startX, startY, endX, endY, player)) //Check if move is valid
        {
            makeMove(board, startX, startY, endX, endY, player); //Make move
            if(canCapture(board, endX, endY, player)) //Check if piece can continue capturing
            {
                while(continueCapture(board, endX, endY, player)) //Continue capturing
                {
                    printf("You can capture again!\nEnter your next move: ");
                    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
                    if(moveIsValid(board, startX, startY, endX, endY, player))
                    {
                        makeMove(board, startX, startY, endX, endY, player);
                    }
                    else
                    {
                        printf("Invalid move. Please try again.\n");
                    }
                }
            }
            player = (player == 1) ? 2 : 1; //Switch player turn
        }
        else
        {
            printf("Invalid move. Please try again.\n");
        }
    }

    printf("Player %d has won the game!\n", player == 1 ? 2 : 1);

    return 0;
}

void initializeGame(char board[][SIZE])
{
    int i, j;

    //Set up top and bottom rows of board with player pieces
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if((i + j) % 2 == 0 && i < 3) //Player 1 pieces
            {
                board[i][j] = '1';
            }
            else if((i + j) % 2 == 0 && i > 4) //Player 2 pieces
            {
                board[i][j] = '2';
            }
            else //Blank spaces on board
            {
                board[i][j] = '-';
            }
        }
    }
}

void printBoard(char board[][SIZE])
{
    int i, j;

    printf("  0 1 2 3 4 5 6 7\n"); //Print column numbers
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", i); //Print row numbers
        for(j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool moveIsValid(char board[][SIZE], int startX, int startY, int endX, int endY, int team)
{
    if(board[startX][startY] == '-') //No piece at starting position
    {
        return false;
    }
    if(board[endX][endY] != '-') //Ending position is occupied
    {
        return false;
    }
    if(team == 1 && board[startX][startY] == '2') //Not player 1's piece
    {
        return false;
    }
    if(team == 2 && board[startX][startY] == '1') //Not player 2's piece
    {
        return false;
    }
    if(board[startX][startY] == '1' && endX >= startX) //Player 1 piece moving backwards
    {
        return false;
    }
    if(board[startX][startY] == '2' && endX <= startX) //Player 2 piece moving backwards
    {
        return false;
    }
    if(abs(startX-endX) != abs(startY-endY)) //Not a diagonal move
    {
        return false;
    }
    if(abs(startX-endX) > 2) //Moving too many spaces
    {
        return false;
    }
    if(abs(startX-endX) == 1 && abs(startY-endY) == 1) //Single move is always valid
    {
        return true;
    }
    if(abs(startX-endX) == 2 && abs(startY-endY) == 2) //Capture move
    {
        if(board[(startX+endX)/2][(startY+endY)/2] == '-') //No piece being captured
        {
            return false;
        }
        if(board[(startX+endX)/2][(startY+endY)/2] == board[startX][startY]) //Can't capture own piece
        {
            return false;
        }
        return true;
    }
    return false; //All other cases are invalid moves
}

bool canCapture(char board[][SIZE], int x, int y, int team)
{
    if(board[x][y] == '1') //Check capture for player 1 piece
    {
        if(x >= 2 && y >= 2 && board[x-1][y-1] == '2' && board[x-2][y-2] == '-') //Capture to upper left
        {
            return true;
        }
        if(x >= 2 && y <= 5 && board[x-1][y+1] == '2' && board[x-2][y+2] == '-') //Capture to upper right
        {
            return true;
        }
        if(x <= 5 && y >= 2 && board[x+1][y-1] == '2' && board[x+2][y-2] == '-') //Capture to lower left
        {
            return true;
        }
        if(x <= 5 && y <= 5 && board[x+1][y+1] == '2' && board[x+2][y+2] == '-') //Capture to lower right
        {
            return true;
        }
    }
    else //Check capture for player 2 piece
    {
        if(x >= 2 && y >= 2 && board[x-1][y-1] == '1' && board[x-2][y-2] == '-') //Capture to upper left
        {
            return true;
        }
        if(x >= 2 && y <= 5 && board[x-1][y+1] == '1' && board[x-2][y+2] == '-') //Capture to upper right
        {
            return true;
        }
        if(x <= 5 && y >= 2 && board[x+1][y-1] == '1' && board[x+2][y-2] == '-') //Capture to lower left
        {
            return true;
        }
        if(x <= 5 && y <= 5 && board[x+1][y+1] == '1' && board[x+2][y+2] == '-') //Capture to lower right
        {
            return true;
        }
    }
    return false; //No possible captures
}

bool continueCapture(char board[][SIZE], int currentX, int currentY, int team)
{
    if(board[currentX][currentY] == '1') //Check capture for player 1 piece
    {
        if(currentX >= 2 && currentY >= 2 && board[currentX-1][currentY-1] == '2' && board[currentX-2][currentY-2] == '-') //Capture to upper left
        {
            return true;
        }
        if(currentX >= 2 && currentY <= 5 && board[currentX-1][currentY+1] == '2' && board[currentX-2][currentY+2] == '-') //Capture to upper right
        {
            return true;
        }
        if(currentX <= 5 && currentY >= 2 && board[currentX+1][currentY-1] == '2' && board[currentX+2][currentY-2] == '-') //Capture to lower left
        {
            return true;
        }
        if(currentX <= 5 && currentY <= 5 && board[currentX+1][currentY+1] == '2' && board[currentX+2][currentY+2] == '-') //Capture to lower right
        {
            return true;
        }
    }
    else //Check capture for player 2 piece
    {
        if(currentX >= 2 && currentY >= 2 && board[currentX-1][currentY-1] == '1' && board[currentX-2][currentY-2] == '-') //Capture to upper left
        {
            return true;
        }
        if(currentX >= 2 && currentY <= 5 && board[currentX-1][currentY+1] == '1' && board[currentX-2][currentY+2] == '-') //Capture to upper right
        {
            return true;
        }
        if(currentX <= 5 && currentY >= 2 && board[currentX+1][currentY-1] == '1' && board[currentX+2][currentY-2] == '-') //Capture to lower left
        {
            return true;
        }
        if(currentX <= 5 && currentY <= 5 && board[currentX+1][currentY+1] == '1' && board[currentX+2][currentY+2] == '-') //Capture to lower right
        {
            return true;
        }
    }
    return false; //No more possible captures
}

void makeMove(char board[][SIZE], int startX, int startY, int endX, int endY, int team)
{
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '-';

    if(abs(startX-endX) == 2 && abs(startY-endY) == 2) //Capture move
    {
        board[(startX+endX)/2][(startY+endY)/2] = '-';
    }
}

bool gameFinished(char board[][SIZE])
{
    int i, j;
    int player1Pieces = 0, player2Pieces = 0;

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(board[i][j] == '1') //Player 1 piece
            {
                player1Pieces++;
            }
            else if(board[i][j] == '2') //Player 2 piece
            {
                player2Pieces++;
            }
        }
    }

    if(player1Pieces == 0 || player2Pieces == 0) //One player has lost all their pieces
    {
        return true;
    }
    else //Game is not finished
    {
        return false;
    }
}