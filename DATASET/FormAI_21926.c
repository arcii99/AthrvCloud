//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KING 2
#define PIECE 1
#define EMPTY 0

// Define the game board
int board[8][8] = {{0, 1, 0, 1, 0, 1, 0, 1},
                   {1, 0, 1, 0, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0, 1, 0, 1},
                   {EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY, 0},
                   {0, EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY},
                   {2, 0, 2, 0, 2, 0, 2, 0},
                   {0, 2, 0, 2, 0, 2, 0, 2},
                   {2, 0, 2, 0, 2, 0, 2, 0}};

// Define the player and game state
int player = 1;
int winner = 0;
int game_over = 0;

// Function to print the game board
void printBoard()
{
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++)
        {
            switch(board[i][j])
            {
                case EMPTY:
                    printf(". ");
                    break;
                case PIECE:
                    printf("%d ", player == 1 ? 1 : 2);
                    break;
                case KING:
                    printf("%d* ", player == 1 ? 1 : 2);
                    break;
            }
        }
        printf("%d\n", i + 1);
    }
    printf("  a b c d e f g h\n");
}

// Function to check if a move is valid
int isValidMove(int x1, int y1, int x2, int y2)
{
    // Check if destination is valid
    if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7)
    {
        return 0;
    }

    // Check if piece is moving forward (unless it's a king)
    if (board[x1][y1] == PIECE)
    {
        if (player == 1 && x2 <= x1)
        {
            return 0;
        }
        else if (player == 2 && x2 >= x1)
        {
            return 0;
        }
    }

    // Check if destination is empty
    if (board[x2][y2] != EMPTY)
    {
        return 0;
    }
    
    // Check if it's a jump move
    if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2)
    {
        // Determine the coordinates of the jumped piece
        int jumpedX = (x1 + x2) / 2;
        int jumpedY = (y1 + y2) / 2;

        // Check if the jumped piece is of the other color
        if (board[jumpedX][jumpedY] == 0 || board[jumpedX][jumpedY] == player)
        {
            return 0;
        }
    }
    
    return 1;
}

// Function to check whether a player can still move
int canMove()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == PIECE && player == 1)
            {
                if (isValidMove(i, j, i+1, j+1) || isValidMove(i, j, i+1, j-1) || isValidMove(i, j, i+2, j+2) || isValidMove(i, j, i+2, j-2))
                {
                    return 1;
                }
            }
            else if (board[i][j] == PIECE && player == 2)
            {
                if (isValidMove(i, j, i-1, j+1) || isValidMove(i, j, i-1, j-1) || isValidMove(i, j, i-2, j+2) || isValidMove(i, j, i-2, j-2))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to move a piece and check for a win
void move(int x1, int y1, int x2, int y2)
{
    // Check if move is valid
    if (!isValidMove(x1, y1, x2, y2))
    {
        printf("Invalid move!\n");
        return;
    }

    // Make the move
    int temp = board[x1][y1];
    board[x1][y1] = 0;
    board[x2][y2] = temp;

    // Check if the piece should be crowned
    if (board[x2][y2] == PIECE && ((player == 1 && x2 == 7) || (player == 2 && x2 == 0)))
    {
        board[x2][y2] = KING;
    }

    // Check if there's a winner
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == PIECE || board[i][j] == KING)
            {
                if (board[i][j] == 1 || board[i][j] == 2)
                {
                    count1++;
                }
                else
                {
                    count2++;
                }
            }
        }
    }

    // Check if a player has no more pieces
    if (count1 == 0 || count2 == 0)
    {
        game_over = 1;
        if (count1 == 0)
        {
            winner = 2;
        }
        else
        {
            winner = 1;
        }
    }

    // Switch player if there's no jump available
    if (abs(x2 - x1) == 1)
    {
        if (player == 1 && !canMove())
        {
            game_over = 1;
            winner = 2;
        }
        else if (player == 2 && !canMove())
        {
            game_over = 1;
            winner = 1;
        }
        else
        {
            player = player == 1 ? 2 : 1;
        }
    }
    // If there's a jump available, the current player goes again
    else
    {
        while (abs(x2 - x1) == 2)
        {
            printBoard();
            printf("Jump is available! Please enter coordinates for next jump: ");
            char input[10];
            fgets(input, sizeof(input), stdin);
            int x3 = atoi(&input[1]) - 1;
            int y3 = input[0] - 'a';
            if (isValidMove(x2, y2, x3, y3))
            {
                move(x2, y2, x3, y3);
                x2 = x3;
                y2 = y3;
            }
            else
            {
                printf("Invalid jump!\n");
                break;
            }
        }
    }
}

// Main function
int main()
{
    printf("Welcome to Cyber Checkers!\n");
    printf("Player 1: 1\nPlayer 2: 2\n");
    printf("------------------------\n");
    printBoard();
    while (!game_over)
    {
        printf("Player %d's turn. Please enter your move: ", player);
        char input[10];
        fgets(input, sizeof(input), stdin);
        int x1 = atoi(&input[1]) - 1;
        int y1 = input[0] - 'a';
        int x2 = atoi(&input[4]) - 1;
        int y2 = input[3] - 'a';
        move(x1, y1, x2, y2);
        printBoard();
    }
    printf("Game over! Player %d wins!\n", winner);
    return 0;
}