//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>
#define ROWS 8
#define COLUMNS 8

int board[ROWS][COLUMNS]; // initialize board

void initialize_board(); // function prototypes
void print_board();
int check_move(int, int, int, int);
void move_piece(int, int, int, int);

int main()
{
    initialize_board(); // initialize the board
    print_board(); // print the board state

    int turn = 1; // initialize the turn counter
    int game_over = 0; // initialize game over flag

    while(!game_over) // loop until game over
    {
        int selected_row, selected_column, target_row, target_column;
        printf("Player %d's turn.\n", turn); // print turn indicator

        // get user input for selected piece and target position
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &selected_row, &selected_column);

        printf("Enter the row and column of the target position: ");
        scanf("%d %d", &target_row, &target_column);

        if(check_move(selected_row, selected_column, target_row, target_column))
        {
            // move piece if valid move
            move_piece(selected_row, selected_column, target_row, target_column);

            // check for game over
            game_over = 1;
            for(int i=0; i<ROWS; i++)
            {
                for(int j=0; j<COLUMNS; j++)
                {
                    if(board[i][j] == turn)
                    {
                        if(check_move(i, j, i+1, j+1) || check_move(i, j, i+1, j-1) ||
                           check_move(i, j, i-1, j+1) || check_move(i, j, i-1, j-1))
                        {
                            game_over = 0;
                            break;
                        }
                    }
                }
                if(!game_over)
                    break;
            }

            // switch turns
            if(turn == 1)
                turn = 2;
            else
                turn = 1;

            print_board(); // print board state
        }
        else
        {
            printf("Invalid move. Please enter a valid move.\n");
        }
    }

    // print game over message
    printf("Player %d wins!\n", turn);

    return 0; // end program
}

// function definitions

void initialize_board()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            if(i%2 == 0 && j%2 == 0)
                board[i][j] = 0; // empty space
            else if(i%2 != 0 && j%2 != 0 && i < 3)
                board[i][j] = 2; // player 2 piece
            else if(i%2 != 0 && j%2 != 0 && i > 4)
                board[i][j] = 1; // player 1 piece
            else
                board[i][j] = -1; // invalid position
        }
    }
}

void print_board()
{
    printf("  ");
    for(int i=0; i<COLUMNS; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for(int i=0; i<ROWS; i++)
    {
        printf("%d ", i);
        for(int j=0; j<COLUMNS; j++)
        {
            if(board[i][j] == 0)
                printf(". ");
            else if(board[i][j] == 1)
                printf("x ");
            else if(board[i][j] == 2)
                printf("o ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int check_move(int selected_row, int selected_column, int target_row, int target_column)
{
    // check if target position is within bounds
    if(target_row < 0 || target_row >= ROWS || target_column < 0 || target_column >= COLUMNS)
        return 0;

    // check if target position is empty
    if(board[target_row][target_column] != 0)
        return 0;

    // check if selected piece belongs to current player
    if(board[selected_row][selected_column] != 1 && board[selected_row][selected_column] != 2)
        return 0;

    // check if selected piece can make valid move
    if(board[selected_row][selected_column] == 1) // player 1 piece
    {
        if(target_row == selected_row-1 && (target_column == selected_column-1 || target_column == selected_column+1))
            return 1; // normal move
        else if(target_row == selected_row-2 && target_column == selected_column+2 &&
                board[selected_row-1][selected_column+1] == 2)
        {
            board[selected_row-1][selected_column+1] = 0; // remove opponent's piece
            return 1; // capture move
        }
        else if(target_row == selected_row-2 && target_column == selected_column-2 &&
                board[selected_row-1][selected_column-1] == 2)
        {
            board[selected_row-1][selected_column-1] = 0; // remove opponent's piece
            return 1; // capture move
        }
        else
            return 0; // invalid move
    }
    else // player 2 piece
    {
        if(target_row == selected_row+1 && (target_column == selected_column-1 || target_column == selected_column+1))
            return 1; // normal move
        else if(target_row == selected_row+2 && target_column == selected_column+2 &&
                board[selected_row+1][selected_column+1] == 1)
        {
            board[selected_row+1][selected_column+1] = 0; // remove opponent's piece
            return 1; // capture move
        }
        else if(target_row == selected_row+2 && target_column == selected_column-2 &&
                board[selected_row+1][selected_column-1] == 1)
        {
            board[selected_row+1][selected_column-1] = 0; // remove opponent's piece
            return 1; // capture move
        }
        else
            return 0; // invalid move
    }
}

void move_piece(int selected_row, int selected_column, int target_row, int target_column)
{
    board[target_row][target_column] = board[selected_row][selected_column];
    board[selected_row][selected_column] = 0;
}