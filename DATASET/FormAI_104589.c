//FormAI DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>

// Constants
#define BOARD_SIZE 8
#define EMPTY_SPACE '-'
#define BLACK_PAWN 'B'
#define BLACK_KING 'K'
#define WHITE_PAWN 'W'
#define WHITE_KING 'M'

// Global Variables
char board[BOARD_SIZE][BOARD_SIZE];

// Function Prototypes
void initializeBoard();
void displayBoard();
void makeMove(char player[], int move[]);
int isLegal(char player[], int move[]);
int isCaptureMove(char player[], int move[]);
void makeCaptureMove(char player[], int move[]);
int canCapture(char player[]);
void makeComputerMove(char player[]);

// Main Function
int main()
{
    char player1[] = "Player 1";
    char player2[] = "Computer";
    int player1Pieces = 12;
    int player2Pieces = 12;
    int move[4];
    int currentPlayer = 1;
    int gameOver = 0;

    // Set up the board
    initializeBoard();
    displayBoard();

    // Main game loop
    while (!gameOver)
    {
        // Player 1's turn
        if (currentPlayer == 1)
        {
            printf("%s's turn:\n", player1);
            makeMove(player1, move);
            currentPlayer = 2;
        }
        // Computer's turn
        else
        {
            printf("%s's turn:\n", player2);
            makeComputerMove(player2);
            currentPlayer = 1;
        }

        // Check for game over
        player1Pieces = 0;
        player2Pieces = 0;
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (board[row][col] == BLACK_PAWN || board[row][col] == BLACK_KING)
                {
                    player1Pieces++;
                }
                else if (board[row][col] == WHITE_PAWN || board[row][col] == WHITE_KING)
                {
                    player2Pieces++;
                }
            }
        }

        if (player1Pieces == 0)
        {
            printf("%s wins!\n", player2);
            gameOver = 1;
        }
        else if (player2Pieces == 0)
        {
            printf("%s wins!\n", player1);
            gameOver = 1;
        }
    }

    return 0;
}

// Initialize the board
void initializeBoard()
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if ((row + col) % 2 == 0)
            {
                if (row < 3)
                {
                    board[row][col] = WHITE_PAWN;
                }
                else if (row > 4)
                {
                    board[row][col] = BLACK_PAWN;
                }
                else
                {
                    board[row][col] = EMPTY_SPACE;
                }
            }
            else
            {
                board[row][col] = EMPTY_SPACE;
            }
        }
    }
}

// Display the board
void displayBoard()
{
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

// Prompt the user for a move and make it
void makeMove(char player[], int move[])
{
    // Prompt for move
    printf("Enter your move (row col newRow newCol): ");
    scanf("%d %d %d %d", &move[0], &move[1], &move[2], &move[3]);

    // Check if move is legal and make move
    if (isLegal(player, move))
    {
        board[move[2]][move[3]] = board[move[0]][move[1]];
        board[move[0]][move[1]] = EMPTY_SPACE;
        // Check for promotion to king
        if (board[move[2]][move[3]] == WHITE_PAWN && move[2] == 0)
        {
            board[move[2]][move[3]] = WHITE_KING;
        }
        else if (board[move[2]][move[3]] == BLACK_PAWN && move[2] == 7)
        {
            board[move[2]][move[3]] = BLACK_KING;
        }
        // Check for capture move
        if (isCaptureMove(player, move))
        {
            makeCaptureMove(player, move);
        }
    }
    else
    {
        printf("Invalid move. Try again!\n");
        makeMove(player, move);
    }

    // Display the board after move
    displayBoard();
}

// Check if a move is legal
int isLegal(char player[], int move[])
{
    // Check if piece belongs to player
    if ((player == "Player 1" && (board[move[0]][move[1]] == BLACK_PAWN || board[move[0]][move[1]] == BLACK_KING)) || 
        (player == "Computer" && (board[move[0]][move[1]] == WHITE_PAWN || board[move[0]][move[1]] == WHITE_KING)))
    {
        // Check that move is diagonal
        if (abs(move[2] - move[0]) != abs(move[3] - move[1]))
        {
            return 0;
        }
        // Check that move is one or two spaces
        else if (abs(move[2] - move[0]) == 1)
        {
            return 1;
        }
        // Check that move is a capture move
        else if (abs(move[2] - move[0]) == 2)
        {
            return isCaptureMove(player, move);
        }
    }
    return 0;
}

// Check if a move is a capture move
int isCaptureMove(char player[], int move[])
{
    // Check that there is a piece to capture
    if (board[(move[0] + move[2])/2][(move[1] + move[3])/2] == (player == "Player 1" ? WHITE_PAWN : BLACK_PAWN) ||
        board[(move[0] + move[2])/2][(move[1] + move[3])/2] == (player == "Player 1" ? WHITE_KING : BLACK_KING))
    {
        // Check that there is a space to land after capture
        if (board[move[2]][move[3]] == EMPTY_SPACE)
        {
            return 1;
        }
    }
    return 0;
}

// Make a capture move
void makeCaptureMove(char player[], int move[])
{
    // Remove captured piece
    board[(move[0] + move[2])/2][(move[1] + move[3])/2] = EMPTY_SPACE;
    // Promote to king if necessary
    if (player == "Player 1" && move[2] == 0)
    {
        board[move[2]][move[3]] = BLACK_KING;
    }
    else if (player == "Computer" && move[2] == 7)
    {
        board[move[2]][move[3]] = WHITE_KING;
    }
}

// Check if the player can make a capture move
int canCapture(char player[])
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if ((player == "Player 1" && (board[row][col] == BLACK_PAWN || board[row][col] == BLACK_KING)) || 
                (player == "Computer" && (board[row][col] == WHITE_PAWN || board[row][col] == WHITE_KING)))
            {
                for (int i = -2; i <= 2; i += 4)
                {
                    for (int j = -2; j <= 2; j += 4)
                    {
                        if (row+i >= 0 && row+i < BOARD_SIZE && col+j >= 0 && col+j < BOARD_SIZE)
                        {
                            if (board[row+i/2][col+j/2] == (player == "Player 1" ? WHITE_PAWN : BLACK_PAWN) ||
                                board[row+i/2][col+j/2] == (player == "Player 1" ? WHITE_KING : BLACK_KING))
                            {
                                if (board[row+i][col+j] == EMPTY_SPACE)
                                {
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// Have the computer make a move
void makeComputerMove(char player[])
{
    int move[4];

    // Check for capture move
    if (canCapture(player))
    {
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if ((player == "Player 1" && (board[row][col] == BLACK_PAWN || board[row][col] == BLACK_KING)) || 
                    (player == "Computer" && (board[row][col] == WHITE_PAWN || board[row][col] == WHITE_KING)))
                {
                    for (int i = -2; i <= 2; i += 4)
                    {
                        for (int j = -2; j <= 2; j += 4)
                        {
                            if (row+i >= 0 && row+i < BOARD_SIZE && col+j >= 0 && col+j < BOARD_SIZE)
                            {
                                if (board[row+i/2][col+j/2] == (player == "Player 1" ? WHITE_PAWN : BLACK_PAWN) ||
                                    board[row+i/2][col+j/2] == (player == "Player 1" ? WHITE_KING : BLACK_KING))
                                {
                                    if (board[row+i][col+j] == EMPTY_SPACE)
                                    {
                                        move[0] = row;
                                        move[1] = col;
                                        move[2] = row+i;
                                        move[3] = col+j;
                                        printf("Computer chooses capture move %d %d %d %d\n", row, col, row+i, col+j);
                                        board[move[2]][move[3]] = board[move[0]][move[1]];
                                        board[move[0]][move[1]] = EMPTY_SPACE;
                                        makeCaptureMove(player, move);
                                        // Check for promotion to king
                                        if (board[move[2]][move[3]] == WHITE_PAWN && move[2] == 0)
                                        {
                                            board[move[2]][move[3]] = WHITE_KING;
                                        }
                                        else if (board[move[2]][move[3]] == BLACK_PAWN && move[2] == 7)
                                        {
                                            board[move[2]][move[3]] = BLACK_KING;
                                        }
                                        // Display the board after move
                                        displayBoard();
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Choose a random move
    do
    {
        move[0] = rand() % BOARD_SIZE;
        move[1] = rand() % BOARD_SIZE;
        move[2] = rand() % BOARD_SIZE;
        move[3] = rand() % BOARD_SIZE;
    } while(!isLegal(player, move));

    // Make move
    printf("Computer chooses move %d %d %d %d\n", move[0], move[1], move[2], move[3]);
    board[move[2]][move[3]] = board[move[0]][move[1]];
    board[move[0]][move[1]] = EMPTY_SPACE;
    // Check for promotion to king
    if (board[move[2]][move[3]] == WHITE_PAWN && move[2] == 0)
    {
        board[move[2]][move[3]] = WHITE_KING;
    }
    else if (board[move[2]][move[3]] == BLACK_PAWN && move[2] == 7)
    {
        board[move[2]][move[3]] = BLACK_KING;
    }
    // Display the board after move
    displayBoard();
}