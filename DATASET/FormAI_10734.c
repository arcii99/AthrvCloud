//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30

// Global variables
int ball_x, ball_y, paddle_y, ai_y, score;
int ball_dir_x, ball_dir_y;

// Function prototypes
void init_game();
void print_game();
void update_ball();
void update_player();
void update_ai();

int main()
{
    init_game(); // Initialize game state
    
    // Game loop
    while (1)
    {
        print_game(); // Print game state
        
        update_player(); // Update player's paddle position
        
        update_ai(); // Update AI's paddle position
        
        update_ball(); // Update ball position
        
        // Check for game over condition
        if (ball_x == 0 || ball_x == WIDTH-1)
        {
            printf("GAME OVER!\nYour score: %d\n", score);
            break;
        }
        
        // Pause for a short amount of time to slow down game speed
        usleep(50000);
    }

    return 0;
}

// Initialize game state
void init_game()
{
    // Randomize seed for ball direction
    srand(time(NULL));
    
    // Initialize ball position and direction
    ball_x = WIDTH/2;
    ball_y = HEIGHT/2;
    ball_dir_x = rand() % 2 == 0 ? -1 : 1;
    ball_dir_y = rand() % 2 == 0 ? -1 : 1;
    
    // Initialize player and AI paddle positions
    paddle_y = HEIGHT/2;
    ai_y = HEIGHT/2;
    
    // Initialize score to zero
    score = 0;
}

// Print game state
void print_game()
{
    // Clear screen
    system("clear");
    
    // Print top wall
    for (int i = 0; i < WIDTH+2; i++)
    {
        printf("#");
    }
    printf("\n");
    
    // Print player paddle and ball
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("#");
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0 || j == WIDTH-1)
            {
                printf("#");
            }
            else if (i == paddle_y && j == 1)
            {
                printf("P");
            }
            else if (i == ai_y && j == WIDTH-2)
            {
                printf("A");
            }
            else if (i == ball_y && j == ball_x)
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }
        }
        printf("#");
        printf("\n");
    }
    
    // Print bottom wall
    for (int i = 0; i < WIDTH+2; i++)
    {
        printf("#");
    }
    printf("\n");
    
    // Print score
    printf("Score: %d\n", score);
}

// Update ball position
void update_ball()
{
    // Check for collision with player paddle
    if (ball_dir_x == -1 && ball_x == 1 && ball_y >= paddle_y-2 && ball_y <= paddle_y+2)
    {
        ball_dir_x = 1;
        score++;
    }
    
    // Check for collision with AI paddle
    if (ball_dir_x == 1 && ball_x == WIDTH-2 && ball_y >= ai_y-2 && ball_y <= ai_y+2)
    {
        ball_dir_x = -1;
    }
    
    // Check for collision with top or bottom walls
    if (ball_y == 0 || ball_y == HEIGHT-1)
    {
        ball_dir_y *= -1;
    }
    
    // Update ball position
    ball_x += ball_dir_x;
    ball_y += ball_dir_y;
}

// Update player's paddle position
void update_player()
{
    char input;
    
    // Check for input
    if (kbhit())
    {
        input = getchar();
        if (input == 'w' && paddle_y > 2)
        {
            paddle_y--;
        }
        if (input == 's' && paddle_y < HEIGHT-3)
        {
            paddle_y++;
        }
    }
}

// Update AI's paddle position
void update_ai()
{
    // Simple AI algorithm
    if (ai_y < ball_y && ai_y < HEIGHT-3)
    {
        ai_y++;
    }
    if (ai_y > ball_y && ai_y > 2)
    {
        ai_y--;
    }
}

// Function to check for keyboard input
int kbhit(void)
{
    struct timeval tv;
    fd_set read_fd;
    
    // Set timeout value to zero
    tv.tv_sec=0;
    tv.tv_usec=0;
    
    // Set the file descriptor
    FD_ZERO(&read_fd);
    FD_SET(0,&read_fd);
    
    // Check if input is available
    if(select(1, &read_fd, NULL, NULL, &tv) == -1)
    {
        return 0;
    }
    return 1;
}