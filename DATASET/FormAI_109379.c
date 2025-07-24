//FormAI DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>

#define BOARD_SIZE 8

void printBoard(char board[][BOARD_SIZE]);
int getPosition(int x, int y);
int getJump(int x1, int y1, int x2, int y2, char board[][BOARD_SIZE]);
int checkForWin(char board[][BOARD_SIZE], char player);
void move(char board[][BOARD_SIZE], char player);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', 'R', ' ', 'R', ' ', 'R', ' ', 'R'},
        {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '},
        {' ', 'R', ' ', 'R', ' ', 'R', ' ', 'R'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
        {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '}
    };
    
    printBoard(board);
    char player = 'R';
    
    while(!checkForWin(board,player))
    {
        printf("%c's Turn.\n", player);
        move(board,player);
        printBoard(board);
        player = (player == 'R') ? 'B' : 'R';
    }
    
    printf("%c Wins!\n", player);
    
    return 0;
}

void printBoard(char board[][BOARD_SIZE])
{
    printf("   ");
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i+1);
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int getPosition(int x, int y)
{
    return ((x-1)*BOARD_SIZE)+(y-1);
}

int getJump(int x1, int y1, int x2, int y2, char board[][BOARD_SIZE])
{
    int pos1 = getPosition(x1,y1);
    int pos2 = getPosition(x2,y2);
    
    if(board[pos2/BOARD_SIZE][pos2%BOARD_SIZE] != ' ')
    {
        return -1;
    }
    
    int dx = x2-x1;
    int dy = y2-y1;
    int adx = (dx > 0) ? dx : -dx;
    int ady = (dy > 0) ? dy : -dy;
    
    if(adx != ady || adx > 2)
    {
        return -1;
    }
    if(adx == 1 && ady == 1)
    {
        return 0;
    }
    
    int xdir = (dx > 0) ? 1 : -1;
    int ydir = (dy > 0) ? 1 : -1;
    int middleX = x1 + xdir;
    int middleY = y1 + ydir;
    
    if(board[getPosition(middleX,middleY)/BOARD_SIZE][getPosition(middleX,middleY)%BOARD_SIZE] == ' ')
    {
        return -1;
    }
    
    if(board[getPosition(middleX,middleY)/BOARD_SIZE][getPosition(middleX,middleY)%BOARD_SIZE] != (board[pos1/BOARD_SIZE][pos1%BOARD_SIZE] == 'R' ? 'B' : 'R'))
    {
        return -1;
    }
    
    xdir *= 2;
    ydir *= 2;
    middleX += xdir;
    middleY += ydir;
    
    if(middleX < 1 || middleX > BOARD_SIZE || middleY < 1 || middleY > BOARD_SIZE)
    {
        return -1;
    }
    
    if(board[getPosition(middleX,middleY)/BOARD_SIZE][getPosition(middleX,middleY)%BOARD_SIZE] != ' ')
    {
        return -1;
    }
    
    return pos2;
}

int checkForWin(char board[][BOARD_SIZE], char player)
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == player || board[i][j] == (player == 'R' ? 'r' : 'b'))
            {
                if(i > 0 && j > 0 && board[i-1][j-1] == ' ')
                {
                    return 0;
                }
                if(i > 0 && j < 7 && board[i-1][j+1] == ' ')
                {
                    return 0;
                }
                if(i < 7 && j > 0 && board[i+1][j-1] == ' ')
                {
                    return 0;
                }
                if(i < 7 && j < 7 && board[i+1][j+1] == ' ')
                {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

void move(char board[][BOARD_SIZE], char player)
{
    int x1, y1, x2, y2, pos;
    int jumpFlag = 0;
    do
    {
        printf("Enter piece position (x y): ");
        scanf("%d %d", &x1, &y1);
        
        pos = getPosition(x1,y1);
        if(board[pos/BOARD_SIZE][pos%BOARD_SIZE] != player && board[pos/BOARD_SIZE][pos%BOARD_SIZE] != (player == 'R' ? 'r' : 'b'))
        {
            printf("Invalid position\n");
        }
    }while(board[pos/BOARD_SIZE][pos%BOARD_SIZE] != player && board[pos/BOARD_SIZE][pos%BOARD_SIZE] != (player == 'R' ? 'r' : 'b'));
    
    do
    {
        printf("Enter destination (x y): ");
        scanf("%d %d", &x2, &y2);
        
        int jumpDest = getJump(x1, y1, x2, y2, board);
        if(jumpDest == -1)
        {
            printf("Invalid move\n");
        }
        else
        {
            board[jumpDest/BOARD_SIZE][jumpDest%BOARD_SIZE] = board[pos/BOARD_SIZE][pos%BOARD_SIZE];
            board[pos/BOARD_SIZE][pos%BOARD_SIZE] = ' ';
            pos = jumpDest;
            jumpFlag = (jumpDest == getPosition(x2,y2)) ? 0 : 1;
        }
    }while(jumpFlag && !checkForWin(board,player));
    
    if(x2 == (player=='R'?8:1))
    {
        board[pos/BOARD_SIZE][pos%BOARD_SIZE] = (player == 'R' ? 'r' : 'b');
    }
}