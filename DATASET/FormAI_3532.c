//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void displayBoard(int board[][10], int rows, int cols);
int getUserInput(int player);
void placePiece(int board[][10], int rows, int cols, int col, int piece);
int checkWin(int board[][10], int rows, int cols, int piece);
int checkHorizontal(int board[][10], int rows, int cols, int piece);
int checkVertical(int board[][10], int rows, int cols, int piece);
int checkDiagonal1(int board[][10], int rows, int cols, int piece);
int checkDiagonal2(int board[][10], int rows, int cols, int piece);

int main()
{
    // initialize the board with all 0s
    int board[6][10] = {{0}};

    // initialize other variables
    int rows = 6, cols = 10;
    int player = 1, input, win = 0;

    // seed the random number generator
    srand(time(NULL));

    // game loop
    while (!win)
    {
        // switch players
        player = player == 1 ? 2 : 1;

        // display the board
        displayBoard(board, rows, cols);

        // get user input or computer input if player 2
        if (player == 1)
        {
            input = getUserInput(player);
        }
        else
        {
            printf("Player 2 is thinking...\n");
            input = rand() % cols;
        }

        // place the piece on the board
        placePiece(board, rows, cols, input, player);

        // check for win
        win = checkWin(board, rows, cols, player);

        // check for tie
        if (!win && input == -1)
        {
            printf("It's a tie!\n");
            exit(0);
        }
    }

    // display the winning board
    displayBoard(board, rows, cols);

    // announce the winner
    printf("Player %d wins!\n", player);

    return 0;
}

// function to display the current state of the board
void displayBoard(int board[][10], int rows, int cols)
{
    printf("\n");
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("| %s ", board[i][j] ? (board[i][j] == 1 ? "X" : "O") : " ");
        }
        printf("|\n");
    }
    printf("- - - - - - - - - - -\n");
    for (int i = 0; i < cols; i++)
    {
        printf("  %d ", i);
    }
    printf("\n\n");
}

// function to get user input and validate it
int getUserInput(int player)
{
    int input;
    printf("Player %d's turn. Enter column (0-9) or -1 to quit: ", player);
    scanf("%d", &input);
    while (input < -1 || input > 9)
    {
        printf("Invalid input. Enter column (0-9) or -1 to quit: ");
        scanf("%d", &input);
    }
    return input;
}

// function to place a piece on the board
void placePiece(int board[][10], int rows, int cols, int col, int piece)
{
    if (col == -1)
    {
        return;
    }
    for (int row = 0; row < rows; row++)
    {
        if (board[row][col] == 0)
        {
            board[row][col] = piece;
            return;
        }
    }
    // if column is full, ask for input again
    printf("Column is full. Enter column (0-9) or -1 to quit: ");
    scanf("%d", &col);
    placePiece(board, rows, cols, col, piece);
}

// function to check for a win
int checkWin(int board[][10], int rows, int cols, int piece)
{
    // horizontal check
    if (checkHorizontal(board, rows, cols, piece))
    {
        return 1;
    }

    // vertical check
    if (checkVertical(board, rows, cols, piece))
    {
        return 1;
    }

    // diagonal check \
    if (checkDiagonal1(board, rows, cols, piece))
    {
        return 1;
    }

    // diagonal check /
    if (checkDiagonal2(board, rows, cols, piece))
    {
        return 1;
    }

    return 0;
}

// function to check for a horizontal win
int checkHorizontal(int board[][10], int rows, int cols, int piece)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols - 3; col++)
        {
            if (board[row][col] == piece && board[row][col+1] == piece && board[row][col+2] == piece && board[row][col+3] == piece)
            {
                return 1;
            }
        }
    }
    return 0;
}

// function to check for a vertical win
int checkVertical(int board[][10], int rows, int cols, int piece)
{
    for (int row = 0; row < rows - 3; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] == piece && board[row+1][col] == piece && board[row+2][col] == piece && board[row+3][col] == piece)
            {
                return 1;
            }
        }
    }
    return 0;
}

// function to check for a diagonal win (\)
int checkDiagonal1(int board[][10], int rows, int cols, int piece)
{
    for (int row = 0; row < rows - 3; row++)
    {
        for (int col = 0; col < cols - 3; col++)
        {
            if (board[row][col] == piece && board[row+1][col+1] == piece && board[row+2][col+2] == piece && board[row+3][col+3] == piece)
            {
                return 1;
            }
        }
    }
    return 0;
}

// function to check for a diagonal win (/)
int checkDiagonal2(int board[][10], int rows, int cols, int piece)
{
    for (int row = 0; row < rows - 3; row++)
    {
        for (int col = 3; col < cols; col++)
        {
            if (board[row][col] == piece && board[row+1][col-1] == piece && board[row+2][col-2] == piece && board[row+3][col-3] == piece)
            {
                return 1;
            }
        }
    }
    return 0;
}