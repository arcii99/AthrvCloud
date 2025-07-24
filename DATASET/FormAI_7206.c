//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 40
#define SYMBOL "@"

int pacman_row, pacman_col;
int ghost_row, ghost_col;
int score;

char grid[ROWS][COLUMNS];

void initialize_grid()
{
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            if(i==0 || i==ROWS-1 || j==0 || j==COLUMNS-1)
                grid[i][j] = '#';
            else
                grid[i][j] = ' ';
        }
    }
}

void print_grid()
{
    system("clear");
    int i, j;
    printf("Score: %d\n", score);
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void spawn_pacman()
{
    pacman_row = ROWS/2;
    pacman_col = COLUMNS/2;
    grid[pacman_row][pacman_col] = 'C';
}

void move_pacman(int direction)
{
    switch(direction) {
        case 0: // up
            if(grid[pacman_row-1][pacman_col] != '#')
                pacman_row--;
            break;
        case 1: // down
            if(grid[pacman_row+1][pacman_col] != '#')
                pacman_row++;
            break;
        case 2: // left
            if(grid[pacman_row][pacman_col-1] != '#')
                pacman_col--;
            break;
        case 3: // right
            if(grid[pacman_row][pacman_col+1] != '#')
                pacman_col++;
            break;
    }
    if(grid[pacman_row][pacman_col] == '@') {
        score += 10;
        grid[pacman_row][pacman_col] = ' ';
    }
    grid[pacman_row][pacman_col] = 'C';
}

void spawn_ghost()
{
    ghost_row = rand() % (ROWS-2) + 1;
    ghost_col = rand() % (COLUMNS-2) + 1;
    grid[ghost_row][ghost_col] = 'G';
}

void move_ghost()
{
    int p_row = pacman_row;
    int p_col = pacman_col;
    if(ghost_row < p_row && grid[ghost_row+1][ghost_col] != '#')
        ghost_row++;
    else if(ghost_row > p_row && grid[ghost_row-1][ghost_col] != '#')
        ghost_row--;
    else if(ghost_col < p_col && grid[ghost_row][ghost_col+1] != '#')
        ghost_col++;
    else if(ghost_col > p_col && grid[ghost_row][ghost_col-1] != '#')
        ghost_col--;
    grid[ghost_row][ghost_col] = 'G';
}

int main()
{
    initialize_grid();
    spawn_pacman();
    spawn_ghost();
    srand(time(NULL));
    int i, direction;
    for(i=0; i<10; i++) {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLUMNS-2) + 1;
        grid[row][col] = '@';
    }
    print_grid();
    while(1) {
        direction = getchar();
        switch(direction) {
            case 65: // up arrow
                move_pacman(0);
                break;
            case 66: // down arrow
                move_pacman(1);
                break;
            case 68: // left arrow
                move_pacman(2);
                break;
            case 67: // right arrow
                move_pacman(3);
                break;
        }
        move_ghost();
        print_grid();
        if(pacman_row == ghost_row && pacman_col == ghost_col) {
            printf("Game Over. Final score: %d\n", score);
            return 0;
        }
    }
    return 0;
}