//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 25 // Number of rows on the board
#define COLS 80 // Number of columns on the board
#define FPS 60 // Frame rate of the game

#define PADDLE_WIDTH 4 
#define PADDLE_HEIGHT 1 

#define BALL_SIZE 1 

#define PLAYER1_POS 2 
#define PLAYER2_POS 78

// Function prototypes
void init_board(char board[][COLS]);
void print_board(char board[][COLS]);
void update_ball(char board[][COLS], int *ball_x, int *ball_y, int *ball_vel_x, int *ball_vel_y, int *player1_x, int *player1_y, int *player2_x, int *player2_y);
int ai_move(int ball_y, int player2_y);
void move_paddle(char board[][COLS], int *player_x, int *player_y, char dir);

int main()
{
    char board[ROWS][COLS]; // The game board
    srand(time(NULL)); // Seed random number generator

    // Initialize board
    init_board(board);

    // Set starting positions for players and ball
    int player1_x = PLAYER1_POS, player1_y = ROWS / 2 - PADDLE_HEIGHT / 2;
    int player2_x = PLAYER2_POS, player2_y = ROWS / 2 - PADDLE_HEIGHT / 2;
    int ball_x = COLS / 2, ball_y = ROWS / 2, ball_vel_x = 1, ball_vel_y = 1;

    // Set up input settings for detecting key presses
    struct termios orig, new;
    tcgetattr(0, &orig);
    new = orig;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);

    // Main game loop
    while (true)
    {
        usleep(1000000 / FPS); // Wait for next frame

        // Read input
        char input;
        if (read(0, &input, 1) == 1)
        {
            // Move player 1 paddle
            if (input == 'w')
                move_paddle(board, &player1_x, &player1_y, 'u');
            else if (input == 's')
                move_paddle(board, &player1_x, &player1_y, 'd');
        }

        // Move player 2 paddle based on AI
        int ai_move_dir = ai_move(ball_y, player2_y);
        if (ai_move_dir == -1)
            move_paddle(board, &player2_x, &player2_y, 'u');
        else if (ai_move_dir == 1)
            move_paddle(board, &player2_x, &player2_y, 'd');

        // Update ball position and velocities
        update_ball(board, &ball_x, &ball_y, &ball_vel_x, &ball_vel_y, &player1_x, &player1_y, &player2_x, &player2_y);

        // Clear screen and print board
        system("clear");
        print_board(board);
    }

    // Reset terminal settings
    tcsetattr(0, TCSANOW, &orig);

    return 0;
}

// Initialize game board with starting characters
void init_board(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Draw top and bottom borders
            if (i == 0 || i == ROWS - 1)
                board[i][j] = '-';
            // Draw left and right borders
            else if (j == 0 || j == COLS - 1)
                board[i][j] = '|';
            // Draw players
            else if (i >= PLAYER1_POS && i < PLAYER1_POS + PADDLE_HEIGHT && j >= 2 && j < 2 + PADDLE_WIDTH)
                board[i][j] = '#';
            else if (i >= PLAYER2_POS && i < PLAYER2_POS + PADDLE_HEIGHT && j >= COLS - 2 - PADDLE_WIDTH && j < COLS - 2)
                board[i][j] = '#';
            // Draw ball
            else if (i == ROWS / 2 && j == COLS / 2)
                board[i][j] = 'O';
            else
                board[i][j] = ' ';
        }
    }
}

// Print the game board to the console
void print_board(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

// Update ball position and velocities, and check for collision with walls and paddles
void update_ball(char board[][COLS], int *ball_x, int *ball_y, int *ball_vel_x, int *ball_vel_y, int *player1_x, int *player1_y, int *player2_x, int *player2_y)
{
    // Check for collision with top or bottom wall
    if (*ball_y == 1 || *ball_y == ROWS - 2)
        *ball_vel_y = -*ball_vel_y;

    // Check for collision with player 1 paddle
    if (*ball_x == *player1_x + PADDLE_WIDTH && *ball_y >= *player1_y && *ball_y < *player1_y + PADDLE_HEIGHT)
        *ball_vel_x = -*ball_vel_x;

    // Check for collision with player 2 paddle
    if (*ball_x == *player2_x - 1 && *ball_y >= *player2_y && *ball_y < *player2_y + PADDLE_HEIGHT)
        *ball_vel_x = -*ball_vel_x;

    // Check for scoring a point
    if (*ball_x == 1 || *ball_x == COLS - 2)
    {
        *ball_x = COLS / 2;
        *ball_y = ROWS / 2;
        *ball_vel_x = -*ball_vel_x;
        *player1_y = ROWS / 2 - PADDLE_HEIGHT / 2;
        *player2_y = ROWS / 2 - PADDLE_HEIGHT / 2;
    }

    // Move ball
    *ball_x += *ball_vel_x;
    *ball_y += *ball_vel_y;

    // Update ball position on board
    init_board(board);
    board[*ball_y][*ball_x] = 'O';
    for (int i = 0; i < PADDLE_HEIGHT; i++)
    {
        board[*player1_y + i][*player1_x] = '#';
        board[*player2_y + i][*player2_x + PADDLE_WIDTH - 1] = '#';
    }
}

// Determine AI's paddle movement based on current ball position
int ai_move(int ball_y, int player2_y)
{
    if (ball_y == player2_y + PADDLE_HEIGHT / 2)
        return 0;
    else if (ball_y < player2_y + PADDLE_HEIGHT / 2)
        return -1;
    else
        return 1;
}

// Move a player's paddle up or down
void move_paddle(char board[][COLS], int *player_x, int *player_y, char dir)
{
    if (dir == 'u' && *player_y > 1)
    {
        board[*player_y + PADDLE_HEIGHT - 1][*player_x] = ' ';
        (*player_y)--;
        board[*player_y][*player_x] = '#';
    }
    else if (dir == 'd' && *player_y < ROWS - PADDLE_HEIGHT - 1)
    {
        board[*player_y][*player_x] = ' ';
        (*player_y)++;
        board[*player_y + PADDLE_HEIGHT - 1][*player_x] = '#';
    }
}