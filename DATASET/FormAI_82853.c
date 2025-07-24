//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include<stdio.h>

// Constants
#define BOARDSIZE 8

// Global variables
int board[BOARDSIZE][BOARDSIZE] = {
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,-1,0,-1,0,-1,0,-1},
    {-1,0,-1,0,-1,0,-1,0},
    {0,-1,0,-1,0,-1,0,-1}
};
int turn = 1; // 1 for player 1, -1 for player 2
int player1Pieces = 12; // Number of pieces each player has
int player2Pieces = 12;

// Function prototypes
void printBoard();
void makeMove(int x1, int y1, int x2, int y2);
int canMove(int x, int y);
int canJump(int x, int y);
int getPlayerInput();
void endGame(int winner);

int main()
{
    printf("Welcome to Checkers!\n\n");

    // Game loop
    int winner = 0; // 0 for no winner
    while (player1Pieces > 0 && player2Pieces > 0)
    {
        printBoard();

        // Get player's move
        int playerInput = getPlayerInput();
        int x1 = playerInput / 1000;
        int y1 = (playerInput / 100) % 10;
        int x2 = (playerInput / 10) % 10;
        int y2 = playerInput % 10;

        // Make the move
        makeMove(x1, y1, x2, y2);

        // Check for winner
        if (player1Pieces == 0) winner = -1;
        else if (player2Pieces == 0) winner = 1;

        // Switch turns
        turn *= -1;
    }

    // End of game
    endGame(winner);
    return 0;
}

// Function definitions
void printBoard()
{
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  -----------------\n");
    for (int i = 0; i < BOARDSIZE; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < BOARDSIZE; j++)
        {
            if (board[i][j] == 1) printf("o|");
            else if (board[i][j] == -1) printf("x|");
            else printf(" |");
        }
        printf("\n");
        printf("  -----------------\n");
    }
}

int canMove(int x, int y)
{
    if (board[x][y] == 0 || board[x][y] != turn) return 0;
    if (turn == 1 && x > 0)
    {
        if (y > 0 && board[x-1][y-1] == 0) return 1;
        else if (y < BOARDSIZE-1 && board[x-1][y+1] == 0) return 1;
    }
    else if (turn == -1 && x < BOARDSIZE-1)
    {
        if (y > 0 && board[x+1][y-1] == 0) return 1;
        else if (y < BOARDSIZE-1 && board[x+1][y+1] == 0) return 1;
    }
    return 0;
}

int canJump(int x, int y)
{
    if (board[x][y] == 0 || board[x][y] != turn) return 0;
    if (turn == 1 && x > 1)
    {
        if (y > 1 && board[x-1][y-1] == -1 && board[x-2][y-2] == 0) return 1;
        else if (y < BOARDSIZE-2 && board[x-1][y+1] == -1 && board[x-2][y+2] == 0) return 1;
    }
    else if (turn == -1 && x < BOARDSIZE-2)
    {
        if (y > 1 && board[x+1][y-1] == 1 && board[x+2][y-2] == 0) return 1;
        else if (y < BOARDSIZE-2 && board[x+1][y+1] == 1 && board[x+2][y+2] == 0) return 1;
    }
    return 0;
}

void makeMove(int x1, int y1, int x2, int y2)
{
    if (canJump(x1, y1))
    {
        // Jumps take priority
        if (turn == 1 && x1 > x2 && board[x2+1][y2+1] == -1)
        {
            board[x1][y1] = 0;
            board[x2][y2] = 1;
            board[x2+1][y2+1] = 0;
            player2Pieces--;
        }
        else if (turn == 1 && x1 > x2 && board[x2+1][y2-1] == -1)
        {
            board[x1][y1] = 0;
            board[x2][y2] = 1;
            board[x2+1][y2-1] = 0;
            player2Pieces--;
        }
        else if (turn == -1 && x1 < x2 && board[x2-1][y2-1] == 1)
        {
            board[x1][y1] = 0;
            board[x2][y2] = -1;
            board[x2-1][y2-1] = 0;
            player1Pieces--;
        }
        else if (turn == -1 && x1 < x2 && board[x2-1][y2+1] == 1)
        {
            board[x1][y1] = 0;
            board[x2][y2] = -1;
            board[x2-1][y2+1] = 0;
            player1Pieces--;
        }
        else
        {
            printf("Invalid jump.\n");
            return;
        }
    }
    else if (canMove(x1, y1))
    {
        if ((turn == 1 && x1 - x2 == 1) || (turn == -1 && x2 - x1 == 1))
        {
            board[x1][y1] = 0;
            board[x2][y2] = turn;
        }
        else
        {
            printf("Invalid move.\n");
            return;
        }
    }
    else
    {
        printf("You cannot move that piece.\n");
        return;
    }
}

int getPlayerInput()
{
    int x1, y1, x2, y2;
    do {
        printf("Player %d, enter your move (in the format x1y1 x2y2): ", turn);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    } while (x1 < 0 || x1 >= BOARDSIZE || y1 < 0 || y1 >= BOARDSIZE ||
             x2 < 0 || x2 >= BOARDSIZE || y2 < 0 || y2 >= BOARDSIZE);

    return (x1*1000) + (y1*100) + (x2*10) + y2;
}

void endGame(int winner)
{
    printf("Game over! ");
    if (winner == 1) printf("Player 1 wins!\n");
    else if (winner == -1) printf("Player 2 wins!\n");
    else printf("It's a tie!\n");
}