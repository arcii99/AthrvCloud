//FormAI DATASET v1.0 Category: Chess engine ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

const char init_board_state[8][8] = {{'r','n','b','q','k','b','n','r'},
                                     {'p','p','p','p','p','p','p','p'},
                                     {' ','.',' ','.',' ','.',' ','.'},
                                     {'.',' ','.',' ','.',' ','.',' '},
                                     {' ','.',' ','.',' ','.',' ','.'},
                                     {'.',' ','.',' ','.',' ','.',' '},
                                     {'P','P','P','P','P','P','P','P'},
                                     {'R','N','B','Q','K','B','N','R'}};
void print_board(const char board[8][8])
{
    printf("\n");
    for (int i=0; i<8; i++)
    {
        printf("+---+---+---+---+---+---+---+---+\n|");
        for (int j=0; j<8; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf(" %d\n", 8 - i);
    }
    printf("+---+---+---+---+---+---+---+---+\n");
    printf("  A   B   C   D   E   F   G   H\n\n");
}

int get_board_score(const char board[8][8])
{
    int score = 0;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            switch (board[i][j])
            {
                case 'P':
                    score += 1;
                    break;
                case 'p':
                    score -= 1;
                    break;
                case 'R':
                    score += 5;
                    break;
                case 'r':
                    score -= 5;
                    break;
                case 'N':
                    score += 3;
                    break;
                case 'n':
                    score -= 3;
                    break;
                case 'B':
                    score += 3;
                    break;
                case 'b':
                    score -= 3;
                    break;
                case 'Q':
                    score += 9;
                    break;
                case 'q':
                    score -= 9;
                    break;
            }
        }
    }
    return score;
}

int is_valid_square(const int x, const int y)
{
    if (x < 0 || y < 0 || x > 7 || y > 7)
    {
        return 0;
    }
    return 1;
}

int is_valid_move(const char board[8][8], const int start_x, const int start_y, const int end_x, const int end_y)
{
    if (!is_valid_square(start_x, start_y) || !is_valid_square(end_x, end_y))
    {
        return 0;
    }
    if (board[start_x][start_y] == ' ' || (start_x == end_x && start_y == end_y))
    {
        return 0;
    }
    switch (board[start_x][start_y])
    {
        case 'P': /* Pawn */
            if ((end_x == start_x - 1 || end_x == start_x + 1) && end_y == start_y + 1 && board[end_x][end_y] != ' ')
            {
                return 1; /* Capture */
            }
            if (end_x == start_x && (end_y == start_y + 1 || (end_y == start_y + 2 && start_y == 1)) && board[end_x][end_y] == ' ')
            {
                return 1; /* Move forward */
            }
            break;
        case 'p': /* Black Pawn */
            if ((end_x == start_x - 1 || end_x == start_x + 1) && end_y == start_y - 1 && board[end_x][end_y] != ' ')
            {
                return 1; /* Capture */
            }
            if (end_x == start_x && (end_y == start_y - 1 || (end_y == start_y - 2 && start_y == 6)) && board[end_x][end_y] == ' ')
            {
                return 1; /* Move forward */
            }
            break;
        case 'R': /* Rook */
        case 'r': /* Black Rook */
            if (start_x == end_x) /* Horizontal movement */
            {
                int minn = MIN(start_y, end_y);
                int maxx = MAX(start_y, end_y);
                for (int i=minn+1; i<maxx; i++)
                {
                    if (board[start_x][i] != ' ')
                    {
                        return 0;
                    }
                }
                return 1;
            }
            if (start_y == end_y) /* Vertical movement */
            {
                int minn = MIN(start_x, end_x);
                int maxx = MAX(start_x, end_x);
                for (int i=minn+1; i<maxx; i++)
                {
                    if (board[i][start_y] != ' ')
                    {
                        return 0;
                    }
                }
                return 1;
            }
            break;
    }
    return 0;
}

int main()
{
    char board[8][8];
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            board[i][j] = init_board_state[i][j];
        }
    }
    printf("Initial Board:\n");
    print_board(board);
    int game_over = 0;
    while (!game_over)
    {
        /* TODO: Implement AI */
        int start_x, start_y, end_x, end_y;
        printf("Enter move (e.g. \"E2 E4\"): ");
        scanf("%c%d %c%d", &start_y, &start_x, &end_y, &end_x);
        start_x = 8 - start_x;
        end_x = 8 - end_x;
        start_y = start_y - 'A';
        end_y = end_y - 'A';
        if (is_valid_move(board, start_x, start_y, end_x, end_y))
        {
            board[end_x][end_y] = board[start_x][start_y];
            board[start_x][start_y] = ' ';
            printf("Board state after your move:\n");
            print_board(board);
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
        int score = get_board_score(board);
        if (score == 0) /* Draw */
        {
            printf("Draw game.\n");
            game_over = 1;
        }
        /* TODO: Implement checkmate detection */
    }
    return 0;
}