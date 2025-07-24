//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int f[ROWS][COLS];   // F cost of each cell
int g[ROWS][COLS];   // G cost of each cell
int h[ROWS][COLS];   // H cost of each cell
int open_list[ROWS*COLS];   // Open list to hold cells to be checked
int closed_list[ROWS*COLS]; // Closed list to hold already checked cells
bool obstacles[ROWS][COLS] = {false}; // Boolean array to hold obstacles

/* calculate heuristic cost of a cell */
int calc_h_cost(int curr_x, int curr_y, int target_x, int target_y)
{
    return abs(target_x - curr_x) + abs(target_y - curr_y);
}

/* check if a cell is valid (within bounds and not an obstacle) */
bool is_valid_cell(int x, int y)
{
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && !obstacles[x][y])
        return true;
    else
        return false;
}

/* check if a cell is already in the open or closed list */
bool is_in_list(int x, int y, int list[], int len)
{
    for (int i = 0; i < len; i += 2)
    {
        if (list[i] == x && list[i+1] == y)
            return true;
    }
    return false;
}

/* get index of cell with minimum F cost in the open list */
int get_min_f_cell(int list[], int len)
{
    int min_f = 1000;
    int min_f_index = -1;
    for (int i = 0; i < len; i += 2)
    {
        int x = list[i];
        int y = list[i+1];
        if (f[x][y] < min_f)
        {
            min_f = f[x][y];
            min_f_index = i;
        }
    }
    return min_f_index;
}

/* print the path found */
void print_path(int path_x[], int path_y[], int len)
{
    printf("\nPath found:\n");
    for (int i = len-1; i >= 0; i--)
    {
        printf("(%d,%d)", path_x[i], path_y[i]);
        if (i > 0)
            printf(" -> ");
    }
    printf("\n");
}

/* find shortest path using A* algorithm */
void find_path(int start_x, int start_y, int target_x, int target_y)
{
    int curr_x = start_x;
    int curr_y = start_y;
    int num_open = 0;
    int num_closed = 0;
    int path_x[ROWS*COLS] = {0};
    int path_y[ROWS*COLS] = {0};
    
    // Initialize F, G, H costs of each cell
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            g[i][j] = 1000;
            h[i][j] = calc_h_cost(i, j, target_x, target_y);
            f[i][j] = g[i][j] + h[i][j];
        }
    }
    
    // Add start cell to open list
    open_list[num_open++] = curr_x;
    open_list[num_open++] = curr_y;
    g[curr_x][curr_y] = 0;
    f[curr_x][curr_y] = h[curr_x][curr_y];
    
    // Loop until target found or no more open cells
    while (num_open > 0)
    {
        // Get cell with minimum F cost from open list
        int min_f_index = get_min_f_cell(open_list, num_open);
        curr_x = open_list[min_f_index];
        curr_y = open_list[min_f_index+1];
        
        // Check if target cell found
        if (curr_x == target_x && curr_y == target_y)
        {
            path_x[0] = curr_x;
            path_y[0] = curr_y;
            int path_len = 1;
            while (curr_x != start_x || curr_y != start_y)
            {
                int px = curr_x;
                curr_x = closed_list[num_closed-2*path_len];
                int py = curr_y;
                curr_y = closed_list[num_closed-2*path_len+1];
                path_x[path_len] = px;
                path_y[path_len++] = py;
            }
            print_path(path_x, path_y, path_len);
            return;
        }
        
        // Move current cell from open to closed list
        open_list[min_f_index] = open_list[num_open-2];
        open_list[min_f_index+1] = open_list[num_open-1];
        num_open -= 2;
        closed_list[num_closed++] = curr_x;
        closed_list[num_closed++] = curr_y;
        
        // Check and add adjacent cells to open list
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((i != 0 || j != 0) && is_valid_cell(curr_x+i, curr_y+j))
                {
                    int temp_g = g[curr_x][curr_y] + 1;
                    int index_open = -1;
                    int index_closed = -1;
                    
                    // Check if cell is in open or closed list
                    if (is_in_list(curr_x+i, curr_y+j, open_list, num_open))
                        index_open = 2*(curr_x+i) + 2*(curr_y+j)*COLS;
                    
                    if (is_in_list(curr_x+i, curr_y+j, closed_list, num_closed))
                        index_closed = 2*(curr_x+i) + 2*(curr_y+j)*COLS;
                    
                    // If cell is not in any of the lists, add to open list
                    if (index_open == -1 && index_closed == -1)
                    {
                        open_list[num_open++] = curr_x+i;
                        open_list[num_open++] = curr_y+j;
                        g[curr_x+i][curr_y+j] = temp_g;
                        h[curr_x+i][curr_y+j] = calc_h_cost(curr_x+i, curr_y+j, target_x, target_y);
                        f[curr_x+i][curr_y+j] = g[curr_x+i][curr_y+j] + h[curr_x+i][curr_y+j];
                    }
                    // If cell is in open list and new G cost is lower, update values
                    else if (index_open != -1 && temp_g < g[curr_x+i][curr_y+j])
                    {
                        g[curr_x+i][curr_y+j] = temp_g;
                        f[curr_x+i][curr_y+j] = g[curr_x+i][curr_y+j] + h[curr_x+i][curr_y+j];
                        open_list[index_open] = curr_x+i;
                        open_list[index_open+1] = curr_y+j;
                    }
                }
            }
        }
    }
    
    printf("\nNo path found.\n");
}

int main()
{
    // Set obstacles
    obstacles[1][4] = true;
    obstacles[2][4] = true;
    obstacles[3][4] = true;
    obstacles[4][4] = true;
    obstacles[5][4] = true;
    obstacles[6][4] = true;
    obstacles[7][4] = true;
    obstacles[8][3] = true;
    obstacles[8][4] = true;
    obstacles[8][5] = true;
    
    // Find path
    find_path(2, 2, 8, 7);
    return 0;
}