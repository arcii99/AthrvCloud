//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>

//Constants
#define BOARD_SIZE 8

//Function prototypes
void initialize_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int is_valid_move(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2);
void make_move(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2, char player);
int check_for_win(char board[][BOARD_SIZE], char player);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn = 1; //1 for player 1, 2 for player 2
    int r1, c1, r2, c2; //row and column positions for moves
    char player1 = 'x', player2 = 'o'; //pieces for player 1 and 2 respectively
    
    initialize_board(board);
    print_board(board);
    
    while(1)
    {
        printf("Turn %d: Player %d\n", turn, turn);
        
        //Get user input
        printf("Enter the row and column of the piece to move (separated by a space): ");
        scanf("%d %d", &r1, &c1);
        printf("Enter the row and column of the destination (separated by a space): ");
        scanf("%d %d", &r2, &c2);
        
        //Check if move is valid
        if(is_valid_move(board, r1, c1, r2, c2))
        {
            //Make the move
            if(turn == 1)
                make_move(board, r1, c1, r2, c2, player1);
            else
                make_move(board, r1, c1, r2, c2, player2);
            
            //Print the board after the move
            print_board(board);
            
            //Check for a win
            if(check_for_win(board, player1))
            {
                printf("Player 1 wins!");
                break;
            }
            else if(check_for_win(board, player2))
            {
                printf("Player 2 wins!");
                break;
            }
            
            //Switch turns
            if(turn == 1)
                turn = 2;
            else
                turn = 1;
        }
        else
        {
            printf("Invalid move, try again.\n");
        }
    }
    
    return 0;
}

//Function definitions
void initialize_board(char board[][BOARD_SIZE])
{
    int i, j;
    
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if((i + j) % 2 == 0 && i < 3)
                board[i][j] = 'o'; //player 2 piece
            else if((i + j) % 2 == 0 && i > 4)
                board[i][j] = 'x'; //player 1 piece
            else
                board[i][j] = ' ';
        }
    }
}

void print_board(char board[][BOARD_SIZE])
{
    int i, j;
    
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("-----------------\n");
        for(j = 0; j < BOARD_SIZE; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

int is_valid_move(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2)
{
    //Check if piece is on the board and is the player's piece
    if(r1 < 0 || r1 >= BOARD_SIZE || c1 < 0 || c1 >= BOARD_SIZE)
        return 0;
    else if(board[r1][c1] == ' ')
        return 0;
    
    //Check if destination is on the board and is empty
    if(r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE)
        return 0;
    else if(board[r2][c2] != ' ')
        return 0;
    
    //Check if move is a valid diagonal move
    if(((r1 - r2 == 1 || r2 - r1 == 1) && (c1 - c2 == 1 || c2 - c1 == 1)) &&
      ((board[r1][c1] == 'x' && r1 > r2) || (board[r1][c1] == 'o' && r1 < r2)))
    {
        return 1;
    }
    
    //Check if move is a valid diagonal jump
    if(((r1 - r2 == 2 || r2 - r1 == 2) && (c1 - c2 == 2 || c2 - c1 == 2)) &&
      ((board[r1][c1] == 'x' && r1 > r2) || (board[r1][c1] == 'o' && r1 < r2)))
    {
        //Check if there is an opponent's piece in the middle
        int mid_r = (r1 + r2) / 2;
        int mid_c = (c1 + c2) / 2;
        if(board[mid_r][mid_c] == 'x' || board[mid_r][mid_c] == 'o')
            return 1;
    }
    
    //Move is not valid
    return 0;
}

void make_move(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2, char player)
{
    //Make the move
    board[r1][c1] = ' ';
    board[r2][c2] = player;
    
    //Check if a jump was made and remove the opponent's piece
    if((r1 - r2 == 2 || r2 - r1 == 2) && (c1 - c2 == 2 || c2 - c1 == 2))
    {
        int mid_r = (r1 + r2) / 2;
        int mid_c = (c1 + c2) / 2;
        board[mid_r][mid_c] = ' ';
    }
}

int check_for_win(char board[][BOARD_SIZE], char player)
{
    int i, j;
    
    //Check if all opponent's pieces are gone
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] != player && board[i][j] != ' ')
                return 0;
        }
    }
    
    //Player has won
    return 1;
}