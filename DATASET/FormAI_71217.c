//FormAI DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define EMPTY ' '
#define BLACK 'B'
#define WHITE 'W'
#define KING 'K'

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];
char turn = BLACK;

void initialize_board();
void print_board();
int move_valid(int x1, int y1, int x2, int y2);
void make_move(int x1, int y1, int x2, int y2);
void make_king(int x, int y);
int check_win();

int main()
{
    int x1, y1, x2, y2;
    int valid_move;
    
    initialize_board();
    
    while(check_win() == 0)
    {
        print_board();
        printf("It is %c's turn.\n", turn);
        
        do
        {
            printf("Enter the coordinates of the piece you want to move: ");
            scanf("%d %d", &x1, &y1);
        } while(board[x1][y1] == EMPTY || board[x1][y1] == WHITE || (turn == BLACK && board[x1][y1] != BLACK && board[x1][y1] != KING));
        
        do
        {
            printf("Enter the coordinates of where you want to move the piece: ");
            scanf("%d %d", &x2, &y2);
            valid_move = move_valid(x1, y1, x2, y2);
            if(!valid_move)
            {
                printf("Invalid move. Try again.\n");
            }
        } while(!valid_move);
        
        make_move(x1, y1, x2, y2);
        if((turn == BLACK && x2 == 0) || (turn == WHITE && x2 == ROWS-1))
        {
            make_king(x2, y2);
        }
        turn = (turn == BLACK) ? WHITE : BLACK;
    }
    
    print_board();
    printf("%c wins!\n", check_win());
    return 0;
}

void initialize_board()
{
    int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if((i+j) % 2 == 0)
            {
                if(i < 3) board[i][j] = BLACK;
        else if(i > 4) board[i][j] = WHITE;
        else board[i][j] = EMPTY;
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board()
{
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for(i=0; i<ROWS; i++)
    {
        printf("%d ", i);
        for(j=0; j<COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int move_valid(int x1, int y1, int x2, int y2)
{
    if(x2<0 || x2>=ROWS || y2<0 || y2>=COLS) return 0;
    if(board[x2][y2] != EMPTY) return 0;
    if((turn == BLACK && board[x1][y1] == BLACK) || (turn == WHITE && board[x1][y1] == WHITE))
    {
        if(x2 == x1+1 && (y2 == y1+1 || y2 == y1-1))
        {
            return 1;
        }
        else if(x2 == x1+2 && (y2 == y1+2 || y2 == y1-2))
        {
            if(board[(x1+x2)/2][(y1+y2)/2] == WHITE || board[(x1+x2)/2][(y1+y2)/2] == KING)
            {
                board[(x1+x2)/2][(y1+y2)/2] = EMPTY;
                return 1;
            }
        }
    }
    else if((turn == BLACK && board[x1][y1] == KING) || (turn == WHITE && board[x1][y1] == KING))
    {
        if((x2 == x1+1 || x2 == x1-1) && (y2 == y1+1 || y2 == y1-1))
        {
            return 1;
        }
        else if((x2 == x1+2 || x2 == x1-2) && (y2 == y1+2 || y2 == y1-2))
        {
            if(board[(x1+x2)/2][(y1+y2)/2] == BLACK || board[(x1+x2)/2][(y1+y2)/2] == KING)
            {
                board[(x1+x2)/2][(y1+y2)/2] = EMPTY;
                return 1;
            }
        }
    }
    return 0;
}

void make_move(int x1, int y1, int x2, int y2)
{
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = EMPTY;
}

void make_king(int x, int y)
{
    if(turn == BLACK)
    {
        board[x][y] = KING;
    }
    else if(turn == WHITE)
    {
        board[x][y] = KING;
    }
}

int check_win()
{
    int i, j;
    int black=0, white=0;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(board[i][j] == BLACK || board[i][j] == KING)
            {
                black++;
            }
            else if(board[i][j] == WHITE || board[i][j] == KING)
            {
                white++;
            }
        }
    }
    
    if(black == 0)
    {
        return WHITE;
    }
    else if(white == 0)
    {
        return BLACK;
    }
    
    return 0;
}