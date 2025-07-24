//FormAI DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHESSBOARD_SIZE 8

int board[CHESSBOARD_SIZE][CHESSBOARD_SIZE];
int player;

int abs(int n)
{
    return (n < 0) ? -n : n;
}

void display_board()
{
    int i, j;
    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        for(j=0; j<CHESSBOARD_SIZE; j++)
        {
            printf("| ");
            if(board[i][j] == 0)
            {
                printf("   ");
            }
            else if(board[i][j] == 1)
            {
                printf(" P ");
            }
            else if(board[i][j] == 2)
            {
                printf(" R ");
            }
            else if(board[i][j] == 3)
            {
                printf(" N ");
            }
            else if(board[i][j] == 4)
            {
                printf(" B ");
            }
            else if(board[i][j] == 5)
            {
                printf(" Q ");
            }
            else if(board[i][j] == 6)
            {
                printf(" K ");
            }
            printf("| ");
        }
        printf("\n");
    }
}

void initialize_board()
{
    int i, j;

    // Clear board
    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        for(j=0; j<CHESSBOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set white pieces
    board[0][0] = board[0][7] = 2;
    board[0][1] = board[0][6] = 3;
    board[0][2] = board[0][5] = 4;
    board[0][3] = 5;
    board[0][4] = 6;

    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        board[1][i] = 1;
    }

    // Set black pieces
    board[7][0] = board[7][7] = -2;
    board[7][1] = board[7][6] = -3;
    board[7][2] = board[7][5] = -4;
    board[7][3] = -5;
    board[7][4] = -6;

    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        board[6][i] = -1;
    }

    player = 1;
}

int is_valid_move(int fromx, int fromy, int tox, int toy)
{
    int type = abs(board[fromx][fromy]);
    int color = board[fromx][fromy] / type;

    if(board[tox][toy] != 0 && board[tox][toy] / abs(board[tox][toy]) == color)
    {
        return 0;
    }

    switch(type)
    {
        case 1: // Pawn
            if(fromy == toy && board[tox][toy] == 0)
            {
                if(color == 1)
                {
                    if(fromx == 1)
                    {
                        if(tox == fromx+1 || tox == fromx+2)
                        {
                            return 1;
                        }
                    }
                    else if(tox == fromx+1)
                    {
                        return 1;
                    }
                }
                else // color == -1
                {
                    if(fromx == 6)
                    {
                        if(tox == fromx-1 || tox == fromx-2)
                        {
                            return 1;
                        }
                    }
                    else if(tox == fromx-1)
                    {
                        return 1;
                    }
                }
            }
            else if(abs(fromy - toy) == 1 && board[tox][toy] != 0)
            {
                if(color == 1 && tox == fromx+1)
                {
                    return 1;
                }
                else if(color == -1 && tox == fromx-1)
                {
                    return 1;
                }
            }
            break;
        case 2: // Rook
            if(fromx == tox)
            {
                int direction = (toy > fromy) ? 1 : -1;
                int i;
                for(i=fromy+direction; i!=toy; i+=direction)
                {
                    if(board[fromx][i] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else if(fromy == toy)
            {
                int direction = (tox > fromx) ? 1 : -1;
                int i;
                for(i=fromx+direction; i!=tox; i+=direction)
                {
                    if(board[i][fromy] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case 3: // Knight
            if((abs(fromx-tox) == 2 && abs(fromy-toy) == 1) || (abs(fromx-tox) == 1 && abs(fromy-toy) == 2))
            {
                return 1;
            }
            break;
        case 4: // Bishop
            if(abs(fromx-tox) == abs(fromy-toy))
            {
                int xdirection = (tox > fromx) ? 1 : -1;
                int ydirection = (toy > fromy) ? 1 : -1;
                int i;
                for(i=1; i<abs(tox-fromx); i++)
                {
                    if(board[fromx+i*xdirection][fromy+i*ydirection] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case 5: // Queen
            if(fromx == tox)
            {
                int direction = (toy > fromy) ? 1 : -1;
                int i;
                for(i=fromy+direction; i!=toy; i+=direction)
                {
                    if(board[fromx][i] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else if(fromy == toy)
            {
                int direction = (tox > fromx) ? 1 : -1;
                int i;
                for(i=fromx+direction; i!=tox; i+=direction)
                {
                    if(board[i][fromy] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else if(abs(fromx-tox) == abs(fromy-toy))
            {
                int xdirection = (tox > fromx) ? 1 : -1;
                int ydirection = (toy > fromy) ? 1 : -1;
                int i;
                for(i=1; i<abs(tox-fromx); i++)
                {
                    if(board[fromx+i*xdirection][fromy+i*ydirection] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case 6: // King
            if(abs(fromx-tox) <= 1 && abs(fromy-toy) <= 1)
            {
                return 1;
            }
            break;
    }

    return 0;
}

int is_check(int color)
{
    int i, j;

    // Find the king of that color
    int kingx = -1, kingy = -1;
    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        for(j=0; j<CHESSBOARD_SIZE; j++)
        {
            if(abs(board[i][j]) == 6 && board[i][j]/abs(board[i][j]) == color)
            {
                kingx = i;
                kingy = j;
            }
        }
    }

    // Check for pawns
    if(color == 1)
    {
        if(kingx > 0 && kingy > 0 && board[kingx-1][kingy-1] == -1)
        {
            return 1;
        }
        else if(kingx > 0 && kingy < 7 && board[kingx-1][kingy+1] == -1)
        {
            return 1;
        }
    }
    else // color == -1
    {
        if(kingx < 7 && kingy > 0 && board[kingx+1][kingy-1] == 1)
        {
            return 1;
        }
        else if(kingx < 7 && kingy < 7 && board[kingx+1][kingy+1] == 1)
        {
            return 1;
        }
    }

    // Check for all other pieces
    int type, tox, toy;
    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        for(j=0; j<CHESSBOARD_SIZE; j++)
        {
            if(board[i][j] != 0 && board[i][j]/abs(board[i][j]) == color)
            {
                type = abs(board[i][j]);
                for(tox=0; tox<CHESSBOARD_SIZE; tox++)
                {
                    for(toy=0; toy<CHESSBOARD_SIZE; toy++)
                    {
                        if(is_valid_move(i, j, tox, toy))
                        {
                            int temp = board[tox][toy];
                            board[tox][toy] = board[i][j];
                            board[i][j] = 0;

                            if(abs(board[tox][toy]) == 6 && board[tox][toy]/abs(board[tox][toy]) == color)
                            {
                                board[i][j] = board[tox][toy];
                                board[tox][toy] = temp;
                                return 1;
                            }

                            board[i][j] = board[tox][toy];
                            board[tox][toy] = temp;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int is_checkmate(int color)
{
    int i, j, k, l;
    int type, tox, toy;
    for(i=0; i<CHESSBOARD_SIZE; i++)
    {
        for(j=0; j<CHESSBOARD_SIZE; j++)
        {
            if(board[i][j] != 0 && board[i][j]/abs(board[i][j]) == color)
            {
                type = abs(board[i][j]);
                for(tox=0; tox<CHESSBOARD_SIZE; tox++)
                {
                    for(toy=0; toy<CHESSBOARD_SIZE; toy++)
                    {
                        if(is_valid_move(i, j, tox, toy))
                        {
                            int temp = board[tox][toy];
                            board[tox][toy] = board[i][j];
                            board[i][j] = 0;

                            if(!is_check(color))
                            {
                                board[i][j] = board[tox][toy];
                                board[tox][toy] = temp;
                                return 0;
                            }

                            board[i][j] = board[tox][toy];
                            board[tox][toy] = temp;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

void make_move()
{
    int x1, y1, x2, y2;
    char temp[5];
    printf("Enter your move (e.g. e2e4): ");
    scanf("%s", temp);
    x1 = temp[0] - 'a';
    y1 = temp[1] - '1';
    x2 = temp[2] - 'a';
    y2 = temp[3] - '1';

    if(is_valid_move(y1, x1, y2, x2))
    {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = 0;
    }
    else
    {
        printf("Invalid move\n");
        make_move();
    }
}

int main()
{
    initialize_board();
    while(1)
    {
        display_board();
        if(is_check(player))
        {
            printf("Check!\n");
        }
        if(is_checkmate(player))
        {
            printf("Checkmate! Player %d wins.\n", -player);
            break;
        }
        make_move();
        player = -player;
    }
    return 0;
}