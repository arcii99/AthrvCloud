//FormAI DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>

#define ROWS 8
#define COLS 8

void initializeBoard(char board[][COLS]);
void printBoard(char board[][COLS]);
int isValidMove(char board[][COLS], int cRow, int cCol, int nRow, int nCol, char player);
int isJump(char board[][COLS], int cRow, int cCol, int nRow, int nCol, char player);
void makeMove(char board[][COLS], int cRow, int cCol, int nRow, int nCol, char player);

int main()
{
    char board[ROWS][COLS];
    char player = 'B';
    int cRow, cCol, nRow, nCol;
    
    initializeBoard(board);
    
    printf("CHECKERS GAME\n");
    printf("---------------\n");
    printf("Instructions:\n");
    printf("Enter the row and column numbers of the piece you want to move followed by the row and column numbers of where you want to move it to.\n");
    printf("Example: 2 3 3 4\n\n");
    
    while(1)
    {
        // Print the current state of the board and player turn
        printf("Player %c's turn\n", player);
        printBoard(board);
        
        // Get the coordinates of the piece the player wants to move
        printf("Enter the current row and column of the piece you want to move:\n");
        scanf("%d %d", &cRow, &cCol);
        
        // Get the coordinates of the spot the player wants to move the piece to
        printf("Enter the row and column of where you want to move the piece to:\n");
        scanf("%d %d", &nRow, &nCol);
        
        // Check if the move is valid
        if(isValidMove(board, cRow, cCol, nRow, nCol, player))
        {
            // Make the move on the board
            makeMove(board, cRow, cCol, nRow, nCol, player);
            
            // Check if the player won
            // Player B wins when all of Player A's pieces are gone, Player A wins when all of Player B's pieces are gone
            int bPieces = 0;
            int wPieces = 0;
            for(int row = 0; row < ROWS; row++)
            {
                for(int col = 0; col < COLS; col++)
                {
                    if(board[row][col] == 'B')
                    {
                        bPieces++;
                    }
                    else if(board[row][col] == 'W')
                    {
                        wPieces++;
                    }
                }
            }
            if(bPieces == 0)
            {
                printf("PLAYER A WINS!\n");
                break;
            }
            else if(wPieces == 0)
            {
                printf("PLAYER B WINS!\n");
                break;
            }
            
            // Switch players
            if(player == 'B')
            {
                player = 'W';
            }
            else
            {
                player = 'B';
            }
        }
        else
        {
            printf("Invalid move, try again.\n\n");
        }
    }
    
    return 0;
}

// Initialize the board to its starting state
void initializeBoard(char board[][COLS])
{
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            if(row < 3 && (row + col) % 2 == 0)
            {
                board[row][col] = 'B';
            }
            else if(row > 4 && (row + col) % 2 == 0)
            {
                board[row][col] = 'W';
            }
            else
            {
                board[row][col] = ' ';
            }
        }
    }
}

// Print the current state of the board
void printBoard(char board[][COLS])
{
    printf("\n  0 1 2 3 4 5 6 7\n");
    for(int row = 0; row < ROWS; row++)
    {
        printf("%d ", row);
        for(int col = 0; col < COLS; col++)
        {
            if(col != 7)
            {
                printf("%c|", board[row][col]);
            }
            else
            {
                printf("%c", board[row][col]);
            }
        }
        if(row != 7)
        {
            printf("\n  -+-+-+-+-+-+-\n");
        }
    }
    printf("\n\n");
}

// Check if the move is valid
int isValidMove(char board[][COLS], int cRow, int cCol, int nRow, int nCol, char player)
{
    // Check if start and end indices are valid
    if(cRow < 0 || cCol < 0 || cRow > 7 || cCol > 7 || nRow < 0 || nCol < 0 || nRow > 7 || nCol > 7)
    {
        return 0;
    }
    
    // Check if start index contains the correct player's piece
    if(board[cRow][cCol] != player && board[cRow][cCol] != player + 32)
    {
        return 0;
    }
    
    // Check if end index is empty
    if(board[nRow][nCol] != ' ')
    {
        return 0;
    }
    
    // Check if move is diagonal
    if(cRow == nRow || cCol == nCol)
    {
        return 0;
    }
    
    // Check if move is in the correct direction
    if(player == 'B' && nRow < cRow)
    {
        return 0;
    }
    
    if(player == 'W' && nRow > cRow)
    {
        return 0;
    }
    
    // Check if move is a diagonal jump
    if(isJump(board, cRow, cCol, nRow, nCol, player))
    {
        return 1;
    }
    
    // Check if move is a diagonal non-jump
    if((nRow - cRow == 1 || nRow - cRow == -1) && (nCol - cCol == 1 || nCol - cCol == -1))
    {
        return 1;
    }
    
    return 0;
}

// Check if the move is a diagonal jump
int isJump(char board[][COLS], int cRow, int cCol, int nRow, int nCol, char player)
{
    int rDiff = nRow - cRow;
    int cDiff = nCol - cCol;
    
    if(rDiff == -2 || rDiff == 2)
    {
        if(cDiff == -2 || cDiff == 2)
        {
            int midRow = (nRow + cRow) / 2;
            int midCol = (nCol + cCol) / 2;
            
            if((board[midRow][midCol] == 'B' || board[midRow][midCol] == 'b') && player == 'W')
            {
                return 1;
            }
            else if((board[midRow][midCol] == 'W' || board[midRow][midCol] == 'w') && player == 'B')
            {
                return 1;
            }
        }
    }
    
    return 0;
}

// Make the move on the board
void makeMove(char board[][COLS], int cRow, int cCol, int nRow, int nCol, char player)
{
    // If move is a jump, remove the jumped piece
    if(isJump(board, cRow, cCol, nRow, nCol, player))
    {
        int midRow = (nRow + cRow) / 2;
        int midCol = (nCol + cCol) / 2;
        board[midRow][midCol] = ' ';
    }
    
    // Move the piece
    board[nRow][nCol] = board[cRow][cCol];
    board[cRow][cCol] = ' ';
    
    // If piece reaches opposite end of the board, promote it to a king
    if(player == 'B' && nRow == 0)
    {
        board[nRow][nCol] = 'B';
    }
    if(player == 'W' && nRow == 7)
    {
        board[nRow][nCol] = 'W';
    }
}