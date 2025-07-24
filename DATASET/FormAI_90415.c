//FormAI DATASET v1.0 Category: Chess AI ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

bool move_white = true;

int evaluate()
{
    int white_points = 0, black_points = 0;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            switch (board[row][col])
            {
                case 'P':
                    white_points += 10;
                    break;
                case 'p':
                    black_points += 10;
                    break;
                case 'N':
                case 'B':
                    white_points += 30;
                    break;
                case 'n':
                case 'b':
                    black_points += 30;
                    break;
                case 'R':
                    white_points += 50;
                    break;
                case 'r':
                    black_points += 50;
                    break;
                case 'Q':
                    white_points += 90;
                    break;
                case 'q':
                    black_points += 90;
                    break;
            }
        }
    }

    return (move_white) ? white_points - black_points : black_points - white_points;
}

int minimax(int depth, int alpha, int beta)
{
    if (depth == 0) return evaluate();

    int best_score;
    if (move_white)
    {
        best_score = -1000;
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (board[row][col] == ' '
                    || board[row][col] == '.'
                    || board[row][col] >= 'a' && board[row][col] <= 'z') continue;

                for (int i = 0; i < 8; i++)
                {
                    int new_row = row + "87654321"[i] - '1';
                    int new_col = col + "0x06050403020100"[i] - '0' - (i >= 4);
                    if (new_row < 0 || new_col < 0 || new_row > 7 || new_col > 7) continue;
                    char piece = board[new_row][new_col];
                    board[new_row][new_col] = board[row][col];
                    board[row][col] = ' ';

                    move_white = !move_white;
                    best_score = (best_score > minimax(depth - 1, alpha, beta)) ? best_score : minimax(depth - 1, alpha, beta);
                    move_white = !move_white;

                    board[row][col] = board[new_row][new_col];
                    board[new_row][new_col] = piece;

                    alpha = (alpha > best_score) ? alpha : best_score;
                    if (beta <= alpha) return best_score;
                }
            }
        }
    }
    else
    {
        best_score = 1000;
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (board[row][col] == ' '
                    || board[row][col] == '.'
                    || board[row][col] >= 'A' && board[row][col] <= 'Z') continue;

                for (int i = 0; i < 8; i++)
                {
                    int new_row = row + "12345678"[i] - '1';
                    int new_col = col + "0x06050403020100"[i] - '0' - (i >= 4);
                    if (new_row < 0 || new_col < 0 || new_row > 7 || new_col > 7) continue;
                    char piece = board[new_row][new_col];
                    board[new_row][new_col] = board[row][col];
                    board[row][col] = ' ';

                    move_white = !move_white;
                    best_score = (best_score < minimax(depth - 1, alpha, beta)) ? best_score : minimax(depth - 1, alpha, beta);
                    move_white = !move_white;

                    board[row][col] = board[new_row][new_col];
                    board[new_row][new_col] = piece;

                    beta = (beta < best_score) ? beta : best_score;
                    if (beta <= alpha) return best_score;
                }
            }
        }
    }

    return best_score;
}

int main()
{
    printf("Current position: \n");
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }

    int score = minimax(3, -1000000, 1000000);
    printf("Score: %d\n", score);

    return 0;
}