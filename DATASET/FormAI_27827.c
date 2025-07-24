//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generate_maze(int maze[][COLS])
{
    srand(time(NULL));

    // initialize maze with all walls
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            maze[i][j] = 0b1111; // binary representation of four walls
        }
    }
    
    int current_row = rand() % ROWS;
    int current_col = rand() % COLS;

    // carve paths through the maze using depth-first search
    while(1)
    {
        // mark current cell as visited
        maze[current_row][current_col] &= 0b0111; // remove north wall

        // check neighboring cells
        int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
        int unvisited_neighbors = 0;
        int unvisited_neighbor_row = -1;
        int unvisited_neighbor_col = -1;
        for(int i = 0; i < 4; i++)
        {
            int neighbor_row = current_row + neighbors[i][0];
            int neighbor_col = current_col + neighbors[i][1];
            if(neighbor_row >= 0 && neighbor_row < ROWS && neighbor_col >= 0 && neighbor_col < COLS)
            {
                if(maze[neighbor_row][neighbor_col] == 0b1111) // not visited
                {
                    unvisited_neighbors++;
                    unvisited_neighbor_row = neighbor_row;
                    unvisited_neighbor_col = neighbor_col;
                }
            }
        }

        if(unvisited_neighbors > 0)
        {
            // choose a random unvisited neighbor
            int neighbor_index = rand() % unvisited_neighbors;
            current_row = unvisited_neighbor_row;
            current_col = unvisited_neighbor_col;
            
            // remove walls between current cell and chosen neighbor
            if(neighbor_index == 0) // up
            {
                maze[current_row][current_col] &= 0b1011; // remove south wall in current cell
                maze[current_row-1][current_col] &= 0b1101; // remove north wall in neighbor
            }
            else if(neighbor_index == 1) // down
            {
                maze[current_row][current_col] &= 0b1101; // remove north wall in current cell
                maze[current_row+1][current_col] &= 0b1011; // remove south wall in neighbor
            }
            else if(neighbor_index == 2) // left
            {
                maze[current_row][current_col] &= 0b1110; // remove east wall in current cell
                maze[current_row][current_col-1] &= 0b0111; // remove west wall in neighbor
            }
            else if(neighbor_index == 3) // right
            {
                maze[current_row][current_col] &= 0b0111; // remove west wall in current cell
                maze[current_row][current_col+1] &= 0b1110; // remove east wall in neighbor
            }
        }
        else
        {
            // no unvisited neighbors, backtrack
            int backtrack_row = -1;
            int backtrack_col = -1;
            for(int i = 0; i < 4; i++)
            {
                int neighbor_row = current_row + neighbors[i][0];
                int neighbor_col = current_col + neighbors[i][1];
                if(neighbor_row >= 0 && neighbor_row < ROWS && neighbor_col >= 0 && neighbor_col < COLS)
                {
                    if((maze[neighbor_row][neighbor_col] & 0b1000) == 0) // visited
                    {
                        backtrack_row = neighbor_row;
                        backtrack_col = neighbor_col;
                        break;
                    }
                }
            }
            if(backtrack_row == -1 || backtrack_col == -1)
            {
                break; // done carving paths
            }
            current_row = backtrack_row;
            current_col = backtrack_col;
        }
    }
}

void print_maze(int maze[][COLS])
{
    printf("+---+---+---+---+---+---+---+---+---+---+\n");
    for(int i = 0; i < ROWS; i++)
    {
        printf("|");
        for(int j = 0; j < COLS; j++)
        {
            printf("   ");
            if((maze[i][j] & 0b0001) == 0) // north wall
            {
                printf(" ");
            }
            else
            {
                printf("-");
            }
            printf(" ");
        }
        printf("|\n|");
        for(int j = 0; j < COLS; j++)
        {
            if((maze[i][j] & 0b0010) == 0) // west wall
            {
                printf(" ");
            }
            else
            {
                printf("|");
            }
            printf("   ");
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+---+---+---+\n");
}

int main()
{
    int maze[ROWS][COLS];
    generate_maze(maze);
    print_maze(maze);
    return 0;
}