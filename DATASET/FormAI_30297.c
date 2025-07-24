//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// Struct to hold information about each cell
typedef struct{
    int row;
    int col;
    int distance; // distance from the starting point
    int visited; // 1 if cell has been visited, 0 otherwise
} Cell;

// Function to initialize the maze
void initialize_maze(char maze[][COL], Cell start, Cell end){
    int i, j;

    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if(i == start.row && j == start.col)
                maze[i][j] = 'S'; // Starting point
            else if(i == end.row && j == end.col)
                maze[i][j] = 'E'; // Ending point
            else
                maze[i][j] = '.'; // Empty cell
        }
    }
}

// Function to print the maze
void print_maze(char maze[][COL]){
    int i, j;

    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid (within bounds and not a wall)
int is_valid(char maze[][COL], Cell cell){
    if(cell.row >= 0 && cell.row < ROW && cell.col >= 0 && cell.col < COL && maze[cell.row][cell.col] != '#')
        return 1;
    else
        return 0;
}

// Function to calculate the distance between two cells
int calculate_distance(Cell cell1, Cell cell2){
    return abs(cell1.row - cell2.row) + abs(cell1.col - cell2.col);
}

// Function to implement the A* pathfinding algorithm
void a_star_algorithm(char maze[][COL], Cell start, Cell end){
    int i, j, min_distance, min_index;
    Cell current_cell, adjacent_cell, neighbors[8];

    // Array to store the distance from the starting point to each cell
    int distance[ROW][COL];
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            distance[i][j] = -1; // Initialize to -1 (unvisited)
        }
    }
    distance[start.row][start.col] = 0; // Set distance of starting cell to 0

    // Array to store the parent of each cell
    Cell parent[ROW][COL];
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            parent[i][j].row = -1; // Initialize to -1 (no parent)
            parent[i][j].col = -1; // Initialize to -1 (no parent)
        }
    }

    // Array to store whether each cell has been visited or not
    int visited[ROW][COL];
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            visited[i][j] = 0; // Initialize to 0 (unvisited)
        }
    }

    // Add starting cell to open list
    Cell open_list[ROW * COL];
    int open_list_size = 1;
    open_list[0] = start;

    // Loop until end cell is found or open list is empty
    while(open_list_size > 0){
        // Find cell with minimum distance from start in open list
        min_distance = distance[open_list[0].row][open_list[0].col];
        min_index = 0;
        for(i = 1; i < open_list_size; i++){
            if(distance[open_list[i].row][open_list[i].col] < min_distance){
                min_distance = distance[open_list[i].row][open_list[i].col];
                min_index = i;
            }
        }
        // Set current cell to the cell with minimum distance from start
        current_cell = open_list[min_index];
        // Remove current cell from open list
        for(i = min_index; i < open_list_size - 1; i++){
            open_list[i] = open_list[i + 1];
        }
        open_list_size--;

        // Check if current cell is end cell
        if(current_cell.row == end.row && current_cell.col == end.col){
            // Trace path from end cell to start cell using parent array
            Cell path[ROW * COL];
            int path_size = 0;

            while(current_cell.row != start.row || current_cell.col != start.col){
                path[path_size] = current_cell;
                path_size++;
                current_cell = parent[current_cell.row][current_cell.col];
            }

            // Add start cell to path and print path
            path[path_size] = start;
            path_size++;
            printf("Path found with distance %d:\n", distance[end.row][end.col]);
            for(i = path_size - 1; i >= 0; i--){
                printf("(%d, %d)\n", path[i].row, path[i].col);
                maze[path[i].row][path[i].col] = '*'; // Mark cell in maze as part of path
            }

            return; // Exit function
        }

        // Mark current cell as visited
        visited[current_cell.row][current_cell.col] = 1;

        // Find neighboring cells and add them to open list if they are valid
        neighbors[0].row = current_cell.row - 1;
        neighbors[0].col = current_cell.col;
        neighbors[1].row = current_cell.row;
        neighbors[1].col = current_cell.col + 1;
        neighbors[2].row = current_cell.row + 1;
        neighbors[2].col = current_cell.col;
        neighbors[3].row = current_cell.row;
        neighbors[3].col = current_cell.col - 1;
        neighbors[4].row = current_cell.row - 1;
        neighbors[4].col = current_cell.col - 1;
        neighbors[5].row = current_cell.row - 1;
        neighbors[5].col = current_cell.col + 1;
        neighbors[6].row = current_cell.row + 1;
        neighbors[6].col = current_cell.col + 1;
        neighbors[7].row = current_cell.row + 1;
        neighbors[7].col = current_cell.col - 1;

        for(i = 0; i < 8; i++){
            adjacent_cell = neighbors[i];
            if(is_valid(maze, adjacent_cell)){
                // Calculate tentative distance from starting cell to adjacent cell
                int tentative_distance = distance[current_cell.row][current_cell.col] + calculate_distance(current_cell, adjacent_cell);
                if(!visited[adjacent_cell.row][adjacent_cell.col] || tentative_distance < distance[adjacent_cell.row][adjacent_cell.col]){
                    // Update distance to adjacent cell and add it to open list
                    distance[adjacent_cell.row][adjacent_cell.col] = tentative_distance;
                    parent[adjacent_cell.row][adjacent_cell.col] = current_cell;
                    // Add adjacent cell to open list if it's not already there
                    for(j = 0; j < open_list_size; j++){
                        if(open_list[j].row == adjacent_cell.row && open_list[j].col == adjacent_cell.col)
                            break;
                    }
                    if(j == open_list_size){
                        open_list[open_list_size] = adjacent_cell;
                        open_list_size++;
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

int main(){
    int i, j;
    char maze[ROW][COL];

    // Initialize maze
    Cell start = {3, 3};
    Cell end = {5, 8};
    initialize_maze(maze, start, end);

    // Add walls to maze
    maze[1][4] = '#';
    maze[2][4] = '#';
    maze[3][4] = '#';
    maze[4][4] = '#';
    maze[5][4] = '#';

    // Print maze before finding path
    printf("Maze before:\n");
    print_maze(maze);

    // Find path using A* algorithm
    a_star_algorithm(maze, start, end);

    // Print maze after finding path
    printf("Maze after:\n");
    print_maze(maze);

    return 0;
}