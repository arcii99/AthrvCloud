//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 20
#define COLUMNS 30
#define PLAYER_SIZE 3
#define ENEMY_SIZE 3

// Function to handle terminal input
bool kbhit(void) 
{
    struct termios oldt, newt;
    int ch;
    bool input_available;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    input_available = (ch != EOF);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    if(input_available) 
    {
        ungetc(ch, stdin);
    } 
    return input_available;
}

// Enemy struct
struct Enemy 
{
    int x, y;
    bool active;
};

// Draw player and enemies on the board
void display(char board[ROWS][COLUMNS], int player_x, struct Enemy enemies[ENEMY_SIZE]) 
{
    int i, j, k;
    system("clear");    // Clear terminal window
    // Print board with player and enemies
    for(i=0; i<ROWS; i++) 
    {
        for(j=0; j<COLUMNS; j++) 
        {
            if (i==ROWS-1 && (j==player_x-1||j==player_x||j==player_x+1)) 
            {
                printf("A");
            } 
            else 
            {
                bool printed = false;
                for(k=0; k<ENEMY_SIZE; k++) 
                {
                    if (enemies[k].active && enemies[k].y==i && enemies[k].x==j) 
                    {
                        printf("X");                    
                        printed = true;
                        break;
                    }
                }
                if (!printed) 
                {
                    printf("%c", board[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main() 
{
    srand(time(NULL));   // Set random seed

    // Initialize board and player start position
    int i,j;
    char board[ROWS][COLUMNS] = {{0}};
    int player_x = COLUMNS/2;
    for(i=ROWS-1; i<ROWS; i++) 
    {
        for(j=0; j<COLUMNS; j++) 
        {
            board[i][j] = '-';
        }
    }

    // Initialize enemies
    struct Enemy enemies[ENEMY_SIZE];
    for(i=0; i<ENEMY_SIZE; i++) 
    {
        enemies[i].x = rand() % COLUMNS;
        enemies[i].y = rand() % (ROWS/2);
        enemies[i].active = true;
    }

    // Game Loop
    bool game_over = false;
    int score = 0;
    while(!game_over) 
    {
        // Check player input
        if(kbhit()) 
        {
            char input = getchar();
            if(input == 'a' && player_x>0) 
            {
                player_x -= 1;
            }
            if(input == 'd' && player_x<COLUMNS-PLAYER_SIZE) 
            {
                player_x += 1;
            }
        }

        // Move enemies
        for(i=0; i<ENEMY_SIZE; i++) 
        {
            if (enemies[i].active) 
            {
                enemies[i].y += 1;
                // Check for collision with player
                if (enemies[i].y == ROWS-1 && enemies[i].x >= player_x-1 && enemies[i].x <= player_x+1) 
                {
                    game_over = true;
                    break;
                }
                // Check for collision with bottom of board
                if (enemies[i].y == ROWS-1) 
                {
                    enemies[i].active = false;
                    score += 1;
                }
            }
        }

        // Check for win condition
        bool win = true;
        for(i=0; i<ENEMY_SIZE; i++) 
        {
            if (enemies[i].active) 
            {
                win = false;
                break;
            }
        }
        if (win) 
        {
            game_over = true;
            printf("You win! Score: %d\n", score);
        }

        display(board, player_x, enemies);
        usleep(100000); // Sleep for 0.1 sec
    }

    // Print game over message
    printf("Game over! Final score: %d\n", score);

    return 0;
}