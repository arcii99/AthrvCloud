//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// cell structure to store f, g, and h
struct cell
{
    bool traversable; // is the cell traversable or not
    int row, col; // coordinates
    int f, g, h; // f = g + h
    struct cell *parent; // to track the path
};

// create a 2D array of cells
struct cell grid[ROWS][COLS];

// function to calculate the h value of a cell using Manhattan distance
int calculate_h(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}

// function to check if a cell is traversable or not
bool is_traversable(int row, int col)
{
    if (row >= 0 && col >= 0 && row < ROWS && col < COLS && grid[row][col].traversable)
        return true;
    else
        return false;
}

// function to get the neighboring cells of a given cell
void get_neighbors(struct cell *current, struct cell **neighbors, int *num_neighbors)
{
    int row = current->row;
    int col = current->col;
    int count = 0;

    // check the eight surrounding cells
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) // skip the current cell
                continue;
            if (is_traversable(row+i, col+j)) // if the cell is traversable, add it to the neighbors list
            {
                neighbors[count] = &grid[row+i][col+j];
                count++;
            }
        }
    }

    *num_neighbors = count;
}

// function to find the cell with the lowest f value
struct cell *get_lowest_f_cell(struct cell **open_list, int num_open)
{
    int lowest_f = open_list[0]->f;
    int lowest_index = 0;

    for (int i = 1; i < num_open; i++)
    {
        if (open_list[i]->f < lowest_f)
        {
            lowest_f = open_list[i]->f;
            lowest_index = i;
        }
    }

    return open_list[lowest_index];
}

// function to check if a cell is in a list
bool is_in_list(struct cell *cell, struct cell **list, int num_cells)
{
    for (int i = 0; i < num_cells; i++)
    {
        if (cell == list[i])
            return true;
    }

    return false;
}

// function to get the path from the start cell to the end cell
void get_path(struct cell *start, struct cell *end)
{
    struct cell *current = end;

    // follow the parent pointers until we reach the start cell
    while (current != start)
    {
        printf("(%d, %d) ", current->row, current->col);
        current = current->parent;
    }

    printf("(%d, %d)\n", start->row, start->col);
}

// function to search for a path from the start cell to the end cell
bool a_star_search(struct cell *start, struct cell *end)
{
    struct cell *open_list[ROWS*COLS]; // list of cells to be evaluated
    int num_open = 0;

    struct cell *closed_list[ROWS*COLS]; // list of cells already evaluated
    int num_closed = 0;

    // set the g and h values of the start cell
    start->g = 0;
    start->h = calculate_h(start->row, start->col, end->row, end->col);
    start->f = start->g + start->h;

    // add the start cell to the open list
    open_list[num_open] = start;
    num_open++;

    // loop until we find the end cell or the open list is empty
    while (num_open > 0)
    {
        // get the cell with the lowest f value from the open list
        struct cell *current = get_lowest_f_cell(open_list, num_open);

        // if the current cell is the end cell, we're done
        if (current == end)
        {
            get_path(start, end);
            return true;
        }

        // move the current cell from the open list to the closed list
        for (int i = 0; i < num_open; i++)
        {
            if (open_list[i] == current)
            {
                // shift the remaining cells to fill the gap
                for (int j = i; j < num_open-1; j++)
                    open_list[j] = open_list[j+1];
                num_open--;
                break;
            }
        }

        closed_list[num_closed] = current;
        num_closed++;

        // get the neighboring cells of the current cell
        struct cell *neighbors[8];
        int num_neighbors = 0;

        get_neighbors(current, neighbors, &num_neighbors);

        // evaluate each neighboring cell
        for (int i = 0; i < num_neighbors; i++)
        {
            struct cell *neighbor = neighbors[i];

            // if the neighbor is already evaluated, skip it
            if (is_in_list(neighbor, closed_list, num_closed))
                continue;

            // calculate the g value of the neighbor
            int temp_g = current->g + calculate_h(current->row, current->col, neighbor->row, neighbor->col);

            // if the neighbor is not in the open list, add it
            if (!is_in_list(neighbor, open_list, num_open))
            {
                neighbor->g = temp_g;
                neighbor->h = calculate_h(neighbor->row, neighbor->col, end->row, end->col);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
                open_list[num_open] = neighbor;
                num_open++;
            }
            // if the neighbor is already in the open list, update its g value if necessary
            else if (temp_g < neighbor->g)
            {
                neighbor->g = temp_g;
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
            }
        }
    }

    // if we get here, there is no path from the start cell to the end cell
    printf("No path found.\n");
    return false;
}

// main function
int main()
{
    // initialize the grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j].traversable = true;
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].parent = NULL;
        }
    }

    // set some cells as not traversable (obstacles)
    grid[1][1].traversable = false;
    grid[2][1].traversable = false;
    grid[3][1].traversable = false;
    grid[4][1].traversable = false;
    grid[5][1].traversable = false;
    grid[6][1].traversable = false;
    grid[7][1].traversable = false;
    grid[8][1].traversable = false;
    grid[9][1].traversable = false;
    grid[9][2].traversable = false;
    grid[9][3].traversable = false;
    grid[9][4].traversable = false;
    grid[9][5].traversable = false;
    grid[9][6].traversable = false;
    grid[9][7].traversable = false;
    grid[9][8].traversable = false;
    grid[9][9].traversable = false;

    // set the start and end cells
    struct cell *start = &grid[0][0];
    struct cell *end = &grid[5][9];

    // search for a path from the start cell to the end cell
    a_star_search(start, end);

    return 0;
}