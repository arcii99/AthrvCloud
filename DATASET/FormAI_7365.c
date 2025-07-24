//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define WALL '#'
#define EMPTY ' '
#define FOOD '.'
#define PACMAN 'P'
#define GHOST 'G'

// Function prototypes
void initializeBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
void spawnPacman(char board[ROWS][COLS], int *p_row, int *p_col);
void spawnGhosts(char board[ROWS][COLS], int *g_row, int *g_col, int num_ghosts);
void movePacman(char board[ROWS][COLS], int *p_row, int *p_col, char direction);
void moveGhosts(char board[ROWS][COLS], int *g_row, int *g_col, int num_ghosts);
int checkGameOver(char board[ROWS][COLS], int p_row, int p_col);

int main(void)
{
    // Set up game board
    char board[ROWS][COLS];
    initializeBoard(board);
    
    // Set up game variables
    int p_row, p_col, g_row, g_col, num_ghosts = 5;
    char direction;
    srand(time(NULL)); // Seed random number generator
    
    // Spawn Pacman and ghosts randomly
    spawnPacman(board, &p_row, &p_col);
    spawnGhosts(board, &g_row, &g_col, num_ghosts);
    
    // Play game until game over
    while(!checkGameOver(board, p_row, p_col))
    {
        printBoard(board);
        printf("\nEnter direction (w/a/s/d): ");
        scanf(" %c", &direction);
        
        movePacman(board, &p_row, &p_col, direction);
        moveGhosts(board, &g_row, &g_col, num_ghosts);
    }
    
    // Print end-of-game message
    printBoard(board);
    printf("\nGame over!\n");
    
    return 0;
}

// Initializes the game board with walls and food
void initializeBoard(char board[ROWS][COLS])
{
    int i, j;
    
    // Create walls
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1)
                board[i][j] = WALL;
            else
                board[i][j] = EMPTY;
        }
    }
    
    // Place food
    for(i=1; i<ROWS-1; i++)
    {
        for(j=1; j<COLS-1; j++)
        {
            if((i+j)%2 == 0) // Alternate food placement to create pattern
                board[i][j] = FOOD;
        }
    }
}

// Prints the game board
void printBoard(char board[ROWS][COLS])
{
    int i, j;
    
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Spawns Pacman randomly on the game board
void spawnPacman(char board[ROWS][COLS], int *p_row, int *p_col)
{
    int row, col;
    
    // Find valid spawn location
    do
    {
        row = rand() % (ROWS-2) + 1;
        col = rand() % (COLS-2) + 1;
    } while(board[row][col] != EMPTY);
    
    // Spawn Pacman
    board[row][col] = PACMAN;
    *p_row = row;
    *p_col = col;
}

// Spawns ghosts randomly on the game board
void spawnGhosts(char board[ROWS][COLS], int *g_row, int *g_col, int num_ghosts)
{
    int i, row, col;
    
    // Spawn ghosts
    for(i=0; i<num_ghosts; i++)
    {
        // Find valid spawn location
        do
        {
            row = rand() % (ROWS-2) + 1;
            col = rand() % (COLS-2) + 1;
        } while(board[row][col] != EMPTY);
        
        // Spawn ghost
        board[row][col] = GHOST;
        g_row[i] = row;
        g_col[i] = col;
    }
}

// Moves Pacman in the specified direction
void movePacman(char board[ROWS][COLS], int *p_row, int *p_col, char direction)
{
    // Move Pacman based on direction input
    switch(direction)
    {
        case 'w':
            if(board[*p_row-1][*p_col] != WALL)
            {
                board[*p_row][*p_col] = EMPTY;
                *p_row -= 1;
                board[*p_row][*p_col] = PACMAN;
            }
            break;
        case 'a':
            if(board[*p_row][*p_col-1] != WALL)
            {
                board[*p_row][*p_col] = EMPTY;
                *p_col -= 1;
                board[*p_row][*p_col] = PACMAN;
            }
            break;
        case 's':
            if(board[*p_row+1][*p_col] != WALL)
            {
                board[*p_row][*p_col] = EMPTY;
                *p_row += 1;
                board[*p_row][*p_col] = PACMAN;
            }
            break;
        case 'd':
            if(board[*p_row][*p_col+1] != WALL)
            {
                board[*p_row][*p_col] = EMPTY;
                *p_col += 1;
                board[*p_row][*p_col] = PACMAN;
            }
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

// Moves ghosts randomly
void moveGhosts(char board[ROWS][COLS], int *g_row, int *g_col, int num_ghosts)
{
    int i, rand_dir;
    char dir;
    
    // Move each ghost randomly
    for(i=0; i<num_ghosts; i++)
    {
        // Randomly choose direction
        rand_dir = rand() % 4;
        switch(rand_dir)
        {
            case 0:
                dir = 'w';
                break;
            case 1:
                dir = 'a';
                break;
            case 2:
                dir = 's';
                break;
            case 3:
                dir = 'd';
                break;
        }
        
        // Move in chosen direction if possible
        if(dir == 'w' && board[g_row[i]-1][g_col[i]] != WALL)
        {
            board[g_row[i]][g_col[i]] = EMPTY;
            g_row[i] -= 1;
            board[g_row[i]][g_col[i]] = GHOST;
        }
        else if(dir == 'a' && board[g_row[i]][g_col[i]-1] != WALL)
        {
            board[g_row[i]][g_col[i]] = EMPTY;
            g_col[i] -= 1;
            board[g_row[i]][g_col[i]] = GHOST;
        }
        else if(dir == 's' && board[g_row[i]+1][g_col[i]] != WALL)
        {
            board[g_row[i]][g_col[i]] = EMPTY;
            g_row[i] += 1;
            board[g_row[i]][g_col[i]] = GHOST;
        }
        else if(dir == 'd' && board[g_row[i]][g_col[i]+1] != WALL)
        {
            board[g_row[i]][g_col[i]] = EMPTY;
            g_col[i] += 1;
            board[g_row[i]][g_col[i]] = GHOST;
        }
    }
}

// Checks if game is over (i.e. Pacman has hit a ghost)
// Returns 1 if game over, 0 otherwise
int checkGameOver(char board[ROWS][COLS], int p_row, int p_col)
{
    int i;
    
    // Check if Pacman has hit a ghost
    if(board[p_row][p_col] == GHOST)
        return 1;
    
    // Check if there is any food left
    for(i=1; i<ROWS-1; i++)
    {
        if(strchr(board[i], FOOD) != NULL)
            return 0;
    }
    
    // No food left, game over
    return 1;
}