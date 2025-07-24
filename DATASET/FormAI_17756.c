//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: energetic
// Welcome to my exciting pathfinding algorithm program!
#include <stdio.h>
#include <stdlib.h>

// Define the size of the grid
#define ROWS 10
#define COLUMNS 10

// Define the start and end points
int start_row = 0;
int start_column = 0;
int end_row = ROWS - 1;
int end_column = COLUMNS - 1;

// Create the grid
int grid[ROWS][COLUMNS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Create a struct for each point on the grid
struct Point {
    int row;
    int column;
    int g_score;
    int h_score;
    int f_score;
    struct Point *parent;
};

// Function to calculate the heuristic value (h score)
int calculate_h_score(struct Point *current) {
    int dx = abs(current->row - end_row);
    int dy = abs(current->column - end_column);
    return dx + dy;
}

// Function to check if a point is valid (not out of bounds and not an obstacle)
int is_valid(struct Point *current) {
    if (current->row < 0 || current->row >= ROWS) return 0;
    if (current->column < 0 || current->column >= COLUMNS) return 0;
    if (grid[current->row][current->column] == 1) return 0;
    return 1;
}

// Function to check if a point is the goal
int is_goal(struct Point *current) {
    if (current->row == end_row && current->column == end_column) return 1;
    return 0;
}

// Function to search for the path using A* algorithm
void find_path() {
    // Create the open and closed lists
    struct Point *open_list[ROWS*COLUMNS];
    int open_list_size = 0;
    struct Point *closed_list[ROWS*COLUMNS];
    int closed_list_size = 0;
    
    // Create the starting point
    struct Point start;
    start.row = start_row;
    start.column = start_column;
    start.g_score = 0;
    start.h_score = calculate_h_score(&start);
    start.f_score = start.g_score + start.h_score;
    start.parent = NULL;
    
    // Add the starting point to the open list
    open_list[open_list_size++] = &start;
    
    while (open_list_size > 0) {
        // Find the lowest f_score point in the open list
        int lowest_f_score = open_list[0]->f_score;
        int lowest_f_score_index = 0;
        for (int i = 1; i < open_list_size; i++) {
            if (open_list[i]->f_score < lowest_f_score) {
                lowest_f_score = open_list[i]->f_score;
                lowest_f_score_index = i;
            }
        }
        struct Point *current = open_list[lowest_f_score_index];
        
        // Remove the current point from the open list and add it to the closed list
        open_list[lowest_f_score_index] = open_list[--open_list_size];
        closed_list[closed_list_size++] = current;
        
        // Check if the current point is the goal
        if (is_goal(current)) {
            // Print the path
            printf("Path: ");
            while (current->parent != NULL) {
                printf("(%d,%d) ", current->row, current->column);
                current = current->parent;
            }
            printf("(%d,%d)\n", start_row, start_column);
            return;
        }
        
        // Generate the neighbors of the current point
        struct Point neighbors[4];
        neighbors[0].row = current->row - 1;
        neighbors[0].column = current->column;
        neighbors[1].row = current->row + 1;
        neighbors[1].column = current->column;
        neighbors[2].row = current->row;
        neighbors[2].column = current->column - 1;
        neighbors[3].row = current->row;
        neighbors[3].column = current->column + 1;
        
        // Loop through the neighbors
        for (int i = 0; i < 4; i++) {
            // Check if the neighbor is valid
            if (!is_valid(&neighbors[i])) continue;
            
            // Check if the neighbor is in the closed list
            int in_closed_list = 0;
            for (int j = 0; j < closed_list_size; j++) {
                if (neighbors[i].row == closed_list[j]->row && neighbors[i].column == closed_list[j]->column) {
                    in_closed_list = 1;
                    break;
                }
            }
            if (in_closed_list) continue;
            
            // Calculate the g score, h score, and f score of the neighbor
            int tentative_g_score = current->g_score + 1;
            int in_open_list = 0;
            for (int j = 0; j < open_list_size; j++) {
                if (neighbors[i].row == open_list[j]->row && neighbors[i].column == open_list[j]->column) {
                    in_open_list = 1;
                    if (tentative_g_score < open_list[j]->g_score) {
                        open_list[j]->g_score = tentative_g_score;
                        open_list[j]->f_score = open_list[j]->g_score + open_list[j]->h_score;
                        open_list[j]->parent = current;
                    }
                    break;
                }
            }
            if (!in_open_list) {
                neighbors[i].g_score = tentative_g_score;
                neighbors[i].h_score = calculate_h_score(&neighbors[i]);
                neighbors[i].f_score = neighbors[i].g_score + neighbors[i].h_score;
                neighbors[i].parent = current;
                open_list[open_list_size++] = &neighbors[i];
            }
        }
    }
    
    printf("No path found!\n");
}

// Main function
int main() {
    printf("Starting point: (%d,%d)\n", start_row, start_column);
    printf("End point: (%d,%d)\n", end_row, end_column);
    find_path();
    return 0;
}