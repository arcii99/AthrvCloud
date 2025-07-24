//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10
#define WALL 1
#define SOURCE 2
#define DEST 3
#define PATH 4

// Struct representing each cell in the grid
typedef struct {
    int row;
    int col;
    int type;
    int g_score;
    int f_score;
    struct cell* parent;
} cell;

// Create the grid and initialize all cells
void createGrid(cell grid[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].type = 0;
            grid[i][j].g_score = 0;
            grid[i][j].f_score = 0;
            grid[i][j].parent = NULL;
        }
    }
}

// Print the grid to console
void printGrid(cell grid[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j].type);
        }
        printf("\n");
    }
}

// Check if a cell is valid to be added to open list
bool isValid(cell c, bool closed[ROWS][COLS], int grid[ROWS][COLS])
{
    int row = c.row;
    int col = c.col;
    
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    
    if(closed[row][col] == true || grid[row][col] == WALL) {
        return false;
    }
    
    return true;
}

// Calculate the heuristic score using Manhattan distance
int distanceBetween(cell a, cell b)
{
    int dx = abs(a.row - b.row);
    int dy = abs(a.col - b.col);
    
    return dx + dy;
}

// Find the lowest f_score cell in the open list
cell* lowestFScore(cell open[], int length)
{
    cell* lowest = &open[0];
    
    for(int i = 0; i < length; i++) {
        if(open[i].f_score < lowest->f_score) {
            lowest = &open[i];
        }
    }
    
    return lowest;
}

// Check if a cell is in a given list
bool isInList(cell* c, cell list[], int length)
{
    for(int i = 0; i < length; i++) {
        if(c->row == list[i].row && c->col == list[i].col) {
            return true;
        }
    }
    
    return false;
}

// Get a list of valid neighbors of a given cell
cell* getNeighbors(cell c, int grid[ROWS][COLS], int* numNeighbors)
{
    cell* neighbors = calloc(8, sizeof(cell));
    int count = 0;
    
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            
            int row = c.row + i;
            int col = c.col + j;
            
            if(row >= 0 && row < ROWS && col >= 0 && col < COLS && (i == 0 || j == 0)) {
                cell n;
                n.row = row;
                n.col = col;
                n.type = grid[row][col];
                neighbors[count] = n;
                count++;
            }
        }
    }
    
    *numNeighbors = count;
    return neighbors;
}

// Mark the cells in the path
void markPath(cell* current)
{
    while(current->parent != NULL) {
        current = current->parent;
        current->type = PATH;
    }
}

// Find the shortest path using A* algorithm
void shortestPath(cell grid[ROWS][COLS], cell* start, cell* end)
{
    cell* open = calloc(ROWS * COLS, sizeof(cell));
    int length = 0;
    bool closed[ROWS][COLS] = {0};
    
    int gridData[ROWS][COLS] = {0};
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            gridData[i][j] = grid[i][j].type;
        }
    }
    
    start->g_score = 0;
    start->f_score = distanceBetween(*start, *end);
    
    open[length] = *start;
    length++;
    
    while(length > 0) {
        cell* current = lowestFScore(open, length);
        
        if(current->row == end->row && current->col == end->col) {
            markPath(current);
            break;
        }
        
        for(int i = 0; i < length; i++) {
            if(current == &open[i]) {
                for(int j = i; j < length - 1; j++) {
                    open[j] = open[j+1];
                }
                length--;
                break;
            }
        }
        
        closed[current->row][current->col] = true;
        
        int numNeighbors = 0;
        cell* neighbors = getNeighbors(*current, gridData, &numNeighbors);
        
        for(int i = 0; i < numNeighbors; i++) {
            cell* n = &neighbors[i];
            
            if(isValid(*n, closed, gridData)) {
                int temp_g_score = current->g_score + 1;
                
                if(isInList(n, open, length) == false) {
                    open[length] = *n;
                    length++;
                    
                    n->g_score = temp_g_score;
                    n->f_score = n->g_score + distanceBetween(*n, *end);
                    n->parent = current;
                }
                else if(temp_g_score < n->g_score) {
                    n->g_score = temp_g_score;
                    n->f_score = n->g_score + distanceBetween(*n, *end);
                    n->parent = current;
                }
            }
        }
        
        free(neighbors);
    }
    
    free(open);
}

int main()
{
    cell grid[ROWS][COLS];
    createGrid(grid);
    
    grid[2][1].type = SOURCE;
    grid[7][8].type = DEST;
    grid[3][1].type = WALL;
    grid[3][2].type = WALL;
    grid[3][3].type = WALL;
    grid[6][8].type = WALL;
    grid[6][9].type = WALL;
    grid[6][7].type = WALL;
    grid[5][7].type = WALL;
    grid[4][7].type = WALL;
    
    printGrid(grid);
    
    shortestPath(grid, &grid[2][1], &grid[7][8]);
    
    printf("\n\n");
    printGrid(grid);
    
    return 0;
}