//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
char player1 = 'W', player2 = 'B';

void initialize_board()
{
    int i,j;
    for(i=0; i<BOARD_SIZE; i++)
    {
        for(j=0; j<BOARD_SIZE; j++)
        {
            // initialize the board with ' ' for empty cells
            if((i+j)%2 == 0) board[i][j] = ' ';
            else
            {
                if(i < 3) board[i][j] = player1;
                else if(i > 4) board[i][j] = player2;
                else board[i][j] = ' ';
            }
        }
    }
}

void display_board()
{
    int i,j;
    printf("  ");
    for(i=0; i<BOARD_SIZE; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n"); 
    for(i=0; i<BOARD_SIZE; i++)
    {
        printf("%d ", i+1);
        for(j=0; j<BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void make_move(int row, int col, int to_row, int to_col)
{
    if(board[row][col] == ' ') return;
    if(to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) return;

    // check if the move is valid
    if(board[to_row][to_col] == ' ')
    {
        board[to_row][to_col] = board[row][col];
        board[row][col] = ' ';
    }
    else
    {
        // check if the move is valid and capture an opponent piece
        int offset_row = to_row - row;
        int offset_col = to_col - col;
        int capture_row = to_row + offset_row;
        int capture_col = to_col + offset_col;
        if(capture_row >= 0 && capture_row < BOARD_SIZE 
            && capture_col >= 0 && capture_col < BOARD_SIZE 
            && board[capture_row][capture_col] == ' ')
            {
                board[capture_row][capture_col] = board[row][col];
                board[row][col] = ' ';
                board[to_row][to_col] = ' ';
            }
            else return;
    }
}

void play_game()
{
    int player_turn = 1;
    int row, col, to_row, to_col;
    while(1)
    {
        display_board();
        printf("Player %d's turn\n", player_turn);
        printf("Enter row and column of piece you want to move: ");
        scanf("%d%d", &row, &col);
        printf("Enter row and column of where you want to move: ");
        scanf("%d%d", &to_row, &to_col);

        make_move(row-1, col-1, to_row-1, to_col-1);

        if(player_turn == 1) player_turn = 2;
        else player_turn = 1;
    }
}

int main()
{
    initialize_board();
    play_game();
    return 0;
}