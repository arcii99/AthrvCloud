//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

/* Function prototypes */
void print_gameboard(int rows, int cols, char gameboard[rows][cols]);
void clear_gameboard(int rows, int cols, char gameboard[rows][cols]);
void spawn_enemy_ships(int rows, int cols, char gameboard[rows][cols]);
void move_enemy_ships(int rows, int cols, char gameboard[rows][cols]);
void player_shot(int rows, int cols, char gameboard[rows][cols], int player_row);
void enemy_shot(int rows, int cols, char gameboard[rows][cols], int* score);

/* Main function */
int main()
{
    char gameboard[ROWS][COLS];
    int player_row = ROWS - 1;
    int score = 0;
    int quit = 0;
    char input;
    
    /* Set seed for random number generator */
    srand(time(NULL));
    
    /* Clear gameboard and spawn enemy ships */
    clear_gameboard(ROWS, COLS, gameboard);
    spawn_enemy_ships(ROWS, COLS, gameboard);
    
    /* Main game loop */
    while(!quit)
    {
        /* Print gameboard and score */
        printf("Score: %d\n", score);
        print_gameboard(ROWS, COLS, gameboard);
        
        /* Get player input */
        printf("Move left (a) / right (d) / shoot (s) / quit (q): ");
        scanf(" %c", &input);
        
        /* Process player input */
        switch(input)
        {
            case 'a':
                if(player_row > 0)
                {
                    player_row--;
                }
                break;
                
            case 'd':
                if(player_row < COLS - 1)
                {
                    player_row++;
                }
                break;
                
            case 's':
                player_shot(ROWS, COLS, gameboard, player_row);
                enemy_shot(ROWS, COLS, gameboard, &score);
                break;
                
            case 'q':
                quit = 1;
                break;
                
            default:
                printf("Invalid input\n");
        }
        
        /* Move enemy ships */
        move_enemy_ships(ROWS, COLS, gameboard);
        
        /* Check for game over */
        for(int i = 0; i < COLS; i++)
        {
            if(gameboard[0][i] == 'E')
            {
                printf("Game over\n");
                quit = 1;
                break;
            }
        }
    }
    
    return 0;
}

/* Function definitions */

void print_gameboard(int rows, int cols, char gameboard[rows][cols])
{
    printf("\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%c ", gameboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void clear_gameboard(int rows, int cols, char gameboard[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            gameboard[i][j] = '.';
        }
    }
}

void spawn_enemy_ships(int rows, int cols, char gameboard[rows][cols])
{
    for(int i = 0; i < cols; i++)
    {
        gameboard[0][i] = 'E';
    }
}

void move_enemy_ships(int rows, int cols, char gameboard[rows][cols])
{
    /* Check if any enemy ships are at the bottom */
    for(int i = 0; i < cols; i++)
    {
        if(gameboard[ROWS - 1][i] == 'E')
        {
            printf("Game over\n");
            exit(0);
        }
    }
    
    /* Move enemy ships down by one row */
    for(int i = ROWS - 1; i > 0; i--)
    {
        for(int j = 0; j < cols; j++)
        {
            gameboard[i][j] = gameboard[i - 1][j];
        }
    }
    
    /* Spawn new row of enemy ships at top */
    spawn_enemy_ships(1, cols, gameboard);
}

void player_shot(int rows, int cols, char gameboard[rows][cols], int player_row)
{
    gameboard[ROWS - 1][player_row] = 'P';
    for(int i = ROWS - 2; i >= 0; i--)
    {
        if(gameboard[i][player_row] == 'E')
        {
            gameboard[i][player_row] = '.';
            return;
        }
        else if(gameboard[i][player_row] == 'P')
        {
            gameboard[i][player_row] = '.';
        }
    }
}

void enemy_shot(int rows, int cols, char gameboard[rows][cols], int* score)
{
    int random_col = rand() % cols; /* Choose random column for enemy shot */
    
    for(int i = 0; i < ROWS; i++)
    {
        if(gameboard[i][random_col] == 'P')
        {
            gameboard[i][random_col] = '.';
            (*score)++;
            return;
        }
    }
}