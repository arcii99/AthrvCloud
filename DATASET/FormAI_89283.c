//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 70
#define HEIGHT 20
#define PADDLE_LENGTH 5
#define BALL_LEFT_POS 35
#define BALL_TOP_POS 10

typedef enum { UP_LEFT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT } direction_t;

typedef struct {
    int X;
    int Y;
    direction_t Direction;
} ball_t;

typedef struct {
    char Symbol;
    int TopPos;
    int BotPos;
    int Score;
} paddle_t;

// Function Declarations
void MovePaddle(paddle_t *p, int direction);
void CreateBall(ball_t *b);
void MoveBall(ball_t *b, paddle_t *p1, paddle_t *p2);
void DrawScreen(ball_t *b, paddle_t *p1, paddle_t *p2);
void ClearScreen();

// Main function
int main()
{
    srand(time(NULL)); // Seed for generating random numbers

    // Initializing player paddles
    paddle_t player1 = { '|', 7, 11, 0 };
    paddle_t player2 = { '|', 7, 11, 0 };

    // Initializing ball
    ball_t ball;
    CreateBall(&ball);

    // Main game loop
    while (1)
    {
        MoveBall(&ball, &player1, &player2); // Move ball
        DrawScreen(&ball, &player1, &player2); // Draw screen
    }

    return 0;
}

// This function moves the paddle
void MovePaddle(paddle_t *p, int direction)
{
    if (direction == -1) // Move Up
    {
        if (p->TopPos > 0) // If paddle is not at the top of the screen
        {
            p->TopPos--;
            p->BotPos--;
        }
    }
    else if (direction == 1) // Move Down
    {
        if (p->BotPos < HEIGHT) // If paddle is not at the bottom of the screen
        {
            p->BotPos++;
            p->TopPos++;
        }
    }
}

// This function creates the ball
void CreateBall(ball_t *b)
{
    b->X = BALL_LEFT_POS;
    b->Y = BALL_TOP_POS;
    b->Direction = rand() % 4; // Choose random direction for the ball
}

// This function moves the ball
void MoveBall(ball_t *b, paddle_t *p1, paddle_t *p2)
{
    switch (b->Direction)
    {
    case UP_LEFT:
        b->X--;
        b->Y--;
        break;
    case UP_RIGHT:
        b->X++;
        b->Y--;
        break;
    case DOWN_RIGHT:
        b->X++;
        b->Y++;
        break;
    case DOWN_LEFT:
        b->X--;
        b->Y++;
        break;
    }

    if (b->X == 0) // Ball hit the left wall
    {
        p2->Score++;
        CreateBall(b); // Create new ball at default position
    }
    else if (b->X == WIDTH - 1) // Ball hit the right wall
    {
        p1->Score++;
        CreateBall(b); // Create new ball at default position
    }

    if (b->Y == 0) // Ball hit the top wall
        b->Direction = (b->Direction == UP_LEFT) ? DOWN_LEFT : DOWN_RIGHT;
    else if (b->Y == HEIGHT - 1) // Ball hit the bottom wall
        b->Direction = (b->Direction == DOWN_LEFT) ? UP_LEFT : UP_RIGHT;

    // Ball hit the paddle
    if (b->X == 1 && b->Y >= p1->TopPos && b->Y <= p1->BotPos)
        b->Direction = (b->Direction == UP_LEFT) ? UP_RIGHT : DOWN_RIGHT;
    else if (b->X == WIDTH - 2 && b->Y >= p2->TopPos && b->Y <= p2->BotPos)
        b->Direction = (b->Direction == UP_RIGHT) ? UP_LEFT : DOWN_LEFT;

    // Automated Computer Opponent
    if (b->X > WIDTH / 2) {
        if (p2->TopPos < b->Y - PADDLE_LENGTH / 2)
            MovePaddle(p2, 1); // Move paddle down
        else if (p2->BotPos > b->Y + PADDLE_LENGTH / 2)
            MovePaddle(p2, -1); // Move paddle up
    }
}

// This function draws the game screen
void DrawScreen(ball_t *b, paddle_t *p1, paddle_t *p2)
{
    ClearScreen(); // Clear the screen before drawing

    // Drawing paddles
    for (int y = p1->TopPos; y <= p1->BotPos; y++)
        printf("%c", p1->Symbol);
    printf("\t\t\t");

    for (int y = p2->TopPos; y <= p2->BotPos; y++)
        printf("%c", p2->Symbol);
    printf("\n");

    // Drawing ball
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == b->X && y == b->Y)
                printf("O");
            else if (x == 0 || x == WIDTH - 1)
                printf("|");
            else if (y == 0 || y == HEIGHT - 1)
                printf("-");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Drawing scores
    printf("\nPlayer 1:\t%d\t\t\t\tPlayer 2:\t%d\n", p1->Score, p2->Score);
}

// This function clears the screen
void ClearScreen()
{
    system("cls"); // Call external command to clear screen
}