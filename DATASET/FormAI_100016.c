//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define HEIGHT 20
#define WIDTH 40

// Function to get keyboard input without waiting for enter key
char getch()
{
    struct termios oldattr, newattr;
    char ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

// Function to draw the game board
void draw_board(char board[HEIGHT][WIDTH])
{
    system("clear");
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("|");
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
}

// Function to move the player's paddle
void move_player(char board[HEIGHT][WIDTH], int player_pos)
{
    board[HEIGHT-1][player_pos-1] = '_';
    board[HEIGHT-1][player_pos] = '_';
    board[HEIGHT-1][player_pos+1] = '_';   
}

// Function to move the AI opponent's paddle
void move_opponent(char board[HEIGHT][WIDTH], int opponent_pos, int ball_pos)
{
    if (opponent_pos > ball_pos)
    {
        board[0][opponent_pos-1] = '_';
        board[0][opponent_pos] = '_';
        board[0][opponent_pos+1] = '_';
    }
    else if (opponent_pos < ball_pos)
    {
        board[0][opponent_pos-1] = ' ';
        board[0][opponent_pos] = '_';
        board[0][opponent_pos+1] = ' ';
    }
}

// Function to move the ball and check for collisions
void move_ball(char board[HEIGHT][WIDTH], int *ball_x, int *ball_y, int *ball_dx, int *ball_dy, int player_pos, int opponent_pos, int *score)
{
    board[*ball_x][*ball_y] = ' ';
    *ball_x += *ball_dx;
    *ball_y += *ball_dy;
    if (*ball_x == HEIGHT-2 && (*ball_y == player_pos-1 || *ball_y == player_pos || *ball_y == player_pos+1))
    {
        *ball_dx = -(*ball_dx);
        *score += 1;
    }
    if (*ball_x == 1 && (*ball_y == opponent_pos-1 || *ball_y == opponent_pos || *ball_y == opponent_pos+1))
    {
        *ball_dx = -(*ball_dx);
    }
    if (*ball_x == HEIGHT-1)
    {
        *ball_dx = 0;
        *ball_dy = 0;
        *score -= 5;
    }
    if (*ball_x == 0)
    {
        *ball_dx = 0;
        *ball_dy = 0;
        *score += 5;
    }
    board[*ball_x][*ball_y] = '0';
}

// Recursive function to play the game
void play_game(char board[HEIGHT][WIDTH], int player_pos, int opponent_pos, int ball_x, int ball_y, int ball_dx, int ball_dy, int score)
{
    if (score < -10 || score > 10)
    {
        printf("GAME OVER\n");
        if (score > 0)
        {
            printf("You win!\n");
        }
        else
        {
            printf("You lose!\n");
        }
        return;
    }
    draw_board(board);
    printf("Score: %d\n", score);
    move_player(board, player_pos);
    move_opponent(board, opponent_pos, ball_y);
    move_ball(board, &ball_x, &ball_y, &ball_dx, &ball_dy, player_pos, opponent_pos, &score);
    char ch = getch();
    if (ch == 'a' && player_pos > 2)
    {
        player_pos -= 2;
    }
    else if (ch == 'd' && player_pos < WIDTH-3)
    {
        player_pos += 2;
    }
    if (opponent_pos > ball_y && opponent_pos > 2)
    {
        opponent_pos -= 2;
    }
    else if (opponent_pos < ball_y && opponent_pos < WIDTH-3)
    {
        opponent_pos += 2;
    }
    usleep(75000);
    play_game(board, player_pos, opponent_pos, ball_x, ball_y, ball_dx, ball_dy, score);
}

int main()
{
    srand(time(NULL));
    char board[HEIGHT][WIDTH];
    int player_pos = WIDTH/2, opponent_pos = WIDTH/2;
    int ball_x = 2, ball_y = WIDTH/2, ball_dx = (rand() % 2) ? 1 : -1, ball_dy = (rand() % 2) ? 1 : -1, score = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == HEIGHT-1 || i == 0 || j == 0 || j == WIDTH-1)
            {
                board[i][j] = '*';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
    play_game(board, player_pos, opponent_pos, ball_x, ball_y, ball_dx, ball_dy, score);
    return 0;
}