//FormAI DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>

// Defining constants for the board size
#define BOARD_SIZE 8
#define ROW_SIZE 64

// Function to display the board
void display_board(char (*board)[BOARD_SIZE])
{
    printf("\n    ");
    for(int i=0; i<BOARD_SIZE; i++)
        printf("%c   ", 'a'+i);
    printf("\n  ");
    for(int i=0; i<BOARD_SIZE*4+1; i++)
        printf("-");
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++)
    {
        printf("%d | ", BOARD_SIZE-i);
        for(int j=0; j<BOARD_SIZE; j++)
            printf("%c | ", board[i][j]);
        printf("%d\n", BOARD_SIZE-i);
        printf("  ");
        for(int k=0; k<BOARD_SIZE*4+1; k++)
            printf("-");
        printf("\n");
    }
    printf("    ");
    for(int i=0; i<BOARD_SIZE; i++)
        printf("%c   ", 'a'+i);
    printf("\n\n");
}

// Function to initialize the board
void init_board(char (*board)[BOARD_SIZE])
{
    // Initializing the white pieces
    board[0][0] = board[0][7] = 'R';
    board[0][1] = board[0][6] = 'N';
    board[0][2] = board[0][5] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    for(int i=0; i<BOARD_SIZE; i++)
        board[1][i] = 'P';

    // Initializing the black pieces
    board[7][0] = board[7][7] = 'r';
    board[7][1] = board[7][6] = 'n';
    board[7][2] = board[7][5] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    for(int i=0; i<BOARD_SIZE; i++)
        board[6][i] = 'p';

    // Initializing empty spaces
    for(int i=2; i<6; i++)
        for(int j=0; j<BOARD_SIZE; j++)
            board[i][j] = ' ';
}

// Function to get input from the user
void get_input(char (*board)[BOARD_SIZE], char *piece, int *x, int *y)
{
    char row, col;
    printf("Enter the piece you want to move: ");
    scanf(" %c%d", &col, x);
    *y = col - 'a';
    *x = BOARD_SIZE - *x;

    // Validating the input
    if(*x > BOARD_SIZE || *y > BOARD_SIZE || *x < 0 || *y < 0 || board[*x][*y] == ' ')
    {
        printf("Invalid input. Please try again.\n");
        get_input(board, piece, x, y);
        return;
    }

    *piece = board[*x][*y];

    printf("Enter the destination: ");
    scanf(" %c%d", &col, y);
    *x = BOARD_SIZE - *y;
    *y = col - 'a';

    // Validating the input
    if(*x > BOARD_SIZE || *y > BOARD_SIZE || *x < 0 || *y < 0)
    {
        printf("Invalid input. Please try again.\n");
        get_input(board, piece, x, y);
        return;
    }

    // Checking if the move is valid
    switch(*piece)
    {
        case 'P':
            if(*x == 1 && *y == col-'a' && (board[*x+1][*y] != ' ' || board[*x+2][*y] != ' '))
            {
                printf("Invalid input. Please try again.\n");
                get_input(board, piece, x, y);
                return;
            }
            if((*x == 3 && *y != col-'a') || (*x == 4 && *y == col-'a' && board[*x][*y] != ' '))
            {
                printf("Invalid input. Please try again.\n");
                get_input(board, piece, x, y);
                return;
            }
            break;
        case 'p':
            if(*x == 6 && *y == col-'a' && (board[*x-1][*y] != ' ' || board[*x-2][*y] != ' '))
            {
                printf("Invalid input. Please try again.\n");
                get_input(board, piece, x, y);
                return;
            }
            if((*x == 3 && *y != col-'a') || (*x == 2 && *y == col-'a' && board[*x][*y] != ' '))
            {
                printf("Invalid input. Please try again.\n");
                get_input(board, piece, x, y);
                return;
            }
            break;
        case 'R':
        case 'r':
            if((*x != BOARD_SIZE-1 && *y != BOARD_SIZE-1 && *x != 0 && *y != 0) &&
                (board[*x+1][*y+1] != ' ' || board[*x+1][*y] != ' ' || board[*x+1][*y-1] != ' ' ||
                 board[*x][*y+1] != ' ' || board[*x][*y-1] != ' ' ||
                 board[*x-1][*y+1] != ' ' || board[*x-1][*y] != ' ' || board[*x-1][*y-1] != ' '))
            {
                printf("Invalid input. Please try again.\n");
                get_input(board, piece, x, y);
                return;
            }
            break;
    }
}

// Main function
int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];

    init_board(board);

    // Displaying the initial board
    display_board(board);

    char piece;
    int x, y;

    // Getting the input from the user
    get_input(board, &piece, &x, &y);

    // Moving the piece to the new position
    board[x][y] = piece;
    board[x][y] = ' ';
    display_board(board);

    return 0;
}