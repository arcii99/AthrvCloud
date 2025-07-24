//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_COUNT 10
#define COLUMN_COUNT 10

// Structure to represent a point in the grid
typedef struct Point
{
    int row;
    int column;
} Point;

// Structure to store values of a cell
typedef struct Cell
{
    Point coordinates;
    int f;
    int g;
    int h;
    bool is_obstacle;
} Cell;

// Calculate the distance between two points using Manhattan distance algorithm
int calc_manhattan_distance(Point start, Point end)
{
    return abs(start.row - end.row) + abs(start.column - end.column);
}

// Check if the given point is within the bounds of the grid
bool is_valid_point(Point point)
{
    return point.row >= 0 && point.row < ROW_COUNT && point.column >= 0 && point.column < COLUMN_COUNT;
}

// Check if the given point is an obstacle
bool is_obstacle(Cell grid[ROW_COUNT][COLUMN_COUNT], Point point)
{
    return grid[point.row][point.column].is_obstacle;
}

// Check if the given point is the destination
bool is_destination(Point point, Point destination)
{
    return point.row == destination.row && point.column == destination.column;
}

// Get the adjacent cells of the given cell
void get_adjacent_cells(Cell grid[ROW_COUNT][COLUMN_COUNT], Point point, Cell adjacent_cells[])
{
    // Define the directions and possible moves
    Point directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Loop through each direction and add adjacent cells
    for (int i = 0; i < 4; i++)
    {
        Point move = directions[i];
        Point adjacent_point = {point.row + move.row, point.column + move.column};

        if (is_valid_point(adjacent_point) && !is_obstacle(grid, adjacent_point))
        {
            Cell adjacent_cell = grid[adjacent_point.row][adjacent_point.column];
            adjacent_cells[i] = adjacent_cell;
        }
    }
}

// Get the cell with the lowest f value
Cell get_lowest_f(Cell open_set[], int open_set_size)
{
    int lowest_f = open_set[0].f;
    int lowest_f_index = 0;

    // Loop through each cell and get the cell with the lowest f value
    for (int i = 1; i < open_set_size; i++)
    {
        if (open_set[i].f < lowest_f)
        {
            lowest_f = open_set[i].f;
            lowest_f_index = i;
        }
    }

    Cell lowest_f_cell = open_set[lowest_f_index];
    return lowest_f_cell;
}

// Initialize the grid with cells
void initialize_grid(Cell grid[ROW_COUNT][COLUMN_COUNT])
{
    for (int row = 0; row < ROW_COUNT; row++)
    {
        for (int column = 0; column < COLUMN_COUNT; column++)
        {
            Cell cell;
            cell.coordinates = (Point){row, column};
            cell.f = 0;
            cell.g = 0;
            cell.h = 0;
            cell.is_obstacle = false;

            grid[row][column] = cell;
        }
    }

    // Set some cells as obstacles
    grid[2][4].is_obstacle = true;
    grid[3][4].is_obstacle = true;
    grid[4][4].is_obstacle = true;
}

int main()
{
    // Initialize the grid with cells
    Cell grid[ROW_COUNT][COLUMN_COUNT];
    initialize_grid(grid);

    Point start = {0, 0};
    Point destination = {9, 9};

    Cell open_set[ROW_COUNT * COLUMN_COUNT];
    int open_set_size = 1;
    open_set[0] = grid[start.row][start.column];

    Cell came_from[ROW_COUNT][COLUMN_COUNT];

    // Loop through each cell
    while (open_set_size > 0)
    {
        // Get the cell with the lowest f value
        Cell current_cell = get_lowest_f(open_set, open_set_size);

        // Check if the current cell is the destination
        if (is_destination(current_cell.coordinates, destination))
        {
            Point path[ROW_COUNT * COLUMN_COUNT];
            int path_size = 0;

            // Reconstruct the path
            while (!is_destination(current_cell.coordinates, start))
            {
                path_size++;
                path[path_size] = current_cell.coordinates;
                current_cell = came_from[current_cell.coordinates.row][current_cell.coordinates.column];
            }

            // Print the path
            for (int i = path_size; i > 0; i--)
            {
                printf("(%d, %d) ", path[i].row, path[i].column);
            }
            printf("-> (%d, %d)\n", destination.row, destination.column);

            return 0;
        }

        // Remove the current cell from the open set
        for (int i = 0; i < open_set_size; i++)
        {
            if (open_set[i].coordinates.row == current_cell.coordinates.row && open_set[i].coordinates.column == current_cell.coordinates.column)
            {
                open_set_size--;
                open_set[i] = open_set[open_set_size];
                break;
            }
        }

        // Get the adjacent cells
        Cell adjacent_cells[4];
        get_adjacent_cells(grid, current_cell.coordinates, adjacent_cells);

        // Loop through each adjacent cell
        for (int i = 0; i < 4; i++)
        {
            Cell adjacent_cell = adjacent_cells[i];

            if (adjacent_cell.coordinates.row == 0 && adjacent_cell.coordinates.column == 0)
            {
                continue;
            }

            int tentative_g_score = current_cell.g + 1;

            // Check if the adjacent cell is already visited
            bool is_visited = false;
            for (int j = 0; j < open_set_size; j++)
            {
                if (open_set[j].coordinates.row == adjacent_cell.coordinates.row && open_set[j].coordinates.column == adjacent_cell.coordinates.column)
                {
                    is_visited = true;
                    break;
                }
            }

            if (!is_visited || tentative_g_score < adjacent_cell.g)
            {
                // Set the values of the adjacent cell
                Cell new_cell = adjacent_cell;
                new_cell.g = tentative_g_score;
                new_cell.h = calc_manhattan_distance(adjacent_cell.coordinates, destination);
                new_cell.f = new_cell.g + new_cell.h;

                // Add the adjacent cell to the open set
                open_set[open_set_size] = new_cell;
                open_set_size++;

                // Set the came_from value of the adjacent cell
                came_from[adjacent_cell.coordinates.row][adjacent_cell.coordinates.column] = current_cell;
            }
        }
    }

    printf("No path found\n");

    return 0;
}