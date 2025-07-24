//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define SIZE 8
#define BLACK 1
#define WHITE 2
#define KING_B 3
#define KING_W 4

// Declare global variables
int board[SIZE][SIZE];
int turn;
int score_b = 0;
int score_w = 0;

// Declare function prototypes
void init_board();
void print_board();
void make_move(int x1, int y1, int x2, int y2);
int check_valid_move(int x1, int y1, int x2, int y2);
int check_jump(int x1, int y1, int x2, int y2);
void promote_king(int x, int y);

int main()
{
    init_board();
    print_board();

    while (1)
    {
        int x1, y1, x2, y2;
        printf("\n\nPlayer %d's turn\nEnter your move: ", turn);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        // Check if move is valid
        int valid_move = check_valid_move(x1, y1, x2, y2);
        if (valid_move)
        {
            make_move(x1, y1, x2, y2);
            print_board();
        }
        else
        {
            printf("\nInvalid move. Please try again.\n");
        }

        // Check for game end conditions
        if (score_b == 12 || score_w == 12)
        {
            printf("\n\nGAME OVER!\nFinal score:\nBlack: %d\nWhite: %d\n", score_b, score_w);
            break;
        }
        else if (turn == BLACK && score_b == 0)
        {
            printf("\n\nGAME OVER!\nWhite Wins!\n");
            break;
        }
        else if (turn == WHITE && score_w == 0)
        {
            printf("\n\nGAME OVER!\nBlack Wins!\n");
            break;
        }
        else
        {
            // Switch turn
            turn = (turn == BLACK) ? WHITE : BLACK;
        }
    }

    return 0;
}

void init_board()
{
    // Initialize board with empty spaces
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set up black pieces
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i+j) % 2 == 0)
            {
                board[i][j] = BLACK;
            }
        }
    }

    // Set up white pieces
    for (int i = SIZE-1; i >= SIZE-3; i--)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i+j) % 2 == 0)
            {
                board[i][j] = WHITE;
            }
        }
    }

    // Set initial turn
    turn = BLACK;
}

void print_board()
{
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++)
        {
            switch (board[i][j])
            {
                case 0:
                    printf(". ");
                    break;
                case BLACK:
                    printf("b ");
                    break;
                case WHITE:
                    printf("w ");
                    break;
                case KING_B:
                    printf("B ");
                    break;
                case KING_W:
                    printf("W ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\nScore:\nBlack: %d\nWhite: %d\n", score_b, score_w);
}

void make_move(int x1, int y1, int x2, int y2)
{
    // Make the move
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;

    // Check for a promotion to king
    if (board[x2][y2] == BLACK && x2 == SIZE-1)
    {
        promote_king(x2, y2);
    }
    else if (board[x2][y2] == WHITE && x2 == 0)
    {
        promote_king(x2, y2);
    }

    // Check for a jump move
    int jump = check_jump(x1, y1, x2, y2);
    if (jump)
    {
        board[(x1+x2)/2][(y1+y2)/2] = 0; // Remove the jumped piece
        if (turn == BLACK)
        {
            score_w--;
        }
        else
        {
            score_b--;
        }
    }

    // Update scores
    if (board[x2][y2] == BLACK || board[x2][y2] == KING_B)
    {
        score_b++;
    }
    else if (board[x2][y2] == WHITE || board[x2][y2] == KING_W)
    {
        score_w++;
    }
}

int check_valid_move(int x1, int y1, int x2, int y2)
{
    // Check if the piece belongs to the current player
    if (board[x1][y1] == 0 || (turn == BLACK && (board[x1][y1] == WHITE || board[x1][y1] == KING_W)) || (turn == WHITE && (board[x1][y1] == BLACK || board[x1][y1] == KING_B)))
    {
        return 0;
    }

    // Check if destination is a valid empty space
    if (board[x2][y2] != 0)
    {
        return 0;
    }

    // Check if move is diagonal
    if (abs(x1-x2) != abs(y1-y2))
    {
        return 0;
    }

    // Check if move distance is not greater than 2
    if (abs(x1-x2) > 2)
    {
        return 0;
    }

    // Check if move direction is valid based on piece type
    if (board[x1][y1] == BLACK && x2 > x1)
    {
        return 0;
    }
    else if (board[x1][y1] == WHITE && x2 < x1)
    {
        return 0;
    }

    // Check for jump move
    int jump = check_jump(x1, y1, x2, y2);
    if (jump)
    {
        return 2;
    }

    // Move is valid
    return 1;
}

int check_jump(int x1, int y1, int x2, int y2)
{
    // Check if jump distance is 2
    if (abs(x1-x2) != 2 || abs(y1-y2) != 2)
    {
        return 0;
    }

    // Check if the jumped piece is an opponent piece
    int i = (x1+x2)/2;
    int j = (y1+y2)/2;
    if (turn == BLACK && (board[i][j] == WHITE || board[i][j] == KING_W))
    {
        return 1;
    }
    else if (turn == WHITE && (board[i][j] == BLACK || board[i][j] == KING_B))
    {
        return 1;
    }

    // No jump move found
    return 0;
}

void promote_king(int x, int y)
{
    // Promote to king
    if (board[x][y] == BLACK)
    {
        board[x][y] = KING_B;
    }
    else if (board[x][y] == WHITE)
    {
        board[x][y] = KING_W;
    }
}